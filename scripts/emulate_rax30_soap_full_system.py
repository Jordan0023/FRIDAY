#!/usr/bin/env python3
"""Build and run an isolated full-system RAX30 SOAP analysis lab."""

from __future__ import annotations

import argparse
import hashlib
import os
import re
import shutil
import socket
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
IMAGE = (
    ROOT
    / "known_firmware/extracted/6e7f95ab08e7b702/"
    "_RAX30-V1.0.14.108.zip.extracted/RAX30-V1.0.14.108_1.img"
)
SQUASHFS_OFFSET = 7_850_958
INIT = ROOT / "known_firmware/emulation/RAX30/full_system_init"
SHIM = ROOT / "known_firmware/emulation/RAX30/rax30_emulation_shim.c"
LAB = ROOT / "known_firmware/emulation/RAX30/full-system-lab"
STAGING = Path("/tmp/friday-rax30-full-system-root")
EXTRACTED = Path("/tmp/friday-rax30-squashfs-root")
KERNEL = Path("/tmp/ad7200-armmp-vmlinuz")
KMODS = Path("/tmp/ad7200-kmods/lib/modules")
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm")
INITRAMFS = LAB / "rax30-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HOST_PORT = 25_130
SECURITY_PROBE = ROOT / "scripts/probe_rax30_soap_security.py"
MATRIX_PROBE = ROOT / "scripts/audit_rax30_soap_matrix.py"
DOS_STRESS = ROOT / "scripts/stress_rax30_soap_dos.py"


def find_arm_linker() -> Path:
    candidates = (
        shutil.which("ld.lld"),
        shutil.which("ld.lld-14"),
        "/tmp/lld14-local/usr/lib/llvm-14/bin/ld.lld",
    )
    for candidate in candidates:
        if candidate and Path(candidate).is_file():
            return Path(candidate)
    raise SystemExit(
        "an ARM-capable LLVM linker is required (install lld-14 or extract it "
        "under /tmp/lld14-local)"
    )


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def shell_quote(value: str) -> str:
    return "'" + value.replace("'", "'\"'\"'") + "'"


def build() -> None:
    required = (IMAGE, INIT, SHIM, KERNEL, KMODS, QEMU)
    missing = [str(path) for path in required if not path.exists()]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(EXTRACTED, ignore_errors=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    run([
        "unsquashfs", "-o", str(SQUASHFS_OFFSET), "-d", str(EXTRACTED), str(IMAGE)
    ])
    shutil.copytree(EXTRACTED, STAGING, symlinks=True)
    shutil.copytree(KMODS, STAGING / "lib/modules", dirs_exist_ok=True)
    entity_file = STAGING / "etc/cms_entity_info.d/eid_bcm_base.txt"
    entity_text = entity_file.read_text()
    entity_text, replacements = re.subn(
        r"\nBEGIN\n\s+eid\s+= EID_SSK\n.*?\nEND\n",
        "\n",
        entity_text,
        count=1,
        flags=re.DOTALL,
    )
    if replacements != 1:
        raise SystemExit(f"expected SSK entity block not found in {entity_file}")
    os.chmod(entity_file, entity_file.stat().st_mode | 0o200)
    entity_file.write_text(entity_text)
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    linker = find_arm_linker()
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a",
        "-fPIC", "-shared", "-nostdlib", f"-fuse-ld={linker}",
        "-Wl,-soname,rax30_emulation_shim.so",
        "-o", str(STAGING / "lib/rax30_emulation_shim.so"), str(SHIM),
    ])
    for relative in ("proc", "sys", "dev", "run", "tmp", "var/run", "var/log", "var/tmp"):
        (STAGING / relative).mkdir(parents=True, exist_ok=True)
    command = (
        f"cd {shell_quote(str(STAGING))} && "
        f"find . -print0 | cpio --null -o --format=newc 2>/dev/null | "
        f"gzip -1 > {shell_quote(str(INITRAMFS))}"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS} sha256={sha256(INITRAMFS)}")


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
    command = [
        str(QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev", f"user,id=lan,restrict=on,hostfwd=tcp:127.0.0.1:{HOST_PORT}-:5000",
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]
    with QEMU_LOG.open("wb") as qemu_log:
        process = subprocess.Popen(command, stdout=qemu_log, stderr=subprocess.STDOUT)
    PIDFILE.write_text(f"{process.pid}\n")
    print(
        f"qemu_pid={process.pid} network=user,restrict=on "
        f"tcp=127.0.0.1:{HOST_PORT}->guest:5000"
    )


def wait_for(marker: str, timeout: float) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        content = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if marker in content:
            return content
        if "Kernel panic" in content:
            raise RuntimeError("guest kernel panic; inspect serial.log")
        if PIDFILE.exists():
            try:
                pid = int(PIDFILE.read_text().strip())
                cmdline = Path(f"/proc/{pid}/cmdline")
                if not cmdline.exists() or b"qemu-system-arm" not in cmdline.read_bytes():
                    qemu_error = QEMU_LOG.read_text(errors="replace") if QEMU_LOG.exists() else ""
                    raise RuntimeError(f"QEMU exited before guest readiness:\n{qemu_error}")
            except ValueError as error:
                raise RuntimeError("invalid QEMU pidfile") from error
        time.sleep(0.5)
    raise TimeoutError(f"guest did not emit {marker!r}; inspect {SERIAL}")


def probe() -> None:
    content = wait_for("FRIDAY_RAX30_READY=1", 120)
    if "SMD_SOCKET=ready" not in content or "SOAP_ALIVE=yes" not in content:
        raise SystemExit(content)
    body = (
        '<?xml version="1.0"?>'
        '<soap-env:Envelope xmlns:soap-env="http://schemas.xmlsoap.org/soap/envelope/">'
        "<soap-env:Body/></soap-env:Envelope>"
    ).encode()
    request = (
        b"POST /soap/server_sa HTTP/1.1\r\n"
        b"Host: 10.0.2.15:5000\r\n"
        b'SOAPAction: "urn:NETGEAR-ROUTER:service:DeviceInfo:1#GetInfo"\r\n'
        b"Content-Type: text/xml\r\n"
        + f"Content-Length: {len(body)}\r\n".encode()
        + b"Connection: close\r\n\r\n"
        + body
    )
    with socket.create_connection(("127.0.0.1", HOST_PORT), timeout=5) as client:
        client.sendall(request)
        client.shutdown(socket.SHUT_WR)
        response = bytearray()
        while True:
            chunk = client.recv(4096)
            if not chunk:
                break
            response.extend(chunk)
    status = bytes(response).splitlines()[0].decode(errors="replace") if response else "no response"
    print(f"baseline_status={status}")
    print(f"baseline_bytes={len(response)}")
    if not response.startswith(b"HTTP/1.1"):
        raise SystemExit("SOAP listener accepted the connection but returned no HTTP response")


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
        print("\n".join(SERIAL.read_text(errors="replace").splitlines()[-30:]))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=(
            "build", "start", "probe", "test", "run", "security-test",
            "matrix-test", "full-audit", "status", "stop",
        ),
    )
    args = parser.parse_args()
    if args.action in ("build", "run"):
        build()
    if args.action in ("start", "test", "run", "security-test", "matrix-test", "full-audit"):
        start()
    if args.action in ("probe", "test", "run"):
        try:
            probe()
        finally:
            if args.action in ("test", "run"):
                stop()
    if args.action == "status":
        status()
    if args.action == "security-test":
        try:
            probe()
            run([sys.executable, str(SECURITY_PROBE)])
        finally:
            stop()
    if args.action == "matrix-test":
        try:
            probe()
            run([sys.executable, str(MATRIX_PROBE)])
        finally:
            stop()
    if args.action == "full-audit":
        try:
            probe()
            run([sys.executable, str(SECURITY_PROBE)])
            run([sys.executable, str(MATRIX_PROBE)])
            run([sys.executable, str(DOS_STRESS)])
        finally:
            stop()
    if args.action == "stop":
        stop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
