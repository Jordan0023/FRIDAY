# Firmware Audit: ASUS 4G-N12 B1 / FW_4G_N12_B1_P01_12_firmware_update.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-N12_B1/FW_4G_N12_B1_P01_12_firmware_update.zip
- Local path: known_firmware/firmware/ASUS_4G-N12_B1/FW_4G_N12_B1_P01_12_firmware_update.zip
- SHA-256: `ef249f4c0f81331b74944093d3c991c42120f328798482f7618f9a32af03180c`
- Size: 39497848 bytes
- Version: vP01_12
- Release date: 2024/09/26

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SShD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, boa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Sink Summary

- exec: 7
- file_write: 41
- popen: 0
- system: 22
- unsafe_copy: 2

### Config Writer Leads

- `702D30: # iptables trigger is under Netfilter config (LED target)`
- `702D30: CONFIG_IP6_NF_IPTABLES=y`
- `702D30: CONFIG_IP_NF_IPTABLES=y`
- `tz.mbn: write_macchiato_msg_TA_firewalling_fields`

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_4G-N12_B1/FW_4G_N12_B1_P01_12_firmware_update.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ef249f4c0f81331b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
