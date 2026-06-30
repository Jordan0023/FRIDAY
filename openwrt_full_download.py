#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path

from netgear_firmware_audit.openwrt import DEFAULT_TARGETS, download_openwrt_router_firmware


def main() -> int:
    parser = argparse.ArgumentParser(description="Download OpenWrt router firmware into known_firmware.")
    parser.add_argument("--root", type=Path, default=Path("known_firmware"))
    parser.add_argument("--timeout", type=int, default=90, help="Network timeout in seconds.")
    parser.add_argument("--release", default=None, help="OpenWrt release, default is latest stable from downloads.openwrt.org.")
    parser.add_argument(
        "--target",
        action="append",
        default=[],
        help=f"OpenWrt target/subtarget, repeatable. Defaults: {', '.join(DEFAULT_TARGETS)}",
    )
    parser.add_argument("--limit-products", type=int, default=None)
    parser.add_argument("--limit-firmware", type=int, default=1)
    parser.add_argument("--resume", action="store_true", help="Skip OpenWrt products already recorded in the manifest.")
    parser.add_argument("--analyze", action="store_true", help="Run static analysis after each new download.")
    parser.add_argument("--max-extract-mb", type=int, default=768, help="Stop extracting one firmware after this many MB during analysis.")
    parser.add_argument("--cleanup-extracted", action="store_true", help="Delete extracted filesystems after each report is written.")
    parser.add_argument("--build-site", action="store_true", help="Rebuild site/data/firmware-dashboard.* after download.")
    args = parser.parse_args()

    products, firmware, downloaded = download_openwrt_router_firmware(
        root=args.root,
        timeout=args.timeout,
        release=args.release,
        targets=args.target or None,
        limit_products=args.limit_products,
        limit_firmware=args.limit_firmware,
        resume=args.resume,
        analyze=args.analyze,
        max_extract_mb=args.max_extract_mb,
        cleanup_extracted=args.cleanup_extracted,
        build_site=args.build_site,
    )
    print(f"OpenWrt products checked: {products}")
    print(f"OpenWrt firmware links found: {firmware}")
    print(f"New downloads: {downloaded}")
    print(f"Manifest: {args.root / 'manifest.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
