# Firmware Audit: RAX36S / RAX36S_V1.0.7.54.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36S/RAX36S_V1.0.7.54.zip
- Local path: known_firmware/firmware/RAX36S/RAX36S_V1.0.7.54.zip
- SHA-256: `502a73b7a1f58628dece59c5b665a0b7e2b974a23f1e3d2c697a79ea1215dc73`
- Size: 60767434 bytes
- Version: 0.7.54
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

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

- `sbin/shn_ctrl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `sw-apps/dynamic-qos/trend`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `bin/curl`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `docs/ssl-ciphers.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `docs/sslcerts.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `fcache/stats/errors`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/evict`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/fhw`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/flow_bmap`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/notify`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/path`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/path_usage`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/query`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/slow_path`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `fcache/stats/vtdev`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `about/security`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `dm/name`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `evms/volumes`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/brlist`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/l2list`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/evt_list_info`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/fdblist`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/host_dev_mac`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/host_netdev`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/mcast_group_info`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/mcastdnatlist`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/mcastlist`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/npelist`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/rtpseqlist`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2
- `fcache/misc/slice_info`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=2

### Non-HTTP Service Surface

- `telnetd` (tcp, lan): auth=unknown, risk=high; source=`_RAX36S_V1.0.7.54.zip.extracted/65DCAA`; evidence=service marker present
- `ftpd` (tcp, lan): auth=unknown, risk=medium; source=`_RAX36S_V1.0.7.54.zip.extracted/65DCAA`; evidence=service marker present

### Sink Summary

- exec: 0
- file_write: 18
- popen: 0
- system: 3
- unsafe_copy: 10

### Config Writer Leads

- `65DCAA: crontab`

### Handler-level Correlated Flows

- `_RAX36S_V1.0.7.54.zip.extracted/6E5810`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory

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
- Structured fuzz seeds: 37
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

Structured zero-day triage JSON: `known_firmware/reports/RAX36S/RAX36S_V1.0.7.54.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/502a73b7a1f58628 stopped: extraction exceeded 768 MB

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX36S_502a73b7 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX36S_502a73b7 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX36S_502a73b7 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX36S_502a73b7 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
