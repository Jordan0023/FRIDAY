from __future__ import annotations

import hashlib
import json
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path

import requests

from .audit import FirmwareAuditor
from .manifest import Manifest
from .models import FirmwareLink, FirmwareRecord, Product, safe_name


GLINET_DOWNLOAD = "https://dl.gl-inet.com"
GLINET_API = "https://firmware-api.gl-inet.com"
GLINET_FIRMWARE_HOST = "fw.gl-inet.com"


class GlinetApiError(requests.HTTPError):
    pass


@dataclass(frozen=True)
class GlinetModel:
    product: Product
    code: str


class GlinetDiscovery:
    def __init__(self, timeout: int = 45) -> None:
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update(
            {
                "Accept": "application/json,text/plain,*/*",
                "Origin": GLINET_DOWNLOAD,
                "Referer": f"{GLINET_DOWNLOAD}/",
                "User-Agent": "firmware-audit/1.0",
            }
        )

    def discover_models(self) -> list[GlinetModel]:
        data = self._get_json("/cloud-api/products", {"modelType": "router"})
        models: dict[str, GlinetModel] = {}
        for item in data.get("info", []) or []:
            code = str(item.get("code") or "").strip()
            name = str(item.get("name") or "").strip()
            if not code or not name:
                continue
            product_name = name if name.upper().startswith("GL-") else f"GL.iNet {name}"
            if product_name.upper().startswith("GL-"):
                product_name = f"GL.iNet {product_name}"
            models.setdefault(
                code,
                GlinetModel(
                    product=Product(name=product_name, url=f"{GLINET_DOWNLOAD}/#/model/{code}"),
                    code=code,
                ),
            )
        return sorted(models.values(), key=lambda model: model.product.name)

    def discover_firmware(
        self,
        model: GlinetModel,
        stages: set[str] | None = None,
    ) -> list[FirmwareLink]:
        allowed_stages = {stage.upper() for stage in stages} if stages else {"RELEASE"}
        data = self._get_json("/cloud-api/model/info", {"model": model.code})
        links: list[FirmwareLink] = []
        for release in data.get("info", []) or []:
            stage = str(release.get("stage") or "RELEASE").upper()
            if stage not in allowed_stages:
                continue
            version = str(release.get("version") or "").strip()
            release_time = str(release.get("release_time") or "").strip()
            for item in release.get("download", []) or []:
                url = str(item.get("link") or "").strip()
                filename = str(item.get("name") or Path(url).name).strip()
                if not self._is_router_firmware_url(url) or not filename:
                    continue
                links.append(
                    FirmwareLink(
                        product=model.product.name,
                        url=url,
                        filename=safe_name(filename),
                        title=f"{model.product.name} firmware {version}".strip(),
                        version=version,
                        release_date=release_time,
                        uploaded_at=release_time,
                    )
                )
        return _unique_links(links)

    def _get_json(self, path: str, params: dict[str, str]) -> dict:
        response = self.session.get(f"{GLINET_API}{path}", params=params, timeout=self.timeout)
        response.raise_for_status()
        data = response.json()
        if data.get("code") != 0:
            raise GlinetApiError(f"GL.iNet API returned {data}", response=response)
        return data

    @staticmethod
    def _is_router_firmware_url(url: str) -> bool:
        lower = url.lower()
        return (
            GLINET_FIRMWARE_HOST in lower
            and "/firmware/" in lower
            and lower.rsplit(".", 1)[-1] in {"bin", "img", "tar", "zip"}
            and "uboot" not in lower
            and "u-boot" not in lower
        )


class GlinetFirmwareDownloader:
    def __init__(self, root: Path, timeout: int = 90) -> None:
        self.root = root
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update({"User-Agent": "firmware-audit/1.0"})

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


def download_glinet_router_firmware(
    root: Path,
    timeout: int = 45,
    limit_products: int | None = None,
    limit_firmware: int | None = None,
    resume: bool = False,
    stages: set[str] | None = None,
    analyze: bool = False,
    max_extract_mb: int | None = None,
    cleanup_extracted: bool = False,
    build_site: bool = False,
) -> tuple[int, int, int]:
    root.mkdir(parents=True, exist_ok=True)
    manifest = Manifest(root).load()
    discovery = GlinetDiscovery(timeout=timeout)
    downloader = GlinetFirmwareDownloader(root, timeout=timeout)
    auditor = FirmwareAuditor(
        root,
        max_ghidra_files=0,
        max_extract_bytes=max_extract_mb * 1024 * 1024 if max_extract_mb else None,
    )
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
            links = discovery.discover_firmware(model, stages=stages)
        except requests.RequestException as exc:
            _record_glinet_unavailable(root, "products", model.product.name, model.product.url, str(exc), model.code)
            print(f"Could not check {model.product.name}: {exc}")
            continue
        if limit_firmware is not None:
            links = links[:limit_firmware]
        if not links:
            _record_glinet_unavailable(root, "products", model.product.name, model.product.url, "No matching firmware links listed", model.code)
        for link in links:
            firmware_seen += 1
            if manifest.has_url(link.url):
                continue
            try:
                record = downloader.download(link)
            except requests.RequestException as exc:
                _record_glinet_unavailable(root, "downloads", link.product, link.url, str(exc), model.code)
                print(f"Could not download {link.product} {link.url}: {exc}")
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


def _record_glinet_unavailable(root: Path, bucket: str, product: str, url: str, reason: str, model: str = "") -> None:
    target = root / "glinet_unavailable.json"
    try:
        data = json.loads(target.read_text(encoding="utf-8")) if target.exists() else {}
    except json.JSONDecodeError:
        data = {}
    entries = data.setdefault(bucket, {})
    entries[f"{product}|{url}"] = {
        "product": product,
        "url": url,
        "model": model,
        "reason": reason,
        "checked_at": datetime.now(timezone.utc).isoformat(timespec="seconds"),
    }
    target.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")


def _unique_links(links: list[FirmwareLink]) -> list[FirmwareLink]:
    unique: dict[str, FirmwareLink] = {}
    for link in links:
        unique.setdefault(link.url, link)
    return list(unique.values())
