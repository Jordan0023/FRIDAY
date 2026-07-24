# RAX36 V1.0.7.54 pre-authentication RCE/DoS triage

Date: 2026-07-23

## Scope

- Product: NETGEAR RAX36
- Firmware: V1.0.7.54
- Firmware SHA-256:
  `7dfad4f35401482f562210c3406de68b3cc3bf1b886819feeb965ba161dcd200`
- Objective: identify LAN/WAN reachable paths that could yield unauthenticated
  remote code execution or reliable input-specific denial of service.

## Extraction correction

The campaign's earlier `fully_decompiled` result was not full-firmware
coverage. Recursive extraction exhausted its 768 MB allowance on false-positive
XZ streams before reaching the real root filesystem.

The actual SquashFS begins at firmware-image offset `0x8ba2a8` (decimal
`9151144`). Manual extraction recovered 2,367 files and 560 symlinks, including
the previously missed primary attack-surface binaries:

- `/usr/sbin/net-cgi`
- `/usr/sbin/lighttpd`
- `/usr/sbin/miniupnpd`
- `/usr/sbin/dnsmasq`
- `/usr/sbin/telnetenable`
- `/usr/sbin/utelnetd`
- `/opt/xagent/xagent`

The prior `fully_decompiled` label therefore means only that every ELF found by
the incomplete extraction was processed. It must not be interpreted as full
RAX36 binary coverage.

## Confirmed attack-surface architecture

`lighttpd` listens on TCP port 80 and maps every requested path to
`/usr/sbin/net-cgi` through a catch-all `cgi.assign` entry. `net-cgi` therefore
implements both authentication and request dispatch.

`net-cgi` contains explicit pre-authentication or authentication-adjacent
routes including:

- `unauth.cgi`
- `recover.cgi`
- `securityquestions.cgi`
- `passwd_reset.cgi`
- factory/setup `BRS_*` pages

It also implements authenticated high-impact handlers including firmware
upgrade, debug collection, configuration apply, SOAP handling, and diagnostic
ping functionality.

`miniupnpd` is started by normal WAN/LAN initialization and accepts LAN-side
SSDP and SOAP requests without web-administrator authentication.

`telnetenable` runs in normal mode. It receives the classic NETGEAR enable
packet, obtains the configured administrator password through
`/tmp/uhttp_key_telnet`, and then starts `utelnetd`. Factory mode can start
`utelnetd` with `/bin/sh` directly, but that state is a separate physical or
manufacturing precondition.

## Decompilation coverage completed in this pass

### net-cgi

- Functions discovered: 925
- Functions submitted successfully to the decompiler: 925
- Function-local source/sink correlations: 50
- Failed functions: 0

The two initially interesting `getenv` plus `system` correlations at
`0x2287c` and `0x31390` were reviewed. Their `system` arguments are fixed
program strings; the HTTP environment values do not form the command
arguments. Other sampled `fgets` plus `system` correlations likewise use
fixed commands or trusted local files. They are not current command-injection
leads.

The explicit `unauth.cgi` route reaches `FUN_0002dce8`. Its visible stack
copies and formatting operations are bounded. No direct command-execution sink
was recovered in that route handler.

The four direct `strcpy` call sites recovered from `net-cgi` were reviewed.
The principal large validation function rejects shell metacharacters, slashes,
quotes, and other unsafe characters according to field type. Other call sites
operate on fixed-size address/configuration values or are analysis artifacts.
No pre-authentication overflow was established.

### miniupnpd

- Functions discovered: 121
- Functions submitted successfully to the decompiler: 121
- Function-local source/sink correlations: 6
- Failed functions: 0

The apparent `popen` candidate at `0x24390` uses a fixed command after writing
fixed-format firewall state. SOAP parameters are not incorporated into the
command string. It is not a command-injection lead.

The remaining correlations are local configuration-file parsing and bounded
file-update operations. No request-derived command sink was identified.

## Current candidate ranking

### 1. net-cgi authentication exception dispatcher

Priority: medium-high for further review.

Reason: a small set of recovery and factory-setup routes intentionally bypass
normal administrator authentication. The large dispatcher at `0x2287c`
contains many state-dependent exceptions. The visible top-level unauthenticated
handler is bounded, but indirect template callbacks and recovery POST handlers
still require call-graph-specific review.

Current evidence level: L2. A dangerous firmware sink and intentional pre-auth
routes exist, but no attacker-input-to-sink flow is proven.

#### Focused dispatcher and recovery review (2026-07-24)

The genuine V1.0.7.54 `lighttpd` and `net-cgi` binaries were booted in an
isolated full-system ARM VM. The lab used a localhost-only forwarded port and a
configuration shim modeling a configured router with password recovery
enabled.

Confirmed without administrator credentials:

- `/unauth.cgi` renders the serial-number recovery form;
- `/securityquestions.cgi` is reachable but redirects to `unauth.cgi` unless
  the expected recovery state exists;
- `/passwd_reset.cgi` is reachable and renders the recovery questions in the
  emulated state;
- `/BRS_index.htm` is served by the setup dispatcher.

The `/recover.cgi` POST dispatcher rejected all tested requests with HTTP 400
before the recovery input handler was reached. This included freshly extracted
per-request timestamps, the browser's encoded form-action variants, a normal
13-byte serial number, shell metacharacters, and serial/answer fields through
65,536 bytes. `net-cgi` and `lighttpd` remained alive. This is a negative DoS
result, but the missing production `smd` service and writable configuration
partition mean it does not prove that valid recovery submissions are
unreachable on hardware.

The BRS ping path was also reviewed because the binary contains:

`ping -c %d %s > %s 2> %s &`

Direct string xrefs identify the command constructor as `FUN_0003f004`. It
uses a 128-byte bounded formatter. One-level caller recovery found callers at
`FUN_00032618`, `FUN_0003298c`, `FUN_0003f35c`, `FUN_00055c18`,
`FUN_00032a60`, and `FUN_00035ca4`. Each supplies fixed firmware strings or
configuration-derived addresses; none passes a CGI field into the command's
host argument. The apparent BRS ping command-injection lead is therefore
rejected.

Reusable analysis artifacts:

- `known_firmware/emulation/RAX36/rax36_recovery_probe.py`
- `known_firmware/emulation/RAX36/rax36_web_shim.c`
- `ghidra_scripts/FridayStringXrefs.java`

### 2. miniupnpd HTTP/SOAP parser

Priority: medium for DoS/memory-corruption review.

Reason: it is unauthenticated and LAN reachable. It parses attacker-controlled
HTTP `Content-Length`, `SOAPAction`, callback URLs, subscription headers, and
SOAP bodies. Complete function submission found no obvious source-to-unsafe
copy correlation, and the command candidate was rejected. Parser-specific
boundary testing remains warranted.

Current evidence level: L1-L2. Reachability and inputs are known, but no
faulting condition or unsafe size relationship is proven.

#### RAX30-method transfer test (2026-07-24)

The genuine RAX36 V1.0.7.54 `/usr/sbin/miniupnpd` was run under `qemu-arm` in
a privileged Docker container with `--network none`. The lab provided only
synthetic `br0`, LAN-client, and WAN interfaces. The client explicitly bound
to `192.168.1.2`; this is required because MiniUPnPd rejects event callbacks
whose address does not match the subscriber.

The 35-case bounded HTTP/SOAP corpus previously used against the NETGEAR
BE17000 completed without terminating the daemon. It covered truncated XML,
malformed and 8 KiB `SOAPAction` values, invalid and overflowing
`Content-Length` values, a 16 KiB header, and a 64 KiB body. The descriptor
endpoint remained healthy after every case.

The confirmed RAX30 event-subscription DoS method was then transferred to the
RAX36 `/evt/L3F` endpoint. Results:

- valid short callback: `HTTP/1.1 200 OK`, daemon alive;
- RAX30-shaped callback (76 bytes in the RAX36-addressed case):
  `HTTP/1.1 200 OK`, daemon alive;
- 73-byte callback without a URL scheme: `HTTP/1.1 412 Precondition Failed`,
  daemon alive;
- 8,211-byte callback: `HTTP/1.1 200 OK`, daemon alive.

Therefore the RAX30 crash does not transfer to RAX36. This is consistent with
the products using unrelated UPnP implementations: RAX30 uses NETGEAR's
Broadcom-derived `upnp` binary, while RAX36 uses MiniUPnPd 2.2.0-RC0.

Reusable bounded probe:

- `known_firmware/emulation/RAX36/rax36_upnp_probe.py`

#### Extended RAX30-method validation (2026-07-24)

The eventing test was expanded while retaining the RAX30
control/candidate/post-case-health method. Ten unauthenticated event requests
covered callbacks through 65,536 bytes, 65,536-byte `TIMEOUT` and `NT` values,
duplicate callback headers, and 8,192-byte renewal/unsubscribe SIDs.

The valid callback and both long callbacks were accepted with HTTP 200. The
daemon's debug output showed that it parsed the 65,536-byte callback and
attempted the event connection. Invalid event fields received HTTP 412. The
descriptor endpoint returned HTTP 200 after every case and the daemon remained
alive. No event-subscription service DoS was observed.

The web recovery surface was also subjected to a raw HTTP matrix under
full-system ARM emulation. It covered 65,536-byte query strings, paths,
`Cookie`, `User-Agent`, and `Host` headers; conflicting `Content-Length`
headers; chunked form data; and an encoded-NUL query. Oversized request-line
and header cases were closed without a response, malformed framing received
HTTP 400, and `/unauth.cgi` remained healthy after every case.

Additional reusable probe:

- `known_firmware/emulation/RAX36/rax36_web_dos_probe.py`

### 3. telnetenable UDP activation path

Priority: reduced after static and dynamic validation.

Reason: activation leads to a remote login service and is LAN reachable.
Normal-mode configuration appears to bind activation to the configured
administrator password. Direct `/bin/sh` login is limited to factory mode or
a separate configuration flag.

The exact binary's receive loop binds UDP/23 to the LAN address and reads at
most 512 bytes into a 512-byte buffer. For every datagram it independently
constructs the expected encrypted activation packet from the LAN MAC, the
literal `admin`, and the configured password read from
`/tmp/uhttp_key_telnet`. It requires both an exact packet-length match and a
full `memcmp()` match before launching the fixed telnet update script and
`utelnetd`. No request-derived shell command is constructed.

The genuine ARM daemon was started with a nonempty disposable administrator
password inside the network-isolated RAX36 emulator. Thirteen datagrams
covered zero and one byte, protocol-like text, NUL and `0xff` blocks,
boundaries from 255 through 513 bytes, 4,096 bytes, and the maximum 65,507-byte
UDP payload. The kernel/daemon truncated oversized input to the fixed receive
bound, the same daemon PID survived every case, no response was returned, and
telnet was not activated.

Result: no authentication bypass and no service DoS were established.
Factory-mode direct-shell startup remains a separate physical/configuration
precondition rather than a network authentication bypass.

Artifacts:

- `known_firmware/emulation/RAX36/rax36_telnetenable_dos_probe.py`
- `known_firmware/reports/RAX36/decompile/telnetenable-auth-path.c`
- `known_firmware/reports/RAX36/decompile/telnetenable-receive.c`

### 4. dnsmasq

Priority: reduced after exact-binary validation.

The exact RAX36 binary is dnsmasq 2.80:

- SHA-256:
  `4fa4a10761d0dd80b1c245edfcaa00bd2f9521360aae6f08d29a11de4f8eac20`;
- enabled: IPv6, DHCPv4, DHCPv6, authoritative DNS, loop detection, ipset;
- disabled: DNSSEC, TFTP, DBus, Lua, conntrack, IDN.

An exhaustive receipt decompiled 423/423 functions with no failures or
timeouts. Eight function-local source/sink correlations were emitted. The
network-receive candidate uses a 1,024-byte `recvmsg()` buffer, rejects
truncated messages, and bounds its length-derived clearing operation by the
same buffer size. Its nearby `system()` call uses a fixed firmware string,
not packet data. Other candidates consume local configuration files.

The exact binary was then run with DNS and DHCP enabled in a disposable
networkless container. A synthetic LAN router at `192.168.1.1` and client at
`192.168.1.2` were the only interfaces. Twenty-two explicit cases covered:

- short DNS headers, invalid question counts, truncated labels;
- compression loops/chains and maximum wire-format names;
- binary labels, malformed EDNS lengths, and a 4 KiB datagram;
- DNS-over-TCP zero, short, and 65,535-byte declared lengths;
- DHCP missing cookies and truncated options;
- 255-byte hostname, client-ID, and vendor-class options;
- invalid DHCP option-overload state; and
- an 8 KiB DHCP padding/options packet.

The DHCP cases reached the parser, as confirmed by the daemon's own
`DHCPDISCOVER`/`DHCPOFFER` records. A further 768 deterministic mutations
covered every possible first-label byte, compression-pointer low byte, and
DHCP option code. The known-good DNS answer and daemon PID remained healthy
after every explicit case and each 16-case mutation group.

The May 2026 upstream CVE patches were reviewed separately. The NSEC/RRSIG
issues require DNSSEC, which is compiled out. The DHCPv6 CLID overflow requires
`--dhcp-script`, which the RAX36 launcher does not configure. The arbitrary-RR
length crash affects code added after 2.80. No version-only vulnerability claim
is therefore justified for those paths. The `struct bigname` fix is relevant
to escaped DNSSEC names; this build's non-DNSSEC extractor rejects the
characters that cause representation expansion.

Artifacts:

- `known_firmware/emulation/RAX36/rax36_dnsmasq_dos_probe.py`
- `known_firmware/reports/RAX36/decompile/dnsmasq-receipt.json`
- `known_firmware/reports/RAX36/decompile/dnsmasq-evidence.jsonl`
- `known_firmware/reports/RAX36/decompile/dnsmasq-candidates.c`

Result: no unauthenticated dnsmasq service DoS was confirmed in this pass.

### 5. Remaining discovery daemons

Priority: reduced after LLTD validation.

Reason: these unauthenticated parsers have not yet received the same targeted
decompilation and dynamic boundary testing.

#### LLTD boundary validation (2026-07-24)

The genuine RAX36 `/usr/sbin/lld2d` (SHA-256
`653b485da76ae98293a76c787e45fe89825ea388ae474fd6038a0e193d01a105`)
was submitted exhaustively to Ghidra. All 99 discovered functions decompiled
successfully. The daemon reads at most 2,048 bytes from its raw Ethernet
socket and applies explicit minimum-header, version, opcode, station-count,
descriptor-count, and end-of-frame checks before dispatch.

The exact ARM daemon was then started on the synthetic `br0` LAN in the
existing Docker emulator, which has `NetworkMode=none`. A client on the
container-local `client0` veth sent 21 bounded LLTD frames. The matrix
included:

- Ethernet and LLTD headers truncated at several boundaries;
- unsupported versions and opcodes;
- Discover frames declaring one or 65,535 stations with missing data;
- Emit frames declaring 65,535 descriptors with zero or one descriptor;
- truncated and maximum-offset large-TLV queries;
- malformed quick-discovery and QoS messages; and
- a 1,494-byte maximum Ethernet frame.

The same daemon PID survived every case. This is a negative service-DoS
result, not proof that every LLTD state-machine sequence is safe.

Artifacts:

- `known_firmware/emulation/RAX36/rax36_lld2d_dos_probe.py`
- `known_firmware/reports/RAX36/decompile/lld2d-candidates.c`
- `known_firmware/reports/RAX36/decompile/lld2d-packet-handlers.c`

#### Focused authentication-marker review (2026-07-24)

The EX2800 discovery method was applied to RAX36 state markers and setup
routes. Recursive decompilation covered `/tmp/AUTH_no_need_auth`,
`/tmp/AUTH_nullpass`, `/tmp/AUTH_token_unauth`, `/tmp/first_time_login`,
`BRS_index.htm`, and the firmware-upload handler.

Unlike EX2800, no setup-route-to-one-shot-upgrade-bypass chain was recovered.
`AUTH_nullpass` is derived from an actually empty configured administrator
password, the token paths compare request state with per-login files and
timestamps, and `first_time_login` is rendered as setup state. The reviewed
firmware-upload command is a fixed firmware command; request bytes do not form
its shell command. An unauthenticated request to `BRS_index.htm` in the
isolated web lab did not create any of the reviewed authentication marker
files.

Artifact:

- `known_firmware/reports/RAX36/decompile/net-cgi-auth-markers.c`

#### CVE-2026-9212 patch-boundary and token robustness review (2026-07-24)

The exact RAX36/RAX36S `net-cgi` binaries bracketing NETGEAR's published
CVE-2026-9212 fix were recovered and verified:

- V1.0.4.46 (affected): SHA-256
  `41c88c63a7cff5ae000a8cb55ce4bd95257d1a864120b5c839a987e2c329f6ad`
- V1.0.5.50 (fixed): SHA-256
  `c2a3165a0c42af9fc41593f2e10d696605617a86d81fd44c5da03e8215823db4`
- V1.0.7.54 (current target): SHA-256
  `7c18f98cec185600880d086d7c01102600516fa1948e4155351290d16eb2ec64`

The fixed boundary introduces a cookie-token authentication framework absent
from the affected binary. New strings and their recovered users include
`auth_token=`, `/tmp/AUTH_token_unauth`, `/tmp/AUTH_token_login`,
`/tmp/AUTH_token_temp_%s`, `send_authenticate`, and `update_token`. This
supports an authentication/input-validation fix, but the public record scores
the disclosed issue as adjacent-network with low privileges; it is not itself
evidence of an unauthenticated zero-day.

The strongest sibling hypothesis was malformed token parsing in the current
binary. The genuine V1.0.7.54 web service was exercised in the isolated
network-none container with empty, one-byte, percent-NUL, format-shaped,
traversal-shaped, duplicate, quoted, and 1,024 through 65,536-byte cookie
values. The original lighttpd PID survived all 12 cases. Requests through
4,096 bytes received HTTP 200 in this lab; larger headers were closed without
a response. A post-matrix health request succeeded, and no `AUTH_token`,
`auth_token`, or traversal-canary file was created.

Artifact:

- `known_firmware/emulation/RAX36/rax36_auth_token_dos_probe.py`

#### Focused discovery-binary coverage (2026-07-24)

The corrected extraction's `lld2d`, `net-scan`, `telnetenable`, and
`genie.cgi` were submitted to the receipt-driven decompiler. Coverage was
complete for 326/326 discovered functions. `net-scan` receives into explicit
60-byte and 1,024-byte buffers using those exact bounds. Its initial
source/sink correlations primarily cover local configuration parsing, JSON
serialization, and fixed maintenance commands; no packet-derived command
argument was established in this pass.

Receipt:

- `router-agent-results/20260724T-RAX36-focused-discovery/summary.json`

## Current disposition

- Confirmed unauthenticated RCE: no
- Confirmed unauthenticated DoS: no
- Strong command-injection lead: no; the highest-ranked apparent correlations
  used fixed command strings
- Strong memory-corruption lead: no
- Best remaining target: the `net-cgi` pre-authentication exception dispatcher
  and indirect recovery/setup handlers
- Best remaining DoS target: discovery daemons not yet faithfully emulated
- RAX30 UPnP event DoS transfer: tested negative in genuine-daemon emulation
- BRS ping command injection: rejected; command arguments are not CGI-derived
- Recovery parser DoS: not observed through 65,536-byte fields in emulation
- Raw HTTP/CGI DoS: not observed through 65,536-byte request components
- dnsmasq DNS/DHCP DoS: not observed across 22 explicit cases and 768
  deterministic parser mutations
- LLTD service DoS: not observed across 21 bounded malformed Ethernet frames
- telnetenable service DoS: not observed across 13 bounded UDP cases through
  the maximum UDP payload; activation remains password- and MAC-bound
- EX2800-style setup/auth-marker chain: not found in focused static review;
  `BRS_index.htm` did not create a bypass marker in emulation
- CVE-2026-9212 token-parser sibling: no observable DoS or token-file side
  effect across 12 malformed-cookie cases; published issue itself requires
  low privileges

No item should be described as a vulnerability until an attacker-controlled
parameter reaches a dangerous sink or produces a reproducible, input-specific
fault.
