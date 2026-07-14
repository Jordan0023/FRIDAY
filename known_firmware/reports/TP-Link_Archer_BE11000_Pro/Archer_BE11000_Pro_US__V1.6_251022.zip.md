# Firmware Audit: TP-Link Archer BE11000 Pro / Archer_BE11000_Pro_US__V1.6_251022.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251113/Archer BE11000 Pro(US)_V1.6_251022.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE11000_Pro/Archer_BE11000_Pro_US__V1.6_251022.zip
- SHA-256: `0795cae638225029f1525f2d969a84c0ed6fc1591d594e2cac9aa26680f0c271`
- Size: 50602579 bytes
- Version: V1.6_1.1.2 Build 20251022
- Release date: 2025-11-13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, boA, boa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

No routes were explicitly rejected by the impact gate.

### Non-HTTP Service Surface

No prioritized non-HTTP services were identified.

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

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Archer_BE11000_Pro/Archer_BE11000_Pro_US__V1.6_251022.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/0795cae638225029

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
