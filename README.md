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

## Advanced zero-day analysis

The advanced scanner correlates input sources and dangerous sinks within the
same handler or binary, profiles vendor runtime dependencies, discovers
rootfs trees independent of extractor naming, fingerprints executables for
patch-diffing, and emits bounded validation recipes:

```bash
python3 scripts/advanced_firmware_analysis.py scan /path/to/rootfs --product "TP-Link Archer C5400X"
python3 scripts/advanced_firmware_analysis.py diff /path/to/older/rootfs /path/to/newer/rootfs
python3 scripts/advanced_firmware_analysis.py recipes
```

The zero-day map is authentication-first. It inventories web routes and
high-value non-HTTP services, correlates dangerous sinks only within a
standalone handler or a bounded route-local binary context, labels likely
exposure and authentication, and separates promoted candidates from rejected
or administrator-only routes.
Firmware-wide sink counts remain inventory data but no longer increase an
unrelated route's evidence level or impact score.

Candidate JSON includes `auth_class`, `exposure`, `impact_class`,
`disposition`, and concrete `evidence`. The `rejected_candidates` collection
records why routes were filtered, while `service_surface` highlights LAN/WAN
parsers such as UPnP, DNS, DHCP, file sharing, cloud, and mesh services.

Promoted impactful candidates are deliberately narrow: they must have static
evidence of no authentication, LAN or WAN exposure, and either possible command
execution or memory corruption. Unknown authentication is not treated as
unauthenticated. Memory corruption is only a DoS/RCE lead until an isolated
runtime test proves an attacker-correlated, repeatable fault; generic resource
exhaustion is excluded.

Validation recipes are intentionally limited to localhost/isolated namespaces,
disable external networking, avoid persistence, and write markers only beneath
`/tmp/friday-proof`. The Docker image includes AFL++, QEMU user emulation,
Ghidra, tracing tools, ELF parsing, and CPU emulation support. Rebuild the image
to install the added packages.

A **confirmed zero-day** requires L5 technical confirmation (a reproducible
security effect with source/sink attribution), a novel reproducible
pre-authentication path that does not require a remote administrator session,
a documented and dated search of public prior art, and no matching public
disclosure or publicly available fix at the recorded discovery time. A flaw
that directly requires an authenticated administrator remains a confirmed
vulnerability but is not labeled a confirmed zero-day. A chain through a
publicly known authentication bypass does not satisfy the novel pre-authentication
requirement. Vendor or CNA contact is not required. This is a public-novelty
determination and cannot exclude an unknown private or embargoed duplicate;
reports must retain that caveat.

Ghidra audits run `ghidra_scripts/FridayRouteEvidence.java` after import. It
emits machine-readable, function-local route/sink pairs which are consumed by
the route scorer. These pairs are correlation evidence, not a claim that an
attacker parameter reaches the sink.

GL.iNet extraction is unlimited by default because nested sysupgrade images
can expand beyond 768 MB. Set `--max-extract-mb` only when a disk budget is
required.

The RT-AX82U validation helper builds the bundled Greenhouse artifact, rehosts
the firmware without external networking, and can replay a bounded proof to a
loopback-published emulator:

```bash
python3 scripts/emulate_asus_rt_ax82u.py build-greenhouse
python3 scripts/emulate_asus_rt_ax82u.py rehost --mode single --timeout-minutes 45
python3 scripts/emulate_asus_rt_ax82u.py replay --base-url http://127.0.0.1:8080 --cookie 'asus_token=...'
```

The replay command refuses non-loopback targets. Its archive is constrained to
the modeled `/tmp/friday-proof` directory.
