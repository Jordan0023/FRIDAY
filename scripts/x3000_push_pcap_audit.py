#!/usr/bin/env python3
"""Offline decoder for X3000 push traffic captured from an owned router."""

import argparse
import ipaddress
import json
import struct
from pathlib import Path

from x3000_push_lab_server import xxtea_decrypt


def read_pcap(path):
    raw = Path(path).read_bytes()
    if len(raw) < 24:
        raise ValueError("short PCAP")
    magic = raw[:4]
    if magic == b"\xd4\xc3\xb2\xa1":
        endian = "<"
    elif magic == b"\xa1\xb2\xc3\xd4":
        endian = ">"
    else:
        raise ValueError("only classic PCAP is supported (not pcapng)")
    if struct.unpack(endian + "I", raw[20:24])[0] != 1:
        raise ValueError("expected Ethernet linktype 1")
    offset = 24
    while offset + 16 <= len(raw):
        _, _, captured, _ = struct.unpack(endian + "IIII", raw[offset : offset + 16])
        offset += 16
        yield raw[offset : offset + captured]
        offset += captured


def tcp_payload(packet):
    if len(packet) < 14 or struct.unpack(">H", packet[12:14])[0] != 0x0800:
        return None
    ip = packet[14:]
    if len(ip) < 20 or ip[9] != 6:
        return None
    ihl = (ip[0] & 0x0F) * 4
    tcp = ip[ihl : struct.unpack(">H", ip[2:4])[0]]
    if len(tcp) < 20:
        return None
    src_port, dst_port, seq = struct.unpack(">HHI", tcp[:8])
    payload = tcp[(tcp[12] >> 4) * 4 :]
    if not payload or (src_port != 1887 and dst_port != 1887):
        return None
    src = str(ipaddress.ip_address(ip[12:16]))
    dst = str(ipaddress.ip_address(ip[16:20]))
    return (src, src_port, dst, dst_port), seq, payload


def reassemble(path):
    segments = {}
    for packet in read_pcap(path):
        parsed = tcp_payload(packet)
        if parsed:
            flow, seq, payload = parsed
            segments.setdefault(flow, {}).setdefault(seq, payload)
    for flow, by_seq in segments.items():
        yield flow, b"".join(by_seq[seq] for seq in sorted(by_seq))


def decode_stream(data):
    offset = 0
    while offset < len(data):
        kind = data[offset]
        offset += 1
        if kind != 5:
            yield {"kind": kind, "control": True}
            continue
        if offset + 4 > len(data):
            yield {"error": "truncated data-frame length"}
            return
        size = struct.unpack(">I", data[offset : offset + 4])[0]
        offset += 4
        if size > 1024 * 1024 or offset + size > len(data):
            yield {"error": "invalid or truncated data frame", "declared_size": size}
            return
        encrypted = data[offset : offset + size]
        offset += size
        try:
            message = json.loads(xxtea_decrypt(encrypted))
            for field in ("sign", "imei", "eid"):
                if field in message:
                    message[field] = "<redacted>"
            yield {"kind": kind, "message": message}
        except Exception as exc:
            yield {"kind": kind, "decrypt_error": str(exc), "encrypted_length": size}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("pcap", help="classic Ethernet PCAP from an owned router")
    args = parser.parse_args()
    found = False
    for flow, data in reassemble(args.pcap):
        found = True
        print(json.dumps({"flow": f"{flow[0]}:{flow[1]} -> {flow[2]}:{flow[3]}"}))
        for frame in decode_stream(data):
            print(json.dumps(frame, sort_keys=True))
    if not found:
        raise SystemExit("no TCP/1887 payloads found")


if __name__ == "__main__":
    main()
