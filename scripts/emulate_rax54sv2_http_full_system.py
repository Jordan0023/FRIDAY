#!/usr/bin/env python3
"""Run the isolated HTTP lab against RAX54Sv2 V1.1.6.38."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX54SV2/full-system-http-lab"

lab.ROOTFS = ROOT / "known_firmware/extracted/c9b1ed79f8f766b5/manual-rootfs"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax54sv2-http-full-system-root")
lab.INITRAMFS = LAB / "rax54sv2-http-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.HOST_HTTP_PORT = 25_082
lab.HOST_HTTPS_PORT = 25_156


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
            f"hostfwd=tcp:127.0.0.1:{lab.HOST_HTTP_PORT}-:80,"
            f"hostfwd=tcp:127.0.0.1:{lab.HOST_HTTPS_PORT}-:9443"
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
