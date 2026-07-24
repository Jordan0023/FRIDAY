import json

from netgear_firmware_audit.manifest import Manifest
from netgear_firmware_audit.models import FirmwareRecord


def test_manifest_prunes_and_rejects_eol_products(tmp_path):
    known = tmp_path / "known_firmware"
    site_data = tmp_path / "site" / "data"
    known.mkdir()
    site_data.mkdir(parents=True)
    (site_data / "eol-products.json").write_text(
        json.dumps(
            {
                "products": ["EOL Router", "Vendor EOL Model"],
                "firmware_filenames": ["revision-a1.bin"],
            }
        ),
        encoding="utf-8",
    )
    record = FirmwareRecord(
        product="EOL Router",
        url="https://example.test/eol.bin",
        filename="eol.bin",
        path="firmware/eol.bin",
        sha256="a" * 64,
        size=1,
    )
    archived = known / record.path
    archived.parent.mkdir(parents=True)
    archived.write_bytes(b"obsolete")
    (known / "manifest.json").write_text(
        json.dumps(
            {
                "products": {
                    "EOL Router": "https://example.test/eol",
                    "Current Router": "https://example.test/current",
                },
                "firmware": {record.sha256: record.to_json()},
            }
        ),
        encoding="utf-8",
    )

    manifest = Manifest(known).load()

    assert set(manifest.products) == {"Current Router"}
    assert manifest.records == {}
    assert not archived.exists()
    assert manifest.is_eol("EOL Router")
    assert manifest.is_eol("OpenWrt Vendor EOL Model")
    assert manifest.is_eol("OpenWrt vendor eol model")
    manifest.add_product("EOL Router", "https://example.test/eol")
    assert "EOL Router" not in manifest.products
    manifest.add_product("eol router", "https://example.test/eol-lowercase")
    assert "eol router" not in manifest.products
    assert not manifest.upsert(record)
    revision_record = FirmwareRecord(
        product="Current Router",
        url="https://example.test/revision-a1.bin",
        filename="Revision-A1.bin",
        path="firmware/revision-a1.bin",
        sha256="b" * 64,
        size=1,
    )
    assert manifest.is_eol_firmware("REVISION-A1.BIN")
    assert not manifest.upsert(revision_record)


def test_manifest_does_not_delete_paths_outside_workspace(tmp_path):
    known = tmp_path / "known_firmware"
    site_data = tmp_path / "site" / "data"
    known.mkdir()
    site_data.mkdir(parents=True)
    (site_data / "eol-products.json").write_text(
        json.dumps({"products": ["EOL Router"]}), encoding="utf-8"
    )
    outside = tmp_path / "keep.bin"
    outside.write_bytes(b"keep")
    record = FirmwareRecord(
        product="EOL Router", url="https://example.test/eol.bin", filename="eol.bin",
        path="../keep.bin", sha256="c" * 64, size=4,
    )
    (known / "manifest.json").write_text(
        json.dumps({"firmware": {record.sha256: record.to_json()}}), encoding="utf-8"
    )

    Manifest(known).load()

    assert outside.read_bytes() == b"keep"
