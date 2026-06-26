from __future__ import annotations

import json
from pathlib import Path

from .models import FirmwareRecord, utc_now


class Manifest:
    def __init__(self, root: Path) -> None:
        self.root = root
        self.path = root / "manifest.json"
        self.records: dict[str, FirmwareRecord] = {}
        self.products: dict[str, str] = {}

    def load(self) -> "Manifest":
        if not self.path.exists():
            return self
        data = json.loads(self.path.read_text(encoding="utf-8"))
        self.products = dict(data.get("products", {}))
        self.records = {
            key: FirmwareRecord.from_json(value)
            for key, value in data.get("firmware", {}).items()
        }
        return self

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
        self.products[name] = url

    def upsert(self, record: FirmwareRecord) -> bool:
        existing = self.records.get(record.sha256)
        if existing:
            existing.last_seen = utc_now()
            existing.url = record.url
            existing.report_path = record.report_path or existing.report_path
            return False
        self.records[record.sha256] = record
        return True
