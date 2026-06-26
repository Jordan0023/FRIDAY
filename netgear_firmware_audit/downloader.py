from __future__ import annotations

import hashlib
from email.utils import parsedate_to_datetime
from pathlib import Path

import requests

from .models import FirmwareLink, FirmwareRecord, safe_name


class FirmwareDownloader:
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
                uploaded_at = _uploaded_at_from_headers(response.headers)
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
            uploaded_at=uploaded_at,
        )


def _uploaded_at_from_headers(headers: object) -> str:
    last_modified = getattr(headers, "get", lambda _name, _default=None: None)("Last-Modified")
    if not last_modified:
        return ""
    try:
        return parsedate_to_datetime(last_modified).isoformat()
    except (TypeError, ValueError):
        return str(last_modified)
