#!/usr/bin/env python3
"""Bounded DNS/DHCP parser probes for exact RAX36 dnsmasq in an isolated LAN."""

from __future__ import annotations

import socket
import struct
import time


SERVER = "192.168.1.1"
CLIENT = "192.168.1.2"
DNS_PORT = 5353


def qname(labels: list[bytes]) -> bytes:
    return b"".join(bytes([len(label)]) + label for label in labels) + b"\0"


def dns_query(name: bytes, ident: int = 0x4652) -> bytes:
    return struct.pack("!HHHHHH", ident, 0x0100, 1, 0, 0, 0) + name + struct.pack("!HH", 1, 1)


def udp_exchange(payload: bytes, port: int, timeout: float = 0.25) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
        client.settimeout(timeout)
        client.bind((CLIENT, 0))
        client.sendto(payload, (SERVER, port))
        try:
            return client.recvfrom(65535)[0]
        except socket.timeout:
            return b""


def tcp_exchange(payload: bytes, timeout: float = 1.0) -> bytes:
    output = bytearray()
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
        client.settimeout(timeout)
        client.bind((CLIENT, 0))
        client.connect((SERVER, DNS_PORT))
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        try:
            while len(output) < 65535:
                chunk = client.recv(4096)
                if not chunk:
                    break
                output.extend(chunk)
        except socket.timeout:
            pass
    return bytes(output)


def healthy() -> bool:
    try:
        response = udp_exchange(dns_query(qname([b"router", b"test"])), DNS_PORT)
        return (
            len(response) >= 12
            and response[:2] == b"FR"
            and response[2] & 0x80 != 0
            and b"\xc0\x00\x02\x01" in response
        )
    except OSError:
        return False


def dhcp_packet(options: bytes, xid: int = 0x46524944) -> bytes:
    bootp = struct.pack(
        "!BBBBIHHIIII16s64s128s",
        1,
        1,
        6,
        0,
        xid,
        0,
        0x8000,
        0,
        0,
        0,
        0,
        b"\x02FRIDAY" + b"\0" * 9,
        b"\0" * 64,
        b"\0" * 128,
    )
    return bootp + b"\x63\x82\x53\x63" + options


def dhcp_control() -> bytes:
    return dhcp_packet(b"\x35\x01\x01\x3d\x07\x01\x02FRIDAY\xff")


def main() -> int:
    if not healthy():
        print("baseline_failed")
        return 2

    valid = dns_query(qname([b"router", b"test"]))
    compression_chain = bytearray(struct.pack("!HHHHHH", 0x4343, 0x0100, 1, 0, 0, 0))
    compression_chain.extend(b"\xc0\x0e")
    for offset in range(14, 268, 2):
        compression_chain.extend(b"\xc0" + bytes([(offset + 2) & 0xFF]))
    compression_chain.extend(b"\0")
    compression_chain.extend(struct.pack("!HH", 1, 1))

    dns_cases = [
        ("dns-empty", b""),
        ("dns-short-header", b"A" * 11),
        ("dns-qdcount-ffff", struct.pack("!HHHHHH", 1, 0x0100, 0xFFFF, 0, 0, 0)),
        ("dns-label-truncated", dns_query(b"\x3f" + b"A" * 8)),
        ("dns-compression-self-loop", dns_query(b"\xc0\x0c")),
        ("dns-compression-chain", bytes(compression_chain)),
        (
            "dns-max-wire-name",
            dns_query(qname([b"A" * 63, b"B" * 63, b"C" * 63, b"D" * 61])),
        ),
        ("dns-binary-label", dns_query(qname([bytes(range(1, 64)), b"test"]))),
        (
            "dns-opt-rdlen-overrun",
            valid[:4]
            + struct.pack("!HHHH", 1, 0, 0, 1)
            + valid[12:]
            + b"\0"
            + struct.pack("!HHIH", 41, 4096, 0, 0xFFFF),
        ),
        ("dns-large-datagram", valid + bytes(range(256)) * 16),
    ]

    for name, payload in dns_cases:
        try:
            response = udp_exchange(payload, DNS_PORT)
            outcome = f"response_bytes={len(response)}"
        except OSError as error:
            outcome = f"socket_error={type(error).__name__}:{error}"
        time.sleep(0.05)
        alive = healthy()
        print(f"{name} request_bytes={len(payload)} {outcome} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1

    tcp_cases = [
        ("dns-tcp-zero-length", b"\0\0"),
        ("dns-tcp-short-declared", struct.pack("!H", len(valid) + 32) + valid),
        ("dns-tcp-ffff-declared", b"\xff\xff" + valid),
        ("dns-tcp-valid-control", struct.pack("!H", len(valid)) + valid),
    ]
    for name, payload in tcp_cases:
        try:
            response = tcp_exchange(payload)
            outcome = f"response_bytes={len(response)}"
        except OSError as error:
            outcome = f"socket_error={type(error).__name__}:{error}"
        time.sleep(0.05)
        alive = healthy()
        print(f"{name} request_bytes={len(payload)} {outcome} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1

    dhcp_cases = [
        ("dhcp-control", dhcp_control()),
        ("dhcp-no-cookie", dhcp_control()[:236]),
        ("dhcp-truncated-option", dhcp_packet(b"\x35\xff\x01")),
        ("dhcp-hostname-255", dhcp_packet(b"\x35\x01\x01\x0c\xff" + b"A" * 255 + b"\xff")),
        ("dhcp-client-id-255", dhcp_packet(b"\x35\x01\x01\x3d\xff" + b"A" * 255 + b"\xff")),
        ("dhcp-vendor-255", dhcp_packet(b"\x35\x01\x01\x3c\xff" + b"A" * 255 + b"\xff")),
        ("dhcp-overload-invalid", dhcp_packet(b"\x35\x01\x01\x34\x01\xff\xff")),
        ("dhcp-padding-8192", dhcp_packet(b"\x35\x01\x01" + b"\0" * 8192 + b"\xff")),
    ]
    for name, payload in dhcp_cases:
        try:
            response = udp_exchange(payload, 67)
            outcome = f"response_bytes={len(response)}"
        except OSError as error:
            outcome = f"socket_error={type(error).__name__}:{error}"
        time.sleep(0.05)
        alive = healthy()
        print(f"{name} request_bytes={len(payload)} {outcome} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1

    mutation_count = 0
    dns_header = struct.pack("!HHHHHH", 0x4D55, 0x0100, 1, 0, 0, 0)
    for value in range(256):
        mutations = (
            dns_header + bytes([value]) + b"A" * 64 + b"\0\0\1\0\1",
            dns_header + b"\xc0" + bytes([value]) + b"\0\1\0\1",
            dhcp_packet(b"\x35\x01\x01" + bytes([value, 0xFF]) + b"A" * 8),
        )
        for index, payload in enumerate(mutations):
            port = DNS_PORT if index < 2 else 67
            try:
                udp_exchange(payload, port, timeout=0.01)
            except OSError:
                pass
            mutation_count += 1
        if value % 16 == 15 and not healthy():
            print(f"mutation_crash_group={value - 15}-{value}")
            return 1
    print(f"deterministic_mutations={mutation_count} alive={healthy()}")
    if not healthy():
        return 1

    print("result=no-observable-dnsmasq-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
