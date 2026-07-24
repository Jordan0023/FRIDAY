#!/usr/bin/env python3
"""Bounded loopback-only probes for the ASUS RP-AX56 cfg_server parser."""

from __future__ import annotations

import argparse
import json
import socket
import struct
import time


TARGET = "127.0.0.1"
PORT = 7788
PUBLIC_CONNDIAG_TRIGGER = bytes.fromhex("00000006fffffffc")


def frame(opcode: int, declared_length: int, payload: bytes = b"") -> bytes:
    return struct.pack("!III", opcode, declared_length, 0) + payload


def send_udp(packet: bytes) -> str | None:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
            sock.sendto(packet, (TARGET, PORT))
        return None
    except OSError as exc:
        return f"{type(exc).__name__}: {exc}"


def send_tcp(packet: bytes) -> str | None:
    try:
        with socket.create_connection((TARGET, PORT), timeout=0.5) as sock:
            sock.settimeout(0.25)
            sock.sendall(packet)
        return None
    except OSError as exc:
        return f"{type(exc).__name__}: {exc}"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--case",
        choices=("historical-conndiag", "udp-matrix", "tcp-matrix"),
        required=True,
    )
    args = parser.parse_args()

    if args.case == "historical-conndiag":
        cases = [("published-eight-byte-trigger", PUBLIC_CONNDIAG_TRIGGER)]
        sender = send_udp
    elif args.case == "udp-matrix":
        sizes = (0, 1, 4, 7, 8, 9, 11, 12, 13, 31, 32, 33, 255, 2047)
        cases = [(f"size-{size}", bytes([0x41]) * size) for size in sizes]
        sender = send_udp
    else:
        lengths = (0, 1, 4, 11, 12, 31, 32, 33, 255, 2047, 0x7FFFFFFF, 0xFFFFFFFF)
        cases = [
            (f"opcode-{opcode}-length-{length}", frame(opcode, length))
            for opcode in (1, 3, 4, 5, 8)
            for length in lengths
        ]
        sender = send_tcp

    results = []
    for name, packet in cases:
        started = time.monotonic()
        error = sender(packet)
        results.append(
            {
                "name": name,
                "request_bytes": len(packet),
                "error": error,
                "elapsed_ms": round((time.monotonic() - started) * 1000, 2),
            }
        )
        time.sleep(0.03)

    print(
        json.dumps(
            {
                "target": f"{TARGET}:{PORT}",
                "case": args.case,
                "results": results,
            },
            indent=2,
        )
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
