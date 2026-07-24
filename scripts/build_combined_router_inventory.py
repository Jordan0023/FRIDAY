#!/usr/bin/env python3
"""Combine the 74-router campaign with its 26 resolved predecessor targets."""

from __future__ import annotations

import json
import re
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
KNOWN = ROOT / "known_firmware"
MANIFEST = KNOWN / "manifest.json"
EOL = ROOT / "site/data/eol-products.json"
SEVENTY_FOUR = (
    ROOT
    / "router-agent-results/"
    "20260722T235859Z-seventy-four-router-exhaustive-decompile/inventory.json"
)
PREDECESSOR_RECEIPTS = (
    ROOT
    / "router-agent-results/"
    "20260721T143715Z-hundred-router-exhaustive-decompile/receipts"
)
OUTPUT = KNOWN / "combined_100_router_inventory.json"

# This directory has two receipt files but is not a completed router-wide run.
PARTIAL_PREDECESSOR_HASHES = {
    "8d253ef36151c2a912c6c43e1a6f55b69133c2db5ac5051952a6f22ff6e567b3"
}


def normalized(value: str) -> str:
    value = value.removeprefix("OpenWrt ")
    return " ".join(value.casefold().replace("_", " ").replace("-", " ").split())


def revision_related(left: str, right: str) -> bool:
    """Return true only when names differ by an explicit hardware revision."""
    compact_left = left.replace(" ", "")
    compact_right = right.replace(" ", "")
    for longer, shorter in (
        (compact_left, compact_right),
        (compact_right, compact_left),
    ):
        if longer.startswith(shorter):
            remainder = longer[len(shorter):]
            if re.fullmatch(r"v\d+(?:[a-z]+)?", remainder):
                return True
    for longer, shorter in ((left, right), (right, left)):
        if longer.startswith(shorter + " "):
            remainder = longer[len(shorter) + 1:]
            if re.fullmatch(r"v\d+(?:\s+\w+)*", remainder):
                return True
    return False


def main() -> int:
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    records = manifest.get("firmware", {})
    seventy_four = json.loads(SEVENTY_FOUR.read_text(encoding="utf-8"))
    catalog = json.loads(EOL.read_text(encoding="utf-8"))
    eol_names = {
        normalized(str(product))
        for product in catalog.get("products", [])
        if str(product).strip()
    }

    entries: dict[str, dict[str, object]] = {}
    for item in seventy_four:
        digest = str(item["sha256"])
        record = records.get(digest, {})
        entries[digest] = {
            "product": item["product"],
            "version": record.get("version"),
            "sha256": digest,
            "sources": ["seventy_four_router_campaign"],
            "fully_decompiled": False,
        }

    orphan_hashes: list[str] = []
    for directory in sorted(PREDECESSOR_RECEIPTS.iterdir()):
        if not directory.is_dir() or directory.name in PARTIAL_PREDECESSOR_HASHES:
            continue
        record = records.get(directory.name)
        if not record:
            orphan_hashes.append(directory.name)
            continue
        entry = entries.setdefault(
            directory.name,
            {
                "product": record["product"],
                "version": record.get("version"),
                "sha256": directory.name,
                "sources": [],
                "fully_decompiled": True,
            },
        )
        entry["fully_decompiled"] = True
        sources = entry["sources"]
        if "fully_decompiled_predecessor_campaign" not in sources:
            sources.append("fully_decompiled_predecessor_campaign")

    active: list[dict[str, object]] = []
    removed: list[dict[str, object]] = []
    review: list[dict[str, object]] = []
    for entry in sorted(entries.values(), key=lambda item: normalized(str(item["product"]))):
        name = normalized(str(entry["product"]))
        if name in eol_names:
            entry["eol_match"] = "exact_catalog_match"
            removed.append(entry)
            continue
        # Similar names are review-only. Hardware revisions are never collapsed.
        related = sorted(
            product
            for product in catalog.get("products", [])
            if revision_related(name, normalized(str(product)))
        )
        entry["eol_match"] = None
        if related:
            review.append(
                {
                    "product": entry["product"],
                    "sha256": entry["sha256"],
                    "similar_eol_catalog_entries": related,
                    "disposition": "retained; exact hardware-revision match required",
                }
            )
        active.append(entry)

    output = {
        "generated_at": datetime.now(timezone.utc).replace(microsecond=0).isoformat(),
        "source_counts": {
            "seventy_four_router_campaign": len(seventy_four),
            "fully_decompiled_predecessor_campaign": sum(
                bool(entry["fully_decompiled"]) for entry in entries.values()
            ),
        },
        "combined_unique_count_before_eol": len(entries),
        "active_count_after_eol": len(active),
        "eol_removed_count": len(removed),
        "eol_policy": (
            "Exact normalized product matches only; no hardware-revision inference."
        ),
        "orphan_predecessor_hashes_excluded": orphan_hashes,
        "partial_predecessor_hashes_excluded": sorted(PARTIAL_PREDECESSOR_HASHES),
        "eol_removed": removed,
        "eol_review_required": review,
        "routers": active,
    }
    OUTPUT.write_text(
        json.dumps(output, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    print(json.dumps({
        "output": str(OUTPUT),
        "combined": len(entries),
        "active": len(active),
        "eol_removed": len(removed),
        "review_required": len(review),
        "fully_decompiled": output["source_counts"][
            "fully_decompiled_predecessor_campaign"
        ],
    }, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
