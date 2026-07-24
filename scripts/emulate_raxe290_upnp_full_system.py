#!/usr/bin/env python3
"""Run the RAX30-derived isolated UPnP lab with genuine RAXE290 firmware."""

from __future__ import annotations

import os
import sys
from pathlib import Path

import emulate_rax30_soap_full_system as base
import emulate_rax30_upnp_full_system as upnp


ROOT = Path(__file__).resolve().parents[1]
RAXE290 = ROOT / "known_firmware/extracted/3de38411e3c0353b"
LAB = ROOT / "known_firmware/emulation/RAXE290/full-system-lab"

base.IMAGE = (
    RAXE290
    / "_RAXE290-V1.0.9.82.zip.extracted/RAXE290-V1.0.9.82_1.img"
)
base.SQUASHFS_OFFSET = 9_344_374
base.LAB = LAB
base.STAGING = Path("/tmp/friday-raxe290-full-system-root")
base.EXTRACTED = Path("/tmp/friday-raxe290-squashfs-root")
base.INITRAMFS = LAB / "raxe290-rootfs.cpio.gz"
base.SERIAL = LAB / "base-serial.log"
base.QEMU_LOG = LAB / "base-qemu.log"
base.PIDFILE = LAB / "base-qemu.pid"

upnp.LAB = LAB
upnp.INIT = ROOT / "known_firmware/emulation/RAXE290/full_system_upnp_init"
upnp.INITRAMFS = LAB / "raxe290-upnp-rootfs.cpio.gz"
upnp.SERIAL = LAB / "upnp-serial.log"
upnp.QEMU_LOG = LAB / "upnp-qemu.log"
upnp.PIDFILE = LAB / "upnp-qemu.pid"
upnp.SSDP_HOST_PORT = 39_121
upnp.HTTP_HOST_PORT = 39_122
upnp.WAN_HTTP_HOST_PORT = 39_123
upnp.EXTRA_SHIM_DEFINES = ["-DFRIDAY_TRACE_FATAL"]

_base_qemu_command = upnp.qemu_command


def raxe290_qemu_command() -> list[str]:
    command = _base_qemu_command()
    mode = os.environ.get("RAXE290_UPNP_PROBE_MODE", "")
    if mode in ("candidate", "control"):
        append_index = command.index("-append") + 1
        command[append_index] += f" friday_probe={mode}"
    return command


upnp.qemu_command = raxe290_qemu_command


if __name__ == "__main__":
    sys.exit(upnp.main())
