# Firmware Audit: TP-Link Archer AX1450 / Archer_AX1450_USW__V2.6_250812.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251112/Archer_AX1450(USW)_V2.6_250812.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1450/Archer_AX1450_USW__V2.6_250812.zip
- SHA-256: `7307b7236c9037afa37f14187eb91b826b25f9d46f3bec846b667d7b18c0ce80`
- Size: 24945714 bytes
- Version: V2.6_1.2.2 Build 20250812
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
### Rejected or Deprioritized Routes

No routes were explicitly rejected by the impact gate.

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_AX1450_USW__V2.6_250812.zip.extracted/0.zip`; evidence=service marker present
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_Archer_AX1450_USW__V2.6_250812.zip.extracted/ax10v3-up-us_agc3400-ver1-2-2-P1[20250812-rel75732]_2048_sign_2025-08-13_08.50.24.bin`; evidence=service marker present

### Sink Summary

- exec: 0
- file_write: 0
- popen: 0
- system: 0
- unsafe_copy: 0

### Config Writer Leads

No config-writer markers found in sampled strings.

### Handler-level Correlated Flows

No source and dangerous sink were co-located in the same sampled handler or binary.

### Ghidra Function-local Evidence

No function-local route/sink pairs were emitted by Ghidra.

### Runtime Profile

- Vendor profile: tp-link
- Web stack: not identified
- State backends: not identified
- Architectures: not identified
- Executables/scripts discovered: 0

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 0
- Archive validation cases: 7

### Confirmation Policy

- confirmed_label_requires: L5
- L3: route-specific attacker parameter reaches the sink
- L4: authentication/validation boundary and trigger are proven
- L5: reproducible security effect with fault/sink attribution
- forbidden_shortcut: route string and dangerous symbol merely co-located in a binary

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- Only routes with a plausible low-privilege boundary and route-local sink evidence are promoted. Global firmware sink counts never raise route evidence.
- Authentication labels inferred from strings are hypotheses until dispatcher control flow or a live request confirms them.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Archer_AX1450/Archer_AX1450_USW__V2.6_250812.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/7307b7236c9037af

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
