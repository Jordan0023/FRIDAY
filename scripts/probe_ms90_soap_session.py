#!/usr/bin/env python3
"""Controlled loopback-only probes for the isolated MS90 SOAP service."""

from __future__ import annotations

import argparse
import socket
import ssl
import time


def request(
    port: int,
    service: str,
    action: str,
    session: str | None,
    host: str = "10.0.2.15",
) -> bytes:
    namespace = f"urn:NETGEAR-ROUTER:service:{service}:1"
    header = (
        f"<s:Header><SessionID>{session}</SessionID></s:Header>"
        if session is not None
        else ""
    )
    body = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        f"{header}"
        f'<s:Body><m:{action} xmlns:m="{namespace}"/></s:Body>'
        "</s:Envelope>"
    ).encode()
    headers = [
        "POST /soap/server_sa/ HTTP/1.1",
        f"Host: {host}",
        'Content-Type: text/xml; charset="utf-8"',
        f'SOAPAction: "{namespace}#{action}"',
    ]
    headers.extend((f"Content-Length: {len(body)}", "Connection: close", "", ""))
    payload = "\r\n".join(headers).encode() + body

    context = ssl.create_default_context()
    context.check_hostname = False
    context.verify_mode = ssl.CERT_NONE
    with socket.create_connection(("127.0.0.1", port), timeout=8) as raw:
        with context.wrap_socket(raw, server_hostname=host) as client:
            client.sendall(payload)
            response = bytearray()
            while True:
                chunk = client.recv(65536)
                if not chunk:
                    break
                response.extend(chunk)
    return bytes(response)


def status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "no response"


def alive(port: int, host: str = "10.0.2.15") -> bool:
    try:
        request(port, "DeviceInfo", "GetInfo", None, host)
        return True
    except OSError:
        return False


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("case", choices=("controls", "reboot"))
    parser.add_argument("--port", type=int, default=25093)
    parser.add_argument("--host", default="10.0.2.15")
    args = parser.parse_args()
    fixed = "12345678901234567890"

    if args.case == "controls":
        for name, token in (
            ("missing", None),
            ("invalid", "FRIDAY_INVALID_SESSION"),
            ("fixed", fixed),
        ):
            try:
                response = request(
                    args.port, "DeviceInfo", "GetInfo", token, args.host
                )
                print(f"{name}: {status(response)} bytes={len(response)}")
            except OSError as error:
                print(f"{name}: {type(error).__name__}: {error}")
                return 2
        return 0

    response = request(
        args.port, "DeviceConfig", "Reboot", fixed, args.host
    )
    print(f"reboot: {status(response)} bytes={len(response)}")
    for delay in (1, 3, 8):
        time.sleep(delay)
        print(
            f"alive_after_{delay}s={str(alive(args.port, args.host)).lower()}"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
