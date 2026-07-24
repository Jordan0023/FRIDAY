#!/usr/bin/env python3
"""Bounded DNS and DHCPv4 parser probes for the isolated RP-AX56 lab."""
from __future__ import annotations

import argparse
import json
import socket
import struct
import time


def dns_header(qd: int = 1, ar: int = 0) -> bytes:
    return struct.pack("!HHHHHH", 0x5250, 0x0100, qd, 0, 0, ar)


DNS_CONTROL = (
    dns_header()
    + b"\x07control\x07invalid\x00"
    + struct.pack("!HH", 1, 1)
)

DNS_CASES = {
    "empty": b"",
    "short_header": b"\x52\x50\x01",
    "truncated_label": dns_header() + b"\x3fA",
    "compression_self_loop": dns_header() + b"\xc0\x0c" + struct.pack("!HH", 1, 1),
    "label_64": dns_header() + b"\x40" + b"A" * 64 + b"\0" + struct.pack("!HH", 1, 1),
    "max_qdcount": dns_header(0xffff) + DNS_CONTROL[12:],
    "truncated_edns": dns_header(ar=1) + DNS_CONTROL[12:] + b"\0\0\x29\x10",
    "edns_bad_length": (
        dns_header(ar=1)
        + DNS_CONTROL[12:]
        + b"\0"
        + struct.pack("!HHIH", 41, 4096, 0, 6)
        + b"\0\x0f\xff\xff\0\0"
    ),
}


def dns_udp(packet: bytes) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.settimeout(0.4)
        sock.sendto(packet, ("192.168.50.1", 5353))
        try:
            return sock.recv(65535)
        except (TimeoutError, socket.timeout):
            return b""


def dns_tcp(packet: bytes) -> bytes:
    with socket.create_connection(("192.168.50.1", 5353), timeout=0.5) as sock:
        sock.settimeout(0.4)
        sock.sendall(packet)
        try:
            return sock.recv(65535)
        except (TimeoutError, socket.timeout, ConnectionResetError):
            return b""


def healthy() -> bool:
    response = dns_udp(DNS_CONTROL)
    return len(response) >= 12 and response[:2] == DNS_CONTROL[:2]


def dhcp_discover() -> bytes:
    mac = b"\x02\x46\x52\x49\x44\x41"
    fixed = struct.pack(
        "!BBBBIHHIIII16s64s128s",
        1, 1, 6, 0, 0x46524944, 0, 0x8000, 0, 0, 0, 0,
        mac + b"\0" * 10, b"\0" * 64, b"\0" * 128,
    )
    return fixed + b"\x63\x82\x53\x63\x35\x01\x01\x37\x03\x01\x03\x06\xff"


def send_dhcp(packet: bytes) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BINDTODEVICE, b"br0\0")
        sock.settimeout(0.5)
        try:
            sock.bind(("0.0.0.0", 68))
        except OSError:
            pass
        sock.sendto(packet, ("255.255.255.255", 67))
        try:
            return sock.recv(65535)
        except (TimeoutError, socket.timeout):
            return b""


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--json-out")
    args = parser.parse_args()
    results: list[dict[str, object]] = []
    for name, packet in DNS_CASES.items():
        response = dns_udp(packet)
        results.append({"surface": "dns_udp", "case": name,
                        "response_bytes": len(response), "alive": healthy()})
    tcp_cases = {
        "zero_length": b"\0\0",
        "declared_long_truncated": b"\xff\xff" + DNS_CONTROL,
        "declared_short": b"\0\x01" + DNS_CONTROL,
        "valid": struct.pack("!H", len(DNS_CONTROL)) + DNS_CONTROL,
    }
    for name, packet in tcp_cases.items():
        response = dns_tcp(packet)
        results.append({"surface": "dns_tcp", "case": name,
                        "response_bytes": len(response), "alive": healthy()})
    discover = dhcp_discover()
    dhcp_cases = {
        "empty": b"",
        "short_fixed": discover[:32],
        "truncated_cookie": discover[:238],
        "option_length_overrun": discover[:240] + b"\x35\xff\x01",
        "valid_discover": discover,
    }
    for name, packet in dhcp_cases.items():
        response = send_dhcp(packet)
        time.sleep(0.05)
        results.append({"surface": "dhcpv4", "case": name,
                        "response_bytes": len(response), "alive": healthy()})
    summary = {
        "cases": len(results),
        "all_health_checks_passed": all(item["alive"] for item in results),
        "results": results,
    }
    rendered = json.dumps(summary, indent=2)
    print(rendered)
    if args.json_out:
        with open(args.json_out, "w", encoding="utf-8") as output:
            output.write(rendered + "\n")
    return 0 if summary["all_health_checks_passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
