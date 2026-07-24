#!/usr/bin/env python3
"""Bounded EAPOL parser probes for an isolated OpenWrt wpad instance."""

from __future__ import annotations

import argparse
import os
import socket
import struct
import time


EAPOL_ETHERTYPE = 0x888E


def mac_bytes(value: str) -> bytes:
    return bytes.fromhex(value.replace(":", ""))


def alive(pid: int) -> bool:
    try:
        os.kill(pid, 0)
        return True
    except ProcessLookupError:
        return False


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--interface", required=True)
    parser.add_argument("--target-mac", required=True)
    parser.add_argument("--pid", required=True, type=int)
    parser.add_argument("--observe-interface")
    args = parser.parse_args()

    sock = socket.socket(socket.AF_PACKET, socket.SOCK_RAW)
    sock.bind((args.interface, 0))
    source = sock.getsockname()[4]
    destination = mac_bytes(args.target_mac)
    ethernet = destination + source + struct.pack("!H", EAPOL_ETHERTYPE)
    observer = None
    observed = 0
    if args.observe_interface:
        observer = socket.socket(
            socket.AF_PACKET, socket.SOCK_RAW, socket.htons(0x0003)
        )
        observer.bind((args.observe_interface, 0))
        observer.setblocking(False)

    cases = [
        ("empty", b""),
        ("one-byte", b"\x02"),
        ("short-header", b"\x02\x00\x00"),
        ("valid-start", b"\x02\x01\x00\x00"),
        ("valid-logoff", b"\x02\x02\x00\x00"),
        ("unknown-version", b"\xff\x01\x00\x00"),
        ("unknown-type", b"\x02\xff\x00\x00"),
        ("declared-ffff-empty", b"\x02\x00\xff\xff"),
        ("declared-one-empty", b"\x02\x00\x00\x01"),
        ("eap-short", b"\x02\x00\x00\x01\x01"),
        ("eap-length-underflow", b"\x02\x00\x00\x04\x01\x01\x00\x03"),
        ("eap-length-overflow", b"\x02\x00\x00\x04\x01\x01\xff\xff"),
        ("key-short", b"\x02\x03\x00\x01\x02"),
        ("key-declared-large", b"\x02\x03\x00\x05\x02\x00\x00\xff\xff"),
        ("max-ether-payload", b"\x02\x00\x05\xd8" + b"A" * 1496),
    ]

    for name, payload in cases:
        sock.send(ethernet + payload)
        time.sleep(0.08)
        if observer:
            try:
                while True:
                    frame = observer.recv(65535)
                    if len(frame) >= 14 and frame[12:14] == b"\x88\x8e":
                        observed += 1
            except BlockingIOError:
                pass
        if not alive(args.pid):
            print(f"FAIL {name}: wpad exited")
            return 1
        print(f"PASS {name}: alive")

    for _ in range(64):
        sock.send(ethernet + b"\x02\x03\xff\xff")
    time.sleep(0.25)
    if not alive(args.pid):
        print("FAIL bounded-burst: wpad exited")
        return 1
    print("PASS bounded-burst: alive")
    if observer:
        if observed < len(cases):
            print(f"FAIL delivery-evidence: observed {observed}/{len(cases)}")
            return 1
        print(f"PASS delivery-evidence: observed {observed} EAPOL frames")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
