#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from netgear_firmware_audit.audit import FirmwareAuditor
from netgear_firmware_audit.manifest import Manifest
from netgear_firmware_audit.models import FirmwareRecord, safe_name


def main() -> int:
    parser = argparse.ArgumentParser(description="Stage and audit one local router firmware image.")
    parser.add_argument("firmware", type=Path, help="Path to a firmware file.")
    parser.add_argument("--root", type=Path, default=Path("known_firmware"), help="Firmware workspace root.")
    parser.add_argument("--product", help="Product/report name. Defaults to the firmware filename stem.")
    parser.add_argument("--max-ghidra-files", type=int, default=5, help="Maximum ELF files to import into Ghidra.")
    parser.add_argument("--max-extract-mb", type=int, default=None, help="Stop extraction after this many MB.")
    parser.add_argument("--build-site", action="store_true", help="Rebuild dashboard data after auditing.")
    args = parser.parse_args()

    source = args.firmware.expanduser().resolve()
    if not source.is_file():
        parser.error(f"firmware file does not exist: {source}")

    root = args.root
    root.mkdir(parents=True, exist_ok=True)
    digest = sha256_file(source)
    product = args.product or source.stem
    staged_dir = root / "uploads" / safe_name(product)
    staged_dir.mkdir(parents=True, exist_ok=True)
    staged = staged_dir / source.name
    if not staged.exists() or sha256_file(staged) != digest:
        shutil.copy2(source, staged)

    record = FirmwareRecord(
        product=product,
        url=source.as_uri(),
        filename=source.name,
        path=str(staged.relative_to(root)),
        sha256=digest,
        size=source.stat().st_size,
        title=f"Local upload: {source.name}",
    )

    max_extract_bytes = args.max_extract_mb * 1024 * 1024 if args.max_extract_mb else None
    auditor = FirmwareAuditor(root, max_ghidra_files=args.max_ghidra_files, max_extract_bytes=max_extract_bytes)
    report = auditor.audit(record)
    record.report_path = str(report.relative_to(root))

    manifest = Manifest(root).load()
    manifest.add_product(product, source.as_uri())
    manifest.upsert(record)
    manifest.save()

    if args.build_site:
        subprocess.run([sys.executable, str(ROOT / "scripts" / "build_site_data.py")], check=True)

    print(f"Firmware: {source}")
    print(f"Staged: {staged}")
    print(f"SHA-256: {digest}")
    print(f"Report: {report}")
    return 0


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


if __name__ == "__main__":
    raise SystemExit(main())
