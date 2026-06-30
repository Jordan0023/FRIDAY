#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path

from netgear_firmware_audit.discovery import CATEGORY_URL
from netgear_firmware_audit.workflow import download_known_set, product_from_model


def main() -> int:
    parser = argparse.ArgumentParser(description="Download Netgear router/extender firmware into known_firmware.")
    parser.add_argument("--category-url", default=CATEGORY_URL)
    parser.add_argument("--root", type=Path, default=Path("known_firmware"))
    parser.add_argument("--use-browser", action="store_true", help="Use Playwright for JavaScript-rendered pages.")
    parser.add_argument("--analyze", action="store_true", help="Run static analysis after each new download.")
    parser.add_argument("--timeout", type=int, default=45, help="Network/browser timeout in seconds.")
    parser.add_argument("--limit-products", type=int, default=None)
    parser.add_argument("--limit-firmware", type=int, default=None)
    parser.add_argument("--product", action="append", default=[], help="Seed a product model, e.g. R7000. Repeatable.")
    parser.add_argument("--products-file", type=Path, help="Text file of product models, one per line.")
    parser.add_argument("--resume", action="store_true", help="Skip products already recorded in the manifest.")
    parser.add_argument("--product-timeout", type=int, default=None, help="Maximum seconds to spend discovering one product before skipping it.")
    args = parser.parse_args()

    models = list(args.product)
    if args.products_file:
        models.extend(
            line.strip()
            for line in args.products_file.read_text(encoding="utf-8").splitlines()
            if line.strip() and not line.lstrip().startswith("#")
        )
    seed_products = [product_from_model(model) for model in models] or None

    products, firmware, downloaded = download_known_set(
        root=args.root,
        category_url=args.category_url,
        use_browser=args.use_browser,
        analyze=args.analyze,
        timeout=args.timeout,
        limit_products=args.limit_products,
        limit_firmware=args.limit_firmware,
        seed_products=seed_products,
        skip_known_products=args.resume,
        product_timeout=args.product_timeout,
    )
    print(f"Products checked: {products}")
    print(f"Firmware links found: {firmware}")
    print(f"New downloads: {downloaded}")
    print(f"Manifest: {args.root / 'manifest.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
