#!/usr/bin/env python3
"""Marker-only requests for an isolated X3000 /sdk/v1 emulator."""

import argparse
import http.client
import json


CASES = {
    "install_ac": {
        "method": "install",
        "ac_code": "LPA:1$invalid.local$X;printf X3000_INSTALL_AC >/tmp/x3000-lan-install-ac",
        "cf_code": "",
    },
    "install_cf": {
        "method": "install",
        "ac_code": "LPA:1$invalid.local$X",
        "cf_code": "X;printf X3000_INSTALL_CF >/tmp/x3000-lan-install-cf",
    },
    "nick_name": {
        "method": "nick",
        "iccid": "8986000000000000000",
        "name": "X;printf X3000_NICK_NAME >/tmp/x3000-lan-nick-name",
    },
    "nick_iccid": {
        "method": "nick",
        "iccid": "X;printf X3000_NICK_ICCID >/tmp/x3000-lan-nick-iccid",
        "name": "safe",
    },
    "enable_iccid": {
        "method": "enable",
        "iccid": "X;printf X3000_ENABLE >/tmp/x3000-lan-enable",
    },
    "disable_iccid": {
        "method": "disable",
        "iccid": "X;printf X3000_DISABLE >/tmp/x3000-lan-disable",
    },
    "delete_iccid": {
        "method": "delete",
        "iccid": "X;printf X3000_DELETE >/tmp/x3000-lan-delete",
    },
    "notify_iccid": {
        "method": "notify",
        "iccid": "X;printf X3000_NOTIFY >/tmp/x3000-lan-notify",
    },
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("case", choices=sorted(CASES))
    parser.add_argument("--host", default="172.30.45.2")
    parser.add_argument("--port", type=int, default=8080)
    parser.add_argument("--timeout", type=float, default=8)
    args = parser.parse_args()

    body = json.dumps({"txId": f"marker-{args.case}", **CASES[args.case]})
    conn = http.client.HTTPConnection(args.host, args.port, timeout=args.timeout)
    try:
        conn.request(
            "POST",
            "/sdk/v1",
            body,
            {"Content-Type": "application/json", "Connection": "close"},
        )
        response = conn.getresponse()
        print(f"HTTP {response.status}")
        print(response.read().decode("utf-8", "replace"))
    except TimeoutError:
        print("HTTP TIMEOUT (operation may still be running)")
    finally:
        conn.close()


if __name__ == "__main__":
    main()
