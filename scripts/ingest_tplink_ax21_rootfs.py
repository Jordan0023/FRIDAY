#!/usr/bin/env python3
"""Validate and summarize an authorized Archer AX21 rootfs acquisition."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import subprocess
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
BASELINE_ROOTFS = ROOT / "known_firmware/extracted/021103002dbf716c/manual-rootfs"
DEFAULT_OUTPUT = ROOT / "known_firmware/reports/TP-Link_Archer_AX21/authorized-rootfs-comparison.json"


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def describe(path: Path) -> str:
    result = subprocess.run(
        ["file", "-b", str(path)], check=True, text=True, capture_output=True
    )
    return result.stdout.strip()


def locate_tddp(rootfs: Path) -> Path:
    preferred = rootfs / "usr/bin/tddp"
    if preferred.is_file():
        return preferred
    matches = [path for path in rootfs.rglob("tddp") if path.is_file()]
    if len(matches) != 1:
        raise SystemExit(
            f"expected one tddp executable under {rootfs}, found {len(matches)}"
        )
    return matches[0]


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Ingest a rootfs copied from an owned/authorized AX21"
    )
    parser.add_argument("rootfs", type=Path)
    parser.add_argument("--baseline-rootfs", type=Path, default=BASELINE_ROOTFS)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    args = parser.parse_args()

    rootfs = args.rootfs.resolve()
    baseline_rootfs = args.baseline_rootfs.resolve()
    if not rootfs.is_dir():
        raise SystemExit(f"rootfs directory not found: {rootfs}")

    current = locate_tddp(rootfs)
    baseline = locate_tddp(baseline_rootfs)
    current_hash = sha256(current)
    baseline_hash = sha256(baseline)
    report = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "scope": "authorized-owned-device-rootfs",
        "rootfs": str(rootfs),
        "tddp": {
            "path": str(current.relative_to(rootfs)),
            "size": current.stat().st_size,
            "mode": oct(os.stat(current).st_mode & 0o7777),
            "sha256": current_hash,
            "file": describe(current),
        },
        "baseline": {
            "rootfs": str(baseline_rootfs),
            "path": str(baseline.relative_to(baseline_rootfs)),
            "size": baseline.stat().st_size,
            "sha256": baseline_hash,
        },
        "comparison": {
            "byte_identical": current_hash == baseline_hash,
            "size_delta": current.stat().st_size - baseline.stat().st_size,
        },
        "next_command": (
            f"python3 scripts/emulate_tplink_ax21_tddp.py --rootfs {rootfs} start"
        ),
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2))
    print(f"wrote {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
