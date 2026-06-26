#!/usr/bin/env python3
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

from netgear_firmware_audit.discovery import CATEGORY_URL
from netgear_firmware_audit.workflow import check_new_firmware, product_from_model


def main() -> int:
    parser = argparse.ArgumentParser(description="Check for new Netgear firmware and add it to known_firmware.")
    parser.add_argument("--category-url", default=CATEGORY_URL)
    parser.add_argument("--root", type=Path, default=Path("known_firmware"))
    parser.add_argument("--use-browser", action="store_true", help="Use Playwright for JavaScript-rendered pages.")
    parser.add_argument("--analyze", action="store_true", help="Run static analysis for new downloads.")
    parser.add_argument("--timeout", type=int, default=45, help="Network/browser timeout in seconds.")
    parser.add_argument("--limit-products", type=int, default=None)
    parser.add_argument("--limit-firmware", type=int, default=None)
    parser.add_argument("--product", action="append", default=[], help="Seed a product model, e.g. R7000. Repeatable.")
    parser.add_argument("--products-file", type=Path, help="Text file of product models, one per line.")
    parser.add_argument(
        "--skip-site-data",
        action="store_true",
        help="Do not refresh site/data/firmware-dashboard.json after a successful check.",
    )
    args = parser.parse_args()

    models = list(args.product)
    if args.products_file:
        models.extend(
            line.strip()
            for line in args.products_file.read_text(encoding="utf-8").splitlines()
            if line.strip() and not line.lstrip().startswith("#")
        )
    seed_products = [product_from_model(model) for model in models] or None

    checked, downloaded = check_new_firmware(
        root=args.root,
        category_url=args.category_url,
        use_browser=args.use_browser,
        analyze=args.analyze,
        timeout=args.timeout,
        limit_products=args.limit_products,
        limit_firmware=args.limit_firmware,
        seed_products=seed_products,
    )
    print(f"Firmware links checked: {checked}")
    print(f"New downloads: {downloaded}")
    print(f"Manifest: {args.root / 'manifest.json'}")
    if not args.skip_site_data:
        site_builder = Path(__file__).resolve().parent / "scripts" / "build_site_data.py"
        if site_builder.exists():
            subprocess.run([sys.executable, str(site_builder)], check=True)
            print("Dashboard data refreshed: site/data/firmware-dashboard.json")
        else:
            print("Dashboard data refresh skipped: scripts/build_site_data.py not found")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
