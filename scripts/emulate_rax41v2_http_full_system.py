#!/usr/bin/env python3
"""Run the isolated HTTP lab against the exact RAX41v2 V1.1.6.38 rootfs."""

from __future__ import annotations

from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX41V2/full-system-http-lab"

lab.ROOTFS = ROOT / "known_firmware/extracted/c52efe4a322909d7/manual-rootfs"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax41v2-http-root")
lab.INITRAMFS = LAB / "rax41v2-http-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.HOST_HTTP_PORT = 25_141
lab.HOST_HTTPS_PORT = 25_241
lab.GUEST_MEMORY_MB = 768


if __name__ == "__main__":
    lab.main()
