#!/usr/bin/env python3
"""Test the genuine MK93S/MS90 V1.0.2.38 IPP supervisor activation path."""

from __future__ import annotations

import sys
from pathlib import Path

import emulate_rax42v2_ippd_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/MK93S/ippd-production-lab"

lab.SOURCE_ROOT = (
    ROOT
    / "known_firmware/extracted/29a423e80f1e19f0/"
    "_MS90-V1.0.2.38.zip.extracted/"
    "_MS90-V1.0.2.38_1.0.38.chk.extracted/squashfs-root"
)
lab.LAB = LAB
lab.CMS_HELPER = ROOT / "known_firmware/emulation/RAXE290/cms_start_ippd.c"
lab.STAGING = Path("/tmp/friday-ms90-ippd-production-root")
lab.INITRAMFS = LAB / "ms90-ippd-production-rootfs.cpio.gz"
lab.SERIAL = LAB / "ippd-serial.log"
lab.QEMU_LOG = LAB / "ippd-qemu.log"
lab.PIDFILE = LAB / "ippd-qemu.pid"


def qemu_command() -> list[str]:
    return [
        str(lab.base.QEMU),
        "-M", "virt",
        "-cpu", "cortex-a15",
        "-m", "1024M",
        "-kernel", str(lab.base.KERNEL),
        "-initrd", str(lab.INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic",
        "-monitor", "none",
        "-serial", f"file:{lab.SERIAL}",
        "-netdev",
        "user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:25190-:631",
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


lab.qemu_command = qemu_command


if __name__ == "__main__":
    sys.exit(lab.main())
