#!/usr/bin/env python3
"""Bounded crash-oriented HTTP/SOAP campaign for the isolated RAX36S VM."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import socket
import subprocess
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path

import emulate_rax36s_full_system as emu


URN = "urn:NETGEAR-ROUTER:service:DeviceConfig:1"
RESPONSE_CODE = re.compile(rb"<ResponseCode>([^<]*)</ResponseCode>")


@dataclass(frozen=True)
class Case:
    name: str
    wire: bytes


def http_request(
    target: bytes,
    headers: list[tuple[bytes, bytes]],
    body: bytes,
) -> bytes:
    fields = [
        (b"Host", b"routerlogin.net"),
        (b"Connection", b"close"),
        *headers,
    ]
    if body and not any(name.lower() == b"content-length" for name, _ in fields):
        fields.append((b"Content-Length", str(len(body)).encode()))
    return (
        b"POST " + target + b" HTTP/1.1\r\n"
        + b"".join(name + b": " + value + b"\r\n" for name, value in fields)
        + b"\r\n" + body
    )


def envelope(inner: bytes) -> bytes:
    return (
        b'<?xml version="1.0"?>'
        b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        b"<s:Body>" + inner + b"</s:Body></s:Envelope>"
    )


def soap_wire(
    body: bytes,
    extra: list[tuple[bytes, bytes]] | None = None,
    action: bytes | None = None,
) -> bytes:
    return http_request(
        b"/soapapi",
        [
            (b"Content-Type", b'text/xml; charset="utf-8"'),
            (b"SOAPAction", action or (b'"' + URN.encode() + b'#GetSecurityQuestions"')),
            (b"X-Forwarded-For", b"10.0.2.2"),
            *(extra or []),
        ],
        body,
    )


def control_wire() -> bytes:
    inner = b'<m:GetSecurityQuestions xmlns:m="' + URN.encode() + b'"/>'
    return soap_wire(envelope(inner))


def parser_corpus() -> list[Case]:
    control_body = envelope(
        b'<m:GetSecurityQuestions xmlns:m="' + URN.encode() + b'"/>'
    )
    cases: list[Case] = []
    for size in (256, 1024, 4096, 8192, 16384):
        cases.append(Case(
            f"soapaction-{size}",
            soap_wire(control_body, action=b'"' + (b"A" * size) + b'"'),
        ))
    for name, header, size in (
        ("host", b"Host", 8192),
        ("forwarded-for", b"X-Forwarded-For", 8192),
        ("cookie", b"Cookie", 16384),
        ("user-agent", b"User-Agent", 16384),
    ):
        cases.append(Case(name + f"-{size}", soap_wire(
            control_body, extra=[(header, b"A" * size)]
        )))
    for size in (1024, 4096, 16384):
        inner = (
            b'<m:GetSecurityQuestions xmlns:m="' + URN.encode() + b'">'
            + (b"A" * size) + b"</m:GetSecurityQuestions>"
        )
        cases.append(Case(f"xml-padding-{size}", soap_wire(envelope(inner))))
    cases.extend([
        Case("xml-unterminated", soap_wire(
            b'<?xml version="1.0"?><s:Envelope><s:Body><m:GetSecurityQuestions'
        )),
        Case("xml-depth-64", soap_wire(envelope(
            (b"<x>" * 64) + b"A" + (b"</x>" * 64)
        ))),
        Case("xml-internal-entity", soap_wire(
            b'<!DOCTYPE x [<!ENTITY a "FRIDAY">]>'
            + envelope(b"<x>&a;</x>")
        )),
        Case("path-8192", http_request(
            b"/" + (b"A" * 8192), [(b"Content-Length", b"0")], b""
        )),
        Case("duplicate-content-length", http_request(
            b"/soapapi",
            [
                (b"Content-Type", b"text/xml"),
                (b"SOAPAction", b'"' + URN.encode() + b'#GetSecurityQuestions"'),
                (b"Content-Length", str(len(control_body)).encode()),
                (b"Content-Length", b"1"),
            ],
            control_body,
        )),
        Case("chunked-body", http_request(
            b"/soapapi",
            [
                (b"Content-Type", b"text/xml"),
                (b"SOAPAction", b'"' + URN.encode() + b'#GetSecurityQuestions"'),
                (b"Transfer-Encoding", b"chunked"),
            ],
            f"{len(control_body):x}\r\n".encode() + control_body + b"\r\n0\r\n\r\n",
        )),
    ])
    return cases


def action_wire(action: str, fields: list[tuple[str, bytes]]) -> bytes:
    arguments = b"".join(
        b"<" + name.encode() + b">" + value + b"</" + name.encode() + b">"
        for name, value in fields
    )
    inner = (
        b"<m:" + action.encode() + b' xmlns:m="' + URN.encode() + b'">'
        + arguments + b"</m:" + action.encode() + b">"
    )
    return soap_wire(
        envelope(inner),
        action=b'"' + URN.encode() + b"#" + action.encode() + b'"',
    )


def action_corpus() -> list[Case]:
    schemas: dict[str, list[tuple[str, bytes]]] = {
        "RecoverAdminPassword": [
            ("NewAnswer1", b"FRIDAY-WRONG-ANSWER-ONE"),
            ("NewAnswer2", b"FRIDAY-WRONG-ANSWER-TWO"),
        ],
        "ResetAdminPassword": [
            ("NewPassword", b"FRIDAY-INERT-NEW-PASSWORD"),
            ("NewSecurityQuestion1", b"1"),
            ("NewAnswer1", b"FRIDAY-WRONG-ANSWER-ONE"),
            ("NewSecurityQuestion2", b"2"),
            ("NewAnswer2", b"FRIDAY-WRONG-ANSWER-TWO"),
        ],
        "UpdateAdminPassword": [
            ("OldPassword", b"FRIDAY-DELIBERATELY-WRONG"),
            ("NewPassword", b"FRIDAY-INERT-NEW-PASSWORD"),
            ("NewEnableRecovery", b"1"),
            ("NewSecurityQuestion1", b"1"),
            ("NewAnswer1", b"FRIDAY-INERT-ANSWER-ONE"),
            ("NewSecurityQuestion2", b"2"),
            ("NewAnswer2", b"FRIDAY-INERT-ANSWER-TWO"),
        ],
    }
    cases: list[Case] = []
    string_fields = {
        "NewAnswer1", "NewAnswer2", "OldPassword", "NewPassword",
    }
    for action, defaults in schemas.items():
        for field, _default in defaults:
            if field not in string_fields:
                continue
            for size in (0, 127, 128, 129, 256, 1024, 4096):
                mutated = [
                    (name, (b"A" * size) if name == field else value)
                    for name, value in defaults
                ]
                cases.append(Case(
                    f"{action}-{field}-{size}",
                    action_wire(action, mutated),
                ))
        for field, _default in defaults:
            if field in string_fields:
                continue
            for marker_name, marker in (
                ("negative", b"-1"),
                ("large", b"4294967295"),
                ("text", b"FRIDAY"),
            ):
                mutated = [
                    (name, marker if name == field else value)
                    for name, value in defaults
                ]
                cases.append(Case(
                    f"{action}-{field}-{marker_name}",
                    action_wire(action, mutated),
                ))
    return cases


def exchange(wire: bytes, timeout: float = 8.0) -> tuple[bytes, str]:
    output = bytearray()
    error = ""
    try:
        with socket.create_connection(("127.0.0.1", emu.HOST_PORT), timeout=timeout) as client:
            client.settimeout(timeout)
            client.sendall(wire)
            client.shutdown(socket.SHUT_WR)
            while len(output) < 1024 * 1024:
                try:
                    chunk = client.recv(65536)
                except (TimeoutError, socket.timeout):
                    error = "response-timeout"
                    break
                if not chunk:
                    break
                output.extend(chunk)
    except OSError as exc:
        error = f"{type(exc).__name__}: {exc}"
    return bytes(output), error


def status(response: bytes) -> str:
    return response.splitlines()[0].decode("iso-8859-1", "replace") if response else "empty"


def healthy(process: subprocess.Popen[bytes]) -> tuple[bool, str]:
    if process.poll() is not None:
        return False, f"qemu-exit-{process.returncode}"
    for attempt in range(3):
        response, error = exchange(control_wire(), timeout=12)
        if response.startswith(b"HTTP/") and b"<ResponseCode>000</ResponseCode>" in response:
            return True, status(response)
        if attempt < 2:
            time.sleep(1)
    return False, error or status(response)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build", action="store_true", help="Rebuild the VM before testing.")
    parser.add_argument("--case", help="Run one named case for deterministic replay.")
    parser.add_argument(
        "--profile",
        choices=("parser", "actions", "all"),
        default="parser",
        help="Select generic parser cases, handler-specific arguments, or both.",
    )
    args = parser.parse_args()
    if args.build:
        emu.build()
    if not emu.INITRAMFS.is_file():
        raise SystemExit("build the RAX36S full-system emulator first")
    cases = []
    if args.profile in ("parser", "all"):
        cases.extend(parser_corpus())
    if args.profile in ("actions", "all"):
        cases.extend(action_corpus())
    if args.case:
        cases = [case for case in cases if case.name == args.case]
        if not cases:
            parser.error(f"unknown case: {args.case}")

    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    output_dir = emu.LAB / f"unauth-{args.profile}-campaign-{stamp}"
    requests_dir = output_dir / "requests"
    requests_dir.mkdir(parents=True)
    results_path = output_dir / "results.jsonl"
    emu.SERIAL.unlink(missing_ok=True)
    emu.QEMU_LOG.unlink(missing_ok=True)
    suspected = ""
    with emu.QEMU_LOG.open("wb") as qemu_output:
        process = subprocess.Popen(
            emu.qemu_command(), stdout=qemu_output, stderr=subprocess.STDOUT
        )
        try:
            emu.wait_ready()
            baseline, detail = healthy(process)
            if not baseline:
                raise SystemExit(f"baseline failed: {detail}")
            with results_path.open("w") as results:
                for index, case in enumerate(cases, 1):
                    request_path = requests_dir / f"{index:02d}-{case.name}.http"
                    request_path.write_bytes(case.wire)
                    response, error = exchange(case.wire)
                    response_code_match = RESPONSE_CODE.search(response)
                    time.sleep(0.25)
                    alive, health_detail = healthy(process)
                    record = {
                        "index": index,
                        "case": case.name,
                        "request_path": str(request_path.relative_to(output_dir)),
                        "request_bytes": len(case.wire),
                        "request_sha256": hashlib.sha256(case.wire).hexdigest(),
                        "response_status": status(response),
                        "response_bytes": len(response),
                        "soap_response_code": (
                            response_code_match.group(1).decode(errors="replace")
                            if response_code_match else None
                        ),
                        "response_error": error or None,
                        "control_alive": alive,
                        "control_detail": health_detail,
                    }
                    results.write(json.dumps(record, sort_keys=True) + "\n")
                    results.flush()
                    print(json.dumps(record, sort_keys=True), flush=True)
                    if not alive:
                        suspected = case.name
                        break
            (output_dir / "serial.log").write_bytes(
                emu.SERIAL.read_bytes() if emu.SERIAL.exists() else b""
            )
        finally:
            process.terminate()
            try:
                process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                process.kill()
    summary = {
        "cases_completed": index if cases else 0,
        "cases_planned": len(cases),
        "crash_candidate": suspected or None,
        "result": "candidate-needs-replay" if suspected else "no-observable-dos",
    }
    (output_dir / "summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(f"output_dir={output_dir}\nsummary={json.dumps(summary, sort_keys=True)}")
    return 1 if suspected else 0


if __name__ == "__main__":
    raise SystemExit(main())
