#!/usr/bin/env python3
"""Bounded health-checked malformed-request probe for the local AFC VM."""

from __future__ import annotations

import socket
import ssl
import time


HOST = "127.0.0.1"
PORT = 26103


def exchange(request: bytes, timeout: float = 2.0) -> bytes:
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
    context.check_hostname = False
    context.verify_mode = ssl.CERT_NONE
    with socket.create_connection((HOST, PORT), timeout=timeout) as raw:
        with context.wrap_socket(raw, server_hostname="router.local") as client:
            client.settimeout(timeout)
            client.sendall(request)
            response = bytearray()
            while len(response) < 128 * 1024:
                try:
                    chunk = client.recv(4096)
                except (TimeoutError, socket.timeout, ssl.SSLError):
                    break
                if not chunk:
                    break
                response.extend(chunk)
            return bytes(response)


def request(
    path: bytes,
    body: bytes = b"",
    method: bytes = b"POST",
    headers: tuple[bytes, ...] = (),
) -> bytes:
    return (
        method
        + b" "
        + path
        + b" HTTP/1.1\r\nHost: router.local\r\nConnection: close\r\n"
        + b"Content-Type: application/json\r\n"
        + b"".join(header + b"\r\n" for header in headers)
        + b"Content-Length: "
        + str(len(body)).encode()
        + b"\r\n\r\n"
        + body
    )


def status(response: bytes) -> str:
    return response.splitlines()[0].decode("latin-1", "replace") if response else "no-response"


def main() -> int:
    health = request(b"/info", method=b"GET")
    baseline = exchange(health)
    if not baseline.startswith(b"HTTP/"):
        raise SystemExit(f"baseline failed: {status(baseline)}")

    json_inputs = (
        b"",
        b"{",
        b"[]",
        b"null",
        b'{"password":',
        b'{"password":"\\ud800"}',
        b'{"password":"A","deviceId":"B"}garbage',
        b'{"password":"' + b"A" * 4096 + b'"}',
        b'{"x":' + b"[" * 128 + b"0" + b"]" * 128 + b"}",
        b"\x00\xff\xfe",
    )
    cases: list[tuple[str, bytes]] = []
    for route in (b"/pair", b"/challenge", b"/unpair", b"/pairings", b"/location"):
        for index, body in enumerate(json_inputs):
            cases.append((f"{route.decode()}-json-{index}", request(route, body)))
    cases.extend(
        (
            ("unknown-method", request(b"/info", method=b"A" * 128)),
            ("long-path", request(b"/" + b"A" * 8192, method=b"GET")),
            ("long-header", request(b"/info", method=b"GET", headers=(b"X-Fuzz: " + b"A" * 16384,))),
            (
                "duplicate-length",
                b"POST /pair HTTP/1.1\r\nHost: router.local\r\n"
                b"Content-Length: 1\r\nContent-Length: 8192\r\n\r\n{",
            ),
            (
                "negative-length",
                b"POST /pair HTTP/1.1\r\nHost: router.local\r\n"
                b"Content-Length: -1\r\n\r\n",
            ),
            (
                "chunked-truncated",
                b"POST /pair HTTP/1.1\r\nHost: router.local\r\n"
                b"Transfer-Encoding: chunked\r\n\r\n10\r\n{",
            ),
            (
                "oversize-body",
                request(b"/pair", b"A" * 8193),
            ),
        )
    )

    failures = 0
    for name, probe in cases:
        try:
            probe_response = exchange(probe)
            probe_status = status(probe_response)
        except Exception as error:
            probe_status = f"{type(error).__name__}:{error}"
        time.sleep(0.03)
        try:
            health_response = exchange(health)
            healthy = health_response.startswith(b"HTTP/")
        except Exception:
            healthy = False
        print(f"{name}: response={probe_status} health={'ok' if healthy else 'FAILED'}")
        if not healthy:
            failures += 1
            break

    print(f"cases_attempted={len(cases) if failures == 0 else 'stopped-on-failure'}")
    print(f"health_failures={failures}")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
