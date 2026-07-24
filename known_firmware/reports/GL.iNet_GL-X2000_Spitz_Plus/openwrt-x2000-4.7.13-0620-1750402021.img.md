# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.7.13-0620-1750402021.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.7.13-0620-1750402021.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.7.13-0620-1750402021.img
- SHA-256: `83844f777d2cdf6189ad4ccf2719266e45d8d8726348d9b1bd3e01725ead05b5`
- Size: 72266960 bytes
- Version: 4.7.13
- Release date: 2025-06-20 14:18:42

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `BT/Zigbee`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/m3_fw.b00`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/m3_fw.b01`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/m3_fw.b02`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b00`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b01`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b02`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b03`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b04`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b05`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b07`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b08`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b09`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b10`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b11`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b13`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b14`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b15`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b16`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b17`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b18`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b20`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b21`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b22`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b23`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b25`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/q6_fw.b26`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/qcn6122/m3_fw.b00`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/qcn6122/m3_fw.b01`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `ms/bin/5018.wlanfw2.map_spr_spr_eval_cs/PIL_IMAGES/qcn6122/m3_fw.b02`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10

### Non-HTTP Service Surface

- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_openwrt-x2000-4.7.13-0620-1750402021.img.extracted/squashfs-root/Data.msc`; evidence=service marker present; local sinks: file_write
- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_openwrt-x2000-4.7.13-0620-1750402021.img.extracted/squashfs-root/qcn6122/Data.msc`; evidence=service marker present; local sinks: file_write

### Sink Summary

- exec: 0
- file_write: 7
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

- Vendor profile: openwrt
- Web stack: not identified
- State backends: not identified
- Architectures: elf-164, elf-3
- Executables/scripts discovered: 6

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 58
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

Structured zero-day triage JSON: `known_firmware/reports/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.7.13-0620-1750402021.img.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/83844f777d2cdf61 exited 0

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-X2000_Spitz_Plus_83844f77 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-X2000_Spitz_Plus_83844f77 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-X2000_Spitz_Plus_83844f77 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-X2000_Spitz_Plus_83844f77 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-X2000_Spitz_Plus_83844f77 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects GL.iNet_GL-X2000_Spitz_Plus_83844f77 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
