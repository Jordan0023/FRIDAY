from __future__ import annotations

import hashlib
import html
import json
import re
from dataclasses import dataclass
from pathlib import Path
from urllib.parse import quote, urljoin, urlparse

import requests

from .manifest import Manifest
from .models import FirmwareLink, FirmwareRecord, Product, safe_name


TP_LINK_SUPPORT = "https://www.tp-link.com"
TP_LINK_DOWNLOAD_CENTER = f"{TP_LINK_SUPPORT}/us/support/download/"
TP_LINK_USER_AGENT = "Googlebot/2.1 (+http://www.google.com/bot.html)"

ROUTER_TYPE_PATTERNS = [
    "/deco-mesh-wifi/product-family/",
    "/home-networking/wifi-router/",
    "/home-networking/wired-router/",
    "/home-networking/5g-4g-router/",
    "/home-networking/dsl-gateway/",
    "/home-networking/dsl-modem-router/",
    "/home-networking/cable-gateway/",
    "/home-networking/cable-modem-router/",
    "/home-networking/smart-home-router/",
    "/business-networking/vpn-router/",
    "/business-networking/load-balance-router/",
    "/business-networking/soho-router/",
    "/business-networking/omada-router-wired-router/",
    "/business-networking/omada-router-wifi-router/",
    "/business-networking/omada-router-integrated-router/",
    "/business-networking/omada-router-5g-4g-wifi-router/",
    "/business-networking/omada-pro-router-wired-router/",
    "/business-networking/omada-pro-router-4g-wifi-router/",
    "/business-networking/omada-fusion-gateway-series/",
    "/business-networking/omada-fusion-pro-gateway-series/",
    "/business-networking/soho-festa-gateway/",
    "/service-provider/dsl-router/",
]


@dataclass(frozen=True)
class TpLinkModel:
    product: Product
    slug: str
    menu_name: str
    type_name: str


class TpLinkDiscovery:
    def __init__(self, timeout: int = 45) -> None:
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update(
            {
                "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
                "Accept-Language": "en-US,en;q=0.9",
                "User-Agent": TP_LINK_USER_AGENT,
            }
        )

    def discover_models(self) -> list[TpLinkModel]:
        response = self.session.get(TP_LINK_DOWNLOAD_CENTER, timeout=self.timeout)
        response.raise_for_status()
        product_tree = self._extract_product_tree(response.text)
        models: dict[str, TpLinkModel] = {}
        for products in product_tree.values():
            for item in products:
                type_name = str(item.get("type_name") or "")
                menu_name = str(item.get("menu_name") or "")
                if not self._is_router_product(type_name, menu_name):
                    continue
                name = str(item.get("model_name") or "").strip()
                url = str(item.get("url") or "").strip()
                if not name or not url:
                    continue
                slug = self._slug_from_product_url(url)
                if not slug:
                    continue
                product_name = f"TP-Link {name}" if not name.upper().startswith("TP-LINK ") else name
                product = Product(name=product_name, url=f"{TP_LINK_DOWNLOAD_CENTER}{quote(slug, safe='%+-_()')}/")
                models.setdefault(
                    slug,
                    TpLinkModel(product=product, slug=slug, menu_name=menu_name, type_name=type_name),
                )
        return sorted(models.values(), key=lambda model: model.product.name)

    def discover_firmware(self, model: TpLinkModel) -> list[FirmwareLink]:
        response = self.session.get(model.product.url, timeout=self.timeout)
        response.raise_for_status()
        block = _extract_firmware_block(response.text)
        links: list[FirmwareLink] = []
        for table in re.findall(r'<table\b[^>]*class="[^"]*download-resource-table[^"]*"[^>]*>(.*?)</table>', block, flags=re.I | re.S):
            title = _clean_html(_first_match(r'<th\b[^>]*download-resource-name[^>]*>.*?<p>(.*?)</p>', table))
            href = _first_match(r'<a\b[^>]*class="[^"]*download-resource-btn[^"]*"[^>]*href="([^"]+)"', table)
            if not href or not title:
                continue
            url = html.unescape(href).strip()
            if url.startswith("/"):
                url = urljoin(TP_LINK_SUPPORT, url)
            if "static.tp-link.com" not in url or "/firmware/" not in url:
                continue
            release_date = _clean_html(
                _first_match(r'Published Date:\s*</span>\s*<span>(.*?)</span>', table)
            )
            filename = safe_name(Path(urlparse(url).path).name or f"{model.slug}.bin")
            links.append(
                FirmwareLink(
                    product=model.product.name,
                    url=url,
                    filename=filename,
                    title=title,
                    version=_version_from_title(title),
                    release_date=release_date,
                    uploaded_at=release_date,
                )
            )
        return _unique_links(links)

    @staticmethod
    def _extract_product_tree(page: str) -> dict[str, list[dict[str, object]]]:
        match = re.search(r"var\s+productTree\s*=\s*(\{.*?\});", page, flags=re.S)
        if not match:
            raise ValueError("TP-Link productTree was not found on download center page")
        return json.loads(match.group(1))

    @staticmethod
    def _is_router_product(type_name: str, menu_name: str) -> bool:
        type_lower = type_name.lower()
        menu_lower = menu_name.lower()
        return any(pattern in type_lower for pattern in ROUTER_TYPE_PATTERNS) or "router" in menu_lower or "gateway" in menu_lower

    @staticmethod
    def _slug_from_product_url(url: str) -> str:
        path = urlparse(url).path.strip("/")
        if not path:
            return ""
        return path.split("/")[-1]


class TpLinkFirmwareDownloader:
    def __init__(self, root: Path, timeout: int = 90) -> None:
        self.root = root
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update({"User-Agent": TP_LINK_USER_AGENT})

    def download(self, link: FirmwareLink) -> FirmwareRecord:
        product_dir = self.root / "firmware" / safe_name(link.product)
        product_dir.mkdir(parents=True, exist_ok=True)
        target = product_dir / safe_name(link.filename)
        tmp = target.with_suffix(target.suffix + ".part")
        digest = hashlib.sha256()
        size = 0
        try:
            with self.session.get(link.url, stream=True, timeout=self.timeout) as response:
                response.raise_for_status()
                with tmp.open("wb") as handle:
                    for chunk in response.iter_content(chunk_size=1024 * 1024):
                        if not chunk:
                            continue
                        handle.write(chunk)
                        digest.update(chunk)
                        size += len(chunk)
        except Exception:
            tmp.unlink(missing_ok=True)
            raise
        tmp.replace(target)
        return FirmwareRecord(
            product=link.product,
            url=link.url,
            filename=link.filename,
            path=str(target.relative_to(self.root)),
            sha256=digest.hexdigest(),
            size=size,
            title=link.title,
            version=link.version,
            release_date=link.release_date,
            uploaded_at=link.uploaded_at or link.release_date,
        )


def download_tplink_router_firmware(
    root: Path,
    timeout: int = 45,
    limit_products: int | None = None,
    limit_firmware: int | None = None,
    resume: bool = False,
    build_site: bool = False,
) -> tuple[int, int, int]:
    root.mkdir(parents=True, exist_ok=True)
    manifest = Manifest(root).load()
    discovery = TpLinkDiscovery(timeout=timeout)
    downloader = TpLinkFirmwareDownloader(root, timeout=timeout)
    models = discovery.discover_models()
    if limit_products is not None:
        models = models[:limit_products]

    products_seen = 0
    firmware_seen = 0
    downloaded = 0
    known_products = set(manifest.products)
    for model in models:
        if resume and model.product.name in known_products:
            continue
        products_seen += 1
        print(f"Checking {model.product.name} ({products_seen}/{len(models)})")
        manifest.add_product(model.product.name, model.product.url)
        manifest.save()
        try:
            links = discovery.discover_firmware(model)
        except requests.RequestException as exc:
            _record_tplink_unavailable(root, "products", model.product.name, model.product.url, str(exc), model.menu_name)
            print(f"Could not check {model.product.name}: {exc}")
            continue
        if limit_firmware is not None:
            links = links[:limit_firmware]
        if not links:
            _record_tplink_unavailable(root, "products", model.product.name, model.product.url, "No firmware links listed", model.menu_name)
        for link in links:
            firmware_seen += 1
            if manifest.has_url(link.url):
                continue
            try:
                record = downloader.download(link)
            except requests.RequestException as exc:
                _record_tplink_unavailable(root, "downloads", link.product, link.url, str(exc), model.menu_name)
                print(f"Could not download {link.product} {link.url}: {exc}")
                continue
            if manifest.upsert(record):
                downloaded += 1
                manifest.save()
    manifest.save()
    if build_site:
        from scripts.build_site_data import main as build_site_data

        build_site_data()
    return products_seen, firmware_seen, downloaded


def _extract_firmware_block(page: str) -> str:
    marker = 'id="tabpanel-Firmware"'
    start = page.find(marker)
    if start < 0:
        return ""
    next_tab = page.find('<div class="details"', start + len(marker))
    return page[start:] if next_tab < 0 else page[start:next_tab]


def _first_match(pattern: str, text: str) -> str:
    match = re.search(pattern, text, flags=re.I | re.S)
    return match.group(1) if match else ""


def _clean_html(value: str) -> str:
    text = re.sub(r"<[^>]+>", " ", value or "")
    return re.sub(r"\s+", " ", html.unescape(text)).strip()


def _version_from_title(title: str) -> str:
    match = re.search(r"_((?:V\d+(?:\.\d+)?_)?\d+(?:\.\d+)+(?:\s+Build\s+\d+)?)", title, flags=re.I)
    return match.group(1).strip() if match else ""


def _record_tplink_unavailable(root: Path, bucket: str, product: str, url: str, reason: str, category: str = "") -> None:
    target = root / "tplink_unavailable.json"
    try:
        data = json.loads(target.read_text(encoding="utf-8")) if target.exists() else {}
    except json.JSONDecodeError:
        data = {}
    entries = data.setdefault(bucket, {})
    entries[f"{product}|{url}"] = {
        "product": product,
        "url": url,
        "category": category,
        "reason": reason,
    }
    target.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")


def _unique_links(links: list[FirmwareLink]) -> list[FirmwareLink]:
    unique: dict[str, FirmwareLink] = {}
    for link in links:
        unique.setdefault(link.url, link)
    return list(unique.values())
