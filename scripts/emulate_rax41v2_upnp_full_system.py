#!/usr/bin/env python3
"""Build the isolated genuine-daemon RAX41v2 V1.1.6.38 UPnP lab."""

from __future__ import annotations

from pathlib import Path

import emulate_rax54s_http_full_system as lab


ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "known_firmware/emulation/RAX41V2/full-system-upnp-lab"

lab.ROOTFS = ROOT / "known_firmware/extracted/c52efe4a322909d7/manual-rootfs"
lab.INIT = ROOT / "known_firmware/emulation/RAX41V2/full_system_upnp_init"
lab.LAB = LAB
lab.STAGING = Path("/tmp/friday-rax41v2-upnp-root")
lab.INITRAMFS = LAB / "rax41v2-upnp-rootfs.cpio.gz"
lab.SERIAL = LAB / "serial.log"
lab.QEMU_LOG = LAB / "qemu.log"
lab.PIDFILE = LAB / "qemu.pid"
lab.HOST_HTTP_PORT = 25_341
lab.HOST_HTTPS_PORT = 25_441
lab.GUEST_HTTP_PORT = 56_688
lab.GUEST_MEMORY_MB = 768


if __name__ == "__main__":
    lab.main()
