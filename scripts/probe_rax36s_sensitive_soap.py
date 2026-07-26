#!/usr/bin/env python3
"""Bounded sensitive-SOAP checks for an isolated RAX36S web lab."""

from __future__ import annotations

import argparse
import base64
import http.client
import json
import re


CASES = (
    ("questions", "GetSecurityQuestions", ""),
    ("recover-plain", "RecoverAdminPassword", (
        "<NewAnswer1>FRIDAY-INERT-ONE</NewAnswer1>"
        "<NewAnswer2>FRIDAY-INERT-TWO</NewAnswer2>"
    )),
    ("recover-lab-plain", "RecoverAdminPassword", (
        "<NewAnswer1>friday-answer-one</NewAnswer1>"
        "<NewAnswer2>friday-answer-two</NewAnswer2>"
    )),
    ("recover-lab-base64", "RecoverAdminPassword", (
        f"<NewAnswer1>{base64.b64encode(b'friday-answer-one').decode()}</NewAnswer1>"
        f"<NewAnswer2>{base64.b64encode(b'friday-answer-two').decode()}</NewAnswer2>"
    )),
    ("reset-admin-password", "ResetAdminPassword", (
        "<NewPassword>FRIDAY-INERT-NEW-PASSWORD</NewPassword>"
        "<NewSecurityQuestion1>1</NewSecurityQuestion1>"
        "<NewAnswer1>friday-answer-one</NewAnswer1>"
        "<NewSecurityQuestion2>2</NewSecurityQuestion2>"
        "<NewAnswer2>friday-answer-two</NewAnswer2>"
    )),
    ("update-admin-password", "UpdateAdminPassword", (
        "<OldPassword>FRIDAY-WRONG-OLD-PASSWORD</OldPassword>"
        "<NewPassword>FRIDAY-INERT-NEW-PASSWORD</NewPassword>"
        "<NewEnableRecovery>1</NewEnableRecovery>"
        "<NewSecurityQuestion1>1</NewSecurityQuestion1>"
        "<NewAnswer1>friday-answer-one</NewAnswer1>"
        "<NewSecurityQuestion2>2</NewSecurityQuestion2>"
        "<NewAnswer2>friday-answer-two</NewAnswer2>"
    )),
    ("verify", "SOAPSecurityQAVerifyAns", (
        "<NewAnswer1>FRIDAY-INERT-ONE</NewAnswer1>"
        "<NewAnswer2>FRIDAY-INERT-TWO</NewAnswer2>"
    )),
    ("token", "SOAPQueryAccessToken", ""),
)
RESPONSE_CODE = re.compile(rb"<ResponseCode>([^<]*)</ResponseCode>")


def request(port: int, case: str, action: str, arguments: str) -> dict[str, object]:
    namespace = "urn:NETGEAR-ROUTER:service:DeviceConfig:1"
    body = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        f'<s:Body><m:{action} xmlns:m="{namespace}">{arguments}'
        f"</m:{action}></s:Body></s:Envelope>"
    ).encode()
    connection = http.client.HTTPConnection("127.0.0.1", port, timeout=8)
    try:
        connection.request(
            "POST",
            "/soapapi",
            body,
            {
                "Host": "routerlogin.net",
                "Content-Type": 'text/xml; charset="utf-8"',
                "SOAPAction": f'"{namespace}#{action}"',
                "Connection": "close",
            },
        )
        response = connection.getresponse()
        response_body = response.read(1024 * 1024)
        code = RESPONSE_CODE.search(response_body)
        return {
            "case": case,
            "action": action,
            "http_status": response.status,
            "response_code": (
                code.group(1).decode(errors="replace") if code else None
            ),
            "response_bytes": len(response_body),
            "password_material_present": b"http_passwd" in response_body,
            "response_preview": response_body[:1024].decode(errors="replace"),
        }
    finally:
        connection.close()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", type=int, default=25137)
    args = parser.parse_args()
    for case, action, arguments in CASES:
        try:
            result = request(args.port, case, action, arguments)
        except (OSError, TimeoutError, http.client.HTTPException) as error:
            result = {"case": case, "action": action, "error": f"{type(error).__name__}: {error}"}
        print(json.dumps(result), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
