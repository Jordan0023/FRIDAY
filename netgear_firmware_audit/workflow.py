from __future__ import annotations

from pathlib import Path

from .audit import FirmwareAuditor
from .discovery import CATEGORY_URL, NetgearDiscovery
from .downloader import FirmwareDownloader
from .manifest import Manifest
from .models import Product


def download_known_set(
    root: Path,
    category_url: str = CATEGORY_URL,
    use_browser: bool = False,
    analyze: bool = False,
    timeout: int = 45,
    limit_products: int | None = None,
    limit_firmware: int | None = None,
    seed_products: list[Product] | None = None,
) -> tuple[int, int, int]:
    root.mkdir(parents=True, exist_ok=True)
    manifest = Manifest(root).load()
    discovery = NetgearDiscovery(use_browser=use_browser, timeout=timeout)
    downloader = FirmwareDownloader(root, timeout=timeout)
    auditor = FirmwareAuditor(root)

    products = seed_products or discovery.discover_products(category_url)
    if limit_products is not None:
        products = products[:limit_products]

    products_seen = 0
    firmware_seen = 0
    downloaded = 0
    for product in products:
        products_seen += 1
        manifest.add_product(product.name, product.url)
        links = discovery.discover_firmware(product)
        if limit_firmware is not None:
            links = links[:limit_firmware]
        for link in links:
            firmware_seen += 1
            if manifest.has_url(link.url):
                continue
            record = downloader.download(link)
            if analyze:
                report = auditor.audit(record)
                record.report_path = str(report.relative_to(root))
            if manifest.upsert(record):
                downloaded += 1
                manifest.save()
    manifest.save()
    return products_seen, firmware_seen, downloaded


def product_from_model(model: str) -> Product:
    name = model.strip().upper()
    return Product(name=name, url=f"https://www.netgear.com/support/product/{name}")


def check_new_firmware(
    root: Path,
    category_url: str = CATEGORY_URL,
    use_browser: bool = False,
    analyze: bool = False,
    timeout: int = 45,
    limit_products: int | None = None,
    limit_firmware: int | None = None,
    seed_products: list[Product] | None = None,
) -> tuple[int, int]:
    manifest = Manifest(root).load()
    discovery = NetgearDiscovery(use_browser=use_browser, timeout=timeout)
    downloader = FirmwareDownloader(root, timeout=timeout)
    auditor = FirmwareAuditor(root)

    products = seed_products or [Product(name=name, url=url) for name, url in sorted(manifest.products.items())]
    if not products:
        products = discovery.discover_products(category_url)
    if limit_products is not None:
        products = products[:limit_products]

    checked = 0
    downloaded = 0
    for product in products:
        manifest.add_product(product.name, product.url)
        links = discovery.discover_firmware(product)
        if limit_firmware is not None:
            links = links[:limit_firmware]
        for link in links:
            checked += 1
            if manifest.has_url(link.url):
                continue
            record = downloader.download(link)
            if analyze:
                report = auditor.audit(record)
                record.report_path = str(report.relative_to(root))
            if manifest.upsert(record):
                downloaded += 1
                manifest.save()
    manifest.save()
    return checked, downloaded
