# Firmware Audit: ASUS 4G-AC86U / Modem_FW_4G_AC86U_LTE_A21_02_001.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-AC86U/Modem_FW_4G_AC86U_LTE_A21_02_001.zip
- Local path: known_firmware/firmware/ASUS_4G-AC86U/Modem_FW_4G_AC86U_LTE_A21_02_001.zip
- SHA-256: `13253a38359bdba03854276b1888035c7960c30362147a9e60a14e0118e3af29`
- Size: 108204135 bytes
- Version: A21
- Release date: 2023/05/11

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sshD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Sink Summary

- exec: 8
- file_write: 65
- popen: 0
- system: 31
- unsafe_copy: 1

### Config Writer Leads

- `sdx20-recovery.ubi: /usr/lib/busybox/bin/crontab`
- `sdx20-recovery.ubi: crontab`
- `sdx20-usrfs.ubi: $Id: sample-etc_ddclient.conf 125 2011-05-19H`
- `sdx20-usrfs.ubi: <Firewall>/data/'`
- `sdx20-usrfs.ubi: ddclient.conf`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_4G-AC86U/Modem_FW_4G_AC86U_LTE_A21_02_001.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/13253a38359bdba0 stopped: extraction exceeded 768 MB: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
