#!/usr/bin/env python3
"""Remove EOL or out-of-window router artifacts from the active repository."""

from __future__ import annotations

import argparse
import json
import re
import shutil
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
KNOWN = ROOT / "known_firmware"
FIRMWARE = KNOWN / "firmware"
EXTRACTED = KNOWN / "extracted"
REPORTS = KNOWN / "reports"
EMULATION = KNOWN / "emulation"
PRIVATE_DISCLOSURES = ROOT / "private_disclosures"
MANIFEST = KNOWN / "manifest.json"
EOL_CATALOG = ROOT / "site" / "data" / "eol-products.json"
MIN_YEAR = 2021
MAX_YEAR = 2026
EXPLICIT_EOL_PRODUCTS = {"JWNR2010V3"}


def safe_name(value: str) -> str:
    cleaned = "".join(
        character if character.isalnum() or character in "._-" else "_"
        for character in value.strip()
    )
    return cleaned.strip("._") or "unknown"


def record_year(record: dict[str, object]) -> int | None:
    for field in ("release_date", "uploaded_at"):
        match = re.search(r"(?<!\d)(20\d{2})(?!\d)", str(record.get(field, "")))
        if match:
            return int(match.group(1))
    return None


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--execute", action="store_true")
    args = parser.parse_args()

    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    catalog = json.loads(EOL_CATALOG.read_text(encoding="utf-8"))
    eol_products = {
        str(value).strip().casefold()
        for value in catalog.get("products", [])
        if str(value).strip()
    }
    eol_products.update(value.casefold() for value in EXPLICIT_EOL_PRODUCTS)
    eol_filenames = {
        str(value).strip().casefold()
        for value in catalog.get("firmware_filenames", [])
        if str(value).strip()
    }

    def is_eol_product(product: str) -> bool:
        base = product.removeprefix("OpenWrt ") if product.startswith("OpenWrt ") else product
        return product.casefold() in eol_products or base.casefold() in eol_products

    target_dirs: set[Path] = set()
    for product in catalog.get("products", []):
        for candidate in (str(product), f"OpenWrt {product}"):
            product_dir = safe_name(candidate)
            for artifact_root in (FIRMWARE, REPORTS, EMULATION, PRIVATE_DISCLOSURES):
                path = artifact_root / product_dir
                if path.is_dir():
                    target_dirs.add(path)
    for product in EXPLICIT_EOL_PRODUCTS:
        for artifact_root in (FIRMWARE, REPORTS, EMULATION, PRIVATE_DISCLOSURES):
            path = artifact_root / safe_name(product)
            if path.is_dir():
                target_dirs.add(path)

    target_records: set[str] = set()
    target_files: set[Path] = set()
    retained_records: dict[str, object] = {}
    for key, raw in manifest.get("firmware", {}).items():
        record = dict(raw)
        year = record_year(record)
        eol = is_eol_product(str(record.get("product", ""))) or (
            str(record.get("filename", "")).casefold() in eol_filenames
        )
        out_of_range = year is None or not MIN_YEAR <= year <= MAX_YEAR
        if eol or out_of_range:
            target_records.add(key)
            candidate = (KNOWN / str(record.get("path", ""))).resolve()
            if candidate.is_file() and FIRMWARE.resolve() in candidate.parents:
                target_files.add(candidate)
        else:
            retained_records[key] = raw

    for directory in target_dirs:
        target_files.update(path for path in directory.rglob("*") if path.is_file())

    hashes = set(target_records)
    extraction_dirs = {
        EXTRACTED / digest[:16]
        for digest in hashes
        if (EXTRACTED / digest[:16]).is_dir()
    }
    target_names = {path.name for path in target_files}
    for directory in EXTRACTED.iterdir():
        if not directory.is_dir() or directory in extraction_dirs:
            continue
        children = {path.name for path in directory.iterdir()}
        if any(f"_{name}.extracted" in children for name in target_names):
            extraction_dirs.add(directory)

    firmware_bytes = sum(path.stat().st_size for path in target_files if path.is_file())
    extracted_bytes = sum(
        path.stat().st_size
        for directory in extraction_dirs
        for path in directory.rglob("*")
        if path.is_file()
    )
    summary = {
        "mode": "execute" if args.execute else "dry-run",
        "firmware_files": len(target_files),
        "firmware_directories": len(target_dirs),
        "manifest_records_removed": len(target_records),
        "extracted_directories": len(extraction_dirs),
        "bytes_removed": firmware_bytes + extracted_bytes,
        "reports_removed": sum(directory.parent == REPORTS for directory in target_dirs),
        "evidence_removed": sum(
            directory.parent in {EMULATION, PRIVATE_DISCLOSURES}
            for directory in target_dirs
        ),
    }
    print(json.dumps(summary, indent=2))
    if not args.execute:
        return 0

    for path in sorted(target_files):
        if path.is_file():
            path.unlink()
    for directory in sorted(target_dirs, reverse=True):
        if directory.is_dir():
            shutil.rmtree(directory)
    for directory in sorted(extraction_dirs):
        shutil.rmtree(directory)

    manifest["firmware"] = retained_records
    manifest["updated"] = datetime.now(timezone.utc).replace(microsecond=0).isoformat()
    MANIFEST.write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
