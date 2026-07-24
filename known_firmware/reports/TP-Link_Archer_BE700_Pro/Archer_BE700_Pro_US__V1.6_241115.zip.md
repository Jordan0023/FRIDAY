# Firmware Audit: TP-Link Archer BE700 Pro / Archer_BE700_Pro_US__V1.6_241115.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241202/Archer BE700 Pro(US)_V1.6_241115.zip
- Local path: known_firmware/firmware/TP-Link_Archer_BE700_Pro/Archer_BE700_Pro_US__V1.6_241115.zip
- SHA-256: `8ca87e93b2d4d67fd3e1ab1e2ff9b6ef87e3cb10856aab4e903ef58cf9c841d2`
- Size: 50583527 bytes
- Version: V1.6_1.1.1 Build 20241115
- Release date: 2024-12-02

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `Catalog/Pages`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ExtGState/BM/Normal/CA`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ExtGState/BM/Normal/ca`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Filter/FlateDecode/Length`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Group/S/Transparency/CS/DeviceRGB`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `ObjStm/N`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Page/Parent`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Pages/Count`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `S/StructParents`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `Text/ImageB/ImageC/ImageI`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `03/30-23`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `08/01-19`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `09/16-03`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `1999/02/22-rdf-syntax-ns`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `AA./A`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Action/S/URI/URI`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `BM/Normal/CA`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `CIDToGIDMap/Identity/DW`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `ColorSpace/DeviceRGB/BitsPerComponent`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Encoding/Identity-H/DescendantFonts`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Encoding/Identity-H/Subtype/Type0/ToUnicode`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Encoding/WinAnsiEncoding/FirstChar`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Encoding/WinAnsiEncoding/FontDescriptor`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Filter/DCTDecode/Interpolate`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `FlateDecode/I`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `FlateDecode/Length`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Font/Subtype/TrueType/Name/F1/BaseFont/ABCDEE`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Font/Subtype/TrueType/Name/F2/BaseFont/Times`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Font/Subtype/TrueType/Name/F3/BaseFont/Times`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `Font/Subtype/Type0/BaseFont/Times`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2

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
- Structured fuzz seeds: 98
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

Structured zero-day triage JSON: `known_firmware/reports/TP-Link_Archer_BE700_Pro/Archer_BE700_Pro_US__V1.6_241115.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8ca87e93b2d4d67f exited 0

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
