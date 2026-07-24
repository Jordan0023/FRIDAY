# Firmware Audit: RAXE500 / RAXE500-V1.2.14.114_2.0.67.zip

- Source URL: file:///home/jordan/FRIDAY/known_firmware/firmware/RAXE500/RAXE500-V1.2.14.114_2.0.67.zip
- Local path: known_firmware/uploads/RAXE500/RAXE500-V1.2.14.114_2.0.67.zip
- SHA-256: `b1a11003db07a998df113338b035e066dee7cd503b62126a1fdb9a789a9b22f3`
- Size: 83132824 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

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

No routes were explicitly rejected by the impact gate.

### Non-HTTP Service Surface

No prioritized non-HTTP services were identified.

### Sink Summary

- exec: 0
- file_write: 58
- popen: 0
- system: 0
- unsafe_copy: 24

### Config Writer Leads

- `5C406C: !openvpn_gettimeofday(&s->wakeup, NULL)`
- `5C406C: !openvpn_gettimeofday(&tv, NULL)`
- `5C406C: # %d bit OpenVPN static key`
- `5C406C: -----BEGIN OpenVPN Static key V1-----`
- `5C406C: -----END OpenVPN Static key V1-----`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/argv.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/buffer.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/comp-lz4.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/comp.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/compstub.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/crypto.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/crypto_openssl.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/event.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/fdmisc.h`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/forward.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/fragment.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/gremlin.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/helper.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/init.c`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/integer.h`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/shaper.h`
- `5C406C: ../../../../openvpn-2.4.9/src/openvpn/socket.h`
- `5C406C: Cipher algorithm '%s' uses a default key size (%d bytes) which is larger than OpenVPN's current maximum key size (%d bytes)`
- `5C406C: Entering OpenVPN crypto self-test mode.`
- `5C406C: File '%s' does not have OpenVPN Static Key format.  Using free-form passphrase file is not supported anymore.`
- `5C406C: Key file '%s' used in --%s contains insufficient key material [keys found=%d required=%d] -- try generating a new key file with 'openvpn --genkey --secret [file`
- `5C406C: Message hash algorithm '%s' uses a default hash size (%d bytes) which is larger than OpenVPN's current maximum hash size (%d bytes)`
- `5C406C: OpenVPN crypto self-test mode SUCCEEDED.`
- `5C406C: OpenVPN.  A message digest is used in conjunction with`
- `5C406C: OpenVPN: Out of Memory`

### Handler-level Correlated Flows

- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/41200E`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/4BF9ED`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory
- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/5D49FC`: L2-co-located, score 33; sources=nvram_get; sinks=file_write, unsafe_memory
- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/619AF2`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/628D46`: L2-co-located, score 33; sources=nvram_get; sinks=auth, file_write
- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/69B14B`: L2-co-located, score 33; sources=getenv; sinks=file_write, unsafe_memory
- `_RAXE500-V1.2.14.114_2.0.67.zip.extracted/6310B4`: L2-co-located, score 28; sources=getenv; sinks=file_write

### Ghidra Function-local Evidence

No function-local route/sink pairs were emitted by Ghidra.

### Runtime Profile

- Vendor profile: generic
- Web stack: not identified
- State backends: not identified
- Architectures: aarch64, arm
- Executables/scripts discovered: 23

### Dynamic Validation Plan

- Isolation: no external network, no host ports by default, disposable writable rootfs, synthetic LAN client
- Startup candidates: none identified
- Listener candidates: none identified
- Runtime requirements discovered: 0
- Authentication cases: no_credentials, invalid_session, low_privilege
- Structured fuzz seeds: 0
- Archive validation cases: 7

### Confirmation Policy

- confirmed_label_requires: L5
- confirmed_zero_day_requires: ['L5 reproducible security effect with fault/sink attribution', 'novel reproducible pre-authentication exploitation path with no remote administrator session required', 'documented, dated public-prior-art search', 'no matching public disclosure or publicly available fix at the recorded discovery time']
- authenticated_admin_disposition: confirmed vulnerability, but not a confirmed zero-day
- vendor_contact_required: False
- private_duplicate_caveat: public novelty does not exclude an unknown private or embargoed duplicate
- L3: route-specific attacker parameter reaches the sink
- L4: authentication/validation boundary and trigger are proven
- L5: reproducible security effect with fault/sink attribution
- forbidden_shortcut: route string and dangerous symbol merely co-located in a binary

### Triage Notes

- Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.
- Only routes with a plausible low-privilege boundary and route-local sink evidence are promoted. Global firmware sink counts never raise route evidence.
- Authentication labels inferred from strings are hypotheses until dispatcher control flow or a live request confirms them.
- This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.

Structured zero-day triage JSON: `known_firmware/reports/RAXE500/RAXE500-V1.2.14.114_2.0.67.zip.zero-day.json`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b1a11003db07a998 stopped: extraction exceeded 4096 MB

## Decompiler Notes

- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE500_b1a11003 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE500_b1a11003 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)
- /home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless known_firmware/ghidra_projects RAXE500_b1a11003 -import exited 0: OpenJDK 64-Bit Server VM (build 21.0.11+10-1-22.04.2-Ubuntu, mixed mode)

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
