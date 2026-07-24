#!/usr/bin/env python3
"""Build and run an isolated full-system RAX54S HTTP analysis lab."""

from __future__ import annotations

import argparse
import os
import re
import shutil
import socket
import subprocess
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/12d0be80c7dfee7f/manual-rootfs"
INIT = ROOT / "known_firmware/emulation/RAX54S/full_system_http_init"
SHIM = ROOT / "known_firmware/emulation/RAX30/rax30_emulation_shim.c"
DEVICE_SHIM = ROOT / "known_firmware/emulation/RAX54S/rax54s_device_shim.c"
LAB = ROOT / "known_firmware/emulation/RAX54S/full-system-http-lab"
STAGING = Path("/tmp/friday-rax54s-full-system-root")
KERNEL = Path("/tmp/ad7200-armmp-vmlinuz")
KMODS = Path("/tmp/ad7200-kmods/lib/modules")
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm")
INITRAMFS = LAB / "rax54s-http-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HOST_PORT = 25_154


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def linker() -> Path:
    for candidate in ("ld.lld", "ld.lld-14"):
        path = shutil.which(candidate)
        if path:
            return Path(path)
    fallback = Path("/tmp/lld14-local/usr/lib/llvm-14/bin/ld.lld")
    if fallback.is_file():
        return fallback
    raise SystemExit("ARM-capable lld is missing")


def build() -> None:
    missing = [
        str(path)
        for path in (ROOTFS, INIT, SHIM, DEVICE_SHIM, KERNEL, KMODS, QEMU)
        if not path.exists()
    ]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    shutil.copytree(KMODS, STAGING / "lib/modules", dirs_exist_ok=True)
    entity = STAGING / "etc/cms_entity_info.d/eid_bcm_base.txt"
    text = entity.read_text()
    text, count = re.subn(
        r"\nBEGIN\n\s+eid\s+= EID_SSK\n.*?\nEND\n", "\n", text, count=1, flags=re.DOTALL
    )
    if count == 1:
        os.chmod(entity, entity.stat().st_mode | 0o200)
        entity.write_text(text)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    run([
        "openssl", "req", "-x509", "-newkey", "rsa:2048", "-nodes",
        "-subj", "/CN=rax54s-lab", "-days", "2",
        "-keyout", str(STAGING / "etc/rax54s-lab.key"),
        "-out", str(STAGING / "etc/rax54s-lab.crt"),
    ], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    with (STAGING / "etc/rax54s-lab.pem").open("wb") as combined:
        combined.write((STAGING / "etc/rax54s-lab.key").read_bytes())
        combined.write((STAGING / "etc/rax54s-lab.crt").read_bytes())
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC", "-shared",
        "-nostdlib", f"-fuse-ld={linker()}", "-Wl,-soname,rax54s_emulation_shim.so",
        "-o", str(STAGING / "lib/rax54s_emulation_shim.so"), str(SHIM),
    ])
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC", "-shared",
        "-nostdlib", f"-fuse-ld={linker()}", "-Wl,-soname,rax54s_device_shim.so",
        "-o", str(STAGING / "lib/rax54s_device_shim.so"), str(DEVICE_SHIM),
    ])
    for relative in ("proc", "sys", "dev", "run", "tmp", "var/run", "var/log", "var/tmp"):
        (STAGING / relative).mkdir(parents=True, exist_ok=True)
    command = (
        f"cd '{STAGING}' && find . -print0 | cpio --null -o --format=newc "
        f"2>/dev/null | gzip -1 > '{INITRAMFS}'"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS}")


def stop() -> None:
    if PIDFILE.exists():
        try:
            pid = int(PIDFILE.read_text())
            cmdline = Path(f"/proc/{pid}/cmdline")
            if cmdline.exists() and b"qemu-system-arm" in cmdline.read_bytes():
                os.kill(pid, 15)
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
        str(QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev", f"user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:{HOST_PORT}-:9443",
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(command, stdout=output, stderr=subprocess.STDOUT)
    PIDFILE.write_text(f"{process.pid}\n")
    print(f"qemu_pid={process.pid} tcp=127.0.0.1:{HOST_PORT}->guest:9443")


def wait_ready(timeout: int = 150) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_RAX54S_HTTP_READY=1" in text:
            return text
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic")
        time.sleep(0.5)
    raise SystemExit("HTTP readiness timed out; inspect serial.log")


def probe() -> None:
    text = wait_ready()
    print("\n".join(text.splitlines()[-20:]))
    with socket.create_connection(("127.0.0.1", HOST_PORT), timeout=5) as client:
        client.sendall(b"GET / HTTP/1.1\r\nHost: routerlogin.net\r\nConnection: close\r\n\r\n")
        response = client.recv(4096)
    print(response.splitlines()[0].decode(errors="replace") if response else "no response")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", choices=("build", "start", "probe", "run", "stop", "status"))
    args = parser.parse_args()
    if args.action in ("build", "run"):
        build()
    if args.action in ("start", "run"):
        start()
    if args.action in ("probe", "run"):
        probe()
    if args.action == "stop":
        stop()
    if args.action == "status":
        print(SERIAL.read_text(errors="replace")[-5000:] if SERIAL.exists() else "no serial log")


if __name__ == "__main__":
    main()
