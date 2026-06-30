from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime, timezone
import hashlib
import re
from pathlib import Path
from urllib.parse import urljoin

import requests

from .audit import FirmwareAuditor
from .manifest import Manifest
from .models import FirmwareLink, FirmwareRecord, Product, safe_name


OPENWRT_DOWNLOADS = "https://downloads.openwrt.org"
OPENWRT_RELEASES = f"{OPENWRT_DOWNLOADS}/releases/"

DEFAULT_TARGETS = [
    "ath79/generic",
    "ramips/mt7621",
    "mediatek/filogic",
    "ipq40xx/generic",
    "ipq806x/generic",
]


@dataclass(frozen=True)
class OpenWrtModel:
    product: Product
    release: str
    target: str
    profile: str
    base_url: str
    release_date: str
    images: tuple[dict[str, object], ...]


class OpenWrtDiscovery:
    def __init__(self, timeout: int = 45) -> None:
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update(
            {
                "Accept": "application/json,text/html,*/*",
                "User-Agent": "firmware-audit/1.0",
            }
        )

    def latest_release(self) -> str:
        response = self.session.get(OPENWRT_RELEASES, timeout=self.timeout)
        response.raise_for_status()
        versions = []
        for value in re.findall(r'href="([0-9][^"/]+)/"', response.text):
            if re.fullmatch(r"\d+\.\d+\.\d+", value):
                versions.append(value)
        if not versions:
            raise ValueError("No stable OpenWrt releases found")
        return sorted(versions, key=lambda item: tuple(int(part) for part in item.split(".")))[-1]

    def discover_models(self, release: str | None = None, targets: list[str] | None = None) -> list[OpenWrtModel]:
        selected_release = release or self.latest_release()
        models: dict[tuple[str, str], OpenWrtModel] = {}
        for target in targets or DEFAULT_TARGETS:
            base_url = f"{OPENWRT_RELEASES}{selected_release}/targets/{target.strip('/')}/"
            try:
                data = self._get_json(urljoin(base_url, "profiles.json"))
            except requests.HTTPError as exc:
                if exc.response is not None and exc.response.status_code == 404:
                    continue
                raise
            release_date = _release_date(data.get("source_date_epoch"))
            for profile, info in (data.get("profiles") or {}).items():
                titles = info.get("titles") or []
                title = titles[0] if titles else {}
                vendor = str(title.get("vendor") or "OpenWrt").strip()
                model = str(title.get("model") or profile).strip()
                product_name = f"OpenWrt {vendor} {model}"
                images = tuple(info.get("images") or ())
                if not images:
                    continue
                models[(target, profile)] = OpenWrtModel(
                    product=Product(name=product_name, url=base_url),
                    release=selected_release,
                    target=target,
                    profile=str(profile),
                    base_url=base_url,
                    release_date=release_date,
                    images=images,
                )
        return sorted(models.values(), key=lambda item: (item.product.name, item.target, item.profile))

    def discover_firmware(self, model: OpenWrtModel, image_types: set[str] | None = None) -> list[FirmwareLink]:
        preferred_types = image_types or {"sysupgrade"}
        selected = [image for image in model.images if str(image.get("type") or "").lower() in preferred_types]
        if not selected:
            selected = [image for image in model.images if str(image.get("type") or "").lower() == "factory"]
        if not selected:
            selected = list(model.images[:1])

        links: list[FirmwareLink] = []
        for image in selected:
            name = str(image.get("name") or "").strip()
            if not name:
                continue
            image_type = str(image.get("type") or "image").strip()
            title = f"{model.product.name} OpenWrt {model.release} {model.target} {image_type}"
            links.append(
                FirmwareLink(
                    product=model.product.name,
                    url=urljoin(model.base_url, name),
                    filename=safe_name(name),
                    title=title,
                    version=model.release,
                    release_date=model.release_date,
                    uploaded_at=model.release_date,
                )
            )
        return _unique_links(links)

    def _get_json(self, url: str) -> dict:
        response = self.session.get(url, timeout=self.timeout)
        response.raise_for_status()
        return response.json()


class OpenWrtFirmwareDownloader:
    def __init__(self, root: Path, timeout: int = 90) -> None:
        self.root = root
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update({"User-Agent": "firmware-audit/1.0"})

    def download(self, link: FirmwareLink, expected_sha256: str = "") -> FirmwareRecord:
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

        actual_sha256 = digest.hexdigest()
        if expected_sha256 and actual_sha256.lower() != expected_sha256.lower():
            tmp.unlink(missing_ok=True)
            raise ValueError(f"SHA256 mismatch for {link.url}: expected {expected_sha256}, got {actual_sha256}")

        tmp.replace(target)
        return FirmwareRecord(
            product=link.product,
            url=link.url,
            filename=link.filename,
            path=str(target.relative_to(self.root)),
            sha256=actual_sha256,
            size=size,
            title=link.title,
            version=link.version,
            release_date=link.release_date,
            uploaded_at=link.uploaded_at or link.release_date,
        )


def download_openwrt_router_firmware(
    root: Path,
    timeout: int = 45,
    release: str | None = None,
    targets: list[str] | None = None,
    limit_products: int | None = None,
    limit_firmware: int | None = None,
    resume: bool = False,
    analyze: bool = False,
    max_extract_mb: int | None = None,
    cleanup_extracted: bool = False,
    build_site: bool = False,
) -> tuple[int, int, int]:
    root.mkdir(parents=True, exist_ok=True)
    manifest = Manifest(root).load()
    discovery = OpenWrtDiscovery(timeout=timeout)
    downloader = OpenWrtFirmwareDownloader(root, timeout=timeout)
    auditor = FirmwareAuditor(
        root,
        max_ghidra_files=0,
        max_extract_bytes=max_extract_mb * 1024 * 1024 if max_extract_mb else None,
    )

    models = discovery.discover_models(release=release, targets=targets)
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
        print(f"Checking {model.product.name} ({products_seen}/{len(models)})", flush=True)
        manifest.add_product(model.product.name, model.product.url)
        manifest.save()
        links = discovery.discover_firmware(model)
        if limit_firmware is not None:
            links = links[:limit_firmware]
        image_by_name = {str(image.get("name") or ""): image for image in model.images}
        for link in links:
            firmware_seen += 1
            if manifest.has_url(link.url):
                continue
            image = image_by_name.get(link.filename) or image_by_name.get(Path(link.url).name) or {}
            expected_sha256 = str(image.get("sha256") or image.get("sha256_unsigned") or "")
            try:
                record = downloader.download(link, expected_sha256=expected_sha256)
            except (requests.RequestException, ValueError) as exc:
                print(f"Could not download {link.product} {link.url}: {exc}", flush=True)
                continue
            if analyze:
                report = auditor.audit(record)
                record.report_path = str(report.relative_to(root))
                if cleanup_extracted:
                    import shutil

                    shutil.rmtree(root / "extracted" / record.sha256[:16], ignore_errors=True)
            if manifest.upsert(record):
                downloaded += 1
                manifest.save()
    manifest.save()
    if build_site:
        from scripts.build_site_data import main as build_site_data

        build_site_data()
    return products_seen, firmware_seen, downloaded


def _release_date(source_date_epoch: object) -> str:
    try:
        timestamp = int(source_date_epoch)
    except (TypeError, ValueError):
        return ""
    return datetime.fromtimestamp(timestamp, tz=timezone.utc).date().isoformat()


def _unique_links(links: list[FirmwareLink]) -> list[FirmwareLink]:
    unique: dict[str, FirmwareLink] = {}
    for link in links:
        unique.setdefault(link.url, link)
    return list(unique.values())
