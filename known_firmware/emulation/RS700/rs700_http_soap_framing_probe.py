#!/usr/bin/env python3
"""Bounded raw HTTP/SOAP parser probes for the isolated RS700 upnpd lab."""

from __future__ import annotations

import argparse
import ipaddress
import json
import socket
import time
from dataclasses import dataclass


PATH = "/Public_UPNP_C3"
DESCRIPTION = "/Public_UPNP_gatedesc.xml"
ACTION = "urn:schemas-upnp-org:service:WANIPConnection:1#GetExternalIPAddress"


@dataclass(frozen=True)
class Case:
    name: str
    payload: bytes
    shutdown_write: bool = False


def envelope(inner: bytes | None = None) -> bytes:
    if inner is None:
        inner = (
            b'<u:GetExternalIPAddress xmlns:u="urn:schemas-upnp-org:'
            b'service:WANIPConnection:1"/>'
        )
    return (
        b'<?xml version="1.0"?>'
        b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        b"<s:Body>" + inner + b"</s:Body></s:Envelope>"
    )


def post(
    body: bytes,
    headers: list[tuple[bytes, bytes]] | None = None,
    *,
    ending: bytes = b"\r\n",
    path: bytes = PATH.encode(),
) -> bytes:
    fields = [
        (b"Host", b"192.168.1.1:56688"),
        (b"Content-Type", b'text/xml; charset="utf-8"'),
        (b"SOAPAction", b'"' + ACTION.encode() + b'"'),
    ]
    if headers:
        fields.extend(headers)
    if not any(name.lower() == b"content-length" for name, _ in fields):
        fields.append((b"Content-Length", str(len(body)).encode()))
    lines = [b"POST " + path + b" HTTP/1.1"]
    lines.extend(name + b": " + value for name, value in fields)
    return ending.join(lines) + ending + ending + body


def cases() -> list[Case]:
    body = envelope()
    raw = [
        Case("control", post(body)),
        Case("lf_only", post(body, ending=b"\n")),
        Case(
            "mixed_line_endings",
            b"POST " + PATH.encode() + b" HTTP/1.1\r\n"
            b"Host: 192.168.1.1:56688\nContent-Type: text/xml\r\n"
            b'SOAPAction: "' + ACTION.encode() + b'"\r\n'
            b"Content-Length: " + str(len(body)).encode() + b"\n\r\n" + body,
        ),
        Case("missing_header_terminator", post(body).split(b"\r\n\r\n")[0], True),
        Case("truncated_body", post(body, [(b"Content-Length", str(len(body) + 32).encode())]), True),
        Case("negative_content_length", post(body, [(b"Content-Length", b"-1")])),
        Case("signed_content_length", post(body, [(b"Content-Length", b"+1")]) + body[:1]),
        Case("nonnumeric_content_length", post(body, [(b"Content-Length", b"12x")])),
        Case("hex_content_length", post(body, [(b"Content-Length", b"0x20")])),
        Case(
            "duplicate_content_length_equal",
            post(body, [(b"Content-Length", str(len(body)).encode()), (b"Content-Length", str(len(body)).encode())]),
        ),
        Case(
            "duplicate_content_length_conflict",
            post(body, [(b"Content-Length", str(len(body)).encode()), (b"Content-Length", b"1")]),
        ),
        Case(
            "transfer_encoding_chunked",
            post(
                f"{len(body):x}\r\n".encode() + body + b"\r\n0\r\n\r\n",
                [(b"Transfer-Encoding", b"chunked"), (b"Content-Length", b"0")],
            ),
        ),
        Case("oversized_declared_length", post(b"", [(b"Content-Length", b"2147483647")]), True),
        Case("content_length_wrap", post(b"", [(b"Content-Length", b"4294967297")]), True),
        Case("empty_soapaction", post(body, [(b"SOAPAction", b"")])),
        Case("unquoted_soapaction", post(body, [(b"SOAPAction", ACTION.encode())])),
        Case("unterminated_soapaction_quote", post(body, [(b"SOAPAction", b'"' + ACTION.encode())])),
        Case("duplicate_soapaction", post(body, [(b"SOAPAction", b'"bogus#Action"')])),
        Case("folded_soapaction", post(body, [(b"X-Fold", b"x\r\n SOAPAction: \"bogus#Action\"")])),
        Case("header_without_colon", post(body, [(b"MalformedHeader", b"x\r\nNoColon")])),
        Case("empty_header_name", post(body, [(b"X", b"x\r\n: empty")])),
        Case("header_value_8192", post(body, [(b"X-RS700-Probe", b"A" * 8192)])),
        Case("soapaction_8192", post(body, [(b"SOAPAction", b'"' + b"A" * 8192 + b'"')])),
        Case("path_8192", post(body, path=b"/" + b"P" * 8192)),
        Case("method_1024", post(body).replace(b"POST ", b"M" * 1024 + b" ", 1)),
        Case("nul_in_header_value", post(body, [(b"X-RS700-Probe", b"A\x00B")])),
        Case("nul_in_path", post(body, path=b"/Public_UPNP_C3\x00suffix")),
        Case("empty_body", post(b"")),
        Case("truncated_xml", post(body[:-16])),
        Case("xml_nul", post(body[:64] + b"\x00" + body[64:])),
        Case("mismatched_xml_tags", post(envelope(b"<x><y></x></y>"))),
        Case("deep_xml_128", post(envelope(b"<x>" * 128 + b"z" + b"</x>" * 128))),
        Case(
            "bounded_entity_reference",
            post(
                b'<?xml version="1.0"?><!DOCTYPE x [<!ENTITY a "AAAAAAAA">]>'
                + envelope(b"<x>&a;&a;&a;&a;</x>")
            ),
        ),
        Case(
            "action_body_mismatch",
            post(envelope(b'<u:DeletePortMapping xmlns:u="urn:schemas-upnp-org:service:WANIPConnection:1"/>')),
        ),
        Case("extra_bytes_after_body", post(body) + b"EXTRA"),
        Case("pipelined_second_request", post(body) + b"GET " + DESCRIPTION.encode() + b" HTTP/1.1\r\nHost: x\r\n\r\n"),
    ]
    return raw


def exchange(host: str, port: int, case: Case, timeout: float) -> dict[str, object]:
    result: dict[str, object] = {"sent_bytes": len(case.payload)}
    started = time.monotonic()
    try:
        with socket.create_connection((host, port), timeout=timeout) as sock:
            sock.settimeout(timeout)
            sock.sendall(case.payload)
            if case.shutdown_write:
                sock.shutdown(socket.SHUT_WR)
            chunks: list[bytes] = []
            while sum(len(chunk) for chunk in chunks) < 16_384:
                try:
                    chunk = sock.recv(4096)
                except socket.timeout:
                    result["read_timeout"] = True
                    break
                if not chunk:
                    break
                chunks.append(chunk)
        response = b"".join(chunks)
        result["response_bytes"] = len(response)
        result["status_line"] = response.splitlines()[0].decode("latin-1", "replace") if response else ""
    except OSError as error:
        result["error"] = f"{type(error).__name__}: {error}"
    result["elapsed_ms"] = round((time.monotonic() - started) * 1000)
    return result


def health(host: str, port: int, timeout: float) -> dict[str, object]:
    payload = (
        b"GET " + DESCRIPTION.encode() + b" HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\nConnection: close\r\n\r\n"
    )
    return exchange(host, port, Case("health", payload), timeout)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=56688)
    parser.add_argument("--timeout", type=float, default=2.0)
    parser.add_argument("--allow-non-loopback", action="store_true")
    args = parser.parse_args()
    address = ipaddress.ip_address(socket.gethostbyname(args.host))
    if not address.is_loopback and not args.allow_non_loopback:
        parser.error("non-loopback target refused; use only inside an isolated lab")

    initial = health(args.host, args.port, args.timeout)
    print(json.dumps({"case": "initial_health", **initial}, sort_keys=True), flush=True)
    if not initial.get("status_line"):
        return 2

    for case in cases():
        outcome = exchange(args.host, args.port, case, args.timeout)
        time.sleep(0.1)
        after = health(args.host, args.port, args.timeout)
        record = {"case": case.name, **outcome, "health_after": after}
        print(json.dumps(record, sort_keys=True), flush=True)
        if not after.get("status_line"):
            return 3
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
