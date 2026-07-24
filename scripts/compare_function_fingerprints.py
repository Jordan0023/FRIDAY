#!/usr/bin/env python3
"""Rank changed functions across two FridayFunctionFingerprints JSONL files."""

from __future__ import annotations

import argparse
import json
from difflib import SequenceMatcher
from pathlib import Path


def load(path: Path) -> list[dict]:
    return [json.loads(line) for line in path.read_text().splitlines() if line]


def tokens(item: dict) -> set[str]:
    return {
        *(f"c:{value}" for value in item.get("callees", [])),
        *(f"s:{value}" for value in item.get("strings", [])),
    }


def similarity(left: dict, right: dict) -> float:
    left_tokens, right_tokens = tokens(left), tokens(right)
    union = left_tokens | right_tokens
    token_score = len(left_tokens & right_tokens) / len(union) if union else 0.0
    size_score = min(left["instructions"], right["instructions"]) / max(
        left["instructions"], right["instructions"], 1
    )
    exact_shape = left["mnemonic_sha256"] == right["mnemonic_sha256"]
    return 0.55 * token_score + 0.35 * size_score + 0.10 * exact_shape


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("affected", type=Path)
    parser.add_argument("fixed", type=Path)
    parser.add_argument("--limit", type=int, default=80)
    args = parser.parse_args()
    affected, fixed = load(args.affected), load(args.fixed)

    old_shapes: dict[str, list[int]] = {}
    new_shapes: dict[str, list[int]] = {}
    for index, item in enumerate(affected):
        old_shapes.setdefault(item["mnemonic_sha256"], []).append(index)
    for index, item in enumerate(fixed):
        new_shapes.setdefault(item["mnemonic_sha256"], []).append(index)

    old_unmatched = {
        index
        for shape, indexes in old_shapes.items()
        if len(indexes) != len(new_shapes.get(shape, []))
        for index in indexes
    }
    new_unmatched = {
        index
        for shape, indexes in new_shapes.items()
        if len(indexes) != len(old_shapes.get(shape, []))
        for index in indexes
    }

    # Preserve function order as a useful stripped-binary matching signal.
    matcher = SequenceMatcher(
        a=[item["mnemonic_sha256"] for item in affected],
        b=[item["mnemonic_sha256"] for item in fixed],
        autojunk=False,
    )
    rows: list[dict] = []
    for tag, i1, i2, j1, j2 in matcher.get_opcodes():
        if tag == "equal":
            continue
        old_block = [index for index in range(i1, i2) if index in old_unmatched]
        new_block = [index for index in range(j1, j2) if index in new_unmatched]
        remaining = set(new_block)
        for old_index in old_block:
            candidates = sorted(
                (
                    (similarity(affected[old_index], fixed[new_index]), new_index)
                    for new_index in remaining
                ),
                reverse=True,
            )
            score, new_index = candidates[0] if candidates else (0.0, None)
            if new_index is not None:
                remaining.remove(new_index)
            rows.append(
                {
                    "score": round(score, 4),
                    "affected": affected[old_index],
                    "fixed": fixed[new_index] if new_index is not None else None,
                    "sequence_block": [i1, i2, j1, j2],
                }
            )
        for new_index in remaining:
            rows.append(
                {
                    "score": 0.0,
                    "affected": None,
                    "fixed": fixed[new_index],
                    "sequence_block": [i1, i2, j1, j2],
                }
            )

    rows.sort(
        key=lambda row: (
            -len(tokens(row["affected"] or {}) | tokens(row["fixed"] or {})),
            -row["score"],
        )
    )
    print(json.dumps(rows[: args.limit], indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
