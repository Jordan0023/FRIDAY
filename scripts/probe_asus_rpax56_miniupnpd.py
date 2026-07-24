#!/usr/bin/env python3
"""Bounded, loopback-only RP-AX56 MiniUPnPd HTTP/SOAP/GENA probes."""

from __future__ import annotations

import argparse
import json
import socket
import time


HOST = "192.168.50.1"
SOURCE = "192.168.50.2"
PORT = 5000
CONTROL = "/ctl/IPConn"


def request(method: str, path: str, headers: list[tuple[str, str]], body: bytes = b"") -> bytes:
    lines = [f"{method} {path} HTTP/1.1", f"Host: {HOST}:{PORT}"]
    lines.extend(f"{name}: {value}" for name, value in headers)
    if body and not any(name.lower() == "content-length" for name, _ in headers):
        lines.append(f"Content-Length: {len(body)}")
    return ("\r\n".join(lines) + "\r\n\r\n").encode() + body


def exchange(payload: bytes, fragmented: bool = False) -> tuple[bytes, str | None]:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
            sock.settimeout(0.5)
            sock.bind((SOURCE, 0))
            sock.connect((HOST, PORT))
            sock.settimeout(0.5)
            if fragmented:
                split = min(5, len(payload))
                sock.sendall(payload[:split])
                time.sleep(0.03)
                sock.sendall(payload[split:])
            else:
                sock.sendall(payload)
            response = bytearray()
            while len(response) < 4096:
                try:
                    chunk = sock.recv(min(1024, 4096 - len(response)))
                except socket.timeout:
                    break
                if not chunk:
                    break
                response.extend(chunk)
            return bytes(response), None
    except OSError as exc:
        return b"", f"{type(exc).__name__}: {exc}"


def exchange_ssdp(payload: bytes) -> tuple[bytes, str | None]:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
            sock.settimeout(0.3)
            sock.bind((SOURCE, 0))
            sock.sendto(payload, (HOST, 1900))
            try:
                response, _ = sock.recvfrom(4096)
            except socket.timeout:
                response = b""
            return response, None
    except OSError as exc:
        return b"", f"{type(exc).__name__}: {exc}"


def cases_for(name: str) -> list[tuple[str, bytes, bool]]:
    if name == "baseline":
        return [("root-description", request("GET", "/rootDesc.xml", [], b""), False)]
    if name == "http":
        raw = [
            ("empty", b""),
            ("one-byte", b"G"),
            ("short-request-line", b"GET /\r\n\r\n"),
            ("unknown-method", request("FRIDAY", "/", [], b"")),
            ("long-path-2048", request("GET", "/" + "A" * 2048, [], b"")),
            ("long-header-4096", request("GET", "/", [("X-Friday", "A" * 4096)], b"")),
            ("negative-content-length", request("POST", CONTROL, [("Content-Length", "-1")], b"")),
            ("huge-content-length", request("POST", CONTROL, [("Content-Length", "4294967295")], b"")),
            ("duplicate-content-length", request("POST", CONTROL, [("Content-Length", "0"), ("Content-Length", "8")], b"")),
            ("embedded-nul", b"GET /rootDesc.xml HTTP/1.1\r\nHost: x\x00y\r\n\r\n"),
        ]
        return [(case, payload, case == "long-header-4096") for case, payload in raw]
    if name == "soap":
        actions = (
            "",
            "\"\"",
            "x",
            "\"urn:schemas-upnp-org:service:WANIPConnection:1#GetExternalIPAddress\"",
            "\"" + "A" * 2048 + "\"",
            "\"urn:x#Friday\r\nX-Friday: inert\"",
        )
        body = b'<?xml version="1.0"?><s:Envelope><s:Body/></s:Envelope>'
        return [
            (
                f"soapaction-{index}",
                request("POST", CONTROL, [("SOAPAction", action)], body),
                bool(index & 1),
            )
            for index, action in enumerate(actions)
        ]
    if name == "ssdp":
        valid = (
            b"M-SEARCH * HTTP/1.1\r\n"
            b"HOST: 239.255.255.250:1900\r\n"
            b'MAN: "ssdp:discover"\r\nMX: 1\r\n'
            b"ST: urn:schemas-upnp-org:device:InternetGatewayDevice:1\r\n\r\n"
        )
        raw = (
            ("valid-search", valid),
            ("empty", b""),
            ("one-byte", b"M"),
            ("short-line", b"M-SEARCH *\r\n\r\n"),
            ("long-header-2048", valid[:-4] + b"X-Friday: " + b"A" * 2048 + b"\r\n\r\n"),
            ("duplicate-mx", valid[:-4] + b"MX: 0\r\nMX: 999999999\r\n\r\n"),
            ("embedded-nul", valid[:-4] + b"X-Friday: x\x00y\r\n\r\n"),
        )
        return [(case, payload, False) for case, payload in raw]
    callbacks = (
        "",
        "<>",
        "<http://127.0.0.1:9/>",
        "<http://[::1]:9/>",
        "<http://" + "A" * 1024 + "/>",
        "<http://127.0.0.1:9/>\r\nX-Friday: inert",
    )
    return [
        (
            f"callback-{index}",
            request(
                "SUBSCRIBE",
                "/evt/IPConn",
                [("Callback", callback), ("NT", "upnp:event"), ("Timeout", "Second-30")],
            ),
            bool(index & 1),
        )
        for index, callback in enumerate(callbacks)
    ]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--case", choices=("baseline", "http", "soap", "gena", "ssdp"), required=True
    )
    args = parser.parse_args()

    results = []
    for name, payload, fragmented in cases_for(args.case):
        started = time.monotonic()
        if args.case == "ssdp":
            response, error = exchange_ssdp(payload)
        else:
            response, error = exchange(payload, fragmented)
        status_line = response.split(b"\r\n", 1)[0].decode("latin-1", "replace") if response else ""
        results.append(
            {
                "name": name,
                "request_bytes": len(payload),
                "fragmented": fragmented,
                "response_bytes": len(response),
                "status_line": status_line,
                "error": error,
                "elapsed_ms": round((time.monotonic() - started) * 1000, 2),
            }
        )
        time.sleep(0.04)

    print(json.dumps({"target": f"{HOST}:{PORT}", "case": args.case, "results": results}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
