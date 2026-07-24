# Firmware Audit: RAXE450 / RAXE450-V1.2.14.114_2.0.67.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE450/RAXE450-V1.2.14.114_2.0.67.zip
- Local path: known_firmware/firmware/RAXE450/RAXE450-V1.2.14.114_2.0.67.zip
- SHA-256: `6ff1a084616ba4bbd484c728a6c1ea3e4d05b7c5d6843c9206b4ad9cce7883d2`
- Size: 83132824 bytes
- Version: 1.2.14.114_2.0.67
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `devices/system/cpu`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `lib/locale`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `lib/locale/locale-archive`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `self/maps`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `unix/sysv/linux/ifaddrs.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `about/security`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `devices/system/cpu/online`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `files/GDC/RAXE450/RAXE450-V1.2.14.114_2.0.67.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lib/gconv`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lib/gconv/gconv-modules.cache`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `posix/getaddrinfo.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `run/nscd/socket`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `sys/kernel/osrelease`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `unix/sysv/linux/dl-vdso.h`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `unix/sysv/linux/getcwd.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `unix/sysv/linux/getpagesize.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `unix/sysv/linux/getsysstats.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2

### Non-HTTP Service Surface

No prioritized non-HTTP services were identified.

### Sink Summary

- exec: 0
- file_write: 7
- popen: 0
- system: 0
- unsafe_copy: 6

### Config Writer Leads

No config-writer markers found in sampled strings.

### Handler-level Correlated Flows

- `_RAXE450-V1.2.14.114_2.0.67.zip.extracted/41200E`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAXE450-V1.2.14.114_2.0.67.zip.extracted/4BF9ED`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory

### Ghidra Function-local Evidence

No function-local route/sink pairs were emitted by Ghidra.

### Runtime Profile

- Vendor profile: generic
- Web stack: not identified
- State backends: not identified
- Architectures: arm
- Executables/scripts discovered: 4

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 17
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

Structured zero-day triage JSON: `known_firmware/reports/RAXE450/RAXE450-V1.2.14.114_2.0.67.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6ff1a084616ba4bb stopped: extraction exceeded 768 MB

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE450_6ff1a084 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE450_6ff1a084 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE450_6ff1a084 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE450_6ff1a084 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
