#!/usr/bin/env python3
"""In-namespace HTTP probes for the isolated BE17000 UPnP emulator."""

from __future__ import annotations

import argparse
import socket


HOST = "192.168.1.1"
PORT = 56688


def exchange(request: bytes) -> bytes:
    with socket.create_connection((HOST, PORT), timeout=3) as client:
        client.sendall(request)
        client.shutdown(socket.SHUT_WR)
        client.settimeout(3)
        response = bytearray()
        while True:
            chunk = client.recv(4096)
            if not chunk:
                return bytes(response)
            response.extend(chunk)


def make_post(mode: str) -> bytes:
    if mode == "xml":
        body = b"<element attribute="
        action = (
            b'"urn:schemas-upnp-org:service:'
            b'Layer3Forwarding:1#SetDefaultConnectionService"'
        )
    else:
        body = (
            b'<?xml version="1.0"?>'
            b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
            b"<s:Body/></s:Envelope>"
        )
        action = b""
    return (
        b"POST /ctl/L3F HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"SOAPAction: "
        + action
        + b"\r\nContent-Type: text/xml\r\nContent-Length: "
        + str(len(body)).encode("ascii")
        + b"\r\nConnection: close\r\n\r\n"
        + body
    )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("mode", choices=("baseline", "xml", "soapaction"))
    args = parser.parse_args()
    if args.mode == "baseline":
        request = (
            b"GET /rootDesc.xml HTTP/1.1\r\n"
            b"Host: 192.168.1.1:56688\r\nConnection: close\r\n\r\n"
        )
    else:
        request = make_post(args.mode)
    try:
        response = exchange(request)
    except (OSError, TimeoutError) as error:
        print(f"connection_error={error}")
        return 2
    first = response.splitlines()[0].decode("iso-8859-1", "replace") if response else "no response"
    print(f"status={first}")
    print(f"response_bytes={len(response)}")
    return 0 if response.startswith(b"HTTP/1.1") else 1


if __name__ == "__main__":
    raise SystemExit(main())
