from __future__ import annotations

import hashlib
import json
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from urllib.parse import quote


ENCODE_URI_SAFE = ";/?:@&=+$,-_.!~*'()"

import requests

from .manifest import Manifest
from .models import FirmwareLink, FirmwareRecord, Product, safe_name


ASUS_SUPPORT = "https://www.asus.com"
ASUS_CDN = "https://dlcdnta.asus.com"
ASUS_TOKEN = "https://cdnta.asus.com/api/v1/TokenHQ"

ROUTER_CATEGORIES = {
    "Wireless Routers": "2542",
    "Gaming Routers": "25908",
    "Business Wireless Routers": "24506",
    "Business Mesh WiFi System": "45774",
    "Business Wired Routers": "46465",
    "4G LTE / 3G Routers": "3158",
    "Cable Modems & Routers": "21981",
    "Wi-Fi System": "25266",
    "xDSL Modem Routers": "3081",
}


class AsusFirmwareUnavailable(requests.HTTPError):
    pass


@dataclass(frozen=True)
class AsusModel:
    product: Product
    pdid: str
    hashed_id: str
    category: str


class AsusDiscovery:
    def __init__(self, timeout: int = 45) -> None:
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update(
            {
                "Accept": "application/json,text/plain,*/*",
                "Referer": f"{ASUS_SUPPORT}/support/download-center/",
                "User-Agent": "firmware-audit/1.0",
            }
        )

    def discover_models(self, category_ids: dict[str, str] | None = None) -> list[AsusModel]:
        categories = category_ids or ROUTER_CATEGORIES
        models: dict[str, AsusModel] = {}
        for category, category_id in categories.items():
            data = self._get_json(
                f"{ASUS_SUPPORT}/support/api/product.asmx/GetPDLevel",
                params={
                    "website": "global",
                    "type": "2",
                    "typeid": category_id,
                    "productflag": "1",
                },
            )
            for item in data.get("Result", {}).get("Product", []):
                pdid = str(item.get("PDId", "")).strip()
                name = str(item.get("PDName", "")).strip()
                if not pdid or not name:
                    continue
                product_name = f"ASUS {name}" if not name.upper().startswith("ASUS ") else name
                models.setdefault(
                    pdid,
                    AsusModel(
                        product=Product(name=product_name, url=self.product_url(self.display_model(product_name))),
                        pdid=pdid,
                        hashed_id=str(item.get("PDHashedId", "")).strip(),
                        category=category,
                    ),
                )
        return sorted(models.values(), key=lambda model: model.product.name)

    def discover_firmware(self, model: AsusModel) -> list[FirmwareLink]:
        data = self._get_firmware_json(model)
        links: list[FirmwareLink] = []
        result = data.get("Result", {})
        model_name = str(result.get("Model") or self.display_model(model.product.name))
        for group in result.get("Obj", []) or []:
            if "firmware" not in str(group.get("Name", "")).lower():
                continue
            for item in group.get("Files", []) or []:
                url_path = (item.get("DownloadUrl") or {}).get("Global")
                if not url_path:
                    continue
                url = f"{ASUS_CDN}{url_path}"
                filename = safe_name(Path(url_path).name or str(item.get("Id", "firmware.zip")))
                links.append(
                    FirmwareLink(
                        product=model.product.name,
                        url=url,
                        filename=filename,
                        title=str(item.get("Title") or f"ASUS {model_name} firmware"),
                        version=str(item.get("Version") or ""),
                        release_date=str(item.get("ReleaseDate") or ""),
                    )
                )
        return _unique_links(links)

    def _get_firmware_json(self, model: AsusModel) -> dict:
        last_error: requests.HTTPError | None = None
        unavailable_error: AsusFirmwareUnavailable | None = None
        for params in self._firmware_param_sets(model):
            try:
                return self._get_json(
                    f"{ASUS_SUPPORT}/support/webapi/ProductV2/GetPDBIOS",
                    params=params,
                )
            except AsusFirmwareUnavailable as exc:
                unavailable_error = exc
            except requests.HTTPError as exc:
                last_error = exc
        if unavailable_error is not None and last_error is None:
            raise unavailable_error
        if last_error is not None:
            raise last_error
        raise AsusFirmwareUnavailable(f"ASUS firmware API has no usable parameters for {model.product.name}")

    def _firmware_param_sets(self, model: AsusModel) -> list[dict[str, str]]:
        display_model = self.display_model(model.product.name)
        names = [display_model]
        if display_model.lower() != display_model:
            names.append(display_model.lower())
        if " " in display_model:
            names.append(display_model.replace(" ", "-"))
        param_sets: list[dict[str, str]] = []
        seen: set[tuple[tuple[str, str], ...]] = set()
        for name in names:
            candidates = [
                {"website": "global", "model": name, "pdhashedid": model.hashed_id, "pdid": model.pdid, "cpu": ""},
                {"website": "global", "model": name, "pdid": model.pdid, "cpu": ""},
                {"website": "global", "model": name, "productid": model.pdid, "cpu": ""},
            ]
            for params in candidates:
                key = tuple(sorted(params.items()))
                if key not in seen:
                    seen.add(key)
                    param_sets.append(params)
        return param_sets

    def _get_json(self, url: str, params: dict[str, str]) -> dict:
        response = self.session.get(url, params=params, timeout=self.timeout)
        response.raise_for_status()
        data = response.json()
        status = str(data.get("Status", "SUCCESS")).upper()
        if status not in {"SUCCESS", "200"}:
            message = str(data.get("Message") or "")
            error = AsusFirmwareUnavailable if _is_unavailable_api_message(message) else requests.HTTPError
            raise error(f"ASUS API returned {status}: {message}", response=response)
        return data

    @staticmethod
    def display_model(product_name: str) -> str:
        return product_name.removeprefix("ASUS ").strip()

    @staticmethod
    def product_url(model_name: str) -> str:
        return f"{ASUS_SUPPORT}/supportonly/{quote(model_name, safe='')}/HelpDesk_BIOS/"


class AsusFirmwareDownloader:
    def __init__(self, root: Path, timeout: int = 90) -> None:
        self.root = root
        self.timeout = timeout
        self.session = requests.Session()
        self.session.headers.update(
            {
                "Accept": "application/json,text/plain,*/*",
                "Origin": ASUS_SUPPORT,
                "Referer": f"{ASUS_SUPPORT}/support/download-center/",
                "User-Agent": "firmware-audit/1.0",
            }
        )

    def download(self, link: FirmwareLink) -> FirmwareRecord:
        product_dir = self.root / "firmware" / safe_name(link.product)
        product_dir.mkdir(parents=True, exist_ok=True)
        target = product_dir / safe_name(link.filename)
        tmp = target.with_suffix(target.suffix + ".part")
        signed_url = self._signed_url(link)

        digest = hashlib.sha256()
        size = 0
        try:
            with self.session.get(signed_url, stream=True, timeout=self.timeout) as response:
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
            uploaded_at=link.release_date,
        )

    def _signed_url(self, link: FirmwareLink) -> str:
        display_model = AsusDiscovery.display_model(link.product)
        download_base = quote(f"{link.url}?model={display_model}", safe=ENCODE_URI_SAFE)
        token_value = download_base
        response = self.session.post(
            ASUS_TOKEN,
            params={"filePath": token_value, "systemCode": "asus"},
            headers={"Content-Type": "application/json"},
            timeout=self.timeout,
        )
        response.raise_for_status()
        data = response.json()
        result = data.get("result") or data.get("Result") or {}
        signature = result.get("signature")
        expires = result.get("expires")
        key_pair_id = result.get("keyPairId")
        if not signature or not expires or not key_pair_id:
            raise requests.HTTPError(f"ASUS token response missing signing fields: {data}", response=response)
        return f"{download_base}&Signature={signature}&Expires={expires}&Key-Pair-Id={key_pair_id}"


def download_asus_wireless_router_firmware(
    root: Path,
    timeout: int = 45,
    limit_products: int | None = None,
    limit_firmware: int | None = None,
    resume: bool = False,
    build_site: bool = False,
) -> tuple[int, int, int]:
    root.mkdir(parents=True, exist_ok=True)
    manifest = Manifest(root).load()
    discovery = AsusDiscovery(timeout=timeout)
    downloader = AsusFirmwareDownloader(root, timeout=timeout)
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
        except AsusFirmwareUnavailable as exc:
            _record_asus_unavailable(root, "products", model.product.name, model.product.url, str(exc), category=model.category, pdid=model.pdid)
            print(f"No downloadable ASUS firmware listed for {model.product.name}")
            continue
        except requests.RequestException as exc:
            _record_asus_unavailable(root, "products", model.product.name, model.product.url, str(exc), category=model.category, pdid=model.pdid)
            print(f"Could not check {model.product.name}: {exc}")
            continue
        if limit_firmware is not None:
            links = links[:limit_firmware]
        for link in links:
            firmware_seen += 1
            if manifest.has_url(link.url):
                continue
            try:
                record = downloader.download(link)
            except requests.HTTPError as exc:
                status = exc.response.status_code if exc.response is not None else "unknown"
                _record_asus_unavailable(root, "downloads", link.product, link.url, f"HTTP {status}: {exc}")
                print(f"ASUS CDN file unavailable for {link.product}: HTTP {status}")
                continue
            except requests.RequestException as exc:
                _record_asus_unavailable(root, "downloads", link.product, link.url, str(exc))
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



def _is_unavailable_api_message(message: str) -> bool:
    normalized = message.strip().lower()
    return (
        "找不到資料表" in message
        or "input string was not in a correct format" in normalized
        or "no data" in normalized
        or "not found" in normalized
    )


def _record_asus_unavailable(
    root: Path,
    bucket: str,
    product: str,
    url: str,
    reason: str,
    category: str = "",
    pdid: str = "",
) -> None:
    target = root / "asus_unavailable.json"
    try:
        data = json.loads(target.read_text(encoding="utf-8")) if target.exists() else {}
    except json.JSONDecodeError:
        data = {}
    entries = data.setdefault(bucket, {})
    key = f"{product}|{url}"
    entries[key] = {
        "product": product,
        "url": url,
        "category": category,
        "pdid": pdid,
        "reason": reason,
        "checked_at": datetime.now(timezone.utc).isoformat(timespec="seconds"),
    }
    target.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")

def _unique_links(links: list[FirmwareLink]) -> list[FirmwareLink]:
    unique: dict[str, FirmwareLink] = {}
    for link in links:
        unique.setdefault(link.url, link)
    return list(unique.values())
