#!/usr/bin/env python3
"""Run the isolated IPP lab against the RAXE300 V1.0.9.82 rootfs."""

from __future__ import annotations

import sys
import time
from pathlib import Path

import emulate_rax42v2_ippd_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAXE300/ippd-full-system-lab"

lab.SOURCE_ROOT = (
    ROOT / "known_firmware/extracted/08e53e0924044be5/rootfs"
)
lab.SUPERVISOR_INIT = (
    ROOT / "known_firmware/emulation/RAXE290/full_system_ippd_production_init"
)
lab.CMS_HELPER = ROOT / "known_firmware/emulation/RAXE290/cms_start_ippd.c"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-raxe300-ippd-full-system-root")
lab.INITRAMFS = LAB / "raxe300-ippd-rootfs.cpio.gz"
lab.SERIAL = LAB / "ippd-serial.log"
lab.QEMU_LOG = LAB / "ippd-qemu.log"
lab.PIDFILE = LAB / "ippd-qemu.pid"


def qemu_command() -> list[str]:
    """Keep the guest isolated and expose only IPP on loopback."""
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
        "user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:39633-:631",
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]


lab.qemu_command = qemu_command


def wait_ready(timeout: float = 120) -> str:
    """Wait for the production-style supervisor to expose IPP."""
    deadline = time.monotonic() + timeout
    marker = "FRIDAY_RAXE290_IPPD_PRODUCTION_READY=1"
    while time.monotonic() < deadline:
        content = lab.SERIAL.read_text(errors="replace") if lab.SERIAL.exists() else ""
        if marker in content:
            return content
        if "Kernel panic" in content:
            raise RuntimeError("RAXE300 IPP guest kernel panic; inspect serial log")
        time.sleep(0.5)
    raise TimeoutError("RAXE300 IPP guest did not become ready")


lab.wait_ready = wait_ready


if __name__ == "__main__":
    sys.exit(lab.main())
