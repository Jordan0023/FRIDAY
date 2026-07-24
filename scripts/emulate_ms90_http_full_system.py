#!/usr/bin/env python3
"""Run the isolated full-system HTTP lab against MS90 V1.0.2.38."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/MK93S/full-system-http-lab"

lab.ROOTFS = (
    ROOT
    / "known_firmware/extracted/29a423e80f1e19f0"
    / "_MS90-V1.0.2.38.zip.extracted"
    / "_MS90-V1.0.2.38_1.0.38.chk.extracted"
    / "squashfs-root"
)
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-ms90-http-full-system-root")
lab.INITRAMFS = LAB / "ms90-http-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.SECURITY_LOG = LAB / "http-security-probe.log"
lab.HOST_HTTP_PORT = 25_093
lab.HOST_HTTPS_PORT = 0
lab.GUEST_HTTP_PORT = 443


def foreground() -> int:
    command = [
        str(lab.QEMU),
        "-M", "virt",
        "-cpu", "cortex-a15",
        "-m", "1024M",
        "-kernel", str(lab.KERNEL),
        "-initrd", str(lab.INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic",
        "-monitor", "none",
        "-serial", f"file:{lab.SERIAL}",
        "-netdev",
        (
            "user,id=lan,restrict=on,"
            f"hostfwd=tcp:127.0.0.1:{lab.HOST_HTTP_PORT}-:443"
        ),
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]
    lab.SERIAL.unlink(missing_ok=True)
    lab.QEMU_LOG.unlink(missing_ok=True)
    print("qemu_foreground=yes network=user,restrict=on", flush=True)
    return subprocess.run(command).returncode


if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "foreground":
        sys.exit(foreground())
    sys.exit(lab.main())
