#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from dataclasses import asdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from netgear_firmware_audit.advanced_analysis import (
    archive_test_cases,
    auth_test_matrix,
    build_runtime_launch_plan,
    classify_trace,
    confirmation_policy,
    diff_fingerprints,
    dynamic_sink_spec,
    fingerprint_tree,
    generate_archive_corpus,
    profile_runtime,
    safe_validation_recipes,
    variant_matches,
)
from netgear_firmware_audit.zero_day import analyze_zero_day_surface


def main() -> int:
    parser = argparse.ArgumentParser(description="Advanced, non-destructive firmware vulnerability analysis")
    sub = parser.add_subparsers(dest="command", required=True)
    scan = sub.add_parser("scan", help="Profile a rootfs and emit source/sink analysis")
    scan.add_argument("rootfs", type=Path)
    scan.add_argument("--product", default="")
    scan.add_argument("--output", type=Path, help="Write JSON to this file instead of stdout")
    diff = sub.add_parser("diff", help="Compare executable fingerprints between firmware rootfs trees")
    diff.add_argument("old", type=Path)
    diff.add_argument("new", type=Path)
    sub.add_parser("recipes", help="Print bounded safe-validation payload recipes")
    plan = sub.add_parser("deep-plan", help="Emit runtime, authentication, sink, archive, and confirmation plans")
    plan.add_argument("rootfs", type=Path)
    plan.add_argument("--product", default="")
    trace = sub.add_parser("classify-trace", help="Classify a QEMU/strace/debugger trace")
    trace.add_argument("trace", type=Path)
    corpus = sub.add_parser("archive-corpus", help="Generate a bounded archive-validation corpus")
    corpus.add_argument("output", type=Path)
    variants = sub.add_parser("variants", help="Find identical executables across product rootfs trees")
    variants.add_argument("trees", nargs="+", help="PRODUCT=ROOTFS")
    variants.add_argument("--output", type=Path, help="Write JSON to this file instead of stdout")
    args = parser.parse_args()
    if args.command == "scan":
        payload = analyze_zero_day_surface(args.rootfs, args.product).to_json()
        if args.output:
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(payload + "\n", encoding="utf-8")
            print(args.output)
        else:
            print(payload)
    elif args.command == "diff":
        print(json.dumps(diff_fingerprints(fingerprint_tree(args.old), fingerprint_tree(args.new)), indent=2))
    elif args.command == "recipes":
        print(json.dumps([asdict(item) for item in safe_validation_recipes()], indent=2))
    elif args.command == "deep-plan":
        payload = {
            "runtime": asdict(build_runtime_launch_plan(args.rootfs, args.product)),
            "authentication": [asdict(item) for item in auth_test_matrix()],
            "dynamic_sinks": dynamic_sink_spec(),
            "archive_cases": [asdict(item) for item in archive_test_cases()],
            "confirmation": confirmation_policy(),
        }
        print(json.dumps(payload, indent=2))
    elif args.command == "classify-trace":
        print(json.dumps(asdict(classify_trace(args.trace.read_text(encoding="utf-8", errors="ignore"))), indent=2))
    elif args.command == "archive-corpus":
        print(json.dumps([str(path) for path in generate_archive_corpus(args.output)], indent=2))
    else:
        trees = {}
        for item in args.trees:
            product, separator, path = item.partition("=")
            if not separator:
                parser.error("variant trees must use PRODUCT=ROOTFS")
            trees[product] = Path(path)
        payload = json.dumps(variant_matches(trees), indent=2)
        if args.output:
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(payload + "\n", encoding="utf-8")
            print(args.output)
        else:
            print(payload)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
