#!/usr/bin/env python3
"""Run a reproducible, offline first-pass hunt across fifteen router images.

This does not label static leads as vulnerabilities.  It extracts one exact image
per model, runs the repository's route/auth/sink triage, and emits a campaign
matrix that identifies which targets have enough evidence for manual promotion.
"""
from __future__ import annotations

import argparse
import json
import sys
from dataclasses import asdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from netgear_firmware_audit.advanced_analysis import discover_rootfs_candidates
from netgear_firmware_audit.audit import FirmwareAuditor
from netgear_firmware_audit.manifest import Manifest
from netgear_firmware_audit.zero_day import analyze_zero_day_surface


TARGETS = (
    "ASUS ZenWiFi BD4",
    "ASUS ZenWiFi BD5",
    "ASUS ZenWiFi BE5000",
    "ASUS 4G-BE58",
    "ASUS RT-BE96U",
    "ASUS ROG Rapture GT-BE98 Pro",
    "ASUS ZenWiFi BQ16 Pro",
    "TP-Link Archer AX73",
    "TP-Link Archer BE550",
    "TP-Link Archer BE800",
    "TP-Link Deco BE85",
    "R7000",
    "XR1000",
    "GL.iNet GL-BE9300 Flint 3",
    "GL.iNet GL-MT6000 Flint 2",
)


def select_latest(manifest: Manifest) -> list:
    selected = []
    for product in TARGETS:
        candidates = [
            record for record in manifest.records.values()
            if record.product == product and (manifest.root / record.path).is_file()
        ]
        if not candidates:
            raise SystemExit(f"No local firmware found for {product}")
        selected.append(max(candidates, key=lambda r: (r.release_date or "", r.version or "", r.sha256)))
    return selected


def summarize(root: Path, records: list, output: Path) -> dict:
    rows = []
    for record in records:
        extraction = root / "extracted" / record.sha256[:16]
        roots = discover_rootfs_candidates(extraction) if extraction.exists() else []
        row = {
            "product": record.product,
            "version": record.version,
            "sha256": record.sha256,
            "firmware": record.path,
            "rootfs": str(roots[0]) if roots else None,
            "status": "no-usable-rootfs",
            "candidate_count": 0,
            "impactful_unauthenticated_leads": 0,
            "top_candidates": [],
            "reviewable_service_leads": 0,
            "top_services": [],
        }
        if roots:
            cached = root / "reports" / Path(record.path).parent.name / f"{record.filename}.zero-day.json"
            if cached.is_file():
                triage_data = json.loads(cached.read_text())
            else:
                triage_data = asdict(analyze_zero_day_surface(roots[0], record.product, record.version))
            candidates = list(triage_data["candidates"])
            impactful = [
                c for c in candidates
                if c["auth_class"] in {"none", "likely-none"}
                and c["exposure"] in {"lan", "wan", "lan/wan", "unknown"}
                and c["impact_class"] in {"rce", "dos", "memory-corruption"}
            ]
            services = triage_data["service_surface"]
            reviewable = []
            seen_services = set()
            for service in services:
                key = (service["service"], service["protocol"], service["exposure"], service["auth_class"])
                if (
                    service["risk"] == "high"
                    and service["exposure"] != "outbound"
                    and service["auth_class"] in {"none", "unknown"}
                    and key not in seen_services
                ):
                    seen_services.add(key)
                    reviewable.append(service)
            row.update(
                status="triaged",
                candidate_count=len(candidates),
                impactful_unauthenticated_leads=len(impactful),
                top_candidates=candidates[:5],
                reviewable_service_leads=len(reviewable),
                top_services=reviewable[:5],
            )
        rows.append(row)

    result = {
        "scope": "offline firmware and isolated emulation only",
        "confirmation_rule": "A lead is not a zero-day without repeatable reachability, impact, and a distinct unpublished root cause.",
        "targets": rows,
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2) + "\n")
    markdown = output.with_suffix(".md")
    lines = [
        "# Fifteen-router zero-day hunting campaign",
        "",
        "Static findings are review leads, not confirmed vulnerabilities. Testing is limited to archived firmware and isolated emulators.",
        "",
        "| Product | Version | Exact SHA-256 | Rootfs | HTTP leads | Impactful unauth HTTP | High-risk services |",
        "|---|---|---|---:|---:|---:|---:|",
    ]
    for row in rows:
        lines.append(
            f"| {row['product']} | {row['version'] or 'unknown'} | `{row['sha256']}` | "
            f"{'yes' if row['rootfs'] else 'no'} | {row['candidate_count']} | {row['impactful_unauthenticated_leads']} | "
            f"{row['reviewable_service_leads']} |"
        )
    lines += ["", "## Promotion queue", ""]
    promoted = sorted(
        rows,
        key=lambda r: (r["impactful_unauthenticated_leads"], r["reviewable_service_leads"], r["candidate_count"]),
        reverse=True,
    )
    for row in promoted:
        top = row["top_candidates"][0] if row["top_candidates"] else None
        service = row["top_services"][0] if row["top_services"] else None
        if top:
            detail = f"top route `{top['route']}` at {top['evidence_level']}"
        elif service:
            detail = f"top non-HTTP service `{service['service']}` (auth `{service['auth_class']}`, exposure `{service['exposure']}`)"
        else:
            detail = row["status"]
        lines.append(
            f"- **{row['product']}**: {row['impactful_unauthenticated_leads']} impactful unauthenticated HTTP leads, "
            f"{row['reviewable_service_leads']} reviewable high-risk service leads; {detail}."
        )
    lines += [
        "",
        "## Current conclusion",
        "",
        "No confirmed zero-day was produced by this first pass. A candidate requires route/service-specific control-flow evidence, "
        "a proven unauthenticated boundary, and repeatable impact in an isolated emulator before promotion.",
        "",
        "Five images still lack a usable root filesystem because their signed, nested, or damaged containers were not decoded: "
        "Archer AX73, Archer BE550, Archer BE800, Deco BE85, and XR1000.",
    ]
    markdown.write_text("\n".join(lines) + "\n")
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("known_firmware"))
    parser.add_argument("--extract", action="store_true", help="Audit/extract selected images missing a usable rootfs")
    parser.add_argument("--max-extract-mb", type=int, default=768)
    parser.add_argument("--output", type=Path, default=Path("known_firmware/reports/FIFTEEN_ROUTER_HUNT_2026-07-15.json"))
    args = parser.parse_args()
    manifest = Manifest(args.root).load()
    records = select_latest(manifest)
    if args.extract:
        auditor = FirmwareAuditor(args.root, max_ghidra_files=0, max_extract_bytes=args.max_extract_mb * 1024 * 1024)
        for index, record in enumerate(records, 1):
            extraction = args.root / "extracted" / record.sha256[:16]
            if discover_rootfs_candidates(extraction) if extraction.exists() else []:
                print(f"[{index}/15] existing rootfs: {record.product}", flush=True)
                continue
            print(f"[{index}/15] extracting: {record.product}", flush=True)
            try:
                report = auditor.audit(record)
                record.report_path = str(report.relative_to(args.root))
                manifest.records[record.sha256] = record
                manifest.save()
            except Exception as exc:
                print(f"[{index}/15] extraction failed: {exc}", file=sys.stderr, flush=True)
    result = summarize(args.root, records, args.output)
    usable = sum(row["rootfs"] is not None for row in result["targets"])
    print(f"Usable root filesystems: {usable}/15")
    print(args.output)
    print(args.output.with_suffix('.md'))
    return 0 if usable == 15 else 2


if __name__ == "__main__":
    raise SystemExit(main())
