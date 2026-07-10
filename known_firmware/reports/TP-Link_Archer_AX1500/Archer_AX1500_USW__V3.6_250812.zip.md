# Firmware Audit: TP-Link Archer AX1500 / Archer_AX1500_USW__V3.6_250812.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251112/Archer_AX1500(USW)_V3.6_250812.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1500/Archer_AX1500_USW__V3.6_250812.zip
- SHA-256: `7307b7236c9037afa37f14187eb91b826b25f9d46f3bec846b667d7b18c0ce80`
- Size: 24945714 bytes
- Version: V3.6_1.2.2 Build 20250812
- Release date: 2025-11-12

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

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

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Archer_AX1500/Archer_AX1500_USW__V3.6_250812.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/7307b7236c9037af

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
