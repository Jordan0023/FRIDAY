# FRIDAY

FRIDAY is a local Netgear firmware audit workspace. It discovers router and extender firmware, downloads new firmware into a local archive, runs offline static-analysis heuristics, and serves a browser dashboard for triage.

The checked-in repository tracks source code, the current manifest, static report markdown, and dashboard assets. Large firmware ZIPs, extracted root filesystems, logs, and Ghidra projects are generated locally and intentionally ignored.

## Setup

```bash
cd ~/FRIDAY
python3 -m venv .venv
. .venv/bin/activate
pip install -r requirements.txt
python -m playwright install chromium
```

Optional tools improve extraction and validation:

- `binwalk`
- `sasquatch`
- `qemu-user-static`
- Ghidra `analyzeHeadless`
- `file`, `strings`, `sha256sum`

## Download and Audit Firmware

Download known firmware and run static analysis:

```bash
python netgear_full_download.py --use-browser --analyze
```

Useful smaller runs:

```bash
python netgear_full_download.py --product R7000 --analyze
python netgear_full_download.py --product R7000 --limit-firmware 1
python netgear_full_download.py --products-file models.txt --analyze
```

The local archive is written under `known_firmware/`. Firmware binaries and extracted files are ignored by Git.

## Refresh Dashboard Data

After downloads or analysis runs, rebuild the dashboard data:

```bash
python scripts/build_site_data.py
```

This updates:

- `site/data/firmware-dashboard.json`
- `site/data/firmware-dashboard.js`

## Run the Dashboard

Serve the dashboard locally:

```bash
cd ~/FRIDAY/site
python3 -m http.server 8000
```

Open:

```text
http://127.0.0.1:8000/
```

The dashboard supports searching, filtering by finding type, showing only firmware with findings, and ordering routers by first uploaded date, alphabetical order, or priority.

## Check for New Firmware

Run a one-shot update:

```bash
python netgear_watch_new.py --use-browser --analyze
```

Install the daily user-level systemd timer:

```bash
./scripts/install_daily_watch.sh
```

Useful timer commands:

```bash
systemctl --user list-timers netgear-firmware-watch.timer
systemctl --user start netgear-firmware-watch.service
systemctl --user disable --now netgear-firmware-watch.timer
```

The daily runner writes logs to `known_firmware/logs/daily-watch.log`.

## Emulation Helpers

Inventory extracted firmware and plan local emulation:

```bash
python3 scripts/firmware_emulator.py inventory
python3 scripts/firmware_emulator.py plan --product AC1450
python3 scripts/firmware_emulator.py cgi-smoke --product BE9300
python3 scripts/firmware_emulator.py probe-http --product AC1450 --base-url http://127.0.0.1:8080
```

Install emulator dependencies on Debian/Ubuntu:

```bash
./scripts/install_emulator_deps.sh
```

## Repository Layout

```text
netgear_firmware_audit/     Python package for discovery, download, manifest, and auditing
scripts/                    Dashboard builder, daily timer installer, emulator helpers
site/                       Static dashboard
known_firmware/manifest.json
known_firmware/reports/     Lightweight markdown reports
```

Static findings are triage leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
