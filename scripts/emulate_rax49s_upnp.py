#!/usr/bin/env python3
"""Launch and probe RAX49S V1.1.6.38 upnpd in an isolated container."""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

import emulate_raxe500_upnp as base


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = ROOT / "known_firmware/extracted/fe7d6c417177572b/manual-rootfs"
WORK = Path("/tmp/rax49s-upnp-emulation")
CONTAINER = "rax49s-upnp-emulator"
PROBES = (
    ROOT / "scripts/probe_rax54s_upnp_security.py",
    ROOT / "scripts/probe_rax54s_gena_callback.py",
)

base.CONTAINER = CONTAINER


def start(rebuild: bool) -> None:
    args = argparse.Namespace(
        rootfs=ROOTFS,
        work=WORK,
        qemu=base.DEFAULT_QEMU,
        rebuild=rebuild,
    )
    base.start(args)


def probe(mode: str) -> None:
    if not base.container_exists():
        raise SystemExit("emulator container is not running")
    probe = PROBES[1] if mode == "gena" else PROBES[0]
    destination = f"/tmp/{probe.name}"
    base.docker("cp", str(probe), f"{CONTAINER}:{destination}")
    command = [
        "docker", "exec", CONTAINER, "python3", destination,
        "--host", "192.168.1.1", "--port", "56688",
    ]
    if mode in ("body-overflow", "full"):
        command.extend(["--mode", mode])
    subprocess.run(command, check=False)
    base.status(None)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "action",
        choices=("start", "rebuild", "status", "body-overflow", "full", "gena", "stop"),
    )
    args = parser.parse_args()
    if args.action in ("start", "rebuild"):
        start(args.action == "rebuild")
    elif args.action == "status":
        base.status(None)
    elif args.action == "stop":
        base.stop(None)
    else:
        probe(args.action)
    return 0


if __name__ == "__main__":
    sys.exit(main())
