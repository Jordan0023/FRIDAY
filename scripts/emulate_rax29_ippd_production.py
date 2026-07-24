#!/usr/bin/env python3
"""Test the genuine RAX29 V1.0.14.108 IPP supervisor activation path."""

from __future__ import annotations

import sys
from pathlib import Path

import emulate_rax42v2_ippd_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX29/ippd-production-lab"

lab.SOURCE_ROOT = (
    ROOT
    / "known_firmware/extracted/a5a6fe34b78d4f52/"
    "_RAX29-V1.0.14.108.zip.extracted/"
    "_RAX29-V1.0.14.108_1.img.extracted/squashfs-root"
)
lab.LAB = LAB
lab.CMS_HELPER = ROOT / "known_firmware/emulation/RAXE290/cms_start_ippd.c"
lab.STAGING = Path("/tmp/friday-rax29-ippd-production-root")
lab.INITRAMFS = LAB / "rax29-ippd-production-rootfs.cpio.gz"
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
        "user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:25129-:631",
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


lab.qemu_command = qemu_command


if __name__ == "__main__":
    sys.exit(lab.main())
