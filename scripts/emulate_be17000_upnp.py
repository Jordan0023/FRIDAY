#!/usr/bin/env python3
"""Build and run an isolated BE17000 V1.0.6.22 UPnP firmware emulation."""

from __future__ import annotations

import argparse
import hashlib
import shutil
import subprocess
import sys
import time
import urllib.request
import zipfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ASSETS = ROOT / "known_firmware/emulation/BE17000"
SHIM_SOURCE = ASSETS / "be17000_iptc_shim.c"
PROBE = ASSETS / "be17000_probe.py"
FUZZ_PROBE = ASSETS / "be17000_fuzz_probe.py"
FIRMWARE_URL = "https://www.downloads.netgear.com/files/GDC/BE17000/BE17000-V1.0.6.22.zip"
FIRMWARE_SHA256 = "2a9b10038ea6b9b47f5571d67933104cdd9b57918850c09331bfc7f5e3a1c701"
SQUASHFS_OFFSET = 10_257_620
DEFAULT_ARCHIVE = Path("/tmp/BE17000-V1.0.6.22.zip")
DEFAULT_WORK = Path("/tmp/be17000-upnp-emulation")
DEFAULT_QEMU = Path("/tmp/qemu-user-static-local/usr/bin/qemu-arm-static")
CONTAINER = "be17000-upnp-emulator"
IMAGE = "friday-hacker-agent"
PORT = 56_688


def run(command: list[str], *, check: bool = True, capture: bool = False) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=check, text=True, capture_output=capture)


def docker(*arguments: str, check: bool = True, capture: bool = False) -> subprocess.CompletedProcess[str]:
    return run(["docker", *arguments], check=check, capture=capture)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def find_linker() -> Path:
    candidates = (
        shutil.which("ld.lld"),
        shutil.which("ld.lld-14"),
        "/tmp/lld14-local/usr/lib/llvm-14/bin/ld.lld",
    )
    for candidate in candidates:
        if candidate and Path(candidate).is_file():
            return Path(candidate)
    raise SystemExit("ARM-capable ld.lld is required")


def download(archive: Path) -> None:
    if archive.is_file() and sha256(archive) == FIRMWARE_SHA256:
        return
    archive.parent.mkdir(parents=True, exist_ok=True)
    print(f"Downloading official firmware to {archive} ...")
    with urllib.request.urlopen(FIRMWARE_URL, timeout=60) as response, archive.open("wb") as output:
        shutil.copyfileobj(response, output)
    actual = sha256(archive)
    if actual != FIRMWARE_SHA256:
        archive.unlink(missing_ok=True)
        raise SystemExit(f"firmware SHA-256 mismatch: {actual}")


def prepare(args: argparse.Namespace) -> None:
    download(args.archive)
    if args.rebuild and args.work.exists():
        shutil.rmtree(args.work)
    if args.work.exists():
        print(f"work root already exists: {args.work}")
        return
    image_dir = args.work.parent / f"{args.work.name}-image"
    shutil.rmtree(image_dir, ignore_errors=True)
    image_dir.mkdir(parents=True)
    with zipfile.ZipFile(args.archive) as package:
        package.extract("BE17000-V1.0.6.22.img", image_dir)
    firmware_image = image_dir / "BE17000-V1.0.6.22.img"
    run([
        "unsquashfs", "-d", str(args.work), "-o", str(SQUASHFS_OFFSET),
        str(firmware_image),
    ])
    if not args.qemu.is_file():
        raise SystemExit(f"qemu-arm-static not found: {args.qemu}")
    shutil.copy2(args.qemu, args.work / "qemu-arm-static")
    for relative in ("var/run", "var/tmp", "proc", "sys"):
        (args.work / relative).mkdir(parents=True, exist_ok=True)
    linker = find_linker()
    run([
        "clang", "--target=arm-linux-gnueabi", "-march=armv7-a", "-fPIC",
        "-shared", "-nostdlib", f"-fuse-ld={linker}",
        "-Wl,-soname,be17000_iptc_shim.so",
        "-o", str(args.work / "lib/be17000_iptc_shim.so"), str(SHIM_SOURCE),
    ])
    shutil.rmtree(image_dir)
    daemon = args.work / "usr/sbin/miniupnpd"
    print(f"rootfs={args.work}")
    print(f"miniupnpd_sha256={sha256(daemon)}")


def exists() -> bool:
    return docker("inspect", CONTAINER, check=False, capture=True).returncode == 0


def stop(_: argparse.Namespace | None = None) -> None:
    if exists():
        docker("rm", "-f", CONTAINER)
    print("BE17000 emulator stopped.")


def start(args: argparse.Namespace) -> None:
    if not (args.work / "usr/sbin/miniupnpd").is_file():
        prepare(args)
    if exists():
        docker("rm", "-f", CONTAINER)
    docker(
        "run", "-d", "--name", CONTAINER, "--privileged", "--network", "none",
        "--user", "root", "-v", f"{args.work}:/fw", IMAGE, "sleep", "infinity",
    )
    commands = (
        ("ip", "link", "set", "lo", "up"),
        ("ip", "link", "add", "br0", "type", "bridge"),
        ("ip", "addr", "add", "192.168.1.1/24", "dev", "br0"),
        ("ip", "link", "set", "br0", "up"),
        ("ip", "link", "add", "lan0", "type", "veth", "peer", "name", "client0"),
        ("ip", "link", "set", "lan0", "master", "br0"),
        ("ip", "link", "set", "lan0", "up"),
        ("ip", "link", "set", "client0", "up"),
        ("ip", "link", "add", "wan0", "type", "dummy"),
        ("ip", "addr", "add", "198.51.100.2/24", "dev", "wan0"),
        ("ip", "link", "set", "wan0", "up"),
        ("mount", "--bind", "/proc", "/fw/proc"),
        ("mount", "--bind", "/sys", "/fw/sys"),
    )
    for command in commands:
        docker("exec", CONTAINER, *command)
    for table, chain in (
        ("nat", "MINIUPNPD"),
        ("nat", "MINIUPNPD-POSTROUTING"),
        ("filter", "MINIUPNPD"),
        ("filter", "MINIUPNPD-LAN"),
    ):
        docker("exec", CONTAINER, "iptables-legacy", "-t", table, "-N", chain)
    docker(
        "exec", "-d", CONTAINER, "chroot", "/fw", "/qemu-arm-static",
        "-E", "LD_PRELOAD=/lib/be17000_iptc_shim.so",
        "/usr/sbin/miniupnpd", "-d", "-i", "wan0", "-a", "br0",
        "-p", str(PORT), "-o", "8.8.8.8", "-S",
        "-u", "4d696e69-444c-164e-9d42-000000000001",
        "-s", "FRIDAYLAB", "-m", "BE17000", "-t", "30",
        "-A", "allow 1024-65535 192.168.1.0/24 1024-65535",
        "-w", "http://www.routerlogin.net",
    )
    for _ in range(20):
        if listener():
            break
        time.sleep(0.25)
    else:
        raise SystemExit("firmware MiniUPnPd exited or timed out before opening tcp/56688")
    print("BE17000 V1.0.6.22 UPnP emulation ready.")
    print("Network: Docker namespace with --network=none")
    print("Firmware endpoint: 192.168.1.1:56688 (inside namespace only)")


def listener() -> bool:
    if not exists():
        return False
    result = docker(
        "exec", CONTAINER, "sh", "-c",
        "awk '$2 ~ /:DD70$/ && $4 == \"0A\" { found=1 } END { exit !found }' /proc/net/tcp",
        check=False,
    )
    return result.returncode == 0


def probe(args: argparse.Namespace) -> None:
    if not listener():
        raise SystemExit("emulator is not running")
    if args.mode == "fuzz":
        docker("cp", str(FUZZ_PROBE), f"{CONTAINER}:/tmp/be17000_fuzz_probe.py")
        result = docker(
            "exec", CONTAINER, "python3", "/tmp/be17000_fuzz_probe.py",
            check=False,
        )
    else:
        docker("cp", str(PROBE), f"{CONTAINER}:/tmp/be17000_probe.py")
        result = docker(
            "exec", CONTAINER, "python3", "/tmp/be17000_probe.py", args.mode,
            check=False,
        )
    time.sleep(0.5)
    print(f"listener_after={'yes' if listener() else 'no'}")
    if result.returncode != 0:
        raise SystemExit(result.returncode)


def status(_: argparse.Namespace) -> None:
    print(f"container={'present' if exists() else 'absent'}")
    print(f"tcp_56688_listener={'yes' if listener() else 'no'}")
    if exists():
        docker("exec", CONTAINER, "ps", "-ef", check=False)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--archive", type=Path, default=DEFAULT_ARCHIVE)
    parser.add_argument("--work", type=Path, default=DEFAULT_WORK)
    parser.add_argument("--qemu", type=Path, default=DEFAULT_QEMU)
    parser.add_argument("--rebuild", action="store_true")
    subparsers = parser.add_subparsers(dest="command", required=True)
    subparsers.add_parser("prepare")
    subparsers.add_parser("start")
    probe_parser = subparsers.add_parser("probe")
    probe_parser.add_argument("mode", choices=("baseline", "xml", "soapaction", "fuzz"))
    subparsers.add_parser("status")
    subparsers.add_parser("stop")
    subparsers.add_parser("run")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        if args.command == "prepare":
            prepare(args)
        elif args.command == "start":
            start(args)
        elif args.command == "probe":
            probe(args)
        elif args.command == "status":
            status(args)
        elif args.command == "stop":
            stop(args)
        elif args.command == "run":
            start(args)
            try:
                for mode in ("baseline", "xml", "soapaction"):
                    args.mode = mode
                    print(f"--- {mode} ---")
                    probe(args)
            finally:
                stop(args)
    except subprocess.CalledProcessError as error:
        print(f"command failed ({error.returncode}): {' '.join(error.cmd)}", file=sys.stderr)
        return error.returncode
    return 0


if __name__ == "__main__":
    sys.exit(main())
