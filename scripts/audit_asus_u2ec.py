#!/usr/bin/env python3
"""Bounded localhost-only corpus for the ASUS u2ec discovery/print daemon."""

from __future__ import annotations

import socket
import sys


HOST = "127.0.0.1"
UDP_PORT = 5474
TCP_PORTS = (3394, 5473)
MAX_SIZE = 4096


def udp_probe(payload: bytes) -> str:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.settimeout(0.2)
        sock.sendto(payload, (HOST, UDP_PORT))
        try:
            data, _ = sock.recvfrom(MAX_SIZE)
            return f"reply={len(data)}"
        except (TimeoutError, socket.timeout):
            return "no-reply"


def tcp_probe(port: int, payload: bytes) -> str:
    try:
        with socket.create_connection((HOST, port), timeout=0.5) as sock:
            sock.settimeout(0.2)
            sock.sendall(payload)
            try:
                data = sock.recv(MAX_SIZE)
                return f"reply={len(data)}"
            except (TimeoutError, socket.timeout):
                return "no-reply"
    except OSError as exc:
        return f"connect-error={exc.errno}"


def listener_alive(port: int) -> bool:
    try:
        with socket.create_connection((HOST, port), timeout=0.5):
            return True
    except OSError:
        return False


def main() -> int:
    payloads = [b"GETIP", b"GETCONFIG", b"GETNAME", b"FRIDAY"]
    payloads.extend(b"A" * size for size in (1, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, MAX_SIZE))
    payloads.extend((b"GETIP\x00" + b"B" * 512, b"GETCONFIG\r\n" + b"C" * 512))

    for payload in payloads:
        print(f"udp size={len(payload)} {udp_probe(payload)}")
        for port in TCP_PORTS:
            print(f"tcp/{port} size={len(payload)} {tcp_probe(port, payload)}")

    states = {port: listener_alive(port) for port in TCP_PORTS}
    print("listeners=" + ",".join(f"{port}:{'alive' if alive else 'down'}" for port, alive in states.items()))
    return 0 if all(states.values()) else 1


if __name__ == "__main__":
    sys.exit(main())
