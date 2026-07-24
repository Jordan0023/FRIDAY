# Firmware Audit: EAX18 / EAX20-EAX18-V1.0.1.68_1.0.106.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX18/EAX20-EAX18-V1.0.1.68_1.0.106.zip
- Local path: known_firmware/firmware/EAX18/EAX20-EAX18-V1.0.1.68_1.0.106.zip
- SHA-256: `2f116b321bbb1c7356910d34ae1efa00d60b4b4671e6c0f52ad04d89ef0d008e`
- Size: 33279444 bytes
- Version: 1.0.1.68_1.0.106
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `net/dev`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `self/ns/net`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `files/GDC/EAX18/EAX20-EAX18-V1.0.1.68_1.0.106.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `software/libc/bugs.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `16/18`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `SC22/WG20`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `arm/dl-machine.h`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `class/net`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `enable/force`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/ash`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/dev_mcast`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/econet`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/igmp`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/igmp6`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `posix/tempname.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `run/keyservsock`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `self/exe`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `unix/sysv/linux/dl-origin.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `unix/sysv/linux/opensock.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `usr/arm-buildroot-linux-gnueabi/sysroot/lib/ip/link_`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `1/2`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=-5
- `40/80`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=-5
- `rx/scan`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L0; score=-10

### Non-HTTP Service Surface

- `dropbear` (tcp, lan): auth=required, risk=low; source=`_EAX20-EAX18-V1.0.1.68_1.0.106.zip.extracted/453E9B`; evidence=service marker present; local sinks: file_write, unsafe_copy

### Sink Summary

- exec: 0
- file_write: 27
- popen: 0
- system: 0
- unsafe_copy: 10

### Config Writer Leads

No config-writer markers found in sampled strings.

### Handler-level Correlated Flows

- `_EAX20-EAX18-V1.0.1.68_1.0.106.zip.extracted/444EC2`: L3-correlated, score 30; sources=getenv; sinks=file_write
- `_EAX20-EAX18-V1.0.1.68_1.0.106.zip.extracted/45F60E`: L2-co-located, score 28; sources=getenv; sinks=unsafe_memory

### Ghidra Function-local Evidence

- `43F3C1:FUN_00010a68` at `00010a68`: route `/*`, sink `unsafe_copy`

### Runtime Profile

- Vendor profile: generic
- Web stack: not identified
- State backends: not identified
- Architectures: arm
- Executables/scripts discovered: 8

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 23
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

Structured zero-day triage JSON: `known_firmware/reports/EAX18/EAX20-EAX18-V1.0.1.68_1.0.106.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/2f116b321bbb1c73

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects EAX18_2f116b32 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- Ghidra emitted 1 function-local route/sink evidence records.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
