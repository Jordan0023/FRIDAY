#!/usr/bin/env python3
"""Rank pre-auth RCE/DoS leads from exhaustive 74-router Ghidra evidence."""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path


NETWORK_NAMES = (
    "http", "cgi", "upnp", "soap", "dns", "dhcp", "lpd", "ippd", "telnet",
    "dropbear", "sshd", "rpc", "daemon", "server", "miniupnp", "uhttpd",
    "lighttpd", "nginx", "boa", "udhcp", "hostapd", "wpa", "lld2",
)
NETWORK_SOURCES = {
    "recv", "recvfrom", "recvmsg", "accept", "read", "fgets", "getline",
    "getenv", "FCGX_GetParam", "websGetVar",
}
RCE_SINKS = {
    "system", "popen", "execl", "execle", "execlp", "execv", "execve",
    "execvp", "doSystem", "eval", "wordexp",
}
MEMORY_SINKS = {
    "strcpy", "strcat", "sprintf", "vsprintf", "memcpy", "memmove", "sscanf",
}
RESOURCE_SINKS = {"malloc", "calloc", "realloc", "fork"}


def score_record(record: dict, program: str) -> tuple[int, list[str]]:
    sinks = set(record.get("sinks", []))
    sources = set(record.get("sources", []))
    reasons: list[str] = []
    score = 0
    lower = program.lower()

    if any(token in lower for token in NETWORK_NAMES):
        score += 8
        reasons.append("network-facing binary name")
    network_hits = sorted(sources & NETWORK_SOURCES)
    if network_hits:
        score += 10 + 2 * len(network_hits)
        reasons.append("attacker-input source: " + ", ".join(network_hits))
    rce_hits = sorted(sinks & RCE_SINKS)
    if rce_hits:
        score += 24 + 3 * len(rce_hits)
        reasons.append("execution sink: " + ", ".join(rce_hits))
    memory_hits = sorted(sinks & MEMORY_SINKS)
    if memory_hits:
        score += 12 + 2 * len(memory_hits)
        reasons.append("unsafe memory sink: " + ", ".join(memory_hits))
    resource_hits = sorted(sinks & RESOURCE_SINKS)
    if resource_hits and network_hits:
        score += 7
        reasons.append("network-controlled resource sink: " + ", ".join(resource_hits))
    if record.get("routes"):
        score += 3
        reasons.append("route/protocol marker")
    if not record.get("auth_markers"):
        score += 5
        reasons.append("no local auth marker")
    else:
        score -= 8
        reasons.append("auth marker present")
    if network_hits and rce_hits:
        score += 25
        reasons.append("same-function input/execution correlation")
    if network_hits and memory_hits:
        score += 15
        reasons.append("same-function input/memory correlation")
    return score, reasons


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("campaign", type=Path)
    parser.add_argument("--json-output", type=Path)
    parser.add_argument("--limit", type=int, default=200)
    args = parser.parse_args()

    inventory = json.loads((args.campaign / "inventory.json").read_text())
    instances: dict[str, list[dict]] = defaultdict(list)
    for router in inventory:
        for binary in router.get("elf_files", []):
            instances[binary["content_sha256"]].append(
                {
                    "product": router["product"],
                    "firmware_sha256": router["sha256"],
                    "path": binary["path"],
                }
            )

    leads = []
    for receipt in args.campaign.glob("receipts/*/*.json"):
        data = json.loads(receipt.read_text())
        if data.get("coverage_status") not in {"complete", "partial"}:
            continue
        evidence = Path(data.get("evidence_path", ""))
        if not evidence.is_file():
            continue
        content_sha256 = receipt.stem
        program = data.get("program", "")
        for line in evidence.read_text(errors="replace").splitlines():
            try:
                record = json.loads(line)
            except json.JSONDecodeError:
                continue
            score, reasons = score_record(record, program)
            if score < 20:
                continue
            leads.append(
                {
                    "score": score,
                    "program": program,
                    "function": record.get("function"),
                    "address": record.get("address"),
                    "sinks": record.get("sinks", []),
                    "sources": record.get("sources", []),
                    "routes": record.get("routes", []),
                    "auth_markers": record.get("auth_markers", []),
                    "reasons": reasons,
                    "content_sha256": content_sha256,
                    "coverage_status": data.get("coverage_status"),
                    "instances": instances.get(content_sha256, []),
                    "evidence_path": str(evidence),
                }
            )

    leads.sort(
        key=lambda item: (
            -item["score"],
            item["program"],
            item["function"] or "",
            item["content_sha256"],
        )
    )
    result = {
        "campaign": str(args.campaign),
        "lead_count": len(leads),
        "leads": leads[: args.limit],
    }
    text = json.dumps(result, indent=2) + "\n"
    if args.json_output:
        args.json_output.parent.mkdir(parents=True, exist_ok=True)
        args.json_output.write_text(text)
    else:
        print(text, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
