#!/usr/bin/env python3
"""Run a dual-interface isolated WAN HTTP lab for MR90 V1.0.2.46."""

from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/MK93S/MR90-V1.0.2.46-wan-http-lab"

lab.ROOTFS = Path(
    "/tmp/mr90-10246/extracted/"
    "_MR90-V1.0.2.46_1.0.42.chk.extracted/squashfs-root"
)
lab.INIT = ROOT / "known_firmware/emulation/MK93S/mr90_wan_http_init"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-mr90-10246-wan-http-root")
lab.INITRAMFS = LAB / "mr90-10246-wan-http-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.SECURITY_LOG = LAB / "http-security-probe.log"
lab.HOST_HTTP_PORT = 25_095
lab.HOST_HTTPS_PORT = 0
lab.GUEST_HTTP_PORT = 8443


def foreground() -> int:
    command = [
        str(lab.QEMU),
        "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(lab.KERNEL), "-initrd", str(lab.INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{lab.SERIAL}",
        "-netdev",
        (
            "user,id=wan,restrict=on,net=192.0.2.0/24,"
            f"hostfwd=tcp:127.0.0.1:{lab.HOST_HTTP_PORT}-:8443"
        ),
        "-device", "virtio-net-device,netdev=wan",
        "-netdev",
        (
            "user,id=lan,restrict=on,net=10.0.2.0/24,"
            "hostfwd=tcp:127.0.0.1:25096-:9443"
        ),
        "-device", "virtio-net-device,netdev=lan",
        "-no-reboot",
    ]
    lab.SERIAL.unlink(missing_ok=True)
    lab.QEMU_LOG.unlink(missing_ok=True)
    print("qemu_foreground=yes dual_nic=yes wan_loopback_only=yes", flush=True)
    return subprocess.run(command).returncode


if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "foreground":
        sys.exit(foreground())
    # The shared builder requires executable init.
    os.chmod(lab.INIT, 0o755)
    sys.exit(lab.main())
