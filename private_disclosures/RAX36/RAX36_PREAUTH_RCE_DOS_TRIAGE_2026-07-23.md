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

### 3. telnetenable UDP activation path

Priority: medium-low.

Reason: activation leads to a remote login service and is LAN reachable.
Normal-mode configuration appears to bind activation to the configured
administrator password. Direct `/bin/sh` login is limited to factory mode or
a separate configuration flag.

Current evidence level: L1. It is an exposed control path, but no
authentication bypass is identified.

### 4. dnsmasq and discovery daemons

Priority: pending.

Reason: these are unauthenticated parsers but were not yet included in the
targeted decompilation pass. They should be reviewed after the vendor-specific
web and UPnP paths.

## Current disposition

- Confirmed unauthenticated RCE: no
- Confirmed unauthenticated DoS: no
- Strong command-injection lead: no; the highest-ranked apparent correlations
  used fixed command strings
- Strong memory-corruption lead: no
- Best remaining target: the `net-cgi` pre-authentication exception dispatcher
  and indirect recovery/setup handlers
- Best DoS target: `miniupnpd` request framing and subscription/SOAP parsing
- RAX30 UPnP event DoS transfer: tested negative in genuine-daemon emulation

No item should be described as a vulnerability until an attacker-controlled
parameter reaches a dangerous sink or produces a reproducible, input-specific
fault.
