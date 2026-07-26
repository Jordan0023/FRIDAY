#!/usr/bin/env python3
"""Bounded, deterministic, loopback-only EX2800 Telnet/login fuzzer.

This is a crash/availability triage tool, not an exploit.  It never accepts a
non-loopback target, uses no valid credential, and caps both corpus and input
sizes.  A failed health check is reported as a lead only; it is not classified
as an authentication bypass or RCE.
"""

from __future__ import annotations

import argparse
import hashlib
import ipaddress
import json
import socket
import time
from dataclasses import dataclass


MAX_CASES = 128
MAX_FIELD = 4096


@dataclass(frozen=True)
class Case:
    name: str
    username: bytes
    password: bytes = b""
    preamble: bytes = b""


def loopback(value: str) -> str:
    addresses = {
        item[4][0]
        for item in socket.getaddrinfo(value, None, type=socket.SOCK_STREAM)
    }
    if not addresses or any(not ipaddress.ip_address(item).is_loopback for item in addresses):
        raise argparse.ArgumentTypeError("target must resolve only to loopback")
    return sorted(addresses)[0]


def corpus() -> list[Case]:
    boundary_lengths = (1, 7, 8, 15, 16, 31, 32, 63, 64, 127, 128, 255,
                        256, 511, 512, 1023, 1024, 2047, 2048, 4095, 4096)
    cases = [
        Case("empty", b""),
        Case("root_blank", b"root"),
        Case("option_f", b"-f root"),
        Case("option_p", b"-p"),
        Case("format_tokens", b"%s%n%08x"),
        Case("shell_tokens", b"$(id);`id`;|id"),
        Case("whitespace", b"root \t"),
        Case("high_bytes", bytes(range(0x80, 0x100))),
    ]
    patterns = ((b"A", "ascii"), (b"%", "percent"), (b"\xff", "iac"))
    for unit, label in patterns:
        for length in boundary_lengths:
            cases.append(Case(f"{label}_{length}", unit * length))
    # Exercise Telnet option parsing independently of login parsing.
    for option in (0, 1, 3, 24, 31, 32, 34, 36, 39, 255):
        cases.append(Case(f"iac_will_{option}", b"probe",
                          preamble=bytes((255, 251, option))))
        cases.append(Case(f"iac_sb_{option}", b"probe",
                          preamble=bytes((255, 250, option, 0, 255, 240))))
    assert len(cases) <= MAX_CASES
    assert all(max(len(c.username), len(c.password), len(c.preamble)) <= MAX_FIELD
               for c in cases)
    return cases


def recv_until(sock: socket.socket, needle: bytes, limit: int = 8192) -> bytes:
    output = bytearray()
    while needle.lower() not in output.lower() and len(output) < limit:
        chunk = sock.recv(min(1024, limit - len(output)))
        if not chunk:
            break
        output.extend(chunk)
    return bytes(output)


def run_case(target: str, port: int, case: Case, timeout: float) -> dict[str, object]:
    transcript = bytearray()
    outcome = "completed"
    try:
        with socket.create_connection((target, port), timeout=timeout) as sock:
            sock.settimeout(timeout)
            if case.preamble:
                sock.sendall(case.preamble)
            transcript.extend(recv_until(sock, b"login:"))
            sock.sendall(case.username + b"\r\n")
            transcript.extend(recv_until(sock, b"password:"))
            sock.sendall(case.password + b"\r\n")
            try:
                transcript.extend(sock.recv(2048))
            except socket.timeout:
                outcome = "response_timeout"
    except (ConnectionError, OSError, socket.timeout) as error:
        outcome = f"connection_error:{type(error).__name__}"
    data = bytes(transcript)
    return {
        "case": case.name,
        "outcome": outcome,
        "transcript_bytes": len(data),
        "transcript_sha256": hashlib.sha256(data).hexdigest(),
        "possible_shell_prompt": data.rstrip().endswith((b"#", b"$")),
    }


def healthy(target: str, port: int, timeout: float) -> bool:
    try:
        with socket.create_connection((target, port), timeout=timeout) as sock:
            sock.settimeout(timeout)
            return bool(recv_until(sock, b"login:", 2048))
    except (ConnectionError, OSError, socket.timeout):
        return False


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=loopback, default="127.0.0.1")
    parser.add_argument("--port", type=int, default=23)
    parser.add_argument("--timeout", type=float, default=1.0)
    parser.add_argument("--limit", type=int, default=MAX_CASES)
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()
    if not 1 <= args.port <= 65535:
        parser.error("port must be between 1 and 65535")
    if not 0.1 <= args.timeout <= 5.0:
        parser.error("timeout must be between 0.1 and 5 seconds")
    if not 1 <= args.limit <= MAX_CASES:
        parser.error(f"limit must be between 1 and {MAX_CASES}")

    selected = corpus()[:args.limit]
    if args.dry_run:
        print(json.dumps({"dry_run": True, "cases": len(selected),
                          "max_field": MAX_FIELD}, sort_keys=True))
        return 0

    initial_health = healthy(args.target, args.port, args.timeout)
    print(json.dumps({"event": "initial_health", "healthy": initial_health}))
    if not initial_health:
        return 2

    consecutive_health_failures = 0
    possible_auth_bypass = False
    for case in selected:
        result = run_case(args.target, args.port, case, args.timeout)
        possible_auth_bypass |= bool(result["possible_shell_prompt"])
        time.sleep(0.05)
        result["service_healthy_after"] = healthy(args.target, args.port, args.timeout)
        if result["service_healthy_after"]:
            consecutive_health_failures = 0
        else:
            consecutive_health_failures += 1
        print(json.dumps(result, sort_keys=True))
        if consecutive_health_failures >= 2:
            break

    print(json.dumps({
        "event": "summary",
        "cases_attempted": min(len(selected), selected.index(case) + 1),
        "consecutive_health_failures": consecutive_health_failures,
        "crash_or_hang_lead": consecutive_health_failures >= 2,
        "possible_auth_bypass_lead": possible_auth_bypass,
        "rce_confirmed": False,
    }, sort_keys=True))
    return 1 if consecutive_health_failures >= 2 or possible_auth_bypass else 0


if __name__ == "__main__":
    raise SystemExit(main())
