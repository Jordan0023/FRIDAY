#!/usr/bin/env python3
"""Bounded malformed-request corpus for the isolated BE17000 daemon."""

from __future__ import annotations

import socket
import time


HOST = "192.168.1.1"
PORT = 56688
ACTION = b'"urn:schemas-upnp-org:service:Layer3Forwarding:1#SetDefaultConnectionService"'


def exchange(request: bytes, timeout: float = 1.5) -> bytes:
    with socket.create_connection((HOST, PORT), timeout=timeout) as client:
        client.sendall(request)
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


def request(body: bytes, action: bytes = ACTION, content_length: bytes | None = None) -> bytes:
    length = str(len(body)).encode() if content_length is None else content_length
    return (
        b"POST /ctl/L3F HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"SOAPAction: " + action + b"\r\n"
        b"Content-Type: text/xml\r\n"
        b"Content-Length: " + length + b"\r\n"
        b"Connection: close\r\n\r\n" + body
    )


def healthy() -> bool:
    try:
        response = exchange(
            b"GET /rootDesc.xml HTTP/1.1\r\n"
            b"Host: 192.168.1.1:56688\r\nConnection: close\r\n\r\n"
        )
        return response.startswith(b"HTTP/1.1 200")
    except OSError:
        return False


def corpus() -> list[tuple[str, bytes]]:
    xml = [
        b"<",
        b"<e",
        b"<element",
        b"<element ",
        b"<element a",
        b"<element attribute",
        b"<element attribute=",
        b"<element attribute= ",
        b"<element attribute='",
        b'<element attribute="',
        b"<element attribute=x",
        b"<element attribute=x>",
        b"<element attribute='x",
        b'<element attribute="x',
        b"<!--",
        b"<![CDATA[",
        b"<?xml",
        b"<s:Envelope><s:Body><x a=",
    ]
    cases = [(f"xml-{index:02d}", request(value)) for index, value in enumerate(xml)]
    actions = [
        b"",
        b" ",
        b'"',
        b"'",
        b'""',
        b"''",
        b"A" * 1024,
        b"A" * 8192,
        b'"' + b"A" * 8192 + b'"',
    ]
    cases.extend(
        (f"soapaction-{index:02d}", request(b"<x/>", action=value))
        for index, value in enumerate(actions)
    )
    lengths = [b"-1", b"+1", b"x", b"0x10", b"2147483647", b"4294967295"]
    cases.extend(
        (f"content-length-{index:02d}", request(b"<x/>", content_length=value))
        for index, value in enumerate(lengths)
    )
    cases.extend([
        ("header-16k", request(b"<x/>", action=b"A" * 16384)),
        ("body-64k", request(b"<x>" + b"A" * 65536 + b"</x>")),
    ])
    return cases


def main() -> int:
    if not healthy():
        print("baseline_failed")
        return 2
    cases = corpus()
    print(f"cases={len(cases)}")
    for index, (name, payload) in enumerate(cases, 1):
        try:
            response = exchange(payload)
            status = response.splitlines()[0].decode("iso-8859-1", "replace") if response else "no-response"
        except OSError as error:
            status = f"socket-error:{error}"
        time.sleep(0.03)
        alive = healthy()
        print(f"{index:02d} {name} bytes={len(payload)} status={status} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
