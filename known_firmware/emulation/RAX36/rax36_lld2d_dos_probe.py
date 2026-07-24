#!/usr/bin/env python3
"""Bounded malformed-frame matrix for the genuine RAX36 lld2d.

Run only in the disposable, network-isolated RAX36 container.  Frames leave
the synthetic client0 veth and can reach only the synthetic br0 interface.
"""

from __future__ import annotations

import os
import socket
import struct
import time


INTERFACE = "client0"
ETHERTYPE_LLTD = 0x88D9
LLTD_MULTICAST = bytes.fromhex("0180c200000e")


def interface_mac(name: str) -> bytes:
    with open(f"/sys/class/net/{name}/address", encoding="ascii") as handle:
        return bytes.fromhex(handle.read().strip().replace(":", ""))


def lld2d_pids() -> list[int]:
    result: list[int] = []
    for entry in os.scandir("/proc"):
        if not entry.name.isdigit():
            continue
        try:
            with open(f"/proc/{entry.name}/cmdline", "rb") as handle:
                command = handle.read()
        except OSError:
            continue
        if b"/usr/sbin/lld2d" in command:
            result.append(int(entry.name))
    return sorted(result)


def lltd_header(
    source: bytes,
    *,
    tos: int = 0,
    function: int = 0,
    transaction: int = 1,
    real_dst: bytes = LLTD_MULTICAST,
) -> bytes:
    return struct.pack(
        "!BBBB6s6sH",
        1,
        tos,
        0,
        function,
        real_dst,
        source,
        transaction,
    )


def ethernet(source: bytes, payload: bytes) -> bytes:
    return LLTD_MULTICAST + source + struct.pack("!H", ETHERTYPE_LLTD) + payload


def main() -> int:
    source = interface_mac(INTERFACE)
    cases = [
        ("control-discover-empty", lltd_header(source) + struct.pack("!HH", 1, 0)),
        ("lltd-header-truncated-0", b""),
        ("lltd-header-truncated-1", b"\x01"),
        ("lltd-header-truncated-17", lltd_header(source)[:-1]),
        ("unsupported-version", b"\xff" + lltd_header(source)[1:]),
        ("opcode-out-of-range", lltd_header(source, function=0xFF)),
        ("discover-body-empty", lltd_header(source)),
        ("discover-count-one-truncated", lltd_header(source) + struct.pack("!HH", 2, 1)),
        ("discover-count-max-truncated", lltd_header(source) + struct.pack("!HH", 3, 0xFFFF)),
        (
            "discover-count-max-one-station",
            lltd_header(source) + struct.pack("!HH", 4, 0xFFFF) + source,
        ),
        ("hello-truncated", lltd_header(source, function=1, transaction=1)),
        ("emit-body-empty", lltd_header(source, function=2, transaction=1)),
        ("emit-count-max-truncated", lltd_header(source, function=2) + b"\xff\xff"),
        (
            "emit-count-max-one-descriptor",
            lltd_header(source, function=2)
            + b"\xff\xff"
            + struct.pack("!BB6s6s", 0, 1, source, LLTD_MULTICAST),
        ),
        ("query-large-tlv-empty", lltd_header(source, function=11)),
        ("query-large-tlv-short-offset", lltd_header(source, function=11) + b"\x0e\xff\xff"),
        (
            "query-large-tlv-max-offset",
            lltd_header(source, function=11) + b"\x0e\xff\xff\xff",
        ),
        ("quick-discover-empty", lltd_header(source, tos=1, function=0)),
        ("quick-hello-empty", lltd_header(source, tos=1, function=1)),
        ("qos-function-max", lltd_header(source, tos=2, function=10)),
        ("maximum-ethernet-payload", lltd_header(source, function=2) + b"A" * 1462),
    ]

    before = lld2d_pids()
    if not before:
        print("baseline_failed=no_lld2d_process")
        return 2

    with socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(ETHERTYPE_LLTD)) as sender:
        sender.bind((INTERFACE, 0))
        for name, payload in cases:
            sender.send(ethernet(source, payload))
            time.sleep(0.15)
            after = lld2d_pids()
            alive = bool(set(before) & set(after))
            print(
                f"{name} frame_bytes={14 + len(payload)} "
                f"pids={','.join(map(str, after)) or 'none'} alive={alive}"
            )
            if not alive:
                print(f"crash_candidate={name}")
                return 1

        mutation_groups = (
            (
                "all-opcodes",
                (
                    lltd_header(source, function=value)
                    for value in range(256)
                ),
            ),
            (
                "all-tos-values",
                (
                    lltd_header(source, tos=value, function=0)
                    for value in range(256)
                ),
            ),
            (
                "discover-count-low-byte",
                (
                    lltd_header(source)
                    + struct.pack("!HH", value + 0x100, value)
                    + source
                    for value in range(256)
                ),
            ),
        )
        for group_name, payloads in mutation_groups:
            for index, payload in enumerate(payloads):
                sender.send(ethernet(source, payload))
                time.sleep(0.01)
                after = lld2d_pids()
                alive = bool(set(before) & set(after))
                if not alive:
                    print(
                        f"crash_candidate={group_name}-{index} "
                        f"pids={','.join(map(str, after)) or 'none'}"
                    )
                    return 1
            print(
                f"mutation_group={group_name} cases=256 "
                f"pids={','.join(map(str, after))} alive=true"
            )

    print("result=no-observable-lld2d-dos explicit_cases=21 mutations=768")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
