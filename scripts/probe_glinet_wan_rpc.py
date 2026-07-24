#!/usr/bin/env python3
"""Non-destructive GL.iNet /rpc reachability probe for an isolated WAN lab."""

from __future__ import annotations

import argparse
import ipaddress
import json
import socket
import ssl
import sys
import urllib.error
import urllib.request
from datetime import datetime, timezone
from urllib.parse import urlsplit


PAYLOAD = {
    "jsonrpc": "2.0",
    "id": 1,
    "method": "challenge",
    "params": {"username": "root"},
}


def resolve_lab_target(host: str) -> list[str]:
    addresses = sorted(
        {item[4][0] for item in socket.getaddrinfo(host, None, type=socket.SOCK_STREAM)}
    )
    if not addresses:
        raise ValueError("target did not resolve")
    for text in addresses:
        address = ipaddress.ip_address(text)
        if not (address.is_private or address.is_loopback or address.is_link_local):
            raise ValueError(
                f"refusing non-lab address {address}; use an RFC1918, loopback, "
                "or link-local target"
            )
    return addresses


def main() -> int:
    parser = argparse.ArgumentParser(
        description=(
            "Send exactly one valid root challenge to a GL.iNet /rpc endpoint. "
            "This establishes reachability but does not increment the unknown-user "
            "failure counter or trigger the login lockout."
        )
    )
    parser.add_argument("url", help="for example https://192.168.8.1/rpc")
    parser.add_argument("--timeout", type=float, default=5.0)
    parser.add_argument("--output", help="optional JSON evidence output path")
    args = parser.parse_args()

    parsed = urlsplit(args.url)
    if parsed.scheme not in {"http", "https"} or parsed.path != "/rpc":
        parser.error("URL must use http(s) and have the exact path /rpc")
    if not parsed.hostname:
        parser.error("URL has no hostname")

    try:
        addresses = resolve_lab_target(parsed.hostname)
    except (OSError, ValueError) as exc:
        print(f"safety check failed: {exc}", file=sys.stderr)
        return 2

    request = urllib.request.Request(
        args.url,
        data=json.dumps(PAYLOAD).encode(),
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    context = ssl._create_unverified_context() if parsed.scheme == "https" else None
    evidence = {
        "timestamp_utc": datetime.now(timezone.utc).isoformat(),
        "url": args.url,
        "resolved_addresses": addresses,
        "request_count": 1,
        "request": PAYLOAD,
    }
    try:
        with urllib.request.urlopen(
            request, timeout=args.timeout, context=context
        ) as response:
            body = response.read(65536).decode(errors="replace")
            evidence.update(
                {"reachable": True, "http_status": response.status, "body": body}
            )
    except urllib.error.HTTPError as exc:
        body = exc.read(65536).decode(errors="replace")
        evidence.update(
            {"reachable": True, "http_status": exc.code, "body": body}
        )
    except (urllib.error.URLError, TimeoutError, OSError) as exc:
        evidence.update({"reachable": False, "error": str(exc)})

    rendered = json.dumps(evidence, indent=2, sort_keys=True)
    print(rendered)
    if args.output:
        with open(args.output, "w", encoding="utf-8") as target:
            target.write(rendered + "\n")
    return 0 if evidence["reachable"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
