#!/usr/bin/env python3
"""Run the isolated SOAP lab with the genuine RAXE290 V1.0.9.82 daemon."""

from __future__ import annotations

import os
import sys
from pathlib import Path

import emulate_rax30_soap_full_system as base


ROOT = Path(__file__).resolve().parents[1]
RAXE290 = ROOT / "known_firmware/extracted/3de38411e3c0353b"
LAB = ROOT / "known_firmware/emulation/RAXE290/soap-full-system-lab"

base.IMAGE = RAXE290 / "_RAXE290-V1.0.9.82.zip.extracted/RAXE290-V1.0.9.82_1.img"
base.SQUASHFS_OFFSET = 9_344_374
base.INIT = ROOT / "known_firmware/emulation/RAXE290/full_system_soap_init"
base.LAB = LAB
base.STAGING = Path("/tmp/friday-raxe290-soap-full-system-root")
base.EXTRACTED = Path("/tmp/friday-raxe290-squashfs-root")
base.INITRAMFS = LAB / "raxe290-soap-rootfs.cpio.gz"
base.SERIAL = LAB / "serial.log"
base.QEMU_LOG = LAB / "qemu.log"
base.PIDFILE = LAB / "qemu.pid"
base.HOST_PORT = 25_290
base.HTTP_HOST_PORT = 25_291
base.IPP_HOST_PORT = 39_633
base.DNS_HOST_PORT = 25_390

os.environ["FRIDAY_SOAP_PORT"] = str(base.HOST_PORT)

if __name__ == "__main__":
    sys.exit(base.main())
