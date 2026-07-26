#!/usr/bin/env python3
"""Bounded HTTP/HTTPS authentication-dispatch matrix for the isolated RAX49S lab."""

from __future__ import annotations

import argparse
import base64
import hashlib
import socket
import ssl
import time


HOST = "127.0.0.1"
HTTP_PORT = 25049
HTTPS_PORT = 25149
LAB_AUTH = "Basic " + base64.b64encode(b"admin:FridayLab123!").decode()

ROUTES = (
    "/",
    "/index.htm",
    "/currentsetting.htm",
    "/BRS_index.htm",
    "/BRS_netgear_success.html",
    "/genie_welcome.htm",
    "/genie_wan_detected.htm",
    "/WIZ_select.htm",
    "/unauth.cgi",
    "/recover.cgi",
    "/securityquestions.cgi",
    "/passwordrecovered.cgi",
    "/passwordrecovered_debug",
    "/passwordrecovered_debug2",
    "/MNU_access_unauthorized.htm",
    "/MNU_access_unauthorized_checkSerial.htm",
    "/MNU_accessUnauthorized_checkAnswer.htm",
    "/upgrade_check.cgi",
    "/debug.htm",
    "/DebugHiddenPage.htm",
    "/USB_basic_printing.htm",
    "/soap/server_sa/",
)

METHODS = ("GET", "HEAD", "POST", "OPTIONS")
ALIASES = (
    "/./currentsetting.htm",
    "//currentsetting.htm",
    "/%63urrentsetting.htm",
    "/currentsetting.htm/",
    "/BRS_index.htm?x=1",
    "/soap/server_sa",
    "/soap/server_sa//",
    "/SOAP/server_sa/",
)


def request(method: str, path: str, authorization: str | None = None) -> bytes:
    body = b"FridayLabProbe=1" if method == "POST" else b""
    fields = [
        ("Host", "routerlogin.net"),
        ("Content-Type", "application/x-www-form-urlencoded"),
        ("Content-Length", str(len(body))),
        ("Connection", "close"),
    ]
    if authorization:
        fields.append(("Authorization", authorization))
    return (
        f"{method} {path} HTTP/1.1\r\n".encode()
        + b"".join(f"{key}: {value}\r\n".encode() for key, value in fields)
        + b"\r\n"
        + body
    )


def exchange(port: int, payload: bytes, tls: bool) -> bytes:
    with socket.create_connection((HOST, port), timeout=5) as raw:
        if tls:
            context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
            context.check_hostname = False
            context.verify_mode = ssl.CERT_NONE
            context.minimum_version = ssl.TLSVersion.TLSv1
            context.maximum_version = ssl.TLSVersion.TLSv1_2
            context.set_ciphers("ALL:@SECLEVEL=0")
            client = context.wrap_socket(raw, server_hostname="routerlogin.net")
        else:
            client = raw
        with client:
            client.sendall(payload)
            response = bytearray()
            while chunk := client.recv(65536):
                response.extend(chunk)
            return bytes(response)


def summarize(response: bytes) -> tuple[str, int, str]:
    status = response.splitlines()[0].decode(errors="replace") if response else "empty"
    body = response.partition(b"\r\n\r\n")[2]
    return status, len(body), hashlib.sha256(body).hexdigest()[:12]


def run_case(label: str, port: int, tls: bool, method: str, path: str, auth: str | None) -> None:
    try:
        response = exchange(port, request(method, path, auth), tls)
        status, size, digest = summarize(response)
        result = f"{status}|bytes={size}|sha={digest}"
    except (OSError, ssl.SSLError) as error:
        result = f"{type(error).__name__}:{error}"
    print(f"{label}|{method}|{path}|{result}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--http-port", type=int, default=HTTP_PORT)
    parser.add_argument("--https-port", type=int, default=HTTPS_PORT)
    parser.add_argument("--authenticated", action="store_true")
    args = parser.parse_args()
    auth = LAB_AUTH if args.authenticated else None
    auth_label = "auth" if auth else "preauth"

    for transport, port, tls in (
        ("http", args.http_port, False),
        ("https", args.https_port, True),
    ):
        for path in ROUTES:
            for method in METHODS:
                run_case(f"{auth_label}|{transport}", port, tls, method, path, auth)
                time.sleep(0.02)
        for path in ALIASES:
            run_case(f"{auth_label}|{transport}|alias", port, tls, "GET", path, auth)
            time.sleep(0.02)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
