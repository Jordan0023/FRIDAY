#!/usr/bin/env python3
"""Build and run a full-system MIPS EW1200 stock-init boot attempt."""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
FIRMWARE = (
    ROOT
    / "known_firmware/firmware/OpenWrt_AFOUNDRY_EW1200/"
    "openwrt-25.12.5-ramips-mt7621-afoundry_ew1200-squashfs-sysupgrade.bin"
)
SQUASHFS_OFFSET = 3_321_168
INIT = (
    ROOT
    / "known_firmware/emulation/OpenWrt_AFOUNDRY_EW1200/"
    "full_system_stock_init"
)
LAB = (
    ROOT
    / "known_firmware/emulation/OpenWrt_AFOUNDRY_EW1200/"
    "full-system-stock-init-lab"
)
STAGING = Path("/tmp/friday-ew1200-full-system-root")
KERNEL = Path("/tmp/rax9-vmlinuz-6.1.0-50-4kc-malta")
MODULE_ROOT = Path(
    "/tmp/rax9-debian-malta-initrd/lib/modules/6.1.0-50-4kc-malta"
)
INITRAMFS = LAB / "ew1200-stock-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HOST_PORT = 28_084


def build() -> None:
    required = [
        FIRMWARE,
        INIT,
        KERNEL,
        MODULE_ROOT / "kernel/drivers/net/mii.ko",
        MODULE_ROOT / "kernel/drivers/net/ethernet/amd/pcnet32.ko",
    ]
    missing = [str(path) for path in required if not path.exists()]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))

    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    extracted = subprocess.run([
        "unsquashfs",
        "-o",
        str(SQUASHFS_OFFSET),
        "-d",
        str(STAGING),
        str(FIRMWARE),
    ], text=True)
    if extracted.returncode not in (0, 2):
        raise SystemExit(f"unsquashfs failed with {extracted.returncode}")
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)

    target_modules = STAGING / "lib/modules/6.1.0-50-4kc-malta"
    target_modules.mkdir(parents=True, exist_ok=True)
    shutil.copy2(
        MODULE_ROOT / "kernel/drivers/net/mii.ko",
        target_modules / "mii.ko",
    )
    shutil.copy2(
        MODULE_ROOT / "kernel/drivers/net/ethernet/amd/pcnet32.ko",
        target_modules / "pcnet32.ko",
    )
    for relative in (
        "proc", "sys", "dev", "dev/pts", "run", "tmp", "var/run",
        "var/log", "var/tmp", "var/state",
    ):
        (STAGING / relative).mkdir(parents=True, exist_ok=True)

    command = (
        f"cd '{STAGING}' && find . -print0 | "
        f"cpio --null -o --format=newc 2>/dev/null | "
        f"gzip -1 > '{INITRAMFS}'"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS}")


def stop() -> None:
    if not PIDFILE.exists():
        return
    try:
        pid = int(PIDFILE.read_text().strip())
        cmdline = Path(f"/proc/{pid}/cmdline")
        if cmdline.exists() and b"qemu-system-mipsel" in cmdline.read_bytes():
            os.kill(pid, 15)
            for _ in range(30):
                if not cmdline.exists():
                    break
                time.sleep(0.1)
    except (ValueError, ProcessLookupError, PermissionError):
        pass
    PIDFILE.unlink(missing_ok=True)


def start() -> None:
    if not INITRAMFS.is_file():
        raise SystemExit("build the initramfs first")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    command = [
        "qemu-system-mipsel",
        "-M", "malta",
        "-cpu", "24Kf",
        "-m", "512M",
        "-kernel", str(KERNEL),
        "-initrd", str(INITRAMFS),
        "-append", "console=ttyS0 rdinit=/init panic=-1",
        "-display", "none",
        "-monitor", "none",
        "-serial", f"file:{SERIAL}",
        "-netdev",
        (
            "user,id=lan,restrict=on,"
            f"hostfwd=tcp:127.0.0.1:{HOST_PORT}-:80"
        ),
        "-device", "pcnet,netdev=lan",
        "-no-reboot",
    ]
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(
            command,
            stdout=output,
            stderr=subprocess.STDOUT,
            start_new_session=True,
        )
    PIDFILE.write_text(f"{process.pid}\n")
    print(
        f"qemu_pid={process.pid} network=user,restrict=on "
        f"http=127.0.0.1:{HOST_PORT}->guest:80"
    )


def status() -> None:
    if SERIAL.exists():
        print("\n".join(SERIAL.read_text(errors="replace").splitlines()[-120:]))


def wait(timeout: int = 180) -> None:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "Please press Enter to activate this console" in text:
            print("stock_init_console=ready")
            return
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic; inspect serial.log")
        time.sleep(0.5)
    raise SystemExit("timed out waiting for stock init; inspect serial.log")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action", choices=("build", "start", "wait", "run", "status", "stop")
    )
    args = parser.parse_args()
    if args.action in ("build", "run"):
        build()
    if args.action in ("start", "run"):
        start()
    if args.action in ("wait", "run"):
        wait()
    if args.action == "status":
        status()
    if args.action == "stop":
        stop()


if __name__ == "__main__":
    main()
