#!/usr/bin/env python3
"""Focused unauthenticated checks for high-risk RAX54Sv2 SOAP handlers."""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

import probe_rax54sv2_http_security as probe


ROOT = Path(__file__).resolve().parents[1]
OUTPUT = (
    ROOT
    / "known_firmware/emulation/RAX54SV2/full-system-http-lab/"
    "sensitive-soap-matrix.json"
)
SERVICES = (
    "DeviceConfig",
    "DeviceInfo",
    "LANConfigSecurity",
    "WLANConfiguration",
    "AdvancedQoS",
)
RESPONSE_CODE = re.compile(rb"<ResponseCode>([^<]*)</ResponseCode>")

CASES = {
    "GetSecurityQuestions": "",
    "ResetAdminPassword": (
        "<SerialNumber>FRIDAY0000000</SerialNumber>"
        "<NewSecurityQuestion1>1</NewSecurityQuestion1>"
        "<NewAnswer1>FRIDAY</NewAnswer1>"
        "<NewSecurityQuestion2>2</NewSecurityQuestion2>"
        "<NewAnswer2>FRIDAY</NewAnswer2>"
    ),
    "RecoverAdminPassword": (
        "<SerialNumber>FRIDAY0000000</SerialNumber>"
        "<NewSecurityQuestion1>1</NewSecurityQuestion1>"
        "<NewAnswer1>FRIDAY</NewAnswer1>"
        "<NewSecurityQuestion2>2</NewSecurityQuestion2>"
        "<NewAnswer2>FRIDAY</NewAnswer2>"
    ),
    "SetFirmware": "<NewFirmware>RlJJREFZX0lORVJU</NewFirmware>",
    "SetConfiguration": (
        "<NewConfigFile>RlJJREFZX0lORVJU</NewConfigFile>"
        "<NewLoaddefault>0</NewLoaddefault>"
    ),
    "SetNTP": (
        "<NewNTPServer1>time-a.netgear.com</NewNTPServer1>"
        "<NewNTPServer2>time-b.netgear.com</NewNTPServer2>"
        "<NewNTPServer3>time-c.netgear.com</NewNTPServer3>"
        "<NewNTPServer4>time-d.netgear.com</NewNTPServer4>"
    ),
    "CheckAndDownloadNewFirmware": (
        "<NewFirmwareURL>http://127.0.0.1/FRIDAY</NewFirmwareURL>"
    ),
    "SetWLANWPAPSKByPassphrase": (
        "<NewSSID>FRIDAY</NewSSID>"
        "<NewRegion>1</NewRegion>"
        "<NewChannel>0</NewChannel>"
        "<NewWirelessMode>0</NewWirelessMode>"
        "<NewWPAEncryptionModes>WPA2-PSK</NewWPAEncryptionModes>"
        "<NewWPAPassphrase>FRIDAY-INERT-PASSPHRASE</NewWPAPassphrase>"
    ),
}


def request(service: str, action: str, arguments: str) -> bytes:
    namespace = f"urn:NETGEAR-ROUTER:service:{service}:1"
    body = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        f'<s:Body><m:{action} xmlns:m="{namespace}">'
        f"{arguments}</m:{action}></s:Body></s:Envelope>"
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


def send(service: str, action: str, arguments: str) -> dict[str, object]:
    try:
        response = probe.exchange(
            "127.0.0.1",
            25156,
            request(service, action, arguments),
            timeout=12,
        )
        body = response.partition(b"\r\n\r\n")[2]
        match = RESPONSE_CODE.search(body)
        return {
            "service": service,
            "action": action,
            "http_status": probe.status(response),
            "response_code": match.group(1).decode(errors="replace") if match else None,
            "response_bytes": len(body),
        }
    except OSError as error:
        return {
            "service": service,
            "action": action,
            "error": f"{type(error).__name__}: {error}",
        }


def discover() -> int:
    results = []
    for action, arguments in CASES.items():
        for service in SERVICES:
            result = send(service, action, arguments)
            results.append(result)
            print(json.dumps(result), flush=True)
            if not probe.alive("127.0.0.1", 25156):
                OUTPUT.write_text(json.dumps(results, indent=2) + "\n")
                return 2
    OUTPUT.write_text(json.dumps(results, indent=2) + "\n")
    print(f"output={OUTPUT}")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--mode", choices=("discover",), default="discover")
    parser.parse_args()
    probe.USE_TLS = True
    return discover()


if __name__ == "__main__":
    sys.exit(main())
