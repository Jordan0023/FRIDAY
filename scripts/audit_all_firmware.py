#!/usr/bin/env python3
from __future__ import annotations

import argparse
from concurrent.futures import ProcessPoolExecutor, as_completed
import shutil
import subprocess
import sys
import traceback
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from netgear_firmware_audit.audit import FirmwareAuditor
from netgear_firmware_audit.manifest import Manifest
from netgear_firmware_audit.models import FirmwareRecord


def _audit_worker(task: tuple[str, dict, int, int | None, bool]) -> dict:
    root_str, record_data, max_ghidra_files, max_extract_bytes, cleanup_extracted = task
    root = Path(root_str)
    record = FirmwareRecord.from_json(record_data)
    firmware_path = root / record.path
    if not firmware_path.is_file():
        return {"status": "missing", "record": record.to_json(), "path": str(firmware_path)}
    auditor = FirmwareAuditor(root, max_ghidra_files=max_ghidra_files, max_extract_bytes=max_extract_bytes)
    try:
        report = auditor.audit(record)
    except Exception as exc:
        if cleanup_extracted:
            shutil.rmtree(root / "extracted" / record.sha256[:16], ignore_errors=True)
        return {
            "status": "failed",
            "record": record.to_json(),
            "error": str(exc),
            "traceback": traceback.format_exc(),
        }
    if cleanup_extracted:
        shutil.rmtree(root / "extracted" / record.sha256[:16], ignore_errors=True)
    return {"status": "audited", "record": record.to_json(), "report_path": str(report.relative_to(root))}


def main() -> int:
    parser = argparse.ArgumentParser(description="Audit downloaded firmware and update reports/manifest.")
    parser.add_argument("--root", type=Path, default=Path("known_firmware"))
    parser.add_argument("--all", action="store_true", help="Re-audit records that already have report_path set.")
    parser.add_argument("--limit", type=int, default=None, help="Maximum records to audit in this run.")
    parser.add_argument("--build-site", action="store_true", help="Rebuild site/data after auditing.")
    parser.add_argument("--max-ghidra-files", type=int, default=0, help="Maximum ELF files to import into Ghidra per firmware.")
    parser.add_argument("--cleanup-extracted", action="store_true", help="Delete each firmware extraction directory after its report is written.")
    parser.add_argument("--max-extract-mb", type=int, default=None, help="Stop extracting one firmware after this many MB and scan whatever was extracted.")
    parser.add_argument("--workers", type=int, default=1, help="Number of firmware audits to run in parallel.")
    args = parser.parse_args()

    manifest = Manifest(args.root).load()
    max_extract_bytes = args.max_extract_mb * 1024 * 1024 if args.max_extract_mb else None
    auditor = FirmwareAuditor(args.root, max_ghidra_files=args.max_ghidra_files, max_extract_bytes=max_extract_bytes)
    records = sorted(manifest.records.values(), key=lambda record: (record.product, record.filename, record.sha256))

    selected = []
    for record in records:
        if args.all or not record.report_path:
            selected.append(record)
        if args.limit is not None and len(selected) >= args.limit:
            break

    audited = 0
    failed = 0
    skipped_missing = 0
    print(f"Firmware records: {len(records)}")
    print(f"Selected for audit: {len(selected)}")

    if args.workers <= 1:
        for index, record in enumerate(selected, start=1):
            firmware_path = args.root / record.path
            if not firmware_path.is_file():
                skipped_missing += 1
                print(f"[{index}/{len(selected)}] Missing file, skipping {record.product} {record.filename}: {firmware_path}")
                continue
            print(f"[{index}/{len(selected)}] Auditing {record.product} {record.filename}", flush=True)
            try:
                report = auditor.audit(record)
            except Exception as exc:
                failed += 1
                print(f"Failed {record.product} {record.filename}: {exc}")
                traceback.print_exc()
                if args.cleanup_extracted:
                    shutil.rmtree(args.root / "extracted" / record.sha256[:16], ignore_errors=True)
                continue
            record.report_path = str(report.relative_to(args.root))
            manifest.records[record.sha256] = record
            manifest.save()
            audited += 1
            if args.cleanup_extracted:
                shutil.rmtree(args.root / "extracted" / record.sha256[:16], ignore_errors=True)
    else:
        worker_count = min(args.workers, len(selected))
        print(f"Parallel workers: {worker_count}", flush=True)
        tasks = [
            (str(args.root), record.to_json(), args.max_ghidra_files, max_extract_bytes, args.cleanup_extracted)
            for record in selected
        ]
        with ProcessPoolExecutor(max_workers=worker_count) as executor:
            futures = [executor.submit(_audit_worker, task) for task in tasks]
            for index, future in enumerate(as_completed(futures), start=1):
                result = future.result()
                record = FirmwareRecord.from_json(result["record"])
                if result["status"] == "missing":
                    skipped_missing += 1
                    print(f"[{index}/{len(selected)}] Missing file, skipping {record.product} {record.filename}: {result['path']}", flush=True)
                    continue
                if result["status"] == "failed":
                    failed += 1
                    print(f"[{index}/{len(selected)}] Failed {record.product} {record.filename}: {result['error']}", flush=True)
                    print(result["traceback"], flush=True)
                    continue
                record.report_path = result["report_path"]
                manifest.records[record.sha256] = record
                manifest.save()
                audited += 1
                print(f"[{index}/{len(selected)}] Audited {record.product} {record.filename}", flush=True)

    if args.build_site:
        subprocess.run([sys.executable, str(ROOT / "scripts" / "build_site_data.py")], check=True)

    print(f"Audited: {audited}")
    print(f"Failed: {failed}")
    print(f"Missing firmware files: {skipped_missing}")
    print(f"Manifest: {args.root / 'manifest.json'}")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
