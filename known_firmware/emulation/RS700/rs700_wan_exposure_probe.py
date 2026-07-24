#!/usr/bin/env python3
"""Probe RS700 UPnP reachability from an isolated emulated WAN client."""

from __future__ import annotations

import argparse
import ipaddress
import json
import socket
import time


HTTP_REQUEST = (
    b"GET /Public_UPNP_gatedesc.xml HTTP/1.1\r\n"
    b"Host: rs700\r\nConnection: close\r\n\r\n"
)
MSEARCH = (
    b"M-SEARCH * HTTP/1.1\r\n"
    b"HOST: 239.255.255.250:1900\r\n"
    b'MAN: "ssdp:discover"\r\n'
    b"MX: 1\r\n"
    b"ST: upnp:rootdevice\r\n\r\n"
)


def tcp_probe(source: str, target: str, port: int, timeout: float) -> dict[str, object]:
    result: dict[str, object] = {"source": source, "target": target, "port": port}
    started = time.monotonic()
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        sock.settimeout(timeout)
        sock.bind((source, 0))
        sock.connect((target, port))
        sock.sendall(HTTP_REQUEST)
        response = sock.recv(512)
        result["connected"] = True
        result["status_line"] = response.splitlines()[0].decode("latin-1", "replace")
    except OSError as error:
        result["connected"] = False
        result["error"] = f"{type(error).__name__}: {error}"
    finally:
        sock.close()
    result["elapsed_ms"] = round((time.monotonic() - started) * 1000)
    return result


def udp_probe(source: str, target: str, timeout: float) -> dict[str, object]:
    result: dict[str, object] = {"source": source, "target": target, "port": 1900}
    started = time.monotonic()
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        sock.settimeout(timeout)
        sock.bind((source, 0))
        if ipaddress.ip_address(target).is_multicast:
            sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_IF, socket.inet_aton(source))
            sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 1)
        sock.sendto(MSEARCH, (target, 1900))
        response, peer = sock.recvfrom(2048)
        result["response"] = True
        result["peer"] = f"{peer[0]}:{peer[1]}"
        result["status_line"] = response.splitlines()[0].decode("latin-1", "replace")
    except OSError as error:
        result["response"] = False
        result["error"] = f"{type(error).__name__}: {error}"
    finally:
        sock.close()
    result["elapsed_ms"] = round((time.monotonic() - started) * 1000)
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", default="198.51.100.2")
    parser.add_argument("--wan-address", default="198.51.100.1")
    parser.add_argument("--lan-address", default="192.168.1.1")
    parser.add_argument("--timeout", type=float, default=2.0)
    args = parser.parse_args()

    results = {
        "tcp_wan_address": tcp_probe(args.source, args.wan_address, 56688, args.timeout),
        "tcp_lan_address_via_wan": tcp_probe(args.source, args.lan_address, 56688, args.timeout),
        "ssdp_wan_unicast": udp_probe(args.source, args.wan_address, args.timeout),
        "ssdp_wan_multicast": udp_probe(args.source, "239.255.255.250", args.timeout),
    }
    print(json.dumps(results, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
