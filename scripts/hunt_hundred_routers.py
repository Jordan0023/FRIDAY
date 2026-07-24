#!/usr/bin/env python3
"""Run a bounded, reproducible vulnerability hunt across 100 router models."""
from __future__ import annotations

import argparse
import json
import os
import re
import signal
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from netgear_firmware_audit.audit import FirmwareAuditor
from netgear_firmware_audit.manifest import Manifest
from netgear_firmware_audit.models import FirmwareRecord

VENDORS = ("ASUS", "TP-Link", "GL.iNet", "OpenWrt", "Netgear")
EOL_PRODUCTS_PATH = ROOT / "site" / "data" / "eol-products.json"


def load_eol_products() -> set[str]:
    if not EOL_PRODUCTS_PATH.is_file():
        raise SystemExit(f"EOL registry is required: {EOL_PRODUCTS_PATH}")
    payload = json.loads(EOL_PRODUCTS_PATH.read_text())
    return {str(product).strip() for product in payload.get("products", []) if str(product).strip()}


def reject_eol_targets(targets: list[FirmwareRecord]) -> None:
    blocked = sorted({record.product for record in targets} & load_eol_products())
    if blocked:
        raise SystemExit("Saved campaign contains EOL routers: " + ", ".join(blocked))


def vendor(product: str) -> str:
    for name in VENDORS[:-1]:
        if product.startswith(name + " "):
            return name
    return "Netgear"


def record_year(record: FirmwareRecord) -> int | None:
    for value in (record.uploaded_at, record.release_date):
        match = re.match(r"(\d{4})[-/]", value or "")
        if match:
            return int(match.group(1))
    return None


def select_targets(
    root: Path,
    count: int,
    min_year: int,
    max_year: int,
    excluded_products: set[str] | None = None,
) -> list[FirmwareRecord]:
    manifest = Manifest(root).load()
    eol = load_eol_products()
    excluded_products = excluded_products or set()
    latest: dict[str, FirmwareRecord] = {}
    for record in manifest.records.values():
        year = record_year(record)
        if (
            record.product in eol
            or record.product in excluded_products
            or year is None
            or not min_year <= year <= max_year
            or not (root / record.path).is_file()
        ):
            continue
        current = latest.get(record.product)
        key = (record.release_date or record.uploaded_at or "", record.version or "", record.sha256)
        old_key = (
            current.release_date or current.uploaded_at or "",
            current.version or "",
            current.sha256,
        ) if current else None
        if current is None or key > old_key:
            latest[record.product] = record

    groups = {
        name: sorted(
            (record for record in latest.values() if vendor(record.product) == name),
            key=lambda record: (record.product.casefold(), record.sha256),
        )
        for name in VENDORS
    }
    selected: list[FirmwareRecord] = []
    index = 0
    while len(selected) < count and any(index < len(group) for group in groups.values()):
        for name in VENDORS:
            if index < len(groups[name]) and len(selected) < count:
                selected.append(groups[name][index])
        index += 1
    if len(selected) != count:
        raise SystemExit(f"Only {len(selected)} eligible distinct router models were available")
    return selected


def parse_static_findings(report: Path) -> list[dict[str, str]]:
    if not report.is_file():
        return []
    text = report.read_text(encoding="utf-8", errors="replace")
    match = re.search(r"## Static Findings\n(.*?)(?=\n## |\Z)", text, re.S)
    if not match:
        return []
    findings = []
    for title, body in re.findall(r"### (.+?)\n\n(.*?)(?=\n### |\Z)", match.group(1), re.S):
        evidence = re.search(r"Evidence: `?(.*?)`?(?:\n|$)", body)
        findings.append({"title": title.strip(), "evidence": evidence.group(1).strip() if evidence else ""})
    return findings


def parse_decompilation(report: Path) -> dict[str, object]:
    text = report.read_text(encoding="utf-8", errors="replace") if report.is_file() else ""
    match = re.search(r"## Decompiler Notes\n(.*?)(?=\n## |\Z)", text, re.S)
    notes = match.group(1) if match else ""
    attempted = len(re.findall(r"-import exited \d+", notes)) + notes.count("Ghidra timed out on ")
    succeeded = notes.count("-import exited 0")
    failed = attempted - succeeded
    no_eligible = "No ELF binaries found for Ghidra import." in notes
    if no_eligible:
        status = "no_eligible_elf"
    elif attempted and failed == 0:
        status = "complete"
    elif attempted:
        status = "partial"
    else:
        status = "not_run"
    return {
        "status": status,
        "eligible_files_attempted": attempted,
        "files_succeeded": succeeded,
        "files_failed_or_timed_out": failed,
    }


def worker(root: Path, record_path: Path, output: Path, max_ghidra_files: int, max_extract_mb: int) -> int:
    record = FirmwareRecord.from_json(json.loads(record_path.read_text()))
    started = datetime.now(timezone.utc)
    result: dict[str, object] = {
        "product": record.product,
        "vendor": vendor(record.product),
        "version": record.version,
        "release_date": record.release_date or record.uploaded_at,
        "sha256": record.sha256,
        "firmware": record.path,
        "started_at": started.replace(microsecond=0).isoformat(),
        "status": "failed",
        "potential_findings": [],
        "confirmed_findings": [],
    }
    try:
        auditor = FirmwareAuditor(
            root,
            max_ghidra_files=max_ghidra_files,
            max_extract_bytes=max_extract_mb * 1024 * 1024,
        )
        report = auditor.audit(record)
        triage_path = report.with_name(report.name.removesuffix(".md") + ".zero-day.json")
        triage = json.loads(triage_path.read_text()) if triage_path.is_file() else {}
        candidates = triage.get("candidates", [])
        confirmed = [
            item for item in candidates
            if item.get("evidence_level") == "L5"
            and str(item.get("disposition", "")).lower().startswith("confirmed")
        ]
        result.update(
            status="completed",
            report=str(report),
            triage_report=str(triage_path) if triage_path.is_file() else None,
            static_findings=parse_static_findings(report),
            decompilation=parse_decompilation(report),
            potential_findings=candidates,
            rejected_candidates=triage.get("rejected_candidates", []),
            service_surface=triage.get("service_surface", []),
            confirmed_findings=confirmed,
        )
    except Exception as exc:
        result["error"] = f"{type(exc).__name__}: {exc}"
    finished = datetime.now(timezone.utc)
    result["finished_at"] = finished.replace(microsecond=0).isoformat()
    result["duration_seconds"] = round((finished - started).total_seconds(), 3)
    output.write_text(json.dumps(result, indent=2) + "\n")
    return 0 if result["status"] == "completed" else 1


def run_one(script: Path, root: Path, record_file: Path, result_file: Path, args: argparse.Namespace) -> dict:
    command = [
        sys.executable, str(script), "worker", "--root", str(root),
        "--record", str(record_file), "--output", str(result_file),
        "--max-ghidra-files", str(args.max_ghidra_files),
        "--max-extract-mb", str(args.max_extract_mb),
    ]
    process = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        start_new_session=True,
    )
    try:
        log, _ = process.communicate(timeout=args.timeout_hours * 3600)
    except subprocess.TimeoutExpired:
        os.killpg(process.pid, signal.SIGTERM)
        try:
            log, _ = process.communicate(timeout=20)
        except subprocess.TimeoutExpired:
            os.killpg(process.pid, signal.SIGKILL)
            log, _ = process.communicate()
        record = json.loads(record_file.read_text())
        result_file.write_text(json.dumps({
            "product": record["product"], "vendor": vendor(record["product"]),
            "version": record.get("version", ""), "sha256": record["sha256"],
            "status": "timeout", "timeout_hours": args.timeout_hours,
            "potential_findings": [], "confirmed_findings": [],
        }, indent=2) + "\n")
    result = json.loads(result_file.read_text())
    result["worker_log_tail"] = log.splitlines()[-20:]
    result_file.write_text(json.dumps(result, indent=2) + "\n")
    return result


def write_summary(campaign: Path, targets: list[FirmwareRecord], results: list[dict]) -> None:
    ordered = sorted(results, key=lambda row: (row.get("vendor", ""), row.get("product", "")))
    payload = {
        "generated_at": datetime.now(timezone.utc).replace(microsecond=0).isoformat(),
        "scope": {
            "routers": len(targets),
            "max_concurrency": 5,
            "per_router_timeout_hours": 3,
            "max_ghidra_files": "all" if not results or any(
                row.get("decompilation", {}).get("eligible_files_attempted", 0) > 5 for row in results
            ) else "bounded",
        },
        "classification": {
            "potential": "static route/source/sink candidate requiring validation",
            "confirmed": "L5 reproducible finding with a confirmed disposition",
        },
        "counts": {
            "completed": sum(row.get("status") == "completed" for row in ordered),
            "failed": sum(row.get("status") == "failed" for row in ordered),
            "timed_out": sum(row.get("status") == "timeout" for row in ordered),
            "route_candidates": sum(len(row.get("potential_findings", [])) for row in ordered),
            "static_heuristic_findings": sum(len(row.get("static_findings", [])) for row in ordered),
            "potential_findings": sum(
                len(row.get("potential_findings", [])) + len(row.get("static_findings", []))
                for row in ordered
            ),
            "confirmed_findings": sum(len(row.get("confirmed_findings", [])) for row in ordered),
            "fully_decompiled": sum(row.get("decompilation", {}).get("status") == "complete" for row in ordered),
            "partially_decompiled": sum(row.get("decompilation", {}).get("status") == "partial" for row in ordered),
            "no_eligible_elf": sum(row.get("decompilation", {}).get("status") == "no_eligible_elf" for row in ordered),
        },
        "targets": ordered,
    }
    (campaign / "summary.json").write_text(json.dumps(payload, indent=2) + "\n")
    lines = [
        "# 100-Router Vulnerability Hunt", "",
        "Potential findings are static leads. Confirmed findings require L5 reproducible evidence.", "",
        "| Vendor | Product | Version | Status | Static | Route candidates | Total potential | Confirmed |",
        "|---|---|---|---|---:|---:|---:|---:|",
    ]
    for row in ordered:
        lines.append(
            f"| {row.get('vendor','')} | {row.get('product','')} | {row.get('version') or 'unknown'} | "
            f"{row.get('status','')} | {len(row.get('static_findings', []))} | "
            f"{len(row.get('potential_findings', []))} | "
            f"{len(row.get('static_findings', [])) + len(row.get('potential_findings', []))} | "
            f"{len(row.get('confirmed_findings', []))} |"
        )
    counts = payload["counts"]
    lines += ["", "## Totals", "", *(f"- {key.replace('_', ' ').title()}: {value}" for key, value in counts.items())]
    (campaign / "summary.md").write_text("\n".join(lines) + "\n")


def campaign(args: argparse.Namespace) -> int:
    timestamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    campaign_dir = args.output or ROOT / "router-agent-results" / f"{timestamp}-hundred-router-hunt"
    records_dir, results_dir = campaign_dir / "records", campaign_dir / "results"
    records_dir.mkdir(parents=True, exist_ok=True)
    results_dir.mkdir(parents=True, exist_ok=True)
    selection_path = campaign_dir / "selection.json"
    if selection_path.is_file():
        targets = [FirmwareRecord.from_json(item) for item in json.loads(selection_path.read_text())]
        if len(targets) != args.count:
            raise SystemExit(
                f"Saved selection has {len(targets)} targets, but --count is {args.count}"
            )
        reject_eol_targets(targets)
    else:
        excluded_products: set[str] = set()
        for excluded_campaign in args.exclude_campaign:
            excluded_selection = excluded_campaign / "selection.json"
            if not excluded_selection.is_file():
                raise SystemExit(f"Missing excluded selection: {excluded_selection}")
            excluded_products.update(
                str(item["product"])
                for item in json.loads(excluded_selection.read_text())
            )
        targets = select_targets(
            args.root, args.count, args.min_year, args.max_year, excluded_products
        )
        reject_eol_targets(targets)
        selection_path.write_text(json.dumps([record.to_json() for record in targets], indent=2) + "\n")
    if args.selection_only:
        print(f"Campaign: {campaign_dir}")
        print(f"Selected {len(targets)} distinct non-excluded products")
        return 0
    jobs = []
    results = []
    for index, record in enumerate(targets, 1):
        record_file = records_dir / f"{index:03d}-{record.sha256[:12]}.json"
        result_file = results_dir / f"{index:03d}-{record.sha256[:12]}.json"
        record_file.write_text(json.dumps(record.to_json(), indent=2) + "\n")
        if result_file.is_file():
            try:
                existing = json.loads(result_file.read_text())
            except (OSError, json.JSONDecodeError):
                existing = None
            if existing and existing.get("status") in {"completed", "failed", "timeout"}:
                results.append(existing)
                continue
        jobs.append((record_file, result_file, record))
    print(f"Campaign: {campaign_dir}", flush=True)
    print(
        f"Targets: {len(targets)}; retained: {len(results)}; remaining: {len(jobs)}; "
        f"workers: {args.workers}; timeout: {args.timeout_hours}h each",
        flush=True,
    )
    write_summary(campaign_dir, targets, results)
    script = Path(__file__).resolve()
    with ThreadPoolExecutor(max_workers=args.workers) as executor:
        futures = {
            executor.submit(run_one, script, args.root, record_file, result_file, args): record
            for record_file, result_file, record in jobs
        }
        for index, future in enumerate(as_completed(futures), 1):
            result = future.result()
            results.append(result)
            write_summary(campaign_dir, targets, results)
            print(
                f"[{index}/{len(targets)}] {result['status']}: {result['product']} "
                f"static={len(result.get('static_findings', []))} "
                f"route_candidates={len(result.get('potential_findings', []))} "
                f"confirmed={len(result.get('confirmed_findings', []))}",
                flush=True,
            )
    write_summary(campaign_dir, targets, results)
    print(campaign_dir / "summary.json")
    print(campaign_dir / "summary.md")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    sub = parser.add_subparsers(dest="command", required=True)
    run = sub.add_parser("run")
    run.add_argument("--root", type=Path, default=Path("known_firmware"))
    run.add_argument("--count", type=int, default=100)
    run.add_argument("--workers", type=int, default=5, choices=range(1, 6))
    run.add_argument("--timeout-hours", type=float, default=3.0)
    run.add_argument("--min-year", type=int, default=2021)
    run.add_argument("--max-year", type=int, default=2026)
    run.add_argument("--max-ghidra-files", type=int, default=5, help="Maximum ELF files per router; 0 analyzes all eligible ELF files")
    run.add_argument("--max-extract-mb", type=int, default=768)
    run.add_argument("--output", type=Path)
    run.add_argument(
        "--exclude-campaign",
        type=Path,
        action="append",
        default=[],
        help="Exclude products listed in another campaign's selection.json",
    )
    run.add_argument("--selection-only", action="store_true")
    work = sub.add_parser("worker")
    work.add_argument("--root", type=Path, required=True)
    work.add_argument("--record", type=Path, required=True)
    work.add_argument("--output", type=Path, required=True)
    work.add_argument("--max-ghidra-files", type=int, required=True)
    work.add_argument("--max-extract-mb", type=int, required=True)
    args = parser.parse_args()
    if args.command == "worker":
        return worker(args.root, args.record, args.output, args.max_ghidra_files, args.max_extract_mb)
    return campaign(args)


if __name__ == "__main__":
    raise SystemExit(main())
