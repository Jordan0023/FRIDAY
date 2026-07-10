# Firmware Audit: ASUS DSL-N10E / FW-DSL_N10E_2120.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N10E/FW-DSL_N10E_2120.zip
- Local path: known_firmware/firmware/ASUS_DSL-N10E/FW-DSL_N10E_2120.zip
- SHA-256: `73793048e8b9f13c9d31022cea893abf94672ff5ab3feecccfc46db2a8094407`
- Size: 1378477 bytes
- Version: 2.1.20
- Release date: 2014/01/29

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

Structured zero-day triage JSON: `known_firmware/reports/ASUS_DSL-N10E/FW-DSL_N10E_2120.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/73793048e8b9f13c

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
