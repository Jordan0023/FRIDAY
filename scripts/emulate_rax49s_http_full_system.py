#!/usr/bin/env python3
"""Run the isolated HTTP lab against RAX49S V1.1.6.38."""

from __future__ import annotations

import os
import sys
from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX49S/full-system-http-lab"

lab.ROOTFS = ROOT / "known_firmware/extracted/fe7d6c417177572b/manual-rootfs"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax49s-http-full-system-root")
lab.INITRAMFS = LAB / "rax49s-http-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.SECURITY_LOG = LAB / "http-security-probe.log"
lab.HOST_HTTP_PORT = 25_049
lab.HOST_HTTPS_PORT = 25_149
lab.EXTRA_NVRAM = (
    ("http_username", "admin"),
    ("http_passwd", "FridayLab123!"),
    ("blank_state", os.environ.get("FRIDAY_BLANK_STATE", "0")),
)


if __name__ == "__main__":
    sys.exit(lab.main())
