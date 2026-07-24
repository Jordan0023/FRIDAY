# Firmware Audit: RAXE290 / RAXE290-V1.0.9.82.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE290/RAXE290-V1.0.9.82.zip
- Local path: known_firmware/firmware/RAXE290/RAXE290-V1.0.9.82.zip
- SHA-256: `3de38411e3c0353b373dffe4eb632d6c9f750e3b96c885410b0fb9fc67298f8c`
- Size: 65923668 bytes
- Version: 1.0.9.82
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `bl_L/bl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `bl_S/bl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `bus/i2c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `ns/net`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `self/ns/net`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `-33/-30dBm`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `125/119`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `40/80MHz`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `about/security`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=7
- `device/name`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `files/GDC/RAXE290/RAXE290-V1.0.9.82.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=7
- `run/netns`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `usr/arm-buildroot-linux-gnueabi/sysroot/lib/ip/link_`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `16/18`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `TR/REC-html40`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=2
- `cr1/cr2`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `cr1/cr2/pll/pll0/pll1`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/dev_mcast`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/igmp`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `net/igmp6`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `office/2004/12/omml`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=2
- `radio/ctl1`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `sys/net/ipv4/route/flush`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `1/2`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=-5
- `cr1/cr2/all`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L0; score=-10
- `cr1/cr2/pll/pll0/pll1/all`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L0; score=-10
- `net/tun`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L2; score=-10
- `rx/scan`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L0; score=-10
- `ofdm/11n/11ac`: deprioritized: authenticated administrator or privileged session required; auth=required; evidence=L0; score=-15

### Non-HTTP Service Surface

- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_RAXE290-V1.0.9.82.zip.extracted/RAXE290-V1.0.9.82_Release_Notes.htm`; evidence=service marker present

### Sink Summary

- exec: 0
- file_write: 31
- popen: 0
- system: 0
- unsafe_copy: 13

### Config Writer Leads

No config-writer markers found in sampled strings.

### Handler-level Correlated Flows

- `_RAXE290-V1.0.9.82.zip.extracted/7505A9`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory

### Ghidra Function-local Evidence

- `7BCE01:FUN_000116bc` at `000116bc`: route `/dev/i2c/%d`, sink `file_write`
- `7BCE01:FUN_000116bc` at `000116bc`: route `/dev/i2c/%d`, sink `unsafe_copy`
- `7BCE01:FUN_000116bc` at `000116bc`: route `/dev/i2c-%d`, sink `file_write`
- `7BCE01:FUN_000116bc` at `000116bc`: route `/dev/i2c-%d`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/proc/bus/i2c`, sink `file_write`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/proc/bus/i2c`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/proc/bus/i2c`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/proc/mounts`, sink `file_write`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/proc/mounts`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/proc/mounts`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/name`, sink `file_write`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/name`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/name`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device/name`, sink `file_write`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device/name`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device/name`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device`, sink `file_write`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device/%s/name`, sink `file_write`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device/%s/name`, sink `unsafe_copy`
- `7BCE01:FUN_000117fc` at `000117fc`: route `/%s/device/%s/name`, sink `unsafe_copy`

### Runtime Profile

- Vendor profile: generic
- Web stack: not identified
- State backends: not identified
- Architectures: arm
- Executables/scripts discovered: 7

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 29
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

Structured zero-day triage JSON: `known_firmware/reports/RAXE290/RAXE290-V1.0.9.82.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/3de38411e3c0353b

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE290_3de38411 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- Ghidra emitted 22 function-local route/sink evidence records.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
