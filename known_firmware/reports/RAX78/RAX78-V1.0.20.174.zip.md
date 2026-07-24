# Firmware Audit: RAX78 / RAX78-V1.0.20.174.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.20.174.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.20.174.zip
- SHA-256: `09cd2acd7b5de824406a63f91f1d0d3afcb0bdbe7a4e584ed66aee9b51a6350a`
- Size: 67722334 bytes
- Version: 1.0.20.174
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `registration/register`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `SSH/etc`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `about/security`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=7
- `advisor/direct`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `bin/curl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `curlhere.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `device/entry`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `device/hook`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `docs/ssl-ciphers.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `example.com/docs/manpage.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `files/GDC/RAX78/RAX78-V1.0.20.174.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=7
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.build/public/lib`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `m/D`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `net/igmp`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `peernetwork/services/LeafNetsWebServiceV2`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `presence/presence`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `rcagent/scripts`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `registration/status`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `run/netns`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `sw-apps/dynamic-qos/trend`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `usr/arm-buildroot-linux-gnueabi/sysroot/lib/ip/link_`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.build/gpl/share/locale`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=5
- `genie-remote/claimDevice`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=4
- `lib/e2fsprogs`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.install/etc/iproute2/nl_protos`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.install/etc/iproute2/rt_dsfield`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.install/etc/iproute2/rt_protos`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.install/etc/iproute2/rt_realms`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.install/etc/iproute2/rt_scopes`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `lucas/dni_project/RAX70-25-0923/targets/947622GW/fs.install/etc/iproute2/rt_tables`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX78-V1.0.20.174.zip.extracted/446CE3`; evidence=service marker present; local sinks: file_write, unsafe_copy
- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_RAX78-V1.0.20.174.zip.extracted/446CE3`; evidence=service marker present; local sinks: file_write, unsafe_copy
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX78-V1.0.20.174.zip.extracted/446CE3`; evidence=service marker present; local sinks: file_write, unsafe_copy
- `samba` (tcp, lan): auth=unknown, risk=medium; source=`_RAX78-V1.0.20.174.zip.extracted/446CE3`; evidence=service marker present; local sinks: file_write, unsafe_copy

### Sink Summary

- exec: 0
- file_write: 31
- popen: 0
- system: 1
- unsafe_copy: 19

### Config Writer Leads

- `446CE3: forfirewall`
- `446CE3: leafp2p_firewall`

### Handler-level Correlated Flows

- `_RAX78-V1.0.20.174.zip.extracted/43F75D`: L3-correlated, score 39; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX78-V1.0.20.174.zip.extracted/3E7226`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory
- `_RAX78-V1.0.20.174.zip.extracted/457685`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory
- `_RAX78-V1.0.20.174.zip.extracted/46894B`: L2-co-located, score 28; sources=getenv; sinks=unsafe_memory

### Ghidra Function-local Evidence

- `457685:FUN_00010610` at `00010610`: route `/*`, sink `memory_operation`
- `457685:FUN_00010d10` at `00010d10`: route `/*`, sink `unsafe_copy`

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
- Structured fuzz seeds: 49
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

Structured zero-day triage JSON: `known_firmware/reports/RAX78/RAX78-V1.0.20.174.zip.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/09cd2acd7b5de824

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX78_09cd2acd -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- Ghidra emitted 2 function-local route/sink evidence records.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
