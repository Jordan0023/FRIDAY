import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def test_dashboard_contains_only_non_eol_models_from_2021_through_2026():
    dashboard = json.loads((ROOT / "site/data/firmware-dashboard.json").read_text())
    eol = set(json.loads((ROOT / "site/data/eol-products.json").read_text())["products"])
    firmware = dashboard["firmware"]
    products = {record["product"] for record in firmware}

    assert dashboard["summary"]["products"] == len(products)
    assert products.isdisjoint(eol)

    for record in firmware:
        date = record["uploaded_at"] or record["release_date"]
        assert 2021 <= int(date[:4]) <= 2026
