#!/usr/bin/env python3
"""Bounded malformed DNS probes for a loopback-only OpenWrt dnsmasq lab."""
from __future__ import annotations

import argparse
import socket
import struct


def header(ident: int = 0x4652, flags: int = 0x0100, qd: int = 1,
           an: int = 0, ns: int = 0, ar: int = 0) -> bytes:
    return struct.pack("!HHHHHH", ident, flags, qd, an, ns, ar)


def name(labels: list[bytes]) -> bytes:
    return b"".join(bytes([len(label)]) + label for label in labels) + b"\x00"


BASELINE = header() + name([b"friday", b"invalid"]) + struct.pack("!HH", 1, 1)
CASES = {
    "empty": b"",
    "short_header": b"\x46\x52\x01",
    "truncated_question": header() + b"\x06frid",
    "compression_self_loop": header() + b"\xc0\x0c" + struct.pack("!HH", 1, 1),
    "compression_two_node_loop": header() + b"\xc0\x0e\xc0\x0c" + struct.pack("!HH", 1, 1),
    "label_over_63": header() + b"\x40" + b"A" * 64 + b"\x00" + struct.pack("!HH", 1, 1),
    "max_qdcount": header(qd=0xFFFF) + BASELINE[12:],
    "truncated_edns": header(ar=1) + BASELINE[12:] + b"\x00\x00\x29\x10",
    "oversized_edns_option": (
        header(ar=1) + BASELINE[12:] +
        b"\x00" + struct.pack("!HHIH", 41, 4096, 0, 6) + b"\x00\x0f\xff\xff\x00\x00"
    ),
}


def udp_exchange(host: str, port: int, data: bytes, timeout: float = 1.0) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.settimeout(timeout)
        sock.sendto(data, (host, port))
        try:
            return sock.recv(65535)
        except TimeoutError:
            return b""


def tcp_exchange(host: str, port: int, data: bytes, timeout: float = 1.0) -> bytes:
    with socket.create_connection((host, port), timeout=timeout) as sock:
        sock.settimeout(timeout)
        sock.sendall(data)
        try:
            return sock.recv(65535)
        except (TimeoutError, ConnectionResetError):
            return b""


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=25353)
    parser.add_argument(
        "--health-transport", choices=("udp", "tcp", "any"), default="udp"
    )
    args = parser.parse_args()
    if args.host not in {"127.0.0.1", "localhost", "::1"}:
        parser.error("only loopback targets are permitted")

    def control_alive() -> bool:
        udp = udp_exchange(args.host, args.port, BASELINE)
        udp_ok = len(udp) >= 12 and udp[:2] == BASELINE[:2]
        tcp = tcp_exchange(
            args.host, args.port, struct.pack("!H", len(BASELINE)) + BASELINE
        )
        tcp_ok = len(tcp) >= 14 and tcp[2:4] == BASELINE[:2]
        if args.health_transport == "udp":
            return udp_ok
        if args.health_transport == "tcp":
            return tcp_ok
        return udp_ok or tcp_ok

    failures = 0
    for case, packet in CASES.items():
        try:
            response = udp_exchange(args.host, args.port, packet)
            alive = control_alive()
        except OSError:
            response, alive = b"", False
        print(f"udp_{case}: response_bytes={len(response)} daemon_alive={str(alive).lower()}")
        failures += not alive

    tcp_cases = {
        "zero_length": b"\x00\x00",
        "declared_long_truncated": b"\xff\xff" + BASELINE,
        "declared_short": b"\x00\x01" + BASELINE,
        "valid": struct.pack("!H", len(BASELINE)) + BASELINE,
    }
    for case, packet in tcp_cases.items():
        try:
            response = tcp_exchange(args.host, args.port, packet)
            alive = control_alive()
        except OSError:
            response, alive = b"", False
        print(f"tcp_{case}: response_bytes={len(response)} daemon_alive={str(alive).lower()}")
        failures += not alive
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
