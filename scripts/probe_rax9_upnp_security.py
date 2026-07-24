#!/usr/bin/env python3
"""Bounded parser probes for the isolated genuine RAX9 MiniUPnPd lab."""

from __future__ import annotations

import json
import socket
import time


HOST = "127.0.0.1"
PORT = 56688


def exchange(request: bytes, timeout: float = 2.0) -> dict[str, object]:
    result: dict[str, object] = {"sent": len(request)}
    try:
        with socket.create_connection((HOST, PORT), timeout=timeout) as sock:
            sock.settimeout(timeout)
            sock.sendall(request)
            chunks = []
            while sum(map(len, chunks)) < 8192:
                try:
                    chunk = sock.recv(4096)
                except socket.timeout:
                    break
                if not chunk:
                    break
                chunks.append(chunk)
        response = b"".join(chunks)
        result["response_bytes"] = len(response)
        result["status"] = response.split(b"\r\n", 1)[0].decode("latin-1", "replace")
    except OSError as error:
        result["error"] = f"{type(error).__name__}: {error}"
    return result


def alive() -> bool:
    try:
        with socket.create_connection((HOST, PORT), timeout=1.0):
            return True
    except OSError:
        return False


def request(method: str, path: str, headers: list[tuple[str, str]], body: bytes = b"") -> bytes:
    lines = [f"{method} {path} HTTP/1.1", f"Host: {HOST}:{PORT}"]
    lines.extend(f"{name}: {value}" for name, value in headers)
    if body:
        lines.append(f"Content-Length: {len(body)}")
    return ("\r\n".join(lines) + "\r\n\r\n").encode() + body


def main() -> None:
    marker = "FRIDAY_RAX9_BOUNDED"
    cases = {
        "control_get": request("GET", "/rootDesc.xml", []),
        "rax30_event_shape": request(
            "SUBSCRIBE",
            "/event",
            [
                ("CALLBACK", f"<http://127.0.0.1/{marker}{'A' * 64}>"),
                ("NT", "upnp:event"),
                ("TIMEOUT", "Second-1800"),
            ],
        ),
        "callback_1024": request(
            "SUBSCRIBE",
            "/event",
            [
                ("CALLBACK", f"<http://127.0.0.1/{marker}{'B' * 1024}>"),
                ("NT", "upnp:event"),
            ],
        ),
        "header_4096": request("GET", "/rootDesc.xml", [("X-RAX9-Probe", marker + "C" * 4096)]),
        "uri_4096": request("GET", "/" + marker + "D" * 4096, []),
        "negative_content_length": (
            f"POST /control HTTP/1.1\r\nHost: {HOST}:{PORT}\r\n"
            "Content-Length: -1\r\nSOAPAction: \"urn:schemas-upnp-org:"
            "service:WANIPConnection:1#GetExternalIPAddress\"\r\n\r\n"
        ).encode(),
        "oversized_soapaction": request(
            "POST",
            "/control",
            [("SOAPAction", '"' + marker + "E" * 4096 + '"')],
            b"<s:Envelope/>",
        ),
    }

    output = {}
    for name, payload in cases.items():
        before = alive()
        outcome = exchange(payload)
        time.sleep(0.15)
        after = alive()
        output[name] = {"alive_before": before, "alive_after": after, **outcome}
        if before and not after:
            break

    print(json.dumps(output, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
