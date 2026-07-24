#!/usr/bin/env python3
"""Run the isolated IPP lab against the RAXE290 V1.0.9.82 rootfs."""

from __future__ import annotations

import os
import sys
from pathlib import Path

import emulate_rax42v2_ippd_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAXE290/ippd-full-system-lab"

# The UPnP builder extracts the same genuine firmware image to this directory.
lab.SOURCE_ROOT = Path("/tmp/friday-raxe290-squashfs-root")
lab.CMS_HELPER = (
    ROOT / "known_firmware/emulation/RAXE290/cms_start_ippd.c"
)
if os.environ.get("RAXE290_IPPD_PRODUCTION") != "1":
    lab.SUPERVISOR_INIT = lab.INIT
else:
    lab.SUPERVISOR_INIT = (
        ROOT
        / "known_firmware/emulation/RAXE290/full_system_ippd_production_init"
    )
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-raxe290-ippd-full-system-root")
lab.INITRAMFS = LAB / "raxe290-ippd-rootfs.cpio.gz"
lab.SERIAL = LAB / "ippd-serial.log"
lab.QEMU_LOG = LAB / "ippd-qemu.log"
lab.PIDFILE = LAB / "ippd-qemu.pid"


def qemu_command() -> list[str]:
    """Keep the guest isolated; the bounded probe runs inside the guest."""
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
        "user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:39632-:631",
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


lab.qemu_command = qemu_command


if __name__ == "__main__":
    sys.exit(lab.main())
