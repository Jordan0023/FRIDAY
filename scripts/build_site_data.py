#!/usr/bin/env python3
from __future__ import annotations

import json
import re
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
KNOWN = ROOT / "known_firmware"
SITE_DATA = ROOT / "site" / "data"


def main() -> int:
    manifest_path = KNOWN / "manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    records = sorted(
        manifest.get("firmware", {}).values(),
        key=lambda record: (record.get("product", ""), record.get("filename", "")),
    )

    firmware = []
    finding_counts: Counter[str] = Counter()
    severity_counts: Counter[str] = Counter()
    total_findings = 0
    extracted_count = 0

    for record in records:
        report_path = KNOWN / record.get("report_path", "")
        report_text = report_path.read_text(encoding="utf-8") if report_path.is_file() else ""
        findings = parse_findings(report_text)
        extraction_notes = parse_section(report_text, "Extraction Notes")
        categories = [finding["title"] for finding in findings]
        severity = assess_severity(categories)

        for category in categories:
            finding_counts[category] += 1
        severity_counts[severity["label"]] += 1
        total_findings += len(findings)
        extracted_count += any("existing extraction directory" in note.lower() for note in extraction_notes)

        firmware.append(
            {
                "product": record.get("product", ""),
                "title": clean_value(record.get("title")) or router_title(record),
                "filename": record.get("filename", ""),
                "version": clean_value(record.get("version")) or version_from_filename(record.get("filename", "")),
                "release_date": clean_value(record.get("release_date")) or "Not listed",
                "uploaded_at": clean_value(record.get("uploaded_at")) or clean_value(record.get("release_date")) or "",
                "uploaded_at_source": upload_date_source(record),
                "first_seen": clean_value(record.get("first_seen")) or "",
                "last_seen": clean_value(record.get("last_seen")) or "",
                "size": record.get("size", 0),
                "size_mb": round(record.get("size", 0) / (1024 * 1024), 1),
                "sha256": record.get("sha256", ""),
                "url": record.get("url", ""),
                "path": record.get("path", ""),
                "report_path": record.get("report_path", ""),
                "severity": severity,
                "findings": findings,
                "extraction_notes": extraction_notes,
            }
        )

    data = {
        "generated_at": datetime.now(timezone.utc).replace(microsecond=0).isoformat(),
        "manifest_updated": manifest.get("updated", ""),
        "summary": {
            "products": len(manifest.get("products", {})),
            "firmware": len(firmware),
            "findings": total_findings,
            "extracted": extracted_count,
            "total_size_mb": round(sum(item["size"] for item in firmware) / (1024 * 1024), 1),
        },
        "finding_counts": dict(sorted(finding_counts.items())),
        "severity_counts": dict(sorted(severity_counts.items())),
        "firmware": firmware,
    }

    SITE_DATA.mkdir(parents=True, exist_ok=True)
    (SITE_DATA / "firmware-dashboard.json").write_text(json.dumps(data, indent=2), encoding="utf-8")
    (SITE_DATA / "firmware-dashboard.js").write_text(
        "window.FIRMWARE_DASHBOARD_DATA = "
        + json.dumps(data, separators=(",", ":"))
        + ";\n",
        encoding="utf-8",
    )
    print(f"Wrote {SITE_DATA / 'firmware-dashboard.json'}")
    print(f"Wrote {SITE_DATA / 'firmware-dashboard.js'}")
    print(f"Firmware records: {len(firmware)}")
    print(f"Static findings: {total_findings}")
    return 0


def parse_findings(report: str) -> list[dict[str, str]]:
    section = section_text(report, "Static Findings")
    if not section or "No heuristic findings were identified" in section:
        return []
    chunks = re.split(r"\n### ", section)
    findings = []
    for chunk in chunks:
        chunk = chunk.strip()
        if not chunk:
            continue
        lines = chunk.splitlines()
        title = lines[0].removeprefix("### ").strip()
        evidence = ""
        description_lines = []
        for line in lines[1:]:
            clean = line.strip()
            if clean.startswith("Evidence:"):
                evidence = clean.removeprefix("Evidence:").strip().strip("`")
            elif clean:
                description_lines.append(clean)
        findings.append(
            {
                "title": title,
                "description": " ".join(description_lines),
                "evidence": evidence,
            }
        )
    return findings


def parse_section(report: str, heading: str) -> list[str]:
    text = section_text(report, heading)
    notes = []
    for line in text.splitlines():
        line = line.strip()
        if line.startswith("- "):
            notes.append(line[2:])
    return notes


def section_text(report: str, heading: str) -> str:
    pattern = rf"## {re.escape(heading)}\n(?P<body>.*?)(?=\n## |\Z)"
    match = re.search(pattern, report, flags=re.S)
    return match.group("body").strip() if match else ""


def clean_value(value: object) -> str:
    text = str(value or "").strip()
    return "" if text.lower() in {"", "unknown", "n/a", "none"} else text


def version_from_filename(filename: str) -> str:
    patterns = [
        r"(?:^|[-_])V(?:ersion[_-]?)?(\d+(?:\.\d+)+(?:_\d+(?:\.\d+)*)?)",
        r"(?:^|[-_])v(\d+(?:\.\d+)+(?:_\d+(?:\.\d+)*)?)",
        r"Firmware[_ -]Version[_ -](\d+(?:\.\d+)+(?:_\d+(?:\.\d+)*)?)",
    ]
    for pattern in patterns:
        match = re.search(pattern, filename, flags=re.I)
        if match:
            return match.group(1)
    return "Not listed"


def router_title(record: dict[str, object]) -> str:
    product = clean_value(record.get("product")) or "Unknown model"
    version = clean_value(record.get("version")) or version_from_filename(str(record.get("filename", "")))
    if version and version != "Not listed":
        return f"Netgear {product} firmware {version}"
    return f"Netgear {product} firmware"


def upload_date_source(record: dict[str, object]) -> str:
    if clean_value(record.get("uploaded_at")):
        return "Netgear upload"
    if clean_value(record.get("release_date")):
        return "Release date"
    return "Not listed"


def assess_severity(categories: list[str]) -> dict[str, str | int]:
    if not categories:
        return {
            "label": "No findings",
            "rank": 0,
            "reason": "No heuristic findings were identified.",
        }

    high_categories = {
        "Private keys or certificates bundled in firmware",
        "Hard-coded credentials or secrets",
        "Command execution helpers",
        "Setuid files present",
        "Outdated crypto/library markers",
    }
    medium_categories = {
        "Remote shell services present",
        "HTTP CGI/admin attack surface",
        "Potential memory-unsafe C functions",
    }

    high_hits = [category for category in categories if category in high_categories]
    medium_hits = [category for category in categories if category in medium_categories]

    if high_hits or len(medium_hits) >= 3:
        reason = high_hits[0] if high_hits else "Multiple medium-priority findings"
        return {"label": "High", "rank": 3, "reason": reason}
    if medium_hits:
        return {"label": "Medium", "rank": 2, "reason": medium_hits[0]}
    return {"label": "Review", "rank": 1, "reason": categories[0]}


if __name__ == "__main__":
    raise SystemExit(main())
