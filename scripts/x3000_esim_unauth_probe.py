#!/usr/bin/env python3
"""Bounded read-only probe for the GL-X3000 unauthenticated eSIM API.

The probe refuses public targets and only calls non-mutating methods.  It does
not attempt eSIM installation, profile changes, shell execution, or flooding.
"""

from __future__ import annotations

import argparse
import ipaddress
import json
import socket
import sys
import urllib.error
import urllib.request


READ_ONLY_METHODS = ("running", "progress", "log")


def private_target(host: str) -> bool:
    try:
        addresses = {
            ipaddress.ip_address(item[4][0])
            for item in socket.getaddrinfo(host, None, type=socket.SOCK_STREAM)
        }
    except (OSError, ValueError):
        return False
    return bool(addresses) and all(
        address.is_private or address.is_loopback or address.is_link_local
        for address in addresses
    )


def call(url: str, method: str, timeout: float) -> tuple[int, str]:
    body = json.dumps({"method": method}).encode()
    request = urllib.request.Request(
        url,
        data=body,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    try:
        with urllib.request.urlopen(request, timeout=timeout) as response:
            return response.status, response.read(65536).decode(errors="replace")
    except urllib.error.HTTPError as error:
        return error.code, error.read(65536).decode(errors="replace")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=80)
    parser.add_argument("--https", action="store_true")
    parser.add_argument("--direct", action="store_true",
                        help="Use direct port-3456 path instead of Nginx /sdk/v1")
    parser.add_argument("--timeout", type=float, default=3.0)
    args = parser.parse_args()

    if not private_target(args.target):
        print("refused: target must resolve exclusively to private/local addresses",
              file=sys.stderr)
        return 2

    scheme = "https" if args.https else "http"
    path = "/sdk/v1"
    url = f"{scheme}://{args.target}:{args.port}{path}"
    if args.direct and args.port == 80:
        print("warning: --direct normally uses --port 3456", file=sys.stderr)

    confirmed = False
    for method in READ_ONLY_METHODS:
        try:
            status, response = call(url, method, args.timeout)
        except (OSError, urllib.error.URLError) as error:
            print(f"{method}: transport_error={error}")
            continue
        print(f"{method}: http_status={status}")
        print(response[:4096])
        if status == 200 and (
            '"code":200' in response
            or "lpaVer:" in response
            or "Debug esim:" in response
        ):
            confirmed = True

    print(f"unauthenticated_esim_api_reachable={str(confirmed).lower()}")
    return 0 if confirmed else 1


if __name__ == "__main__":
    raise SystemExit(main())
