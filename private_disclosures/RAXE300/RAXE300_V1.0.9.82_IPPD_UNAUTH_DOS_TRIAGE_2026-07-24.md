# RAXE300 V1.0.9.82 unauthenticated IPP DoS triage

Date: 2026-07-24

## Result

The genuine NETGEAR RAXE300 V1.0.9.82 root filesystem contains a reproducible
unauthenticated memory-corruption vulnerability in `/bin/ippd`. A single
bounded HTTP request with a 257-byte URI corrupts the daemon's heap and removes
its TCP/631 listener in isolated full-system emulation.

This confirms a conditional service-level denial of service. It does not
confirm whole-router denial of service or remote code execution. Exposure
requires the dynamic Internet Printing Protocol service to be enabled, which
normally depends on supported USB-printer state.

This result is treated as an apparent zero-day candidate, not a proven novel
zero-day. NETGEAR's June 2026 advisory publicly lists another unauthenticated
RAXE300 issue, CVE-2026-9211, fixed in V1.0.10.72. The public CVE record maps
that issue to HTTP request smuggling (CAPEC-33), not IPP or TCP/631. More
decisively, the corresponding fixed RAX30 V1.0.10.94 firmware retains the
exact vulnerable `ippd` binary. This demonstrates that the CVE-2026-9211 fix
boundary did not fix or replace this IPP parser in the shared RAX30/RAXE300
component family.

The actual RAXE300 V1.0.10.72 package was not publicly retrievable on
2026-07-24: NETGEAR's advisory names the release, but the official product-page
discovery feed returned no firmware links and the plausible official download
filenames returned HTTP 403. The remaining duplicate caveat therefore requires
either that package, an OTA image from an owned device, or vendor/CNA mapping.

## Firmware and component identity

- Product: NETGEAR RAXE300
- Firmware: V1.0.9.82
- Package SHA-256:
  `08e53e0924044be57ce57e75b8c6b74e40e0513bbb3215fc70a47b5b8c1dbea6`
- `/bin/ippd` SHA-256:
  `4ccd2b74d91c37d71542fdde6227b3dff50404dbffbffb542463f52774a8f88d`

The RAXE300 `ippd` is byte-for-byte identical to the already decompiled and
dynamically tested RAX30-family binary. It is also present unchanged in every
locally archived RAXE300 release:

| RAXE300 firmware | `/bin/ippd` SHA-256 |
|---|---|
| V1.0.5.56_1 | `4ccd2b74...a8f88d` |
| V1.0.7.62 | `4ccd2b74...a8f88d` |
| V1.0.8.64_3 | `4ccd2b74...a8f88d` |
| V1.0.9.82 | `4ccd2b74...a8f88d` |

Build metadata in `/etc/RAXE300` says `BUILD_IPPD=dynamic`, and the shipping CMS
entity table registers `EID_IPPD`. The daemon accepts a printer-definition
file and listens without an HTTP authentication check.

## Root cause transferred from the exact RAX30 binary

- A connection receives a `0x8c`-byte request object.
- The request-line reader accepts up to 1,023 bytes.
- The URI token is copied with unbounded `strcpy()` into the request object at
  offset 8.
- A complete 257-byte URI therefore overwrites heap state beyond the object.
- Header nodes also contain fixed 128-byte name/value fields populated by
  unbounded `strcpy()` and remain a second independently reachable corruption
  path.

The executable is fixed-address ARM with NX, partial RELRO, and no imported
stack-canary support. Prior exact-binary testing established attacker control
of a data pointer but did not establish PC control, ROP, or command execution.

## Genuine RAXE300 dynamic validation

The lab uses:

- the root filesystem extracted from the genuine RAXE300 V1.0.9.82 image;
- the original `/bin/smd` supervisor;
- the original `/bin/ippd`;
- the normal CMS start-message path for EID 45;
- a harmless synthetic printer definition;
- QEMU networking restricted to a loopback-only host forward.

The supervisor successfully launched the daemon as PID 693. TCP/631 was
listening, and three ordinary control requests returned:

```text
baseline=HTTP/1.1 404 Not Found
candidate=HTTP/1.1 404 Not Found
post=HTTP/1.1 404 Not Found
service_available_after_candidate=true
```

A separate bounded URI case returned no response and removed the service:

```text
baseline=HTTP/1.1 404 Not Found
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
```

Serial evidence attributes the failure to the expected copy:

```text
FRIDAY_RAX30_LONG_STRCPY caller=0x00011b68 length=0x00000101
malloc(): corrupted top size
IPPD_HEALTH_PID=693 STATE=Z LISTENING=no
```

The `FRIDAY_RAX30` label is inherited from the tracing shim used for the
byte-identical binary; it does not mean the run used a RAX30 root filesystem.

## Adjacent RAXE290 method transfer

Byte comparison found that the following RAXE300 V1.0.9.82 components are also
identical to RAXE290 V1.0.9.82:

- `/bin/ippd`
- `/bin/upnp`
- `/bin/soap_serverd`
- `/usr/sbin/lighttpd`
- `/webs/cgi-bin/genie.cgi`
- `/webs/cgi-bin/debug.cgi`
- `/webs/cgi-bin/rex_cgi`
- `/lib/libhttpdshared.so`

The existing RAXE290 focused tests therefore provide useful negative evidence
for the same bytes: the RAX30 UPnP event-subscription crash did not reproduce,
and the bounded HTTP/SOAP tests did not confirm pre-authentication RCE or
persistent service DoS. This is not absolute coverage of all handlers or
hardware-only state.

## CVE-2026-9211 fixed-boundary comparison

The archived official RAX30 V1.0.10.94_3 package was extracted because
V1.0.10.94 is the RAX30 fixed version for CVE-2026-9211, while V1.0.10.72 is
the corresponding RAXE300 fixed version.

The fixed RAX30 image still contains:

```text
4ccd2b74d91c37d71542fdde6227b3dff50404dbffbffb542463f52774a8f88d  /bin/ippd
```

This is byte-for-byte identical to the crashing RAXE300 V1.0.9.82 daemon.
Consequently, CVE-2026-9211 cannot reasonably be treated as the same
`ippd` overflow solely because it shares an affected-version boundary and
product list. Its public CAPEC-33 classification and the unchanged daemon in
the fixed sibling release both point to a distinct HTTP-layer issue.

The comparison is not based only on a static dangerous-function match. The
same component hash also appears in the later official RAX30 V1.0.14.108
package, where independent full-system runs reproduced:

- the URI-copy heap corruption twice from clean boots;
- the independent header-value heap corruption;
- daemon exit and loss of TCP/631; and
- attacker control of the data pointer dereferenced at fixed instruction
  `0x1250c` (`r0=r3=0x43434343`).

Because all three packages contain exactly the same ELF bytes, the vulnerable
instructions and object layouts are identical. The RAXE300 run separately
confirms that its genuine surrounding root filesystem and production-style CMS
startup path do not prevent the URI trigger.

## Disposition

- Unauthenticated IPP heap corruption: **confirmed in RAXE300 emulation**
- Unauthenticated IPP service DoS: **confirmed in RAXE300 emulation**
- Default exposure: **conditional on dynamic printer/IPP state**
- Whole-router DoS: **not demonstrated**
- Unauthenticated RCE: **not demonstrated**
- Zero-day status: **apparent candidate; CVE-2026-9211 overlap substantially
  disfavored, but private/embargoed duplicate status remains unknowable**
- Physical RAXE300 validation: **not performed**

## Evidence and reproducer

- Harness:
  `scripts/emulate_raxe300_ippd_full_system.py`
- Bounded probe:
  `scripts/probe_rax42v2_ippd_dos.py --case uri --port 39633`
- Serial transcript:
  `known_firmware/emulation/RAXE300/ippd-full-system-lab/ippd-serial.log`
- Built initramfs:
  `known_firmware/emulation/RAXE300/ippd-full-system-lab/raxe300-ippd-rootfs.cpio.gz`
- Machine-readable fixed-boundary evidence:
  `known_firmware/reports/RAXE300/RAXE300-V1.0.9.82-ippd-fixed-boundary-evidence.json`

## Next validation

1. Acquire V1.0.10.72 through OTA from an owned RAXE300 or when NETGEAR exposes
   the public package, then compare and retest `/bin/ippd`.
2. On an isolated physical device, verify whether attaching a supported USB
   printer starts TCP/631 and whether the supervisor restarts `ippd`.
3. Reproduce the independent 256-byte header-value path using a clean boot.
4. If current firmware still ships the vulnerable binary, submit the evidence
   privately to NETGEAR/Bugcrowd and request explicit duplicate/CVE mapping.

## Unconditional-path follow-up (2026-07-25)

The strongest available path was followed through in two gates.

First, the recovered RAXE300 filesystem was traced for a factory-default or
unauthenticated network activation route. EID 45 is active, but its only flag
is `EIF_MESSAGING_CAPABLE`; it has neither `EIF_LAUNCH_ON_BOOT` nor
`EIF_AUTO_RELAUNCH`. The positive activation path remains
`libcms_core.so:rcl_ippCfgObject`, which writes `/var/printers.ini` and asks
SMD to start EID 45. Searches of the executable, startup, web, CGI, and SOAP
surfaces found no separate caller that directly starts `/bin/ippd`, supplies
`/var/printers.ini`, or identifies EID 45. A clean/default IPP launch therefore
remains unproved, and no unauthenticated remote activation route was found.

Second, the investigation pivoted to the default-listening surface. The
RAXE300 `lighttpd`, `soap_serverd`, `upnp`, CGI, and HTTP support components
are byte-identical to the already tested RAXE290 V1.0.9.82 components.
Bounded sibling tests covered malformed HTTP framing, oversized headers and
request targets, public and setup routes, and malformed DNS inputs without an
independent persistent service failure. SOAP parser reachability remained
incomplete in emulation, so that result is not a claim of SOAP safety.

This follow-up does not support changing the classification to an
unconditional or factory-default DoS. The strongest supported statement
remains: an unauthenticated service-level memory-corruption DoS when dynamic
IPP printing is active.

Structured evidence:
`known_firmware/reports/RAXE300/RAXE300-V1.0.9.82-unconditional-path-evidence.json`.

### Current-firmware acquisition result

NETGEAR's June 2026 advisory identifies RAXE300 V1.0.10.72 as the fixed
version for CVE-2026-9211, the unauthenticated router-control issue. The
separate CVE-2026-3088 router-disruption entry that follows it applies to
listed Orbi products, not RAXE300. This corrects the risk of treating the
RAXE300 version boundary as direct evidence for the IPP crash.

The official product-discovery workflow returned no current firmware link.
Direct checks for `RAXE300-V1.0.10.72.zip`, `_1.zip`, and `_3.zip` in
NETGEAR's official download namespace all returned HTTP 403, so no current
image was available for binary extraction. The strongest available fixed-
boundary comparison remains RAX30 V1.0.10.94: it is the sibling fixed version
for CVE-2026-9211 and still contains the exact vulnerable `ippd`. This
substantially disfavors CVE-2026-9211 as the IPP issue, but it cannot replace
a direct comparison with RAXE300 V1.0.10.72.

The remaining decisive route requires exporting V1.0.10.72 through an owned
RAXE300's OTA/update workflow or waiting for NETGEAR to expose the package.

### Expanded unconditional UPnP hunt (2026-07-25)

The default unauthenticated UPnP surface was exercised in the genuine
full-system runtime used for the byte-identical RAXE290/RAXE300 components.
The run used the real `upnp`, `smd`, libraries, entity metadata, and UPnP
startup arguments, with loopback-only QEMU forwarding.

Ten TCP parser cases covered `CALLBACK` values from 256 through 65,536 bytes,
a 4,096-byte SID, a 4,096-byte `SOAPACTION`, negative and overflowing content
lengths, an 8,192-byte request target, a 65,536-byte generic header, and 1,024
headers. Six independent SSDP cases covered 4,096-byte `ST`, `MAN`, `MX`,
`HOST`, and request-target values plus a 59,986-byte datagram. The daemon
remained alive after every case and emitted no fatal, allocator-corruption, or
segmentation-fault marker.

This matrix does not establish parser safety, but it rejects these specific
boundary families as an unconditional RCE/DoS candidate. No new
unauthenticated RCE or persistent DoS was confirmed in this pass.

- Reproducer: `scripts/probe_raxe300_upnp_boundaries.py`
- Results:
  `known_firmware/emulation/RAXE300/upnp-boundary-matrix.json`
