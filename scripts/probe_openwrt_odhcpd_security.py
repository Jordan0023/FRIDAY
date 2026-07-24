#!/usr/bin/env python3
"""Bounded DHCPv6 parser probes for an isolated genuine odhcpd process."""

from __future__ import annotations

import argparse
import ipaddress
import os
import socket
import struct
import time


def alive(pid: int) -> bool:
    try:
        os.kill(pid, 0)
        return True
    except ProcessLookupError:
        return False


def link_local(interface: str) -> str:
    with open("/proc/net/if_inet6", encoding="ascii") as addresses:
        for line in addresses:
            raw, _index, _prefix, scope, _flags, name = line.split()
            if name == interface and scope == "20":
                return str(ipaddress.IPv6Address(int(raw, 16)))
    raise RuntimeError(f"no link-local IPv6 address on {interface}")


def option(code: int, value: bytes) -> bytes:
    return struct.pack("!HH", code, len(value)) + value


def solicit(transaction: int) -> bytes:
    mac = b"\x02\x12\x00\x00\x10\x02"
    client_id = option(1, struct.pack("!HH", 3, 1) + mac)
    ia_na = option(3, struct.pack("!III", 0x12000001, 0, 0))
    oro = option(6, struct.pack("!HH", 23, 24))
    return b"\x01" + transaction.to_bytes(3, "big") + client_id + ia_na + oro


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--interface", required=True)
    parser.add_argument(
        "--pid", type=int,
        help="optional host-visible daemon PID; response controls remain mandatory",
    )
    args = parser.parse_args()

    index = socket.if_nametoindex(args.interface)
    source = link_local(args.interface)
    sock = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BINDTODEVICE, args.interface.encode())
    sock.setsockopt(socket.IPPROTO_IPV6, socket.IPV6_MULTICAST_IF, index)
    sock.bind((source, 546, 0, index))
    sock.settimeout(1.5)
    destination = ("ff02::1:2", 547, 0, index)

    transaction = 0x120000

    def control() -> bool:
        nonlocal transaction
        transaction = (transaction + 1) & 0xFFFFFF
        expected = transaction.to_bytes(3, "big")
        sock.sendto(solicit(transaction), destination)
        deadline = time.monotonic() + 1.5
        while time.monotonic() < deadline:
            try:
                data, _peer = sock.recvfrom(8192)
            except socket.timeout:
                return False
            if len(data) >= 4 and data[0] in (2, 7) and data[1:4] == expected:
                return True
        return False

    if not control():
        print("FAIL baseline: no Advertise/Reply")
        return 1
    print("PASS baseline: valid Solicit answered")

    relay_header = (
        b"\x0c\x00"
        + ipaddress.IPv6Address("fd42:1200::1").packed
        + ipaddress.IPv6Address(source).packed
    )

    def nested_relay(depth: int) -> bytes:
        inner = solicit(0x332211)
        for hop in range(depth):
            header = (
                b"\x0c"
                + bytes([min(hop, 255)])
                + ipaddress.IPv6Address("fd42:1200::1").packed
                + ipaddress.IPv6Address(source).packed
            )
            inner = header + option(9, inner)
        return inner

    valid = solicit(0x332211)
    cases = [
        ("empty", b""),
        ("one-byte", b"\x01"),
        ("short-transaction", b"\x01\x00\x00"),
        ("unknown-message", b"\xff\x00\x00\x01"),
        ("truncated-option-header", b"\x01\x00\x00\x01\x00"),
        ("option-length-overflow", b"\x01\x00\x00\x01\x00\x01\xff\xff"),
        ("short-client-id", b"\x01\x00\x00\x01" + option(1, b"\x00")),
        (
            "duplicate-client-id",
            b"\x01\x00\x00\x01" + option(1, b"\x00\x03\x00\x01ABCD12") * 2,
        ),
        ("short-ia-na", b"\x01\x00\x00\x01" + option(3, b"\x00" * 11)),
        (
            "ia-na-child-overflow",
            b"\x01\x00\x00\x01"
            + option(3, b"\x00" * 12 + b"\x00\x05\xff\xff"),
        ),
        ("relay-short", b"\x0c\x00" + b"\x00" * 15),
        ("relay-option-overflow", relay_header + b"\x00\x09\xff\xff"),
        ("relay-empty-message", relay_header + option(9, b"")),
        ("relay-hop-255", b"\x0c\xff" + relay_header[2:] + option(9, valid)),
        ("relay-nested-1", nested_relay(1)),
        ("relay-nested-4", nested_relay(4)),
        ("relay-nested-8", nested_relay(8)),
        ("relay-nested-16", nested_relay(16)),
        ("relay-nested-32", nested_relay(32)),
        ("request-minimal", b"\x03\x00\x00\x01"),
        ("confirm-minimal", b"\x04\x00\x00\x01"),
        ("renew-minimal", b"\x05\x00\x00\x01"),
        ("rebind-minimal", b"\x06\x00\x00\x01"),
        ("release-minimal", b"\x08\x00\x00\x01"),
        ("decline-minimal", b"\x09\x00\x00\x01"),
        ("many-zero-options", b"\x01\x00\x00\x01" + b"\x00\x08\x00\x00" * 256),
        ("large-declared-body", b"\x01\x00\x00\x01\x00\x11\x10\x00" + b"A" * 1400),
    ]

    for name, payload in cases:
        sock.sendto(payload, destination)
        time.sleep(0.08)
        if args.pid is not None and not alive(args.pid):
            print(f"FAIL {name}: odhcpd exited")
            return 1
        if not control():
            print(f"FAIL {name}: post-probe control unanswered")
            return 1
        print(f"PASS {name}: alive and control answered")

    for _ in range(128):
        sock.sendto(b"\x01\x00\x00\x01\x00\x01\xff\xff", destination)
    time.sleep(0.25)
    if (args.pid is not None and not alive(args.pid)) or not control():
        print("FAIL bounded-burst: daemon or response control lost")
        return 1
    print("PASS bounded-burst: alive and control answered")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
