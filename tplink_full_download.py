#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path

from netgear_firmware_audit.tp_link import download_tplink_router_firmware


def main() -> int:
    parser = argparse.ArgumentParser(description="Download TP-Link US router firmware into known_firmware.")
    parser.add_argument("--root", type=Path, default=Path("known_firmware"))
    parser.add_argument("--timeout", type=int, default=90, help="Network timeout in seconds.")
    parser.add_argument("--limit-products", type=int, default=None)
    parser.add_argument("--limit-firmware", type=int, default=None)
    parser.add_argument("--resume", action="store_true", help="Skip TP-Link products already recorded in the manifest.")
    parser.add_argument("--build-site", action="store_true", help="Rebuild site/data/firmware-dashboard.* after download.")
    args = parser.parse_args()

    products, firmware, downloaded = download_tplink_router_firmware(
        root=args.root,
        timeout=args.timeout,
        limit_products=args.limit_products,
        limit_firmware=args.limit_firmware,
        resume=args.resume,
        build_site=args.build_site,
    )
    print(f"TP-Link products checked: {products}")
    print(f"TP-Link firmware links found: {firmware}")
    print(f"New downloads: {downloaded}")
    print(f"Manifest: {args.root / 'manifest.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
