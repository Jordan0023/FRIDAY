# RAX9 V1.0.3.32 unauthenticated RCE/DoS triage

Date: 2026-07-24 UTC

## Outcome

A reproducible unauthenticated LAN denial-of-service candidate was confirmed
against the genuine RAX9 `miniupnpd` binary. A long, syntactically quoted
`SOAPAction` header terminates the process with `SIGSEGV`.

Follow-up testing on 2026-07-24 confirmed the same effect in NETGEAR's current
RAX9 V1.0.9.44 release. See
`NETGEAR_RAX9_MINIUPNPD_SOAPACTION_DOS_REPORT_2026-07-24.md`.

This result is **not a zero-day**. Debugger attribution identified the same
unbounded `strchr(action, '#')` root cause that MiniUPnP publicly reported as
issue #675 on 2023-12-19 and fixed in upstream commit `84cd9e6` on 2023-12-29.
The RAX9 firmware retains this already-public vulnerable logic.

Public-prior-art review also found two CVE-assigned MiniUPnPd SOAPAction parser
vulnerabilities:

- CVE-2013-1462: an unauthenticated DoS caused by a SOAPAction missing a
  double quote;
- CVE-2026-5720: an out-of-bounds read/DoS caused by a malformed SOAPAction
  containing a single quote, fixed upstream in MiniUPnPd 2.3.10.

The RAX9 trigger uses balanced double quotes and length alone, so it does not
match the published input descriptions for those two CVEs. Nevertheless,
zero-day status is conclusively excluded by the earlier public issue and
upstream fix for the exact faulting operation.

No unauthenticated RCE was confirmed.

## Firmware and component

- Product: NETGEAR RAX9
- Firmware: V1.0.3.32
- Archive SHA-256:
  `0d20c9b101b197d3bacc1d8d8749db1716208984cd21432c6d98dca50c5c051d`
- Firmware source:
  `https://www.downloads.netgear.com/files/GDC/RAX9/RAX9-V1.0.3.32.zip`
- Root filesystem: SquashFS at image offset `0x380800`
- Architecture: MIPS32 little-endian, musl
- Daemon: `/usr/bin/miniupnpd`
- Daemon SHA-256:
  `0c3cbb19c6fbc9d68defc11416968f690a541d4cbfc3a0979c014c24cb4f92c3`
- Reported component version: `MiniUPnPd/1.6`
- Default configuration: UPnP enabled, LAN interface, no authentication

The normal firmware configuration sets TCP port 56688. SSDP discovery is
unauthenticated and LAN-scoped.

## Genuine-binary validation

The firmware binary and its original shared libraries were run under
`qemu-mipsel-static` in a disposable Docker container with no published host
ports.

A narrow compatibility shim was required because the vendor binary embeds a
MediaTek WPS component:

- return success only for hardware-private ioctl `0x8be1`;
- return success only for the emulation-incompatible `IP_MULTICAST_IF`
  operation used for SSDP notification setup;
- forward all other `ioctl` and `setsockopt` calls to firmware libc.

The shim does not process HTTP, copy request data, parse headers, or alter
signals. The genuine daemon printed:

```text
miniupnpd[16]: WPS listening on port 8888
miniupnpd[16]: HTTP listening on port 56688
WPSInit() ok !
```

## Controls and trigger

The following cases completed without terminating the HTTP listener:

- ordinary `GET /rootDesc.xml`;
- the RAX30-shaped `SUBSCRIBE /event` callback;
- a callback containing 1024 marker bytes;
- an unrelated 4096-byte HTTP header;
- a 4096-byte URI;
- negative `Content-Length`;
- a quoted SOAPAction with 1024 repeated bytes;
- a quoted SOAPAction with 1536 repeated bytes.

The following case terminated the genuine daemon:

```http
POST /control HTTP/1.1
Host: 127.0.0.1:56688
SOAPAction: "FRIDAY_RAX9_SOAPACTION_DOS_AAAA...[1792 A bytes]"
Content-Length: 13

<s:Envelope/>
```

Observed service log:

```text
miniupnpd[16]: HTTP REQUEST : POST /control (HTTP/1.1)
miniupnpd[16]: SOAPAction: FRIDAY_RAX9_SOAPACTION_DOS_AAAA...
Segmentation fault (core dumped)
```

The preserved container state reported:

```text
status=exited exit=139 oom=false
```

This distinguishes an input-specific `SIGSEGV` from an out-of-memory kill or
generic resource-exhaustion test. The request is approximately 1.9 KiB, so the
effect is not bandwidth exhaustion.

An earlier 4096-byte case independently produced the same `Segmentation fault
(core dumped)` result. A 2048-byte case also closed the service. The transition
was narrowed to greater than the 1536-byte control and at or below the
1792-byte reproducer setting; exact byte threshold is not necessary for
impact confirmation.

## Debugger attribution

The 2048-byte reproducer was repeated with the genuine firmware binary under a
QEMU GDB stub. GDB caught:

```text
Program received signal SIGSEGV
pc = 0x2b322f30
ra = 0x2b322e98
s0 = 0x2b39e000
a1 = 0x00000023
```

The faulting firmware-libc instruction was:

```text
0x2b322f30: lw v0,0(s0)
```

Register `a1` is `0x23`, the ASCII `#` separator expected in a SOAP action.
The searched buffer began with the request marker:

```text
0x2b39d04c: "FRIDAY_RAX9_SOAPACTION_DOS_", 'A' ...
```

The return path on the stack pointed to main-binary address `0x0040c8fc`.
Disassembly of the caller shows:

```text
0x0040c8ec: li   a1,35
0x0040c8f0: move a0,v0
0x0040c8f4: jal  0x0042b200
0x0040c8fc: sw   v0,24(s8)
```

The call target is the imported unbounded character-search routine. It searches
for `#` before checking whether the result lies within the supplied SOAPAction
length. With no `#` in the attacker-controlled value, it reads beyond the
bounded request substring and eventually crosses an unmapped page.

Upstream commit `84cd9e62899a091fe73d17596cc7ab97109b8993` changes exactly:

```c
p = strchr(action, '#');
if (p && (p - action) < n) {
```

to:

```c
p = memchr(action, '#', n);
if (p) {
```

This is the same operation, delimiter, ordering defect, and remedy observed in
the RAX9 binary. Upstream issue #675 publicly documented the associated
out-of-bounds read on 2023-12-19, before the RAX9 V1.0.3.32 filesystem build
date in 2024.

## Published-trigger differentiation

The published trigger shapes were tested separately against a fresh genuine
RAX9 daemon:

- CVE-2026-5720-style single-quote-only SOAPAction: HTTP 500/UPnP 401; daemon
  remained alive.
- CVE-2013-1462-style valid action with a missing closing double quote:
  HTTP 200; daemon remained alive.
- Issue #675's unquoted valid action with a 5000-byte body: HTTP 200; daemon
  remained alive.

Those negative results show that the RAX9 vendor fork does not reproduce the
published inputs verbatim. They do not restore zero-day status. The public
`84cd9e6` fix replaces the exact unbounded `#` search that faults in RAX9, and
therefore publicly disclosed the underlying defective operation before this
firmware was built. The RAX9-specific reliable trigger is an affected-product
variant of already-public root cause, not a novel vulnerability.

## Authentication and reachability

MiniUPnPd does not implement HTTP authentication for control requests. The
firmware enables the service and binds it to the LAN interface. The triggering
request reaches parsing before any SOAP action authorization or semantic
validation, and an invalid short action returns an ordinary HTTP 500/UPnP 401
response.

Current evidence therefore supports unauthenticated adjacent-network/LAN DoS.
WAN exposure was not established.

## Public-prior-art disposition

Searches performed on 2026-07-24 included RAX9, NETGEAR RAX9, MiniUPnPd 1.6,
SOAPAction, crash, denial of service, and relevant CVE terms.

Authoritative references:

- Upstream issue #675:
  `https://github.com/miniupnp/miniupnp/issues/675`
- Upstream bounded-search fix:
  `https://github.com/miniupnp/miniupnp/commit/84cd9e62899a091fe73d17596cc7ab97109b8993`
- Follow-up ExecuteSoapAction fix:
  `https://github.com/miniupnp/miniupnp/commit/5380a086935dc40e6ad51acb12ccb398b643c837`
- Debian CVE-2026-5720 tracker:
  `https://security-tracker.debian.org/tracker/CVE-2026-5720`
- Upstream 2.3.10 fix referenced by Debian:
  `https://github.com/miniupnp/miniupnp/commit/f56bd09b2f2650126b832c5f30a65a09e28167fa`
- CVE-2013-1462 record:
  `https://www.cve.org/CVERecord?id=CVE-2013-1462`
- NETGEAR security advisories:
  `https://www.netgear.com/about/security/`

No RAX9-specific advisory was located in the searches. Product-level absence
does not establish novelty: the exact faulty parser operation and fix were
already public upstream.

## Final classification

- Unauthenticated LAN DoS: **confirmed in genuine-binary emulation**
- Zero-day: **no**
- Reason: exact root cause publicly reported and fixed upstream in December
  2023
- RAX9 product exposure: apparently unpatched in V1.0.3.32
- Current V1.0.9.44 product exposure: **confirmed in genuine-binary
  emulation**
- Physical-device confirmation: still recommended before vendor reporting

## Artifacts

- `known_firmware/emulation/RAX9/rax9_ioctl_shim.c`
- `scripts/probe_rax9_upnp_security.py`
- `scripts/reproduce_rax9_upnp_soapaction_dos.py`
- `scripts/audit_rax9_upnp_wps_deep.py`

## Strongest-next-avenue results

A bounded follow-on matrix was run against the genuine RAX9 MiniUPnPd binary
in an unexposed Docker network:

- IGD `AddPortMapping` descriptions at 256, 1024, 4096, and 16384 bytes:
  handled with HTTP 500; daemon remained alive.
- WPS `PutMessage`, `SetSelectedRegistrar`, `GetAPSettings`, and `ResetAP`
  inputs through 16384 decoded/base64 bytes: no daemon death.
- IGD and WPS event callback values through 4096 bytes: HTTP 200; daemon
  remained alive.

The auth-exempt lighttpd `/soap` route was also traced. `soap.plua` loads the
requested service module before application authentication, but service names
are restricted to `%w+` and action names are stripped of non-word characters,
so no module-path traversal was established. Non-login actions subsequently
call `soapAuth.checkAuthenticated`.

`checkAuthenticated` trusts requests whose TCP peer address is `127.0.0.1` or
the router's own LAN address. This is a meaningful trust shortcut, but an
ordinary remote LAN client cannot naturally select either source address.
No unauthenticated SSRF or local proxy capable of reaching this route was
identified in the reviewed firmware, so the shortcut is not currently a
confirmed remote authentication bypass.

Command-execution sinks in SOAP handlers were reviewed. The
`WANIPConnection.SetSmartWizardDetection` `io.popen` command is constant.
Other reviewed shell invocations use constants or enumerated/mapped values.
`soapAuth.getClientMac` concatenates `REMOTE_ADDR` into an `ip neigh` command;
that value originates from the TCP stack (IPv4/IPv6 address syntax), not an
HTTP-controlled string. No pre-authentication command injection was
established.

## Next work

1. Reproduce on a physical factory-reset RAX9 V1.0.3.32 on an isolated LAN.
2. Report the known-upstream/unpatched-product exposure privately to NETGEAR.
3. Search authenticated/unauthenticated HTTP handlers for an SSRF primitive
   that can originate a request to loopback `/soap`; only then retest the
   local-address trust shortcut as a composed pre-authentication chain.

## Follow-on web-route result

The SSRF search instead exposed a stronger direct chain. The auth-exempt
`/pwd_reset/reset_pwd.plua` dispatcher can invoke arbitrary matching
`webPostHandler` modules. Selecting `accessCtrlDev` reaches an input-validation
override that accepts arbitrary `devName` values, which are concatenated into
a command passed to `/bin/sh -c`.

The genuine emulated endpoint returned success and an emulation-only trace at
the production fork boundary captured the injected marker command verbatim.
See `RAX9_PREAUTH_PWD_RESET_COMMAND_INJECTION_2026-07-24.md`.

This is now a confirmed pre-authentication root RCE in full-system MIPS
emulation. The unmodified firmware shell path created a fixed marker as UID 0.
Physical-device confirmation remains recommended, and zero-day status is
unresolved because older NETGEAR advisories describe pre-authentication
command injection in closely related products without publishing enough
root-cause detail to distinguish this chain.
