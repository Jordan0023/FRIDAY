# Firmware Audit: ASUS RT-AX50 Go / FW_RT_AX50_Go_30021.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-AX50 Go/FW_RT_AX50_Go_30021.zip
- Local path: known_firmware/firmware/ASUS_RT-AX50_Go/FW_RT_AX50_Go_30021.zip
- SHA-256: `4b307e5e3cc12a28ed111a208daa31f40c0b3921ac87183ffacea04f6cf3d6e5`
- Size: 14289 bytes
- Version: 3.0.0.21
- Release date: 2025/09/23

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Sink Summary

- exec: 0
- file_write: 0
- popen: 0
- system: 0
- unsafe_copy: 0

### Config Writer Leads

No config-writer markers found in sampled strings.

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/ASUS_RT-AX50_Go/FW_RT_AX50_Go_30021.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4b307e5e3cc12a28 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
