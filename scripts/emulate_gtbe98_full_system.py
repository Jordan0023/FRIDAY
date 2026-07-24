#!/usr/bin/env python3
"""Build and boot a network-isolated GT-BE98 Pro stock-init system lab."""

from __future__ import annotations

import os
import shutil
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = next(
    (ROOT / "known_firmware/extracted/e9c3bdc196cdc005").glob(
        "**/squashfs-root/usr/sbin/wl_server_socket"
    )
).parents[2]
LAB = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro/full-system-lab"
STAGE1 = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro/full_system_stock_init"
BOOT_INIT = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro/boot_init"
PROC_COMPAT = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro/proc_nvram_compat.so"
STAGING = Path("/tmp/friday-gtbe98-system-root")
BOOT_STAGING = Path("/tmp/friday-gtbe98-boot-root")
KVER = "5.15.0-186-generic"
KTREE = Path("/tmp/friday-arm64-kernel")
KERNEL = KTREE / f"boot/vmlinuz-{KVER}"
MODULES = KTREE / f"lib/modules/{KVER}"
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-aarch64")
BUSYBOX = Path("/tmp/friday-arm64-busybox/bin/busybox")
DISK = LAB / "gtbe98-stock-root.ext4"
INITRD = LAB / "gtbe98-boot.cpio.gz"
SERIAL = LAB / "serial.log"


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess:
    return subprocess.run(command, check=True, **kwargs)


def build() -> None:
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    for name in ("proc", "sys", "dev", "run", "tmp"):
        path = STAGING / name
        if path.is_symlink():
            path.unlink()
        path.mkdir(parents=True, exist_ok=True)
    shutil.copytree(MODULES, STAGING / f"lib/modules/{KVER}", symlinks=True)
    (STAGING / "greenhouse").mkdir()
    shutil.copy2(BUSYBOX, STAGING / "greenhouse/busybox")
    shutil.copy2(STAGE1, STAGING / "init")
    shutil.copy2(PROC_COMPAT, STAGING / "lib/libproc-nvram-compat.so")
    os.chmod(STAGING / "init", 0o755)
    DISK.unlink(missing_ok=True)
    run(["truncate", "-s", "1600M", str(DISK)])
    run(["mkfs.ext4", "-q", "-F", "-d", str(STAGING), str(DISK)])

    shutil.rmtree(BOOT_STAGING, ignore_errors=True)
    for name in ("bin", "dev", "proc", "sys", "newroot"):
        (BOOT_STAGING / name).mkdir(parents=True, exist_ok=True)
    shutil.copy2(BUSYBOX, BOOT_STAGING / "bin/busybox")
    shutil.copy2(BOOT_INIT, BOOT_STAGING / "init")
    shutil.copy2(
        MODULES / "kernel/drivers/block/virtio_blk.ko",
        BOOT_STAGING / "virtio_blk.ko",
    )
    command = (
        f"cd '{BOOT_STAGING}' && find . -print0 | cpio --null -o "
        f"--format=newc 2>/dev/null | gzip -1 > '{INITRD}'"
    )
    run(["/bin/sh", "-c", command])


def command() -> list[str]:
    return [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a72", "-smp", "2",
        "-m", "2048M", "-kernel", str(KERNEL), "-initrd", str(INITRD),
        "-drive", f"file={DISK},if=none,format=raw,id=root",
        "-device", "virtio-blk-device,drive=root",
        "-append", "console=ttyAMA0 root=/dev/vda rw rootwait init=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev", "user,id=wan,restrict=on,net=192.0.2.0/24",
        "-device", "virtio-net-device,netdev=wan,mac=52:54:00:98:00:01",
        "-netdev", "user,id=lan,restrict=on,net=10.0.2.0/24",
        "-device", "virtio-net-device,netdev=lan,mac=52:54:00:98:00:02",
        "-no-reboot",
    ]


def boot(seconds: int = 90) -> int:
    SERIAL.unlink(missing_ok=True)
    try:
        result = subprocess.run(command(), timeout=seconds)
        return result.returncode
    except subprocess.TimeoutExpired:
        return 124


def main() -> int:
    if len(sys.argv) != 2 or sys.argv[1] not in {"build", "boot", "run"}:
        print(f"usage: {sys.argv[0]} build|boot|run")
        return 2
    if sys.argv[1] in {"build", "run"}:
        build()
    if sys.argv[1] in {"boot", "run"}:
        code = boot()
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        print(text[-12000:])
        print(f"wl_server_socket_seen={'wl_server_socket' in text}")
        print(f"tcp_8000_seen={':8000' in text}")
        return 0 if code in {0, 124} else code
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
