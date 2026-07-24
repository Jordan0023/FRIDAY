# Firmware Audit: EAX12 / EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip
- Local path: known_firmware/firmware/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip
- SHA-256: `331d99830059c4ac2d1ea782d8de085c063bb50628425c3302f7fe05b9ce0c1e`
- Size: 14554501 bytes
- Version: 1.0.3.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `files/GDC/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `jb/R`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `support/product/EAX11v2.aspx`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `support/product/EAX12.aspx`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `support/product/EAX15v2.aspx`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2

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

- Vendor profile: generic
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
- Structured fuzz seeds: 5
- Archive validation cases: 7

### Confirmation Policy

- confirmed_label_requires: L5
- confirmed_zero_day_requires: ['L5 reproducible security effect with fault/sink attribution', 'novel reproducible pre-authentication exploitation path with no remote administrator session required', 'LAN or WAN network reachability without credentials', 'impact is remote code execution or a reliable input-specific denial of service', 'denial of service reproduces from attacker input and is not generic resource exhaustion', 'documented, dated public-prior-art search', 'no matching public disclosure or publicly available fix at the recorded discovery time']
- authenticated_admin_disposition: confirmed vulnerability, but not a confirmed zero-day
- vendor_contact_required: False
- private_duplicate_caveat: public novelty does not exclude an unknown private or embargoed duplicate
- L3: route-specific attacker parameter reaches the sink
- L4: authentication/validation boundary and trigger are proven
- L5: reproducible security effect with fault/sink attribution
- forbidden_shortcut: route string and dangerous symbol merely co-located in a binary
- impactful_hunt_scope: unauthenticated LAN/WAN RCE or reliable input-specific denial of service

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- Only routes with a plausible low-privilege boundary and route-local sink evidence are promoted. Global firmware sink counts never raise route evidence.
- Authentication labels inferred from strings are hypotheses until dispatcher control flow or a live request confirms them.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/EAX12/EAX12_EAX11v2_EAX15v2-V1.0.3.36.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/331d99830059c4ac

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
