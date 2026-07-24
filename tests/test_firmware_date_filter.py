import json

from netgear_firmware_audit.manifest import Manifest
from netgear_firmware_audit.models import FirmwareLink, is_supported_firmware_date


def test_supported_firmware_date_requires_2021_or_newer():
    assert is_supported_firmware_date("2021-01-01")
    assert is_supported_firmware_date("", "Published 2026/07/23")
    assert not is_supported_firmware_date("2020-12-31")
    assert not is_supported_firmware_date("")


def test_manifest_accepts_only_current_dated_links(tmp_path):
    site_data = tmp_path / "site" / "data"
    site_data.mkdir(parents=True)
    (site_data / "eol-products.json").write_text(
        json.dumps({"products": ["Old Router"], "firmware_filenames": ["retired.bin"]}),
        encoding="utf-8",
    )
    manifest = Manifest(tmp_path / "known_firmware")

    def link(product="Current Router", filename="current.bin", date="2024-01-01"):
        return FirmwareLink(product=product, url="https://example.test/fw", filename=filename, release_date=date)

    assert manifest.accepts_link(link())
    assert not manifest.accepts_link(link(date="2020-12-31"))
    assert not manifest.accepts_link(link(date=""))
    assert not manifest.accepts_link(link(product="Old Router"))
    assert not manifest.accepts_link(link(filename="RETIRED.BIN"))
