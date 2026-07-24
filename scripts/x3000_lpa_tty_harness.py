#!/usr/bin/env python3
"""Run the X3000 LPA daemon against a minimal pseudo-modem for lab validation."""

import os
import pty
import select
import subprocess
import sys
import tty


RESPONSES = {
    "ATE0": "\r\nOK\r\n",
    "AT+CPIN?": "\r\n+CPIN: READY\r\n\r\nOK\r\n",
    "AT+ICCID": "\r\n+ICCID: 8986000000000000000\r\n\r\nOK\r\n",
    "AT+CIMI": "\r\n001010123456789\r\n\r\nOK\r\n",
    "AT+CGSN": "\r\n014622935200310\r\n\r\nOK\r\n",
    "AT+CSQ": "\r\n+CSQ: 20,99\r\n\r\nOK\r\n",
    "AT+CREG?": "\r\n+CREG: 0,1\r\n\r\nOK\r\n",
}


def response_for(command):
    command = command.strip()
    if command in RESPONSES:
        return RESPONSES[command]
    if command.startswith("AT+CGACT"):
        return "\r\n+CGACT: 1,1\r\n\r\nOK\r\n"
    if command.startswith("AT+CSIM"):
        if '"0070000001"' in command:
            return '\r\n+CSIM: 6,"019000"\r\n\r\nOK\r\n'
        if "BF3E" in command or "bf3e" in command:
            return (
                '\r\n+CSIM: 44,"BF3E125A108906010234567890123456789012349000"'
                "\r\n\r\nOK\r\n"
            )
        return "\r\n+CSIM: 4,\"9000\"\r\n\r\nOK\r\n"
    return "\r\nOK\r\n"


def main():
    master, slave = pty.openpty()
    tty.setraw(slave)
    tty_path = os.ttyname(slave)
    print(f"PSEUDO_MODEM {tty_path}", flush=True)
    command = [
        "/usr/bin/qemu-aarch64-static",
        "-strace",
        "-L",
        "/firmware",
        "/firmware/usr/bin/lpa_arm64_v1.50",
        "-at",
        tty_path,
        "-debug",
        "-sync",
        os.environ.get("X3000_SYNC_MODE", "long"),
    ]
    proc = subprocess.Popen(command, stdout=sys.stdout, stderr=sys.stderr)
    pending = b""
    try:
        while proc.poll() is None:
            readable, _, _ = select.select([master], [], [], 0.5)
            if not readable:
                continue
            try:
                chunk = os.read(master, 4096)
            except OSError as exc:
                if exc.errno == 5:  # PTY slave has not been opened by the daemon yet.
                    continue
                raise
            if not chunk:
                break
            pending += chunk
            while b"\r" in pending or b"\n" in pending:
                split_at = min(
                    index for index in (pending.find(b"\r"), pending.find(b"\n")) if index >= 0
                )
                line, pending = pending[:split_at], pending[split_at + 1 :]
                pending = pending.lstrip(b"\r\n")
                if not line:
                    continue
                command_text = line.decode("ascii", "replace")
                reply = response_for(command_text)
                print(f"MODEM_RX {command_text!r} MODEM_TX {reply!r}", flush=True)
                os.write(master, reply.encode())
    finally:
        if proc.poll() is None:
            proc.terminate()
        proc.wait()
        os.close(slave)
        os.close(master)
    return proc.returncode


if __name__ == "__main__":
    raise SystemExit(main())
