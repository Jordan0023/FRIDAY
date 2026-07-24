#!/usr/bin/env python3
"""Build and run an isolated full-system RAX42v2 IPP analysis lab."""

from __future__ import annotations

import argparse
import hashlib
import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

import emulate_rax30_soap_full_system as base


ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = ROOT / "known_firmware/extracted/e6f2fe38e6ad0fa0/manual-rootfs"
INIT = ROOT / "known_firmware/emulation/RAX42V2/full_system_ippd_init"
SUPERVISOR_INIT = ROOT / "known_firmware/emulation/RAX42V2/full_system_ippd_supervisor_init"
CMS_HELPER = ROOT / "known_firmware/emulation/RAX42V2/cms_start_ippd.c"
PRINTERS = ROOT / "known_firmware/emulation/RAX30/ippd-printers.conf"
SHIM = ROOT / "known_firmware/emulation/RAX30/rax30_emulation_shim.c"
LAB = ROOT / "known_firmware/emulation/RAX42V2/full-system-lab"
STAGING = Path("/tmp/friday-rax42v2-full-system-root")
INITRAMFS = LAB / "rax42v2-ippd-rootfs.cpio.gz"
SERIAL = LAB / "ippd-serial.log"
QEMU_LOG = LAB / "ippd-qemu.log"
PIDFILE = LAB / "ippd-qemu.pid"
HOST_PORT = 49_123


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def build() -> None:
    required = (
        SOURCE_ROOT / "bin/ippd", SUPERVISOR_INIT, CMS_HELPER, PRINTERS,
        SHIM, base.KERNEL, base.KMODS, base.QEMU,
    )
    missing = [str(path) for path in required if not path.exists()]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))
    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(SOURCE_ROOT, STAGING, symlinks=True)
    shutil.copytree(base.KMODS, STAGING / "lib/modules", dirs_exist_ok=True)
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
    if os.environ.get("FRIDAY_ENABLE_IPPD_ENTITY") == "1":
        commented = (
            "#BEGIN\n"
            "#  eid         = EID_IPPD\n"
            "#  name        = ippd\n"
            "#  flags       = EIF_MESSAGING_CAPABLE\n"
            "#END"
        )
        enabled = (
            "BEGIN\n"
            "  eid         = EID_IPPD\n"
            "  name        = ippd\n"
            "  flags       = EIF_MESSAGING_CAPABLE\n"
            "END"
        )
        if commented not in entity_text:
            raise SystemExit("expected commented IPPD entity block not found")
        entity_text = entity_text.replace(commented, enabled, 1)
    entity_file.write_text(entity_text)
    shutil.copy2(SUPERVISOR_INIT, STAGING / "init")
    shutil.copy2(PRINTERS, STAGING / "etc/ippd-printers.conf")
    os.chmod(STAGING / "init", 0o755)
    linker = base.find_arm_linker()
    subprocess.run(
        [
            "clang", "--target=arm-linux-gnueabi", "-march=armv7-a",
            "-fPIC", "-shared", "-nostdlib", f"-fuse-ld={linker}",
            "-DFRIDAY_TRACE_FATAL",
            "-Wl,-soname,rax42v2_emulation_shim.so",
            "-o", str(STAGING / "lib/rax42v2_emulation_shim.so"),
            str(SHIM),
        ],
        check=True,
    )
    subprocess.run(
        [
            "clang", "--target=arm-linux-gnueabi", "-march=armv7-a",
            "-nostdlib", f"-fuse-ld={linker}", "-fno-stack-protector",
            "-Wl,-e,_start", "-Wl,--dynamic-linker=/lib/ld-linux.so.3",
            "-Wl,--allow-shlib-undefined", "-Wl,--no-as-needed",
            f"-L{STAGING / 'lib'}", "-lcms_msg", "-lcms_util", "-lgen_util",
            "-lbcm_util", "-lbcm_flashutil", "-lbcm_boardctl", "-lsys_util",
            "-l:libcrypt.so.1", "-l:libc.so.6",
            "-o", str(STAGING / "bin/cms_start_ippd"),
            str(CMS_HELPER),
        ],
        check=True,
    )
    for relative in ("proc", "sys", "dev", "run", "tmp", "var/run", "var/log", "var/tmp"):
        directory = STAGING / relative
        if directory.is_symlink():
            directory.unlink()
        directory.mkdir(parents=True, exist_ok=True)
    command = (
        f"cd {base.shell_quote(str(STAGING))} && "
        "find . -print0 | cpio --null -o --format=newc 2>/dev/null | "
        f"gzip -1 > {base.shell_quote(str(INITRAMFS))}"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"ippd_sha256={sha256(STAGING / 'bin/ippd')}")
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


def qemu_command() -> list[str]:
    return [
        str(base.QEMU), "-M", "virt", "-cpu", "cortex-a15", "-m", "1024M",
        "-kernel", str(base.KERNEL), "-initrd", str(INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-nographic", "-monitor", "none", "-serial", f"file:{SERIAL}",
        "-netdev", "user,id=lan,restrict=on",
        "-device", "virtio-net-device,netdev=lan", "-no-reboot",
    ]


def start() -> None:
    if not INITRAMFS.is_file():
        raise SystemExit(f"missing initramfs; run build first: {INITRAMFS}")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(qemu_command(), stdout=output, stderr=subprocess.STDOUT)
    PIDFILE.write_text(f"{process.pid}\n")
    print(f"qemu_pid={process.pid} network=user,restrict=on host-forwarding=disabled")


def foreground() -> None:
    if not INITRAMFS.is_file():
        raise SystemExit(f"missing initramfs; run build first: {INITRAMFS}")
    stop()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    PIDFILE.write_text(f"{os.getpid()}\n")
    print(
        "qemu_foreground=yes network=user,restrict=on host-forwarding=disabled",
        flush=True,
    )
    try:
        raise SystemExit(subprocess.run(qemu_command()).returncode)
    finally:
        PIDFILE.unlink(missing_ok=True)


def wait_ready(timeout: float = 120) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        content = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_RAX42V2_IPPD_READY=1" in content:
            return content
        if "Kernel panic" in content:
            raise RuntimeError("guest kernel panic; inspect serial log")
        if PIDFILE.exists():
            try:
                pid = int(PIDFILE.read_text().strip())
                cmdline = Path(f"/proc/{pid}/cmdline")
                if not cmdline.exists():
                    details = QEMU_LOG.read_text(errors="replace") if QEMU_LOG.exists() else ""
                    raise RuntimeError(f"QEMU exited before readiness:\n{details}")
            except ValueError as error:
                raise RuntimeError("invalid QEMU pidfile") from error
        time.sleep(0.5)
    raise TimeoutError("RAX42v2 IPP guest did not become ready")


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
        print("\n".join(content.splitlines()[-50:]))
    if args.action == "status":
        print(SERIAL.read_text(errors="replace")[-8000:] if SERIAL.exists() else "no serial log")
    if args.action == "stop":
        stop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
