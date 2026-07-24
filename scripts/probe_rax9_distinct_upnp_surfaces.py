#!/usr/bin/env python3
"""Bounded probes for RAX9 UPnP paths distinct from the known SOAPAction bug."""

from __future__ import annotations

import argparse
import base64
import hashlib
import json
import socket
import time


HTTP_HOST = "127.0.0.1"
HTTP_PORT = 56688
SSDP_PORT = 1900


def http_request(
    method: str,
    path: str,
    headers: list[tuple[str, str]],
    body: bytes = b"",
) -> bytes:
    lines = [f"{method} {path} HTTP/1.1", f"Host: {HTTP_HOST}:{HTTP_PORT}"]
    lines.extend(f"{name}: {value}" for name, value in headers)
    if body:
        lines.append(f"Content-Length: {len(body)}")
    return ("\r\n".join(lines) + "\r\n\r\n").encode() + body


def exchange_http(payload: bytes) -> dict[str, object]:
    result: dict[str, object] = {
        "request_bytes": len(payload),
        "request_sha256": hashlib.sha256(payload).hexdigest(),
    }
    try:
        with socket.create_connection((HTTP_HOST, HTTP_PORT), timeout=1.5) as client:
            client.settimeout(1.5)
            client.sendall(payload)
            response = bytearray()
            while len(response) < 8192:
                try:
                    chunk = client.recv(4096)
                except TimeoutError:
                    break
                if not chunk:
                    break
                response.extend(chunk)
        result["response_bytes"] = len(response)
        result["status"] = response.split(b"\r\n", 1)[0].decode("ascii", "replace")
    except OSError as error:
        result["error"] = f"{type(error).__name__}: {error}"
    return result


def alive() -> bool:
    try:
        with socket.create_connection((HTTP_HOST, HTTP_PORT), timeout=0.5):
            return True
    except OSError:
        return False


def soap(action: str, inner: bytes) -> bytes:
    body = (
        b'<?xml version="1.0"?>'
        b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        b"<s:Body>"
        + inner
        + b"</s:Body></s:Envelope>"
    )
    return http_request(
        "POST",
        "/control",
        [("SOAPAction", f'"urn:schemas-wifialliance-org:service:WFAWLANConfig:1#{action}"')],
        body,
    )


def event_cases() -> list[tuple[str, bytes]]:
    marker = "FRIDAY_RAX9_EVENT_"
    return [
        (
            "valid_callback",
            http_request(
                "SUBSCRIBE",
                "/event",
                [
                    ("CALLBACK", "<http://127.0.0.1:9/callback>"),
                    ("NT", "upnp:event"),
                    ("TIMEOUT", "Second-30"),
                ],
            ),
        ),
        (
            "missing_brackets",
            http_request(
                "SUBSCRIBE",
                "/event",
                [("CALLBACK", "http://127.0.0.1:9/callback"), ("NT", "upnp:event")],
            ),
        ),
        (
            "multiple_callbacks",
            http_request(
                "SUBSCRIBE",
                "/event",
                [
                    ("CALLBACK", "<http://127.0.0.1:9/a><http://127.0.0.1:9/b>"),
                    ("NT", "upnp:event"),
                ],
            ),
        ),
        (
            "callback_4096",
            http_request(
                "SUBSCRIBE",
                "/event",
                [("CALLBACK", f"<http://127.0.0.1:9/{marker}{'A' * 4096}>"), ("NT", "upnp:event")],
            ),
        ),
        (
            "timeout_4096",
            http_request(
                "SUBSCRIBE",
                "/event",
                [
                    ("CALLBACK", "<http://127.0.0.1:9/callback>"),
                    ("NT", "upnp:event"),
                    ("TIMEOUT", "Second-" + "9" * 4096),
                ],
            ),
        ),
        (
            "sid_4096",
            http_request(
                "UNSUBSCRIBE",
                "/event",
                [("SID", "uuid:" + marker + "B" * 4096)],
            ),
        ),
    ]


def xml_cases() -> list[tuple[str, bytes]]:
    action = "SetSelectedRegistrar"
    return [
        ("empty_body", soap(action, b"")),
        ("truncated_xml", soap(action, b"<u:SetSelectedRegistrar")),
        (
            "wrong_namespace",
            soap(action, b"<u:SetSelectedRegistrar xmlns:u=\"x\"><NewMessage>AQ==</NewMessage></u:SetSelectedRegistrar>"),
        ),
        (
            "nested_256",
            soap(action, b"<u:SetSelectedRegistrar>" + b"<x>" * 256 + b"A" + b"</x>" * 256 + b"</u:SetSelectedRegistrar>"),
        ),
        (
            "attribute_4096",
            soap(action, b'<u:SetSelectedRegistrar x="' + b"A" * 4096 + b'"><NewMessage>AQ==</NewMessage></u:SetSelectedRegistrar>'),
        ),
        (
            "text_16384",
            soap(action, b"<u:SetSelectedRegistrar><NewMessage>" + b"A" * 16384 + b"</NewMessage></u:SetSelectedRegistrar>"),
        ),
    ]


def wps_cases() -> list[tuple[str, bytes]]:
    result = []
    for size in (0, 1, 255, 256, 1024, 4096, 16384):
        encoded = base64.b64encode(bytes((index % 251 for index in range(size))))
        inner = (
            b'<u:PutMessage xmlns:u="urn:schemas-wifialliance-org:service:WFAWLANConfig:1">'
            b"<NewInMessage>"
            + encoded
            + b"</NewInMessage></u:PutMessage>"
        )
        result.append((f"putmessage_decoded_{size}", soap("PutMessage", inner)))
    return result


def ssdp_cases() -> list[tuple[str, bytes]]:
    base = (
        b"M-SEARCH * HTTP/1.1\r\n"
        b"HOST: 239.255.255.250:1900\r\n"
        b'MAN: "ssdp:discover"\r\n'
        b"MX: 1\r\n"
    )
    return [
        ("empty", b""),
        ("truncated", b"M-SEARCH"),
        ("valid_all", base + b"ST: ssdp:all\r\n\r\n"),
        ("st_4096", base + b"ST: " + b"A" * 4096 + b"\r\n\r\n"),
        ("man_4096", base.replace(b'MAN: "ssdp:discover"', b"MAN: " + b"B" * 4096) + b"ST: ssdp:all\r\n\r\n"),
        ("mx_4096", base.replace(b"MX: 1", b"MX: " + b"9" * 4096) + b"ST: ssdp:all\r\n\r\n"),
        ("datagram_16384", base + b"ST: ssdp:all\r\nX-Pad: " + b"C" * 16384 + b"\r\n\r\n"),
        ("datagram_65507", b"M-SEARCH " + b"D" * (65507 - len(b"M-SEARCH "))),
    ]


def run_http(cases: list[tuple[str, bytes]]) -> int:
    for name, payload in cases:
        before = alive()
        outcome = exchange_http(payload)
        time.sleep(0.15)
        after = alive()
        print(json.dumps({"case": name, "alive_before": before, "alive_after": after, **outcome}, sort_keys=True))
        if before and not after:
            return 1
    return 0


def run_ssdp(cases: list[tuple[str, bytes]]) -> int:
    for name, payload in cases:
        outcome: dict[str, object] = {
            "case": name,
            "request_bytes": len(payload),
            "request_sha256": hashlib.sha256(payload).hexdigest(),
        }
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
                client.settimeout(0.25)
                client.sendto(payload, (HTTP_HOST, SSDP_PORT))
                try:
                    response, _ = client.recvfrom(4096)
                except TimeoutError:
                    response = b""
            outcome["response_bytes"] = len(response)
        except OSError as error:
            outcome["error"] = f"{type(error).__name__}: {error}"
        time.sleep(0.15)
        outcome["http_alive"] = alive()
        print(json.dumps(outcome, sort_keys=True))
        if not outcome["http_alive"]:
            return 1
    return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--suite", required=True, choices=("event", "xml", "ssdp", "wps"))
    parser.add_argument("--case", help="run only the named case from the selected suite")
    args = parser.parse_args()
    if args.suite == "event":
        cases = event_cases()
    elif args.suite == "xml":
        cases = xml_cases()
    elif args.suite == "wps":
        cases = wps_cases()
    else:
        cases = ssdp_cases()
        if args.case:
            cases = [(name, payload) for name, payload in cases if name == args.case]
            if not cases:
                parser.error(f"unknown ssdp case: {args.case}")
        return run_ssdp(cases)
    if args.case:
        cases = [(name, payload) for name, payload in cases if name == args.case]
        if not cases:
            parser.error(f"unknown {args.suite} case: {args.case}")
    return run_http(cases)


if __name__ == "__main__":
    raise SystemExit(main())
