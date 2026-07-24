#!/usr/bin/env python3
"""Enumerate RAX54Sv2 SOAP actions without credentials in the isolated lab."""

from __future__ import annotations

import json
import re
import subprocess
import sys
from pathlib import Path

import probe_rax54sv2_http_security as probe


ROOT = Path(__file__).resolve().parents[1]
HTTPD = (
    ROOT
    / "known_firmware/extracted/c9b1ed79f8f766b5/manual-rootfs/usr/sbin/httpd"
)
OUTPUT = (
    ROOT
    / "known_firmware/emulation/RAX54SV2/full-system-http-lab/"
    "unauth-soap-action-matrix.json"
)
ACTION = re.compile(
    r"^(?:Add|Apply|Check|Delete|Factory|Get|Reboot|Request|Set|Start|Stop|Update)"
    r"[A-Za-z0-9_]{2,}$"
)
RESPONSE_CODE = re.compile(rb"<ResponseCode>([^<]*)</ResponseCode>")


def action_names() -> list[str]:
    output = subprocess.run(
        ["strings", "-a", str(HTTPD)],
        check=True,
        capture_output=True,
        text=True,
    ).stdout
    return sorted({line for line in output.splitlines() if ACTION.fullmatch(line)})


def payload(action: str) -> bytes:
    namespace = "urn:NETGEAR-ROUTER:service:DeviceConfig:1"
    body = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        f'<s:Body><m:{action} xmlns:m="{namespace}"/></s:Body></s:Envelope>'
    ).encode()
    return probe.request(
        "POST",
        "/soap/server_sa/",
        body,
        (
            ("Content-Type", 'text/xml; charset="utf-8"'),
            ("SOAPAction", f'"{namespace}#{action}"'),
        ),
    )


def main() -> int:
    probe.USE_TLS = True
    results = []
    actions = action_names()
    for index, action in enumerate(actions, 1):
        try:
            response = probe.exchange("127.0.0.1", 25156, payload(action), timeout=8)
            first_line = probe.status(response)
            body = response.partition(b"\r\n\r\n")[2]
            match = RESPONSE_CODE.search(body)
            code = match.group(1).decode(errors="replace") if match else None
            result = {
                "action": action,
                "http_status": first_line,
                "response_code": code,
                "response_bytes": len(body),
            }
        except OSError as error:
            result = {
                "action": action,
                "error": f"{type(error).__name__}: {error}",
            }
        results.append(result)
        if result.get("response_code") not in ("401", None):
            print(json.dumps(result), flush=True)
        if index % 20 == 0:
            alive = probe.alive("127.0.0.1", 25156)
            print(f"progress={index}/{len(actions)} service_alive={str(alive).lower()}", flush=True)
            if not alive:
                break
    OUTPUT.write_text(json.dumps(results, indent=2) + "\n")
    print(f"actions_tested={len(results)} output={OUTPUT}")
    return 0 if probe.alive("127.0.0.1", 25156) else 2


if __name__ == "__main__":
    sys.exit(main())
