#!/usr/bin/env python3
"""Bounded malformed SOAP probe for the loopback-only BE17000 web VM."""

from __future__ import annotations

import socket


HOST = "127.0.0.1"
PORT = 26180


def exchange(request: bytes, timeout: float = 3.0) -> bytes:
    with socket.create_connection((HOST, PORT), timeout=timeout) as client:
        client.settimeout(timeout)
        client.sendall(request)
        response = bytearray()
        while len(response) < 256 * 1024:
            try:
                chunk = client.recv(8192)
            except TimeoutError:
                break
            if not chunk:
                break
            response.extend(chunk)
        return bytes(response)


def request(body: bytes, action: bytes, extra: bytes = b"") -> bytes:
    return (
        b"POST /soap/server_sa/ HTTP/1.1\r\n"
        b"Host: routerlogin.net\r\n"
        b"Content-Type: text/xml\r\n"
        b"SOAPAction: "
        + action
        + b"\r\n"
        + extra
        + b"Content-Length: "
        + str(len(body)).encode()
        + b"\r\nConnection: close\r\n\r\n"
        + body
    )


def main() -> int:
    health_request = (
        b"GET /currentsetting.htm HTTP/1.1\r\n"
        b"Host: routerlogin.net\r\nConnection: close\r\n\r\n"
    )
    baseline = exchange(health_request)
    if not baseline.startswith(b"HTTP/1.1 200"):
        raise SystemExit("baseline health route failed")

    action = b'"urn:NETGEAR-ROUTER:service:DeviceInfo:1#GetInfo"'
    bodies = (
        b"",
        b"<",
        b"<a",
        b"<a>",
        b"<a></",
        b"<a x=",
        b"<a x='",
        b"<!--",
        b"<![CDATA[",
        b"<?xml",
        b"\x00\xff\xfe",
        b"<a>" + b"<b>" * 128 + b"</b>" * 128 + b"</a>",
        b"<a x='" + b"A" * 8192 + b"'/>",
        b"A" * 65536,
    )
    actions = (
        b"",
        b'""',
        b'"',
        b"A" * 4096,
        b'"urn:NETGEAR-ROUTER:service:DeviceInfo:1#' + b"A" * 4096 + b'"',
    )
    cases = [(f"body-{index}", request(body, action)) for index, body in enumerate(bodies)]
    cases.extend(
        (f"action-{index}", request(b"<a/>", candidate))
        for index, candidate in enumerate(actions)
    )
    cases.extend(
        (
            (
                "duplicate-length",
                b"POST /soap/server_sa/ HTTP/1.1\r\nHost: routerlogin.net\r\n"
                b"Content-Length: 1\r\nContent-Length: 8192\r\n\r\n<",
            ),
            (
                "negative-length",
                b"POST /soap/server_sa/ HTTP/1.1\r\nHost: routerlogin.net\r\n"
                b"Content-Length: -1\r\n\r\n",
            ),
            (
                "long-header",
                request(b"<a/>", action, b"X-Fuzz: " + b"A" * 16384 + b"\r\n"),
            ),
        )
    )

    for name, probe in cases:
        try:
            response = exchange(probe)
            probe_status = response.splitlines()[0].decode("latin-1", "replace") if response else "no-response"
        except Exception as error:
            probe_status = f"{type(error).__name__}:{error}"
        try:
            health = exchange(health_request).startswith(b"HTTP/1.1 200")
        except Exception:
            health = False
        print(f"{name}: response={probe_status} health={'ok' if health else 'FAILED'}")
        if not health:
            return 1
    print(f"cases_attempted={len(cases)}")
    print("health_failures=0")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
