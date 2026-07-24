#!/usr/bin/env python3
"""Run the isolated IPP lab against the exact RAX54Sv2 V1.1.6.38 rootfs."""

from __future__ import annotations

import os
import sys
from pathlib import Path

import emulate_rax42v2_ippd_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX54SV2/full-system-lab"

lab.SOURCE_ROOT = (
    ROOT / "known_firmware/extracted/c9b1ed79f8f766b5/manual-rootfs"
)
# Direct-daemon mode is for parser impact tests. The opt-in production mode
# retains the unmodified entity metadata and asks SMD to start EID 45.
if os.environ.get("FRIDAY_RAX54SV2_PRODUCTION_IPPD") != "1":
    lab.SUPERVISOR_INIT = lab.INIT
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax54sv2-full-system-root")
lab.INITRAMFS = LAB / "rax54sv2-ippd-rootfs.cpio.gz"
lab.SERIAL = LAB / "ippd-serial.log"
lab.QEMU_LOG = LAB / "ippd-qemu.log"
lab.PIDFILE = LAB / "ippd-qemu.pid"


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
        "user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:25155-:631",
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


lab.qemu_command = qemu_command


if __name__ == "__main__":
    sys.exit(lab.main())
