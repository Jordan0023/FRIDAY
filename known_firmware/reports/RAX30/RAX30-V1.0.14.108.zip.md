# Firmware Audit: RAX30 / RAX30-V1.0.14.108.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX30/RAX30-V1.0.14.108.zip
- Local path: known_firmware/firmware/RAX30/RAX30-V1.0.14.108.zip
- SHA-256: `6e7f95ab08e7b70280c3c97944e18d0895903b3cf836b8397fe1a20cd395e658`
- Size: 66681154 bytes
- Version: 1.0.14.108
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, popen, system`

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

- `home/w/rax/rax30/504L02/targets/RAX30/fs.install/lib`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=17
- `upload.cgi`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=16
- `src/openvpn/ssl_openssl.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `src/openvpn/status.c`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=15
- `src/openvpn/tun.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=15
- `1/2`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `1/3`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `bitdefender/bin/bd`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `curlhere.html`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `r1/x`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `w/rax/rax30/504L02/targets/RAX30/fs.build/gpl/lib`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=12
- `src/openvpn/tls_crypt.c`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=10
- `2/4`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7
- `about/security`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=7
- `docs/ssl-ciphers.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `enable/force`: deprioritized: authentication boundary is unknown; cannot qualify as unauthenticated; auth=unknown; evidence=L2; score=7
- `example.com/docs/manpage.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
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
- `files/GDC/RAX30/RAX30-V1.0.14.108.zip`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L1; score=7
- `index.html`: rejected: route is not correlated with a dangerous sink; auth=unknown; evidence=L0; score=7
- `w/rax/rax30/504L02/targets/RAX30/fs.build/public/lib`: deprioritized: sink exists but no attacker-controlled parameter is identified; auth=unknown; evidence=L2; score=7

### Non-HTTP Service Surface

- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX30-V1.0.14.108.zip.extracted/55873C`; evidence=service marker present; local sinks: file_write, system, unsafe_copy
- `cloud` (tcp, outbound): auth=device, risk=high; source=`_RAX30-V1.0.14.108.zip.extracted/5FC8F7`; evidence=service marker present; local sinks: file_write, unsafe_copy
- `mesh` (unknown, lan/wireless): auth=device, risk=high; source=`_RAX30-V1.0.14.108.zip.extracted/RAX30-V1.0.14.108_Release_Notes.htm`; evidence=service marker present
- `upnp` (udp, lan): auth=none, risk=high; source=`_RAX30-V1.0.14.108.zip.extracted/73E4EC`; evidence=service marker present; local sinks: file_write, system, unsafe_copy
- `ftpd` (tcp, lan): auth=unknown, risk=medium; source=`_RAX30-V1.0.14.108.zip.extracted/5DF767`; evidence=service marker present
- `smbd` (tcp, lan): auth=unknown, risk=medium; source=`_RAX30-V1.0.14.108.zip.extracted/73E4EC`; evidence=service marker present; local sinks: file_write, system, unsafe_copy

### Sink Summary

- exec: 0
- file_write: 58
- popen: 0
- system: 2
- unsafe_copy: 26

### Config Writer Leads

- `7968D6: %s (No IANA name known to OpenVPN, use OpenSSL name.)`
- `7968D6: ../../../../openvpn-2.4.9/src/openvpn/ssl_openssl.c`
- `7968D6: ../../../../openvpn-2.4.9/src/openvpn/ssl_verify.c`
- `7968D6: ../../../../openvpn-2.4.9/src/openvpn/ssl_verify_openssl.c`
- `7968D6: ../../../../openvpn-2.4.9/src/openvpn/status.c`
- `7968D6: ../../../../openvpn-2.4.9/src/openvpn/tls_crypt.c`
- `7968D6: ../../../../openvpn-2.4.9/src/openvpn/tun.c`
- `7968D6: OpenVPN external private key RSA Method`
- `7968D6: openvpn_base64_encode(tok, AUTH_TOKEN_SIZE, &multi->auth_token) > AUTH_TOKEN_SIZE`

### Handler-level Correlated Flows

- `_RAX30-V1.0.14.108.zip.extracted/67DDC8`: L3-correlated, score 35; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/766FBD`: L3-correlated, score 35; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/68F4AD`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/6AD661`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/73807E`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/797F12`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/7B01C6`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAX30-V1.0.14.108.zip.extracted/746974`: L3-correlated, score 30; sources=getenv; sinks=file_write

### Ghidra Function-local Evidence

- `55873C:FUN_00010fc4` at `00010fc4`: route `/*`, sink `file_write`
- `67DDC8:FUN_00010638` at `00010638`: route `/*`, sink `unsafe_copy`
- `73E4EC:FUN_00010bb8` at `00010bb8`: route `/*`, sink `unsafe_copy`

### Runtime Profile

- Vendor profile: generic
- Web stack: not identified
- State backends: not identified
- Architectures: arm
- Executables/scripts discovered: 21

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 66
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

Structured zero-day triage JSON: `known_firmware/reports/RAX30/RAX30-V1.0.14.108.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6e7f95ab08e7b702 stopped: extraction exceeded 768 MB

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAX30_6e7f95ab -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- Ghidra emitted 3 function-local route/sink evidence records.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
