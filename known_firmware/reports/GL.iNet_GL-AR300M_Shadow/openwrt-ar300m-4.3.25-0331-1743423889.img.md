# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.25-0331-1743423889.img

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.25-0331-1743423889.img
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.25-0331-1743423889.img
- SHA-256: `8e528e385678baccf4b659215aea74744ed5a1d83ec5add2bd3eff42db8d1732`
- Size: 17695635 bytes
- Version: 4.3.25
- Release date: 2025-03-31 20:23:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, boA, boa`

## Zero-day Triage

This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.

### Known Vulnerability Coverage

No known-vulnerability catalog entries matched this product name.
### High-priority New Candidates

No route candidates were identified.
### Rejected or Deprioritized Routes

- `usb/phy/phy.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `AR8236/AR8316`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `base/core.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `base/regmap/regcache.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `base/regmap/regmap.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `char/hw_random/core.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `core-api/kobject.rst`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `core/datagram.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `core/rtnetlink.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `core/scm.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `core/skbuff.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `core/stream.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `firmware/devicetree/base`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `linux/if_vlan.h`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `linux/kobject.h`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/mtdpart.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/ar934x_nand.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/internals.h`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/nand_base.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/nand_legacy.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/nand_samsung.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/nand_timings.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/raw/nand_toshiba.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/spi/core.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/nand/spi/toshiba.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `mtd/spi-nor/core.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `net/dst.h`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `net/netlink.h`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `net/phy/ar8216.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `net/phy/phy.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7

### Non-HTTP Service Surface

No prioritized non-HTTP services were identified.

### Sink Summary

- exec: 0
- file_write: 22
- popen: 0
- system: 1
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
- Architectures: not identified
- Executables/scripts discovered: 0

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 120
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

Structured zero-day triage JSON: `known_firmware/reports/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.25-0331-1743423889.img.zero-day.json`

## Extraction Notes

- Using existing extraction directory: known_firmware/extracted/8e528e385678bacc

## Decompiler Notes

- No ELF binaries found for Ghidra import.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
