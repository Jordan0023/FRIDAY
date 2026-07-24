#!/usr/bin/env python3
"""Manage a disposable, network-disabled Archer AX21 TDDP lab."""

from __future__ import annotations

import argparse
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_ROOTFS = ROOT / "known_firmware/extracted/021103002dbf716c/manual-rootfs"
QEMU_CANDIDATES = (
    Path("/usr/bin/qemu-arm-static"),
    ROOT / "work/rootfs/usr/bin/qemu-arm-static",
    Path("/tmp/qemu-user-static-local/usr/bin/qemu-arm-static"),
    Path("/tmp/qemu-native/usr/bin/qemu-arm-static"),
)
DEFAULT_NAME = "friday-ax21-tddp"
DEFAULT_IMAGE = "friday-hacker-agent"


def default_qemu() -> Path:
    return next((path for path in QEMU_CANDIDATES if path.is_file()), QEMU_CANDIDATES[0])


def run(*args: str, capture: bool = False) -> subprocess.CompletedProcess[str]:
    return subprocess.run(args, check=True, text=True, capture_output=capture)


def stop(name: str) -> None:
    subprocess.run(
        ["docker", "rm", "-f", name],
        check=False,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )


def start(name: str, image: str, rootfs: Path, qemu: Path) -> None:
    if not rootfs.is_dir():
        raise SystemExit(f"rootfs not found: {rootfs}")
    if not qemu.is_file():
        raise SystemExit(f"qemu-arm-static not found: {qemu}")

    stop(name)
    run(
        "docker", "run", "--rm", "-d", "--name", name,
        "--network", "none", "--user", "0",
        "-v", f"{rootfs.resolve()}:/firmware:ro",
        image, "sleep", "infinity",
    )
    try:
        run("docker", "exec", name, "mkdir", "-p", "/lab")
        run("docker", "exec", name, "sh", "-c", "cp -a /firmware/. /lab/")
        run("docker", "cp", str(qemu.resolve()), f"{name}:/lab/qemu-arm-static")
        run("docker", "cp", str(ROOT / "scripts/fuzz_tplink_tddp.py"),
            f"{name}:/tmp/fuzz_tplink_tddp.py")
        run(
            "docker", "exec", "-d", name, "chroot", "/lab",
            "/qemu-arm-static", "/usr/bin/tddp",
        )
    except Exception:
        stop(name)
        raise


def status(name: str) -> None:
    inspect = run(
        "docker", "inspect", name,
        "--format", "network={{.HostConfig.NetworkMode}} status={{.State.Status}}",
        capture=True,
    )
    print(inspect.stdout.strip())
    proc = run(
        "docker", "exec", name, "sh", "-c",
        "test -r /proc/net/udp && grep -i ':0410' /proc/net/udp || true",
        capture=True,
    )
    print(proc.stdout.strip() or "UDP 1040 not observed")


def probe(name: str, mode: str) -> None:
    flag = {
        "read": "--read-probe",
        "bounded": "",
        "offset": "--offset-sweep",
    }[mode]
    command = [
        "docker", "exec", name, "python3", "/tmp/fuzz_tplink_tddp.py",
        "--host", "127.0.0.1", "--timeout", "1" if mode == "read" else "0.05",
    ]
    if flag:
        command.append(flag)
    run(*command)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--name", default=DEFAULT_NAME)
    parser.add_argument("--image", default=DEFAULT_IMAGE)
    parser.add_argument("--rootfs", type=Path, default=DEFAULT_ROOTFS)
    parser.add_argument("--qemu", type=Path, default=default_qemu())
    sub = parser.add_subparsers(dest="action", required=True)
    sub.add_parser("start")
    sub.add_parser("status")
    sub.add_parser("stop")
    probe_parser = sub.add_parser("probe")
    probe_parser.add_argument("mode", choices=("read", "bounded", "offset"))
    args = parser.parse_args()

    if args.action == "start":
        start(args.name, args.image, args.rootfs, args.qemu)
        status(args.name)
    elif args.action == "status":
        status(args.name)
    elif args.action == "stop":
        stop(args.name)
    else:
        probe(args.name, args.mode)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
