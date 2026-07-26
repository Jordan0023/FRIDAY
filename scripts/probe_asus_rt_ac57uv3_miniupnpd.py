#!/usr/bin/env python3
"""Bounded loopback probe for the RT-AC57U V3 MiniUPnPd SOAPAction parser."""

from __future__ import annotations

import argparse
import json
import socket
import time


def exchange(host: str, port: int, request: bytes) -> tuple[bytes, str | None]:
    try:
        with socket.create_connection((host, port), timeout=1.0) as sock:
            sock.settimeout(1.0)
            sock.sendall(request)
            response = bytearray()
            while len(response) < 8192:
                try:
                    chunk = sock.recv(8192 - len(response))
                except socket.timeout:
                    break
                if not chunk:
                    break
                response.extend(chunk)
            return bytes(response), None
    except OSError as exc:
        return b"", f"{type(exc).__name__}: {exc}"


def request(action: bytes | None = None) -> bytes:
    if action is None:
        return b"GET /rootDesc.xml HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n"
    body = b"<s:Envelope><s:Body/></s:Envelope>"
    return (
        b"POST /ctl/IPConn HTTP/1.1\r\n"
        b"Host: 127.0.0.1\r\n"
        b"SOAPAction: " + action + b"\r\n"
        b"Content-Type: text/xml\r\n"
        b"Content-Length: " + str(len(body)).encode() + b"\r\n"
        b"Connection: close\r\n\r\n" + body
    )


def subscribe(callback: bytes) -> bytes:
    return (
        b"SUBSCRIBE /evt/IPConn HTTP/1.1\r\n"
        b"Host: 127.0.0.1\r\n"
        b"Callback: " + callback + b"\r\n"
        b"NT: upnp:event\r\n"
        b"Timeout: Second-30\r\n"
        b"Connection: close\r\n\r\n"
    )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=15000)
    parser.add_argument(
        "--case",
        action="append",
        dest="selected_cases",
        help="run only the named case (repeatable)",
    )
    args = parser.parse_args()

    cases = (
        ("control-before", request()),
        ("single-quote", request(b"'")),
        ("gena-empty-callback", subscribe(b"")),
        ("gena-no-port", subscribe(b"<http://127.0.0.1/>")),
        ("gena-refused-port", subscribe(b"<http://127.0.0.1:9/>")),
        ("gena-long-callback", subscribe(b"<http://127.0.0.1/" + b"A" * 4096 + b">")),
        ("long-soapaction", request(b"'" + b"A" * 16384)),
        ("control-after", request()),
    )
    if args.selected_cases:
        wanted = set(args.selected_cases)
        cases = tuple(case for case in cases if case[0] in wanted)
        missing = wanted.difference(name for name, _ in cases)
        if missing:
            parser.error("unknown case(s): " + ", ".join(sorted(missing)))

    results = []
    for name, payload in cases:
        response, error = exchange(args.host, args.port, payload)
        results.append({
            "name": name,
            "request_bytes": len(payload),
            "response_bytes": len(response),
            "status": response.split(b"\r\n", 1)[0].decode("latin-1", "replace"),
            "error": error,
        })
        time.sleep(0.2)
    print(json.dumps(results, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
