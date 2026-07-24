#!/usr/bin/env python3
"""Build and run an isolated full-system RAX30 UPnP analysis lab."""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
import time
from pathlib import Path

import emulate_rax30_soap_full_system as base


ROOT = Path(__file__).resolve().parents[1]
INIT = ROOT / "known_firmware/emulation/RAX30/full_system_upnp_init"
SSDP_GUEST_PROBE = ROOT / "known_firmware/emulation/RAX30/rax30_ssdp_guest_probe.c"
LAB = ROOT / "known_firmware/emulation/RAX30/full-system-lab"
INITRAMFS = LAB / "rax30-upnp-rootfs.cpio.gz"
SERIAL = LAB / "upnp-serial.log"
QEMU_LOG = LAB / "upnp-qemu.log"
PIDFILE = LAB / "upnp-qemu.pid"
SSDP_HOST_PORT = 21_900
HTTP_HOST_PORT = 26_688
WAN_HTTP_HOST_PORT = 27_688
EXTRA_SHIM_DEFINES: list[str] = []


def build() -> None:
    base.build()
    shutil.copy2(INIT, base.STAGING / "init")
    os.chmod(base.STAGING / "init", 0o755)
    linker = base.find_arm_linker()
    subprocess.run(
        [
            "clang", "--target=arm-linux-gnueabi", "-march=armv7-a",
            "-fPIC", "-shared", "-nostdlib", f"-fuse-ld={linker}",
            "-DFRIDAY_DISABLE_STRCPY",
            *EXTRA_SHIM_DEFINES,
            "-Wl,-soname,rax30_emulation_shim.so",
            "-o", str(base.STAGING / "lib/rax30_emulation_shim.so"),
            str(base.SHIM),
        ],
        check=True,
    )
    subprocess.run(
        [
            "clang", "--target=arm-linux-gnueabi", "-march=armv7-a",
            "-fno-stack-protector", "-nostdlib", "-static",
            f"-fuse-ld={linker}", "-Wl,-e,_start",
            "-o", str(base.STAGING / "bin/ssdp_guest_probe"),
            str(SSDP_GUEST_PROBE),
        ],
        check=True,
    )
    command = (
        f"cd {base.shell_quote(str(base.STAGING))} && "
        "find . -print0 | cpio --null -o --format=newc 2>/dev/null | "
        f"gzip -1 > {base.shell_quote(str(INITRAMFS))}"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS} sha256={base.sha256(INITRAMFS)}")


def stop() -> None:
    if not PIDFILE.exists():
        return
    try:
        pid = int(PIDFILE.read_text().strip())
        cmdline = Path(f"/proc/{pid}/cmdline")
        if cmdline.exists() and b"qemu-system-arm" in cmdline.read_bytes():
            os.kill(pid, 15)
            for _ in range(20):
                if not cmdline.exists():
                    break
                time.sleep(0.1)
    except (ValueError, ProcessLookupError, PermissionError):
        pass
    PIDFILE.unlink(missing_ok=True)


def start() -> None:
    if not INITRAMFS.is_file():
        raise SystemExit(f"missing initramfs; run build first: {INITRAMFS}")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    command = qemu_command()
    with QEMU_LOG.open("wb") as qemu_log:
        process = subprocess.Popen(command, stdout=qemu_log, stderr=subprocess.STDOUT)
    PIDFILE.write_text(f"{process.pid}\n")
    print(
        f"qemu_pid={process.pid} network=user,restrict=on "
        f"udp=127.0.0.1:{SSDP_HOST_PORT}->guest:1900 "
        f"tcp=127.0.0.1:{HTTP_HOST_PORT}->guest:56688"
    )


def qemu_command() -> list[str]:
    return [
        str(base.QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(base.KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev",
        (
            "user,id=lan,restrict=on,"
            f"hostfwd=udp:127.0.0.1:{SSDP_HOST_PORT}-10.0.2.15:1900,"
            f"hostfwd=tcp:127.0.0.1:{HTTP_HOST_PORT}-10.0.2.15:56688"
        ),
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
        "-netdev",
        (
            "user,id=wan,restrict=on,net=198.51.100.0/24,"
            "host=198.51.100.2,"
            f"hostfwd=tcp:127.0.0.1:{WAN_HTTP_HOST_PORT}-198.51.100.15:56688"
        ),
        "-device", "virtio-net-device,netdev=wan",
    ]


def foreground() -> None:
    if not INITRAMFS.is_file():
        raise SystemExit(f"missing initramfs; run build first: {INITRAMFS}")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    PIDFILE.write_text(f"{os.getpid()}\n")
    print(
        f"qemu_foreground=yes network=user,restrict=on "
        f"udp=127.0.0.1:{SSDP_HOST_PORT}->guest:1900 "
        f"lan_tcp=127.0.0.1:{HTTP_HOST_PORT}->guest:56688 "
        f"wan_tcp=127.0.0.1:{WAN_HTTP_HOST_PORT}->guest:56688",
        flush=True,
    )
    result = subprocess.run(qemu_command())
    raise SystemExit(result.returncode)


def wait_ready(timeout: float = 120) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        content = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_RAX30_UPNP_READY=1" in content:
            return content
        if "Kernel panic" in content:
            raise RuntimeError("guest kernel panic; inspect upnp-serial.log")
        time.sleep(0.5)
    raise TimeoutError("UPnP guest did not become ready; inspect upnp-serial.log")


def status() -> None:
    running = False
    if PIDFILE.exists():
        try:
            pid = int(PIDFILE.read_text().strip())
            cmdline = Path(f"/proc/{pid}/cmdline")
            running = cmdline.exists() and b"qemu-system-arm" in cmdline.read_bytes()
        except (ValueError, PermissionError):
            pass
    print(f"qemu_running={'yes' if running else 'no'}")
    if SERIAL.exists():
        print("\n".join(SERIAL.read_text(errors="replace").splitlines()[-60:]))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=("build", "start", "foreground", "run", "wait", "status", "stop"),
    )
    args = parser.parse_args()
    if args.action in ("build", "run"):
        build()
    if args.action in ("start", "run"):
        start()
    if args.action == "foreground":
        foreground()
    if args.action in ("wait", "run"):
        content = wait_ready()
        print("\n".join(content.splitlines()[-60:]))
    if args.action == "status":
        status()
    if args.action == "stop":
        stop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
