#!/usr/bin/env python3
"""Launch the RAXE500 UPnP daemon in a disposable, isolated container."""

from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_ROOTFS = ROOT / "known_firmware/extracted/00ac97d4fdf68dee/manual-rootfs"
DEFAULT_WORK = Path("/tmp/raxe500-upnp-emulation")
DEFAULT_QEMU = Path("/tmp/qemu-user-static-local/usr/bin/qemu-arm-static")
CONTAINER = "raxe500-upnp-emulator"
IMAGE = "friday-hacker-agent"
PROBE = ROOT / "known_firmware/reports/RAXE500/pocs/raxe500_upnp_record_probe.py"


def run(command: list[str], *, check: bool = True, capture: bool = False) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=check, text=True, capture_output=capture)


def docker(*arguments: str, check: bool = True, capture: bool = False) -> subprocess.CompletedProcess[str]:
    return run(["docker", *arguments], check=check, capture=capture)


def container_exists() -> bool:
    return docker("inspect", CONTAINER, check=False, capture=True).returncode == 0


def guest(*arguments: str) -> None:
    docker("exec", CONTAINER, "chroot", "/fw", "/qemu-arm-static", *arguments)


def prepare(rootfs: Path, work: Path, qemu: Path, rebuild: bool) -> None:
    if rebuild and work.exists():
        shutil.rmtree(work)
    if not work.exists():
        if not rootfs.is_dir():
            raise SystemExit(f"rootfs not found: {rootfs}")
        print(f"Copying disposable rootfs to {work} ...")
        shutil.copytree(rootfs, work, symlinks=True)
    if not qemu.is_file():
        raise SystemExit(f"qemu-arm-static not found: {qemu}")
    shutil.copy2(qemu, work / "qemu-arm-static")
    for relative in ("data", "mnt/nvram", "var/run", "var/log", "var/tmp"):
        (work / relative).mkdir(parents=True, exist_ok=True)


def start(args: argparse.Namespace) -> None:
    if container_exists():
        docker("rm", "-f", CONTAINER)
    prepare(args.rootfs, args.work, args.qemu, args.rebuild)
    docker(
        "run", "-d", "--name", CONTAINER, "--privileged", "--network", "none",
        "--user", "root", "-v", f"{args.work}:/fw", IMAGE, "sleep", "infinity",
    )
    docker("exec", CONTAINER, "ip", "link", "add", "br0", "type", "dummy")
    docker("exec", CONTAINER, "ip", "addr", "add", "192.168.1.1/24", "dev", "br0")
    docker("exec", CONTAINER, "ip", "link", "set", "br0", "up")
    docker("exec", CONTAINER, "ip", "addr", "add", "192.168.1.2/32", "dev", "lo")
    docker("exec", CONTAINER, "ip", "link", "set", "lo", "up")
    docker("exec", CONTAINER, "ipcrm", "-M", "0x11223350", check=False)
    docker("exec", CONTAINER, "ipcrm", "-S", "0x11223350", check=False)
    guest("/bin/acos_nvram", "init")
    for setting in (
        "lan_ifname=br0", "lan_ipaddr=192.168.1.1", "lan_netmask=255.255.255.0",
        "upnp_enable=1", "upnp_turn_on=1",
    ):
        guest("/bin/acos_nvram", "set", setting)
    # AddPortMapping consults the NAT runtime segment used by libnat_rule.
    # A zero-initialized segment is sufficient for an empty port-map table.
    docker(
        "exec", CONTAINER, "python3", "-c",
        "import ctypes; r=ctypes.CDLL(None).shmget(0x11223353,474104,0o1666); "
        "raise SystemExit(0 if r >= 0 else 1)",
    )
    guest("/usr/sbin/upnpd")
    time.sleep(1)
    if not has_listener():
        raise SystemExit("upnpd did not open TCP port 56688")
    print("RAXE500 UPnP emulation ready inside its isolated namespace.")
    print(f"Run: {Path(__file__).name} probe")


def has_listener() -> bool:
    return docker(
        "exec", CONTAINER, "sh", "-c",
        "awk '$2 ~ /:DD70$/ && $4 == \"0A\" { found=1 } END { exit !found }' /proc/net/tcp",
        check=False,
    ).returncode == 0


def probe(_: argparse.Namespace) -> None:
    if not container_exists():
        raise SystemExit("emulator container is not running")
    docker("cp", str(PROBE), f"{CONTAINER}:/tmp/raxe500_upnp_record_probe.py")
    docker(
        "exec", CONTAINER, "python3", "/tmp/raxe500_upnp_record_probe.py",
        "--host", "192.168.1.1", "--port", "56688", "--allow-non-loopback",
        check=False,
    )
    status(None)


def status(_: argparse.Namespace | None) -> None:
    if not container_exists():
        print("container: absent")
        return
    state = docker("inspect", "-f", "{{.State.Status}}", CONTAINER, capture=True).stdout.strip()
    print(f"container: {state}; tcp/56688 listener: {'yes' if has_listener() else 'no'}")


def stop(_: argparse.Namespace) -> None:
    if container_exists():
        docker("rm", "-f", CONTAINER)
    print("RAXE500 UPnP emulation stopped.")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)
    start_parser = subparsers.add_parser("start")
    start_parser.add_argument("--rootfs", type=Path, default=DEFAULT_ROOTFS)
    start_parser.add_argument("--work", type=Path, default=DEFAULT_WORK)
    start_parser.add_argument("--qemu", type=Path, default=DEFAULT_QEMU)
    start_parser.add_argument("--rebuild", action="store_true")
    start_parser.set_defaults(function=start)
    subparsers.add_parser("probe").set_defaults(function=probe)
    subparsers.add_parser("status").set_defaults(function=status)
    subparsers.add_parser("stop").set_defaults(function=stop)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        args.function(args)
    except subprocess.CalledProcessError as error:
        print(f"command failed ({error.returncode}): {' '.join(error.cmd)}", file=sys.stderr)
        return error.returncode
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
