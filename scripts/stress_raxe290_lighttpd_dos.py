#!/usr/bin/env python3
"""Bounded malformed-request DoS checks for the loopback-only RAXE290 web lab."""

from __future__ import annotations

import json
import socket
import time
from pathlib import Path


HOST, PORT = "127.0.0.1", 25291
CONTROL = b"GET /currentsetting.htm HTTP/1.0\r\nHost: routerlogin.net\r\n\r\n"


def exchange(payload: bytes, timeout: float = 3) -> bytes:
    data = bytearray()
    with socket.create_connection((HOST, PORT), timeout=timeout) as client:
        client.settimeout(timeout)
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        try:
            while len(data) < 8192:
                chunk = client.recv(4096)
                if not chunk:
                    break
                data.extend(chunk)
        except (TimeoutError, ConnectionResetError):
            pass
    return bytes(data)


def alive() -> bool:
    try:
        return exchange(CONTROL).startswith(b"HTTP/")
    except OSError:
        return False


CASES = {
    "http2_preface": b"PRI * HTTP/2.0\r\n\r\nSM\r\n\r\n",
    "negative_content_length": (
        b"POST /currentsetting.htm HTTP/1.1\r\nHost: x\r\nContent-Length: -1\r\n\r\n"
    ),
    "conflicting_content_length": (
        b"POST /currentsetting.htm HTTP/1.1\r\nHost: x\r\n"
        b"Content-Length: 0\r\nContent-Length: 64\r\n\r\n" + b"A" * 64
    ),
    "chunk_size_overflow": (
        b"POST /currentsetting.htm HTTP/1.1\r\nHost: x\r\n"
        b"Transfer-Encoding: chunked\r\n\r\nFFFFFFFFFFFFFFFF\r\nA\r\n0\r\n\r\n"
    ),
    "chunk_extension_4k": (
        b"POST /currentsetting.htm HTTP/1.1\r\nHost: x\r\n"
        b"Transfer-Encoding: chunked\r\n\r\n1;" + b"A" * 4096 + b"\r\nX\r\n0\r\n\r\n"
    ),
    "header_value_64k": (
        b"GET /currentsetting.htm HTTP/1.1\r\nHost: x\r\nX-Friday: "
        + b"A" * 65536 + b"\r\n\r\n"
    ),
    "many_headers": (
        b"GET /currentsetting.htm HTTP/1.1\r\nHost: x\r\n"
        + b"".join(f"X-F-{index}: A\r\n".encode() for index in range(512))
        + b"\r\n"
    ),
    "nul_in_target": b"GET /current\\x00setting.htm HTTP/1.1\r\nHost: x\r\n\r\n",
    "absolute_uri_8k": (
        b"GET http://routerlogin.net/" + b"A" * 8192 + b" HTTP/1.1\r\nHost: x\r\n\r\n"
    ),
}


def main() -> int:
    results = []
    baseline = alive()
    for name, payload in CASES.items():
        try:
            response = exchange(payload)
            status = response.splitlines()[0].decode(errors="replace") if response else "no response"
        except OSError as error:
            status = f"{type(error).__name__}: {error}"
        time.sleep(0.25)
        healthy = alive()
        results.append({"case": name, "status": status, "service_alive": healthy})
        if not healthy:
            break
    document = {"baseline": baseline, "results": results, "final_alive": alive()}
    output = (
        Path(__file__).resolve().parents[1]
        / "known_firmware/emulation/RAXE290/soap-full-system-lab/lighttpd-dos-matrix.json"
    )
    output.write_text(json.dumps(document, indent=2) + "\n")
    print(json.dumps(document, indent=2))
    print(f"output={output}")
    return 0 if baseline and document["final_alive"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
