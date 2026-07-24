from __future__ import annotations

import json
from pathlib import Path

from .models import FirmwareLink, FirmwareRecord, is_supported_firmware_date, utc_now


class Manifest:
    def __init__(self, root: Path) -> None:
        self.root = root
        self.path = root / "manifest.json"
        self.records: dict[str, FirmwareRecord] = {}
        self.products: dict[str, str] = {}
        self.eol_products = self._load_eol_products()
        self.eol_products_casefold = {product.casefold() for product in self.eol_products}
        self.eol_firmware_filenames = self._load_eol_firmware_filenames()
        self.eol_firmware_filenames_casefold = {
            filename.casefold() for filename in self.eol_firmware_filenames
        }

    def load(self) -> "Manifest":
        if not self.path.exists():
            return self
        data = json.loads(self.path.read_text(encoding="utf-8"))
        self.products = dict(data.get("products", {}))
        raw_records = dict(data.get("firmware", {}))
        self.records = {
            key: FirmwareRecord.from_json(value)
            for key, value in raw_records.items()
            if not self.is_eol_record(value)
        }
        retained_paths = {record.path for record in self.records.values()}
        for value in raw_records.values():
            if self.is_eol_record(value):
                path = str(value.get("path", ""))
                if path and path not in retained_paths:
                    self._delete_archived_firmware(path)
        self.products = {
            name: url for name, url in self.products.items()
            if not self.is_eol(name)
        }
        return self

    def _delete_archived_firmware(self, relative_path: str) -> None:
        """Delete an EOL archive, while refusing paths outside the firmware workspace."""
        root = self.root.resolve()
        candidate = (self.root / relative_path).resolve()
        if candidate == root or root not in candidate.parents:
            return
        if candidate.is_file():
            candidate.unlink()

    def save(self) -> None:
        self.root.mkdir(parents=True, exist_ok=True)
        data = {
            "updated": utc_now(),
            "products": dict(sorted(self.products.items())),
            "firmware": {
                key: record.to_json()
                for key, record in sorted(self.records.items())
            },
        }
        self.path.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")

    def has_url(self, url: str) -> bool:
        return any(record.url == url for record in self.records.values())

    def add_product(self, name: str, url: str) -> None:
        if self.is_eol(name):
            return
        self.products[name] = url

    def upsert(self, record: FirmwareRecord) -> bool:
        if self.is_eol(record.product) or self.is_eol_firmware(record.filename):
            return False
        existing = self.records.get(record.sha256)
        if existing:
            existing.last_seen = utc_now()
            existing.url = record.url
            existing.report_path = record.report_path or existing.report_path
            return False
        self.records[record.sha256] = record
        return True

    def is_eol(self, product: str) -> bool:
        if product.casefold() in self.eol_products_casefold:
            return True
        if product.startswith("OpenWrt "):
            return product.removeprefix("OpenWrt ").casefold() in self.eol_products_casefold
        return False

    def is_eol_firmware(self, filename: str) -> bool:
        return filename.casefold() in self.eol_firmware_filenames_casefold

    def is_eol_record(self, record: dict[str, object]) -> bool:
        return self.is_eol(str(record.get("product", ""))) or self.is_eol_firmware(
            str(record.get("filename", ""))
        )

    def accepts_link(self, link: FirmwareLink) -> bool:
        return (
            not self.is_eol(link.product)
            and not self.is_eol_firmware(link.filename)
            and is_supported_firmware_date(link.uploaded_at, link.release_date)
        )

    def _load_eol_products(self) -> set[str]:
        payload = self._load_eol_catalog()
        return {
            str(product).strip()
            for product in payload.get("products", [])
            if str(product).strip()
        }

    def _load_eol_firmware_filenames(self) -> set[str]:
        payload = self._load_eol_catalog()
        return {
            str(filename).strip()
            for filename in payload.get("firmware_filenames", [])
            if str(filename).strip()
        }

    def _load_eol_catalog(self) -> dict[str, object]:
        path = self.root.parent / "site" / "data" / "eol-products.json"
        if not path.is_file():
            return {}
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except (json.JSONDecodeError, OSError):
            return {}
        return payload if isinstance(payload, dict) else {}
