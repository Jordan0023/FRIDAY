#!/usr/bin/env python3
"""Run the isolated IPP lab against the exact RAX49S V1.1.6.38 rootfs."""

from __future__ import annotations

import sys
import os
from pathlib import Path

import emulate_rax42v2_ippd_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX49S/full-system-lab"

lab.SOURCE_ROOT = ROOT / "known_firmware/extracted/fe7d6c417177572b/manual-rootfs"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax49s-full-system-root")
lab.INITRAMFS = LAB / "rax49s-ippd-rootfs.cpio.gz"
lab.SERIAL = LAB / "ippd-serial.log"
lab.QEMU_LOG = LAB / "ippd-qemu.log"
lab.PIDFILE = LAB / "ippd-qemu.pid"
if os.environ.get("FRIDAY_DIRECT_IPPD") == "1":
    lab.SUPERVISOR_INIT = lab.INIT


def qemu_command() -> list[str]:
    """Keep the guest isolated and expose IPP only on host loopback."""
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
        "user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:25149-:631",
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


lab.qemu_command = qemu_command


if __name__ == "__main__":
    sys.exit(lab.main())
