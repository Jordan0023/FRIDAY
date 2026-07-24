# RAX36S V1.0.7.54 unauthenticated RCE/DoS triage

Date: 2026-07-24

## Scope and disposition

- Product: NETGEAR RAX36S
- Firmware: V1.0.7.54
- Package SHA-256:
  `502a73b7a1f58628dece59c5b665a0b7e2b974a23f1e3d2c697a79ea1215dc73`
- Firmware image SHA-256:
  `f16c1d09e6b6ac67264d55055bece03c6397e822c0b96fdfc27f797030d3cab2`
- Confirmed unauthenticated RCE: no
- Confirmed unauthenticated DoS: no
- Zero-day finding: none confirmed in this pass

This is a product-specific application of the RAX30 and EX2800 workflow:
authentication-first route mapping, command-sink review, similar-model variant
analysis, genuine-binary emulation, harmless command-execution canaries, and a
control/candidate/post-case-health DoS method.

## Exact RAX36/RAX36S image equivalence

The RAX36S V1.0.7.54 and RAX36 V1.0.7.54 ZIP packages differ in their product
name and release-note files. Their 63,488,681-byte firmware `.img` payloads are
byte-for-byte identical (`cmp` exit status 0).

Both contain the same SquashFS at offset `0x8ba2a8` (decimal 9,151,144):

- SquashFS 4.0, little endian;
- XZ compression;
- 54,336,142-byte filesystem;
- 3,102 inodes;
- creation timestamp 2025-09-30 04:40:18 UTC.

Consequently, the exhaustive RAX36 V1.0.7.54 decompilation and genuine-binary
results apply exactly to RAX36S. This is stronger than a same-family or
same-version inference.

The transferred work and detailed coverage are recorded in:

- `private_disclosures/RAX36/RAX36_PREAUTH_RCE_DOS_TRIAGE_2026-07-23.md`
- `known_firmware/reports/RAX36/decompile/`
- `known_firmware/emulation/RAX36/`

## Known vulnerability coverage

### CVE-2026-9212

The June 2026 NETGEAR advisory describes insufficient authentication and input
validation that permits a local-network user to execute commands affecting
confidentiality or change configurations.

- RAX36S affected range: versions before V1.0.5.50
- Tested version: V1.0.7.54
- Status: `NOT_APPLICABLE_VERSION`
- Conclusion: the latest tested image is outside the published affected range.
  CVE-2026-9212 must not be reported as a new finding on V1.0.7.54 without a
  demonstrated patch bypass.

Patch-boundary images V1.0.4.46 and V1.0.5.50 were extracted for variant
analysis. Their `net-cgi` binaries are distinct:

- V1.0.4.46:
  `41c88c63a7cff5ae000a8cb55ce4bd95257d1a864120b5c839a987e2c329f6ad`
- V1.0.5.50:
  `c2a3165a0c42af9fc41593f2e10d696605617a86d81fd44c5da03e8215823db4`
- V1.0.7.54:
  `7c18f98cec185600880d086d7c01102600516fa1948e4155351290d16eb2ec64`

The public advisory does not identify a route or parameter. A semantic
V1.0.4.46-to-V1.0.5.50 function diff is therefore the best next variant-analysis
step, with any candidate re-tested against V1.0.7.54.

## Route and candidate coverage

The exact shared image exposes the same principal unauthenticated or
authentication-adjacent surfaces:

- `net-cgi` recovery and setup dispatch:
  `unauth.cgi`, `recover.cgi`, `securityquestions.cgi`, `passwd_reset.cgi`,
  and `BRS_*`;
- MiniUPnPd SSDP, SOAP, and GENA eventing;
- dnsmasq DNS and DHCP parsers;
- the password-bound `telnetenable` UDP activation service; and
- remaining discovery daemons not yet given equivalent dynamic coverage.

Transferred negative results include:

- all 925 `net-cgi` functions decompiled, with apparent request-plus-command
  correlations reviewed and no attacker-controlled command flow established;
- all 121 MiniUPnPd functions decompiled, with the apparent `popen` lead shown
  to use a fixed command;
- recovery fields and raw HTTP components tested through 65,536 bytes without
  terminating `net-cgi` or `lighttpd`;
- the RAX30 GENA crash shape plus extended callback, `TIMEOUT`, `NT`, and SID
  boundary cases tested without terminating MiniUPnPd;
- 22 explicit dnsmasq DNS/DHCP cases and 768 deterministic mutations tested
  without a persistent daemon DoS.

## RAX36S-labeled genuine-binary canary confirmation

The exact V1.0.7.54 `/usr/sbin/miniupnpd`, `/usr/sbin/lighttpd`, and
`/usr/sbin/net-cgi` were run through `qemu-arm-static` in a Docker container
using `--network none`. Synthetic `br0`, LAN-client, and WAN interfaces were
the only interfaces.

The UPnP probe sent four callback values containing semicolon, command
substitution, backtick, and percent-encoded command-like strings. Every request
received `HTTP/1.1 200 OK`. No `FRIDAY_RAX36S*` marker file was created and the
genuine MiniUPnPd process remained alive.

The recovery probe sent semicolon, command-substitution, and backtick canaries
as unauthenticated serial-number values. Every request received HTTP 400. No
marker file was created and the genuine lighttpd/net-cgi service remained
alive.

Reusable probes:

- `known_firmware/emulation/RAX36/rax36s_upnp_canary_probe.py`
- `known_firmware/emulation/RAX36/rax36s_recovery_canary_probe.py`

These are negative command-injection results. An accepted string is not an RCE
unless it reaches a command interpreter and produces a side effect.

## CVE-2026-9212 patch-boundary variant analysis

A Ghidra function-fingerprint comparison covered 928 functions in affected
V1.0.4.46 and 925 functions in fixed V1.0.5.50. The comparison normalized
instruction shapes and retained imported callees and referenced strings so
address shifts in the stripped ARM binaries would not obscure changed
functions.

The security-relevant patch cluster is in `net-cgi` authentication and session
handling. V1.0.5.50 added functions and dispatcher calls for:

- parsing the `auth_token=` cookie;
- checking `/tmp/AUTH_token_unauth`, `/tmp/AUTH_token_login`, and
  `/tmp/AUTH_token_temp_%s`;
- binding or updating tokens using `HTTP_USER_AGENT` and client/session state;
- issuing `Set-Cookie: auth_token=...; HttpOnly; SameSite=Lax`; and
- applying the token checks throughout the large request dispatcher.

The principal fixed-build functions are:

- `FUN_00020030`: authentication response and token issuance;
- `FUN_0002e5c4`: cookie extraction and token-file comparison;
- `FUN_00031160`: token creation/update;
- `FUN_00031390`: authentication state and timeout dispatcher;
- `FUN_0002287c`: main HTTP dispatcher; and
- `FUN_000225b4`: explicit direct-access page classification.

Every one of those functions is instruction-shape identical and the same size
in V1.0.5.50 and V1.0.7.54. The latest firmware therefore retains the complete
observed CVE-2026-9212 authentication patch cluster; there is no code-level
regression in these gates.

A read-only malformed-cookie matrix was then run against the exact V1.0.7.54
web binaries. It covered absent, empty, arbitrary, and duplicate `auth_token`
cookies on the direct-access classifier's pages. No cookie-dependent access
change or service failure occurred. `hidden_info.htm`, `POT.htm`, and
`currentsetting.htm` are deliberately classified for direct access by the
fixed code and returned only status/device information in the emulated state.
They are an information-exposure/hardening surface, not an RCE or specific-DoS
finding. Other named pages returned empty template output in the incomplete
lab state and cannot establish a hardware access boundary.

Artifacts:

- `ghidra_scripts/FridayFunctionFingerprints.java`
- `scripts/compare_function_fingerprints.py`
- `router-agent-results/rax36s-cve-2026-9212-variant/v104-functions.jsonl`
- `router-agent-results/rax36s-cve-2026-9212-variant/v105-functions.jsonl`
- `router-agent-results/rax36s-cve-2026-9212-variant/v107-functions.jsonl`
- `router-agent-results/rax36s-cve-2026-9212-variant/v107-auth-audit.c`
- `known_firmware/emulation/RAX36/rax36s_auth_token_variant_probe.py`

Disposition: `PATCH_APPEARS_PRESENT`. No V1.0.7.54 authentication bypass, RCE,
or DoS was established by the strongest patch-diff lead.

## Normal-boot discovery-daemon analysis: lld2d

Normal-boot script inventory identified `/usr/sbin/lld2d` as the strongest
remaining discovery target:

- `/etc/init.d/lltd` launches `lld2d br0`;
- bridge/AP mode also launches it on the configured LAN interface;
- it runs as root and parses unauthenticated Ethernet type `0x88d9` frames;
- `lldpd` and Avahi are disabled in the firmware build configuration.

The exact V1.0.7.54 daemon has SHA-256
`653b485da76ae98293a76c787e45fe89825ea388ae474fd6038a0e193d01a105`.
It was run with the firmware's ARM loader and libraries on synthetic `br0`
inside the existing `--network none` container. Test frames originated only
from the synthetic `client0` veth.

An exhaustive Ghidra receipt decompiled 99/99 functions with no failures or
timeouts. Three automatic source/sink correlations were configuration or local
file parsing, not network-input flows. Targeted review of the 5,184-byte packet
dispatcher and adjacent Discover, Emit, query-large-TLV, and response builders
found:

- a fixed `read(..., 0x800)` receive bound;
- minimum Ethernet/base-header and opcode validation before dispatch;
- Discover station iteration bounded simultaneously by the claimed count and
  the received-frame end;
- Emit descriptor count/size and total-pause validation;
- truncated query-large-TLV rejection; and
- bounded response copies in the reviewed builders.

The genuine daemon then survived 21 explicit malformed cases:

- Ethernet/LLTD headers truncated at multiple boundaries;
- unsupported version, type-of-service, and opcode values;
- truncated and maximum-count Discover/Emit bodies;
- truncated Hello and query-large-TLV bodies;
- maximum offset and sequence/count values; and
- a maximum-size Ethernet payload.

A further 768 deterministic cases exercised every opcode byte, every
type-of-service byte, and every low byte of the Discover station count. The
original daemon PID remained alive after every frame.

Artifacts:

- `known_firmware/emulation/RAX36/rax36_lld2d_dos_probe.py`
- `router-agent-results/rax36s-lld2d-triage/lld2d-receipt.json`
- `router-agent-results/rax36s-lld2d-triage/lld2d-evidence.jsonl`
- `router-agent-results/rax36s-lld2d-triage/lld2d-functions.jsonl`
- `router-agent-results/rax36s-lld2d-triage/lld2d-parser-audit.c`

Disposition: no observable unauthenticated `lld2d` service DoS and no
network-input-to-command-execution path. This is a negative result, not proof
that every stateful LLTD sequence is safe.

### Stateful LLTD completion

The residual stateful direction was completed using the Microsoft LLTD
Discover/Hello/session flow rather than malformed standalone frames.

The synthetic Linux bridge initially suppressed LLTD's reserved
`01:80:c2:00:00:0e` multicast group. The lab was corrected by enabling only
group-forwarding bit `0x4000`, allowing frames from synthetic `client0` to
arrive on `br0`. The valid Base header uses the multicast Ethernet destination
and the broadcast Real_Destination_Address for Discover and Reset.

Reachability and state transitions were then proven:

- initial Discover frames elicited genuine function-1 Hello responses;
- the responder's advertised generation was parsed and incremented;
- final Discover frames containing the responder MAC advanced the daemon's
  generation and associated the mapper;
- directed QueryLargeTlv requests received function-12 QueryLargeTlvResp
  frames; and
- Reset returned the responder to the unassociated state, where a directed
  post-reset query received no response.

The associated daemon survived:

- valid consecutive, zero, wraparound, and mismatched sequence numbers;
- valid and truncated Query/QueryLargeTlv frames;
- acknowledged and unacknowledged Charge variants;
- one- and two-descriptor Train/Probe Emit requests;
- all 256 QueryLargeTlv type bytes combined with a deterministic 24-bit offset
  sweep; and
- 32 complete Discover/associate/query/reset cycles.

Generation values advanced from 34 through 66 during the final run, proving
that every cycle reached the state engine rather than merely hitting the raw
frame parser. The genuine daemon PID remained stable throughout.

Artifact:

- `known_firmware/emulation/RAX36/rax36_lld2d_stateful_probe.py`

Final LLTD disposition: no unauthenticated RCE, parser DoS, session-transition
DoS, or persistent LLTD service failure was reproduced. Both stateless and
stateful LLTD directions are now complete for this campaign.

## Unconfirmed candidates

1. `net-cgi` pre-authentication exception and recovery/setup callbacks remain
   the best RCE target. Evidence is L2: intentional pre-auth routes and
   dangerous sinks coexist, but no request parameter-to-sink flow is proven.
2. CVE-2026-9212 patch-diff sibling paths are a useful variant-analysis lead,
   but the latest firmware is outside the known affected range.

## Tooling limitations and next work

- No physical RAX36S was available. Results use exact genuine binaries in
  network-isolated emulation.
- The recovery POST path returns HTTP 400 before its inner handler in the lab;
  missing production `smd` state and writable configuration storage may account
  for this difference.
- The authentication-first `zero-day-map` run over the full rootfs did not
  finish within 150 seconds and was stopped without output. Existing exhaustive
  component receipts remain the stronger evidence for the reviewed binaries.
- The strongest CVE-2026-9212 patch-diff lead is complete and did not produce
  a latest-firmware bypass. Hardware validation of direct-access page behavior
  remains useful but is not currently an RCE/DoS lead.
- The strongest remaining normal-boot discovery daemon, `lld2d`, has now
  received exhaustive static coverage and 789 genuine-daemon dynamic cases
  without a reproduced DoS.
- Valid stateful LLTD Discover/Hello/Emit/query/reset testing is complete in
  addition to the saturated stateless malformed-frame coverage.

No item in this report should be called a vulnerability or zero-day until an
attacker-controlled value reaches a dangerous sink or produces a reproducible,
input-specific service failure on the latest firmware.
