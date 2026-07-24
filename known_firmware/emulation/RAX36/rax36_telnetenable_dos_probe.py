#!/usr/bin/env python3
"""Bounded malformed UDP matrix for the isolated RAX36 telnetenable daemon."""

from __future__ import annotations

import os
import socket
import time


HOST = "192.168.1.1"
PORT = 23
SOURCE = "192.168.1.2"


def daemon_pids() -> list[int]:
    result: list[int] = []
    for entry in os.scandir("/proc"):
        if not entry.name.isdigit():
            continue
        try:
            with open(f"/proc/{entry.name}/cmdline", "rb") as handle:
                command = handle.read()
        except OSError:
            continue
        if b"/usr/sbin/telnetenable" in command:
            result.append(int(entry.name))
    return sorted(result)


def main() -> int:
    cases = [
        ("empty", b""),
        ("one-byte", b"\x00"),
        ("short-pattern", b"AMBIT_TELNET_ENABLE"),
        ("nul-32", b"\x00" * 32),
        ("ff-32", b"\xff" * 32),
        ("pattern-64", bytes(range(64))),
        ("pattern-255", bytes(range(255))),
        ("pattern-256", bytes(range(256))),
        ("pattern-511", bytes(range(256)) + bytes(range(255))),
        ("pattern-512", bytes(range(256)) * 2),
        ("pattern-513", bytes(range(256)) * 2 + b"A"),
        ("pattern-4096", bytes(range(256)) * 16),
        ("maximum-udp", b"A" * 65507),
    ]
    before = daemon_pids()
    if not before:
        print("baseline_failed=no_telnetenable_process")
        return 2

    for name, payload in cases:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
            client.bind((SOURCE, 0))
            client.settimeout(0.2)
            client.sendto(payload, (HOST, PORT))
            try:
                response, _ = client.recvfrom(64)
            except (TimeoutError, socket.timeout):
                response = b""
        time.sleep(0.15)
        after = daemon_pids()
        alive = bool(set(before) & set(after))
        print(
            f"{name} datagram_bytes={len(payload)} response_bytes={len(response)} "
            f"pids={','.join(map(str, after)) or 'none'} alive={alive}"
        )
        if not alive:
            print(f"crash_candidate={name}")
            return 1

    print("result=no-observable-telnetenable-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
