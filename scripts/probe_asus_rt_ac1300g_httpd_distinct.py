#!/usr/bin/env python3
"""Bounded loopback-only probes for distinct RT-AC1300G Plus V3 httpd faults."""

from __future__ import annotations

import argparse
import json
import socket
import time
import urllib.parse


def request(method: bytes, path: bytes, headers: list[tuple[bytes, bytes]], body: bytes = b"") -> bytes:
    lines = [method + b" " + path + b" HTTP/1.1", b"Host: 127.0.0.1"]
    lines.extend(name + b": " + value for name, value in headers)
    lines.append(b"Connection: close")
    return b"\r\n".join(lines) + b"\r\n\r\n" + body


def cases() -> list[tuple[str, bytes]]:
    result: list[tuple[str, bytes]] = []
    for route in (
        b"/QIS_default.cgi",
        b"/cfg_onboarding.cgi",
        b"/check_Auth.cgi",
        b"/findasus.cgi",
        b"/page_default.cgi",
        b"/apply.cgi",
        b"/applyapp.cgi",
        b"/appGet.cgi",
        b"/upload.cgi",
    ):
        result.append((f"route-{route[1:].decode()}", request(b"GET", route, [])))

    for size in (256, 1024, 4096, 16384, 65536):
        result.append((f"host-{size}", request(b"GET", b"/", [(b"Host", b"A" * size)])))
    for size in (1024, 4096, 16384, 65536):
        result.append((f"path-{size}", request(b"GET", b"/" + b"A" * size, [])))

    result.extend(
        (
            (
                "duplicate-content-length",
                b"POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n"
                b"Content-Length: 0\r\nContent-Length: 65535\r\nConnection: close\r\n\r\n",
            ),
            (
                "negative-content-length",
                b"POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n"
                b"Content-Length: -1\r\nConnection: close\r\n\r\n",
            ),
            (
                "content-length-u32-max",
                b"POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n"
                b"Content-Length: 4294967295\r\nConnection: close\r\n\r\n",
            ),
            (
                "content-length-s64-max",
                b"POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n"
                b"Content-Length: 9223372036854775807\r\nConnection: close\r\n\r\n",
            ),
            (
                "transfer-encoding-chunked",
                b"POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n"
                b"Transfer-Encoding: chunked\r\nConnection: close\r\n\r\n0\r\n\r\n",
            ),
            (
                "content-length-plus-chunked",
                b"POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n"
                b"Content-Length: 4\r\nTransfer-Encoding: chunked\r\n"
                b"Connection: close\r\n\r\n0\r\n\r\n",
            ),
            ("empty-request", b"\r\n\r\n"),
            ("nul-method", b"GE\x00T / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n"),
            ("missing-version", b"GET /\r\nHost: 127.0.0.1\r\n\r\n"),
            ("absolute-form", b"GET http://127.0.0.1/ HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n"),
        )
    )

    for key in ("flag", "url"):
        for size in (127, 128, 255, 256, 511, 512, 1024, 4096, 16384):
            query = urllib.parse.urlencode({key: "A" * size}).encode()
            result.append(
                (
                    f"qis-{key}-{size}",
                    request(b"GET", b"/QIS_default.cgi?" + query, []),
                )
            )
    return result


def exchange(port: int, payload: bytes, timeout: float = 2.0) -> bytes:
    response = bytearray()
    with socket.create_connection(("127.0.0.1", port), timeout=timeout) as sock:
        sock.sendall(payload)
        sock.shutdown(socket.SHUT_WR)
        while len(response) < 8192:
            try:
                block = sock.recv(8192 - len(response))
            except (ConnectionResetError, socket.timeout):
                break
            if not block:
                break
            response.extend(block)
    return bytes(response)


def alive(port: int) -> bool:
    try:
        response = exchange(port, b"GET / HTTP/1.0\r\nHost: 127.0.0.1\r\n\r\n")
    except OSError:
        return False
    return response.startswith(b"HTTP/")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", type=int, default=28081)
    parser.add_argument("--start-at", type=int, default=0)
    args = parser.parse_args()
    corpus = cases()
    if not 0 <= args.start_at < len(corpus):
        parser.error(f"--start-at must be between 0 and {len(corpus) - 1}")
    if not alive(args.port):
        raise SystemExit("service is not healthy before corpus")

    results = []
    for index, (name, payload) in enumerate(corpus[args.start_at :], args.start_at):
        try:
            response = exchange(args.port, payload)
            error = None
        except OSError as exc:
            response = b""
            error = f"{type(exc).__name__}: {exc}"
        time.sleep(0.15)
        post_live = alive(args.port)
        record = {
            "index": index,
            "name": name,
            "request_bytes": len(payload),
            "response_bytes": len(response),
            "response_prefix": response[:64].decode("latin-1", errors="replace"),
            "error": error,
            "post_live": post_live,
        }
        results.append(record)
        print(json.dumps(record), flush=True)
        if not post_live:
            print(json.dumps({"stopped_after": record, "tested": len(results)}, indent=2))
            return 1
    print(json.dumps({"completed": True, "tested": len(results)}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
