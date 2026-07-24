#!/usr/bin/env python3
"""Run the isolated HTTP lab against the exact RAX42v2 V1.1.6.38 rootfs."""

from __future__ import annotations

import socket
import time
from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX42V2/full-system-http-lab"

lab.ROOTFS = ROOT / "known_firmware/extracted/e6f2fe38e6ad0fa0/manual-rootfs"
lab.INIT = ROOT / "known_firmware/emulation/RAX42V2/full_system_stock_init"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax42v2-http-root")
lab.INITRAMFS = LAB / "rax42v2-http-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.HOST_HTTP_PORT = 36_242
lab.HOST_HTTPS_PORT = 36_342
lab.GUEST_HTTPS_PORT = 443


def wait_ready(timeout: int = 300) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = lab.SERIAL.read_text(errors="replace") if lab.SERIAL.exists() else ""
        if "FRIDAY_RAX42V2_STOCK_HTTP_READY=1" in text:
            return text
        if "RC3_MONITOR_COMPLETE=1" in text:
            raise SystemExit("stock boot completed without a stable HTTP listener")
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic")
        time.sleep(0.5)
    raise SystemExit("stock HTTP readiness timed out; inspect serial.log")


def probe() -> None:
    text = wait_ready()
    print("\n".join(text.splitlines()[-30:]))
    for port, label in (
        (lab.HOST_HTTP_PORT, "http"),
        (lab.HOST_HTTPS_PORT, "https"),
    ):
        try:
            with socket.create_connection(("127.0.0.1", port), timeout=3) as client:
                client.sendall(
                    b"GET / HTTP/1.1\r\nHost: routerlogin.net\r\n"
                    b"Connection: close\r\n\r\n"
                )
                response = client.recv(4096)
            first = response.splitlines()[0].decode(errors="replace") if response else "no response"
        except OSError as error:
            first = f"{type(error).__name__}: {error}"
        print(f"{label}={first}")


lab.wait_ready = wait_ready
lab.probe = probe


if __name__ == "__main__":
    lab.main()
