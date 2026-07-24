#!/usr/bin/env python3
"""Bounded malformed-request probes for a loopback-only OpenWrt uHTTPd lab."""
from __future__ import annotations

import argparse
import socket
from urllib.parse import urlsplit


CASES = {
    "negative_content_length": (
        b"POST /cgi-bin/luci/ HTTP/1.1\r\nHost: localhost\r\n"
        b"Content-Length: -1\r\nConnection: close\r\n\r\n"
    ),
    "conflicting_content_length": (
        b"POST /cgi-bin/luci/ HTTP/1.1\r\nHost: localhost\r\n"
        b"Content-Length: 0\r\nContent-Length: 8\r\nConnection: close\r\n\r\nABCDEFGH"
    ),
    "unsupported_transfer_encoding": (
        b"POST /cgi-bin/luci/ HTTP/1.1\r\nHost: localhost\r\n"
        b"Transfer-Encoding: gzip\r\nConnection: close\r\n\r\nTEST"
    ),
    "invalid_chunk_hex": (
        b"POST /cgi-bin/luci/ HTTP/1.1\r\nHost: localhost\r\n"
        b"Transfer-Encoding: chunked\r\nConnection: close\r\n\r\nZZ\r\nTEST\r\n0\r\n\r\n"
    ),
    "oversized_chunk_hex": (
        b"POST /cgi-bin/luci/ HTTP/1.1\r\nHost: localhost\r\n"
        b"Transfer-Encoding: chunked\r\nConnection: close\r\n\r\n"
        b"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\r\nX\r\n0\r\n\r\n"
    ),
    "te_and_content_length": (
        b"POST /cgi-bin/luci/ HTTP/1.1\r\nHost: localhost\r\n"
        b"Transfer-Encoding: chunked\r\nContent-Length: 4\r\nConnection: close\r\n"
        b"\r\n4\r\nTEST\r\n0\r\n\r\n"
    ),
    "long_header_name": (
        b"GET / HTTP/1.1\r\nHost: localhost\r\nX-" + b"A" * 8192
        + b": x\r\nConnection: close\r\n\r\n"
    ),
    "long_request_target": (
        b"GET /" + b"A" * 8192 + b" HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"
    ),
}


def exchange(host: str, port: int, request: bytes, timeout: float = 3.0) -> bytes:
    with socket.create_connection((host, port), timeout=timeout) as sock:
        sock.settimeout(timeout)
        sock.sendall(request)
        chunks = []
        while True:
            try:
                chunk = sock.recv(65536)
            except TimeoutError:
                break
            except ConnectionResetError:
                break
            if not chunk:
                break
            chunks.append(chunk)
            if sum(map(len, chunks)) >= 1024 * 1024:
                break
        return b"".join(chunks)


def status_line(response: bytes) -> str:
    return response.split(b"\r\n", 1)[0].decode("ascii", errors="replace") if response else "NO_RESPONSE"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--url", default="http://127.0.0.1:28081")
    args = parser.parse_args()
    parsed = urlsplit(args.url)
    if parsed.hostname not in {"127.0.0.1", "localhost", "::1"}:
        parser.error("only loopback targets are permitted")
    host = parsed.hostname
    port = parsed.port or 80

    failures = 0
    baseline = b"GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"
    for name, request in CASES.items():
        try:
            response = exchange(host, port, request)
            after = exchange(host, port, baseline)
            alive = after.startswith(b"HTTP/1.1 200")
            print(f"{name}: response={status_line(response)!r} daemon_alive={str(alive).lower()}")
            failures += not alive
        except OSError as exc:
            failures += 1
            print(f"{name}: error={exc!r} daemon_alive=false")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
