# Firmware Audit: RAX41V2 / RAX41v2-V1.1.6.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41v2-V1.1.6.38.zip
- Local path: known_firmware/firmware/RAX41V2/RAX41v2-V1.1.6.38.zip
- SHA-256: `c52efe4a322909d7806b29863b601ad4aa4b6b608d033572b1f0c23b7e63eae6`
- Size: 81338011 bytes
- Version: 1.1.6.38
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

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

- `software/libc/bugs.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `SC22/WG20`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `about/security`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `files/GDC/RAX41/RAX41v2-V1.1.6.38.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2

### Non-HTTP Service Surface

- `telnetd` (tcp, lan): auth=unknown, risk=high; source=`_RAX41v2-V1.1.6.38.zip.extracted/364568`; evidence=service marker present

### Sink Summary

- exec: 0
- file_write: 4
- popen: 0
- system: 0
- unsafe_copy: 2

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
- Architectures: arm
- Executables/scripts discovered: 1

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 4
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

Structured zero-day triage JSON: `known_firmware/reports/RAX41V2/RAX41v2-V1.1.6.38.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c52efe4a322909d7 stopped: extraction exceeded 768 MB

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX41V2_c52efe4a -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
