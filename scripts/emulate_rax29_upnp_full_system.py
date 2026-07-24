#!/usr/bin/env python3
"""Run the RAX30-derived isolated UPnP lab with genuine RAX29 firmware."""

from __future__ import annotations

import sys
from pathlib import Path

import emulate_rax30_soap_full_system as base
import emulate_rax30_upnp_full_system as upnp


ROOT = Path(__file__).resolve().parents[1]
RAX29 = ROOT / "known_firmware/extracted/a5a6fe34b78d4f52"
LAB = ROOT / "known_firmware/emulation/RAX29/full-system-lab"

base.IMAGE = (
    RAX29
    / "_RAX29-V1.0.14.108.zip.extracted/RAX29-V1.0.14.108_1.img"
)
base.LAB = LAB
base.STAGING = Path("/tmp/friday-rax29-full-system-root")
base.EXTRACTED = Path("/tmp/friday-rax29-squashfs-root")
base.INITRAMFS = LAB / "rax29-rootfs.cpio.gz"
base.SERIAL = LAB / "base-serial.log"
base.QEMU_LOG = LAB / "base-qemu.log"
base.PIDFILE = LAB / "base-qemu.pid"

upnp.LAB = LAB
upnp.INITRAMFS = LAB / "rax29-upnp-rootfs.cpio.gz"
upnp.SERIAL = LAB / "upnp-serial.log"
upnp.QEMU_LOG = LAB / "upnp-qemu.log"
upnp.PIDFILE = LAB / "upnp-qemu.pid"
upnp.SSDP_HOST_PORT = 21_929
upnp.HTTP_HOST_PORT = 26_729
upnp.EXTRA_SHIM_DEFINES = ["-DFRIDAY_TRACE_FATAL"]


def rax29_qemu_command() -> list[str]:
    """Use one restricted LAN NIC so the positive control is unambiguous."""
    return [
        str(base.QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(base.KERNEL), "-initrd", str(upnp.INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{upnp.SERIAL}",
        "-netdev",
        (
            "user,id=lan,restrict=on,"
            f"hostfwd=udp:127.0.0.1:{upnp.SSDP_HOST_PORT}-:1900,"
            f"hostfwd=tcp:127.0.0.1:{upnp.HTTP_HOST_PORT}-:56688"
        ),
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]


upnp.qemu_command = rax29_qemu_command


if __name__ == "__main__":
    sys.exit(upnp.main())
