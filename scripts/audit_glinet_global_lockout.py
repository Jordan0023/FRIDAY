#!/usr/bin/env python3
"""Inventory GL.iNet firmware images for the global WebUI login lockout."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "known_firmware/manifest.json"
EXTRACTED = ROOT / "known_firmware/extracted"
EOL = ROOT / "site/data/eol-products.json"

MARKERS = {
    "global_login_wait": "local login_wait = 0",
    "global_login_fail": "local login_fail = 0",
    "configured_max_failures": 'c:get("oui-httpd", "main", "max_login_fail") or 10',
    "configured_wait": 'c:get("oui-httpd", "main", "login_fail_wait") or 600',
    "increments_unknown_user": "login_fail = login_fail + 1",
    "sets_global_timer": "login_wait = sys.uptime() + login_fail_wait_time",
    "enforces_global_timer": "if login_wait - sys.uptime() > 0 then",
}


def digest(path: Path) -> str:
    value = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            value.update(chunk)
    return value.hexdigest()


def preferred(paths: list[Path]) -> Path:
    def rank(path: Path) -> tuple[int, int, str]:
        text = str(path)
        duplicate = "squashfs-root-0" in text or "squashfs-root-1" in text
        manual = "/manual-rootfs/" in text
        return (duplicate, manual, text)

    return sorted(paths, key=rank)[0]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--output",
        type=Path,
        default=ROOT / "private_disclosures/GLINET_GLOBAL_LOCKOUT_CAMPAIGN_2026-07-24",
    )
    args = parser.parse_args()

    manifest = json.loads(MANIFEST.read_text())
    records = list(manifest.get("firmware", {}).values())
    by_prefix = {record["sha256"][:16]: record for record in records}
    eol_products = set(json.loads(EOL.read_text()).get("products", []))

    grouped: dict[str, list[Path]] = {}
    for path in EXTRACTED.rglob("usr/sbin/gl-ngx-session"):
        relative = path.relative_to(EXTRACTED)
        firmware_prefix = relative.parts[0]
        if firmware_prefix in by_prefix:
            grouped.setdefault(firmware_prefix, []).append(path)

    rows = []
    for prefix, paths in sorted(grouped.items()):
        path = preferred(paths)
        record = by_prefix[prefix]
        text = path.read_text(errors="replace")
        markers = {name: marker in text for name, marker in MARKERS.items()}
        vulnerable = all(markers.values())
        rows.append(
            {
                "product": record.get("product", ""),
                "version": record.get("version", ""),
                "filename": record.get("filename", ""),
                "sha256": record["sha256"],
                "session_sha256": digest(path),
                "architecture": "script",
                "eol": record.get("product", "") in eol_products,
                "vulnerable_global_lockout_logic": vulnerable,
                "markers": markers,
                "session_path": str(path.relative_to(ROOT)),
                "duplicate_extraction_instances": len(paths),
            }
        )

    current = [row for row in rows if not row["eol"]]
    vulnerable_current = [
        row for row in current if row["vulnerable_global_lockout_logic"]
    ]
    families: dict[str, list[dict]] = {}
    for row in vulnerable_current:
        families.setdefault(row["session_sha256"], []).append(row)

    payload = {
        "scope": "Extracted GL.iNet firmware containing usr/sbin/gl-ngx-session",
        "firmware_images": len(rows),
        "current_images": len(current),
        "eol_images": sum(row["eol"] for row in rows),
        "current_images_with_vulnerable_logic": len(vulnerable_current),
        "distinct_vulnerable_session_implementations": len(families),
        "results": rows,
        "families": [
            {
                "session_sha256": session_sha,
                "members": [
                    {
                        "product": row["product"],
                        "version": row["version"],
                        "firmware_sha256": row["sha256"],
                    }
                    for row in members
                ],
            }
            for session_sha, members in sorted(families.items())
        ],
    }

    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "matrix.json").write_text(json.dumps(payload, indent=2) + "\n")

    lines = [
        "# GL.iNet global WebUI lockout firmware matrix",
        "",
        f"- Extracted firmware images: {payload['firmware_images']}",
        f"- Current/non-EOL images: {payload['current_images']}",
        f"- EOL images excluded from active validation: {payload['eol_images']}",
        (
            "- Current images containing the complete vulnerable state machine: "
            f"{payload['current_images_with_vulnerable_logic']}"
        ),
        (
            "- Distinct vulnerable `gl-ngx-session` implementations: "
            f"{payload['distinct_vulnerable_session_implementations']}"
        ),
        "",
        "| Product | Version | EOL | Vulnerable logic | Session family |",
        "|---|---:|:---:|:---:|---|",
    ]
    for row in rows:
        lines.append(
            f"| {row['product']} | {row['version']} | "
            f"{'yes' if row['eol'] else 'no'} | "
            f"{'yes' if row['vulnerable_global_lockout_logic'] else 'no'} | "
            f"`{row['session_sha256'][:16]}` |"
        )
    lines.extend(
        [
            "",
            "Static classification proves code presence, not model-specific runtime "
            "reachability. Dynamic HTTP confirmation must be recorded separately.",
        ]
    )
    (args.output / "matrix.md").write_text("\n".join(lines) + "\n")

    print(json.dumps({key: payload[key] for key in (
        "firmware_images",
        "current_images",
        "eol_images",
        "current_images_with_vulnerable_logic",
        "distinct_vulnerable_session_implementations",
    )}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
