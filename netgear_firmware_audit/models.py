from __future__ import annotations

from dataclasses import asdict, dataclass, field
from datetime import datetime, timezone
from pathlib import Path
import re
from typing import Any


def utc_now() -> str:
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat()


MIN_SUPPORTED_FIRMWARE_YEAR = 2021


def is_supported_firmware_date(*values: str, min_year: int = MIN_SUPPORTED_FIRMWARE_YEAR) -> bool:
    """Return true when a release/upload date has a year at or after the cutoff."""
    for value in values:
        match = re.search(r"(?<!\d)(20\d{2})(?!\d)", value or "")
        if match:
            return int(match.group(1)) >= min_year
    return False


@dataclass(frozen=True)
class Product:
    name: str
    url: str


@dataclass(frozen=True)
class FirmwareLink:
    product: str
    url: str
    filename: str
    title: str = ""
    version: str = ""
    release_date: str = ""
    uploaded_at: str = ""


@dataclass
class FirmwareRecord:
    product: str
    url: str
    filename: str
    path: str
    sha256: str
    size: int
    first_seen: str = field(default_factory=utc_now)
    last_seen: str = field(default_factory=utc_now)
    title: str = ""
    version: str = ""
    release_date: str = ""
    uploaded_at: str = ""
    report_path: str = ""

    def to_json(self) -> dict[str, Any]:
        return asdict(self)

    @classmethod
    def from_json(cls, data: dict[str, Any]) -> "FirmwareRecord":
        return cls(**data)


def safe_name(value: str) -> str:
    cleaned = "".join(ch if ch.isalnum() or ch in "._-" else "_" for ch in value.strip())
    return cleaned.strip("._") or "unknown"


def relative_to(path: Path, root: Path) -> str:
    try:
        return str(path.relative_to(root))
    except ValueError:
        return str(path)
