#!/usr/bin/env python3
"""Bounded RAX54S GENA callback parser validation for an isolated lab."""

from __future__ import annotations

import argparse
import socket
import time


def exchange(host: str, port: int, payload: bytes, timeout: float = 3.0) -> bytes:
    response = bytearray()
    with socket.create_connection((host, port), timeout=timeout) as client:
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        while chunk := client.recv(65536):
            response.extend(chunk)
    return bytes(response)


def request(method: str, path: str, headers: list[tuple[str, str]]) -> bytes:
    fields = [
        ("Host", "192.168.1.1:56688"),
        ("Connection", "close"),
        *headers,
        ("Content-Length", "0"),
    ]
    return (
        f"{method} {path} HTTP/1.1\r\n".encode()
        + b"".join(f"{name}: {value}\r\n".encode() for name, value in fields)
        + b"\r\n"
    )


def status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "no response"


def alive(host: str, port: int) -> bool:
    try:
        return status(exchange(host, port, request("GET", "/", []))).startswith("HTTP/")
    except OSError:
        return False


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="192.168.1.1")
    parser.add_argument("--port", type=int, default=56688)
    parser.add_argument("--event-path", default="/Public_UPNP_Event_1")
    args = parser.parse_args()

    cases = [
        ("explicit-port-control", "http://192.168.1.2:9/event"),
        ("no-port-candidate", "http://192.168.1.2/event"),
    ]
    for size in (64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384):
        cases.append((f"callback-path-{size}", "http://192.168.1.2:9/" + ("A" * size)))
    print(f"baseline_before={'pass' if alive(args.host, args.port) else 'fail'}")
    for name, callback in cases:
        payload = request(
            "SUBSCRIBE",
            args.event_path,
            [("CALLBACK", f"<{callback}>"), ("NT", "upnp:event")],
        )
        try:
            result = status(exchange(args.host, args.port, payload))
        except OSError as error:
            result = f"{type(error).__name__}: {error}"
        time.sleep(1)
        healthy = alive(args.host, args.port)
        print(f"{name}: response={result!r} service_alive={str(healthy).lower()}")
        if not healthy:
            return 2
    print("baseline_after=pass")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
