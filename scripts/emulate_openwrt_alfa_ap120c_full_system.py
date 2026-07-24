#!/usr/bin/env python3
"""Build and run an isolated full-system ALFA AP120C-AC OpenWrt lab."""

from __future__ import annotations

import argparse
import hashlib
import os
import pwd
import shutil
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = (
    ROOT
    / "known_firmware/extracted/3a6dc689a2247c94/"
    "_openwrt-25.12.5-ipq40xx-generic-alfa-network_ap120c-ac-"
    "squashfs-sysupgrade.bin.extracted/sysupgrade-alfa-network_ap120c-ac/"
    "_root.extracted/squashfs-root"
)
INIT = (
    ROOT
    / "known_firmware/emulation/OpenWrt_ALFA_AP120C-AC/"
    "full_system_stock_init"
)
LAB = (
    ROOT
    / "known_firmware/emulation/OpenWrt_ALFA_AP120C-AC/"
    "full-system-stock-init-lab"
)
STAGING = Path("/tmp/friday-ap120c-full-system-root")
KERNEL = Path("/tmp/ad7200-armmp-vmlinuz")
MODULES = Path("/tmp/ad7200-kmods/lib/modules")
QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm")
HWSIM_KERNEL_COMPRESSED = Path(
    "/tmp/friday-arm64-kernel/boot/vmlinuz-5.15.0-186-generic"
)
HWSIM_KERNEL = Path("/tmp/ap120c-arm64-Image")
HWSIM_MODULES = Path("/tmp/friday-arm64-kernel/lib/modules")
HWSIM_QEMU = Path("/tmp/qemu-system-arm-local/usr/bin/qemu-system-aarch64")
HWSIM_INJECTOR_SOURCE = ROOT / "scripts/ap120c_hwsim_injector.c"
HWSIM_TEST = (
    ROOT / "known_firmware/emulation/OpenWrt_ALFA_AP120C-AC/hwsim_test"
)
ARM_LD = Path("/tmp/rs700-arm-binutils/usr/bin/arm-linux-gnueabi-ld")
ARM_LD_LIBRARY = Path("/tmp/rs700-arm-binutils/usr/lib/x86_64-linux-gnu")
INITRAMFS = LAB / "ap120c-stock-rootfs.cpio.gz"
HWSIM_INITRAMFS = LAB / "ap120c-hwsim-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HTTP_PORT = 28_085
DNS_PORT = 25_356
SSH_PORT = 22_223
TAP_NAME = "friday-ap120c6"
TAP_HOST_ADDRESS = "fd42:120c::2/64"
TAP_STATE = LAB / "tap.enabled"


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def shell_quote(value: str) -> str:
    return "'" + value.replace("'", "'\"'\"'") + "'"


def build(hwsim: bool = False) -> None:
    modules = HWSIM_MODULES if hwsim else MODULES
    qemu = HWSIM_QEMU if hwsim else QEMU
    required = (ROOTFS, INIT, modules, qemu)
    required += ((HWSIM_KERNEL_COMPRESSED,) if hwsim else (KERNEL,))
    missing = [str(path) for path in required if not path.exists()]
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))

    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    shutil.copytree(ROOTFS, STAGING, symlinks=True)
    shutil.copytree(modules, STAGING / "lib/modules", dirs_exist_ok=True)
    # binwalk defensively rewrites absolute symlinks escaping its extraction
    # directory to /dev/null. Restore only links required by this isolated
    # initramfs, using relative targets so the staged tree remains self-contained.
    repaired_links = {
        "sbin/insmod": "kmodloader",
        "sbin/lsmod": "kmodloader",
        "sbin/modinfo": "kmodloader",
        "sbin/modprobe": "kmodloader",
        "sbin/rmmod": "kmodloader",
        "sbin/logread": "logd",
        "usr/bin/ssh": "../sbin/dropbear",
        "usr/bin/scp": "../sbin/dropbear",
        "usr/bin/ssh-keygen": "../sbin/dropbear",
        "usr/bin/wget": "../../bin/uclient-fetch",
    }
    for relative, target in repaired_links.items():
        link = STAGING / relative
        link.unlink(missing_ok=True)
        link.symlink_to(target)
    shutil.copy2(INIT, STAGING / "init")
    if hwsim:
        shutil.copy2(HWSIM_TEST, STAGING / "hwsim_test")
        os.chmod(STAGING / "hwsim_test", 0o755)
        injector_object = Path("/tmp/ap120c-hwsim-injector.o")
        injector = STAGING / "usr/bin/ap120c-hwsim-injector"
        subprocess.run([
            "clang", "--target=arm-linux-musleabi", "-march=armv7-a",
            "-Os", "-ffreestanding", "-fno-stack-protector", "-fno-builtin",
            "-nostdlib", "-c", "-o", str(injector_object),
            str(HWSIM_INJECTOR_SOURCE),
        ], check=True)
        linker_environment = os.environ.copy()
        linker_environment["LD_LIBRARY_PATH"] = str(ARM_LD_LIBRARY)
        subprocess.run([
            str(ARM_LD), "-static", "-e", "_start", "-o", str(injector),
            str(injector_object),
        ], env=linker_environment, check=True)
        os.chmod(injector, 0o755)
    os.chmod(STAGING / "init", 0o755)
    for relative in (
        "proc", "sys", "dev", "dev/pts", "run", "tmp", "var/run",
        "var/log", "var/tmp", "var/state", "overlay",
    ):
        (STAGING / relative).mkdir(parents=True, exist_ok=True)

    initramfs = HWSIM_INITRAMFS if hwsim else INITRAMFS
    command = (
        f"cd {shell_quote(str(STAGING))} && "
        "find . -print0 | cpio --null -o --format=newc 2>/dev/null | "
        f"gzip -1 > {shell_quote(str(initramfs))}"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    if hwsim:
        with HWSIM_KERNEL_COMPRESSED.open("rb") as source:
            subprocess.run(["gzip", "-dc"], stdin=source,
                           stdout=HWSIM_KERNEL.open("wb"), check=True)
    print(f"initramfs={initramfs} sha256={sha256(initramfs)}")


def running_pid() -> int | None:
    if not PIDFILE.exists():
        return None
    try:
        pid = int(PIDFILE.read_text().strip())
        cmdline = Path(f"/proc/{pid}/cmdline")
        if cmdline.exists() and (
            b"qemu-system-arm" in cmdline.read_bytes()
            or b"qemu-system-aarch64" in cmdline.read_bytes()
        ):
            return pid
    except (ValueError, PermissionError):
        pass
    return None


def stop() -> None:
    pid = running_pid()
    if pid is not None:
        try:
            os.kill(pid, 15)
            for _ in range(30):
                if not Path(f"/proc/{pid}/cmdline").exists():
                    break
                time.sleep(0.1)
        except ProcessLookupError:
            pass
    PIDFILE.unlink(missing_ok=True)
    if TAP_STATE.exists():
        remove_tap()


def sudo_ip(*arguments: str, check: bool = True) -> None:
    subprocess.run(["sudo", "-n", "ip", *arguments], check=check)


def create_tap() -> None:
    present = subprocess.run(
        ["ip", "link", "show", "dev", TAP_NAME],
        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
    ).returncode == 0
    if present:
        TAP_STATE.write_text("external\n")
        return
    user = pwd.getpwuid(os.getuid()).pw_name
    sudo_ip("tuntap", "add", "dev", TAP_NAME, "mode", "tap", "user", user)
    try:
        sudo_ip("-6", "addr", "add", TAP_HOST_ADDRESS, "dev", TAP_NAME)
        sudo_ip("link", "set", "dev", TAP_NAME, "up")
    except subprocess.CalledProcessError:
        sudo_ip("link", "delete", "dev", TAP_NAME, check=False)
        raise
    TAP_STATE.write_text("owned\n")


def remove_tap() -> None:
    ownership = TAP_STATE.read_text().strip() if TAP_STATE.exists() else ""
    if ownership == "owned":
        sudo_ip("link", "delete", "dev", TAP_NAME, check=False)
    TAP_STATE.unlink(missing_ok=True)


def qemu_command(tap: bool = False, hwsim: bool = False) -> list[str]:
    forwards = (
        f"hostfwd=tcp:127.0.0.1:{HTTP_PORT}-10.0.2.15:80,"
        f"hostfwd=tcp:127.0.0.1:{SSH_PORT}-10.0.2.15:22,"
        f"hostfwd=udp:127.0.0.1:{DNS_PORT}-10.0.2.15:53,"
        f"hostfwd=tcp:127.0.0.1:{DNS_PORT}-10.0.2.15:53"
    )
    command = [
        str(HWSIM_QEMU if hwsim else QEMU), "-M", "virt",
        "-cpu", "cortex-a57" if hwsim else "cortex-a15",
        "-m", "2048M" if hwsim else "768M",
        "-kernel", str(HWSIM_KERNEL if hwsim else KERNEL),
        "-initrd", str(HWSIM_INITRAMFS if hwsim else INITRAMFS),
        "-append", "console=ttyAMA0 rdinit=/init panic=-1",
        "-display", "none", "-monitor", "none",
        "-serial", f"file:{SERIAL}",
        "-netdev", (
            "user,id=lan,restrict=on" if hwsim
            else f"user,id=lan,restrict=on,{forwards}"
        ),
        "-device", "virtio-net-device,netdev=lan,mac=52:54:00:12:34:10",
        "-no-reboot",
    ]
    if tap:
        command.extend([
            "-netdev",
            f"tap,id=ipv6tap,ifname={TAP_NAME},script=no,downscript=no",
            "-device",
            "virtio-net-device,netdev=ipv6tap,mac=52:54:00:12:34:60",
        ])
    return command


def start(tap: bool = False, hwsim: bool = False) -> None:
    initramfs = HWSIM_INITRAMFS if hwsim else INITRAMFS
    if not initramfs.is_file():
        raise SystemExit(f"missing initramfs; run build first: {initramfs}")
    stop()
    if tap:
        create_tap()
    SERIAL.unlink(missing_ok=True)
    QEMU_LOG.unlink(missing_ok=True)
    with QEMU_LOG.open("wb") as output:
        process = subprocess.Popen(
            qemu_command(tap, hwsim),
            stdout=output,
            stderr=subprocess.STDOUT,
            start_new_session=True,
        )
    PIDFILE.write_text(f"{process.pid}\n")
    print(
        f"qemu_pid={process.pid} network=user,restrict=on "
        f"http=127.0.0.1:{HTTP_PORT}->guest:80 "
        f"ssh=127.0.0.1:{SSH_PORT}->guest:22 "
        f"dns=127.0.0.1:{DNS_PORT}->guest:53"
        + (f" ipv6_tap={TAP_NAME},{TAP_HOST_ADDRESS}" if tap else "")
    )


def wait_ready(timeout: float = 300) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        content = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if "FRIDAY_AP120C_FULL_SYSTEM_READY=1" in content:
            return content
        if "Kernel panic" in content:
            raise RuntimeError("guest kernel panic; inspect serial.log")
        if running_pid() is None:
            raise RuntimeError("QEMU exited; inspect qemu.log and serial.log")
        time.sleep(0.5)
    raise TimeoutError("guest did not finish stock-init diagnostics")


def status() -> None:
    print(f"qemu_running={'yes' if running_pid() else 'no'}")
    if SERIAL.exists():
        print("\n".join(SERIAL.read_text(errors="replace").splitlines()[-100:]))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=(
            "build", "build-hwsim", "start", "start-tap", "start-hwsim",
            "wait", "run", "run-tap", "run-hwsim",
            "status", "stop",
        ),
    )
    args = parser.parse_args()
    if args.action in ("build", "run", "run-tap"):
        build()
    if args.action in ("build-hwsim", "run-hwsim"):
        build(True)
    if args.action in ("start", "run"):
        start(False)
    if args.action in ("start-tap", "run-tap"):
        start(True)
    if args.action in ("start-hwsim", "run-hwsim"):
        start(False, True)
    if args.action in ("wait", "run", "run-tap", "run-hwsim"):
        content = wait_ready()
        print("\n".join(content.splitlines()[-100:]))
    if args.action == "status":
        status()
    if args.action == "stop":
        stop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
