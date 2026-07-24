# RAXE290 V1.0.9.82 pre-authentication RCE/DoS triage

Date: 2026-07-24

## Result

A conditional product-level unauthenticated IPP service denial of service is
confirmed in firmware emulation.

Two RAX30-derived surfaces were transferred into isolated full-system labs
using the genuine RAXE290 V1.0.9.82 root filesystem:

- The RAX30 UPnP event-subscription crash did **not** transfer. Both the short
  control callback and the crash-shaped callback left the genuine RAXE290
  `upnp` daemon alive with its original PID.
- The RAXE290 `ippd` contains two reproducible unauthenticated memory-corruption
  crashes when the daemon is active. A 257-byte URI and an independent
  256-byte header value each terminate the service.
- Reproduction of the genuine `rcl_ippCfgObject` CMS message established the
  shipping dynamic-printer path: SMD launches
  `/bin/ippd /var/printers.ini`, and the daemon listens without authentication
  on `0.0.0.0:631`.
- In that stock-supervised state, the 257-byte URI corrupts the heap, leaves
  `ippd` as a zombie, removes TCP/631, and is not automatically relaunched.

The correct current label is therefore **apparent zero-day conditional
unauthenticated IPP service DoS**. The condition is dynamic printer activation,
normally associated with a configured or attached USB printer. Physical-device
confirmation is still required.

## Firmware

- Product: NETGEAR RAXE290
- Version: V1.0.9.82
- Package: `RAXE290-V1.0.9.82.zip`
- Package SHA-256:
  `3de38411e3c0353b373dffe4eb632d6c9f750e3b96c885410b0fb9fc67298f8c`
- SquashFS offset: `9344374`
- `/bin/upnp` SHA-256:
  `8cd5eaa40b7e4091b43734be193dbd01d21592a0a8041282fecd50f32718a2f2`
- `/bin/ippd` SHA-256:
  `4ccd2b74d91c37d71542fdde6227b3dff50404dbffbffb542463f52774a8f88d`

The RAXE290 `ippd` is byte-for-byte identical to the RAX30 V1.0.14.108
binary used by the existing RAX30 lab.

## Isolation

Both labs use:

- a stock Debian ARM kernel under QEMU;
- the genuine extracted RAXE290 root filesystem;
- QEMU user networking with `restrict=on`;
- loopback-only host forwarding where required; and
- a disposable synthetic printer file for direct `ippd` parser validation.

No live router or internet-reachable target was tested.

## UPnP transfer test

The genuine daemon started, listened on TCP/56688, and answered SSDP. The
guest-side probe recovered the generated UUID and sent each request directly
to `127.0.0.1:56688`.

Short callback control:

```text
FRIDAY_RAXE290_PROBE_MODE=control
FRIDAY_RAXE290_POST_PROBE_PID=720
FRIDAY_RAXE290_POST_PROBE_ALIVE=yes
```

RAX30 crash-shaped callback:

```text
FRIDAY_RAXE290_PROBE_MODE=candidate
FRIDAY_RAXE290_POST_PROBE_PID=711
FRIDAY_RAXE290_POST_PROBE_ALIVE=yes
```

This rejects direct transfer of the RAX30 event-subscription DoS.

## IPP direct-daemon validation

### Control

```text
baseline=HTTP/1.1 200 OK
candidate=HTTP/1.1 200 OK
post=HTTP/1.1 200 OK
service_available_after_candidate=true
```

### 257-byte URI

```text
baseline=HTTP/1.1 200 OK
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00011b68 length=0x00000101
IPPD_EXITED=1
```

### 256-byte header value

```text
baseline=HTTP/1.1 200 OK
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x000124f4 length=0x00000100
IPPD_EXITED=1
```

Both failures are input-specific unbounded-copy crashes, not resource
exhaustion. Authentication is not enforced by the active parser.

## Shipping dynamic-printer activation

Unlike RAX42v2, the RAXE290 shipping entity metadata includes EID 45:

```text
BEGIN
  eid         = EID_IPPD
  name        = ippd
  flags       = EIF_MESSAGING_CAPABLE
END
```

The first-pass activation helper incorrectly addressed the start message
directly to EID 45. Reverse engineering the shipping `rcl_ippCfgObject`
established the real convention:

```text
type=0x10000809
destination=EID_SMD (20)
wordData=EID_IPPD (45)
optional arguments=/var/printers.ini
```

The corrected model-specific helper reproduces that exact CMS/SMD message.
With the shipping entity metadata unchanged, SMD reports:

```text
Got msg type 0x10000809 src=0x14 dst=0x14
setting optional args /var/printers.ini
spawning //bin/ippd args  /var/printers.ini
IPPD_PID=705
IPPD_ALIVE=yes
IPPD_LISTENING=yes
```

The resulting `/proc/net/tcp` entry is `00000000:0277`, confirming
all-interface TCP/631 binding.

### Clean stock-path control

The normal unauthenticated request remained healthy for the ten-second
observation:

```text
baseline=HTTP/1.1 404 Not Found
candidate=HTTP/1.1 404 Not Found
post=HTTP/1.1 404 Not Found
service_available_after_candidate=true
IPPD_HEALTH_PID=705 STATE=S LISTENING=yes
```

### Clean stock-path candidate

The 257-byte URI produced:

```text
baseline=HTTP/1.1 404 Not Found
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00011b68 length=0x00000101
malloc(): corrupted top size
IPPD_HEALTH_PID=705 STATE=Z LISTENING=no
```

The zombie state and absent listener persisted across six health samples.
The shipping entity has `EIF_MESSAGING_CAPABLE` but not `EIF_AUTO_RELAUNCH`;
SMD did not restore the service.

This confirms the vulnerable parser on the shipping activation path, while
retaining one deployment precondition: IPP must first be dynamically enabled
through printer configuration.

## Attempted non-IPP pivot

An exact-hash comparison against the extracted firmware corpus found that the
RAXE290 copies of `bcmmserver`, `bftpd`, `dnsmasq`, `telnetd`, `utelnetd`, and
`toad` are byte-identical to RAX28/RAX29 V1.0.14.108. None currently has a
confirmed unconditional pre-authentication crash in this repository. The
RAXE290 `upnp` and `soap_serverd` binaries do not match the previously
confirmed vulnerable binaries.

The next bounded test targeted `soap_serverd`, whose shipping entity is marked
`EIF_LAUNCH_ON_BOOT|EIF_AUTO_RELAUNCH`. A genuine-firmware full-system image
launched the process using the stock `-d 0 -n 1` arguments. The process stayed
alive, but did not establish the expected TCP/5000 listener in the emulated
configuration; loopback-forwarded requests were reset. Consequently this run
did not reach the SOAP parser and is not evidence of either a vulnerability or
parser safety. It also does not provide a demonstrated route around the IPP
activation precondition.

## Activation-bypass and always-on web review

Three follow-up tracks were completed:

1. **Remote activation trace.** Firmware-wide exact-string tracing found the
   IPP start logic only in `libcms_core.so:rcl_ippCfgObject`. Disassembly shows
   that an enabled IPP data-model object with non-empty printer fields writes
   `/var/printers.ini` and sends `CMS_MSG_START_APP` (`0x10000809`) for EID 45.
   Disabling it sends `CMS_MSG_STOP_APP` (`0x1000080a`) and removes the printer
   file. No web, PHP, CGI, SOAP, or startup file directly references EID 45,
   `/bin/ippd`, or `/var/printers.ini`.

2. **Automatic activation.** A clean boot without the synthetic printer or CMS
   helper exposed no usable IPP response before or after the web probes, and
   the serial log contained no SMD launch of `ippd`. The production-path test
   establishes the converse: enabling and populating the internal IPP object
   causes SMD to launch the daemon. Physical USB hotplug and upgrade-preserved
   configuration still require hardware testing.

3. **Independent always-on surface.** The genuine lighttpd/PHP stack was
   reached through loopback-only forwarding. A bounded unauthenticated matrix
   covered documented auth exceptions, USB pages, PHP data handlers, SOAP,
   CGI, the real password-reset CGI, invalid serial/security-answer requests,
   and a 4096-byte path. Sensitive routes returned HTTP 403; the two
   FastCGI-backed public pages returned 503 because the PHP backend was not
   fully available. The long path was rejected with 403. Lighttpd stayed
   available and IPP stayed unavailable throughout.

These tests did not identify an unauthenticated IPP activation route or an
independent pre-authentication crash. The password-reset result verifies the
boundary in this runtime, but is not complete proof of CGI safety on hardware.

### Extended non-IPP DoS probes

The always-on web parser was then tested with HTTP/2 prior knowledge, negative
and conflicting Content-Length fields, an overflowing chunk size, a 4 KiB
chunk extension, a 64 KiB header value, 512 headers, an embedded NUL in the
request target, and an 8 KiB absolute URI. The genuine lighttpd returned
protocol errors or application responses as appropriate and remained healthy
after every case. No fatal or memory-corruption trace was emitted.

The SMD-launched genuine `dnsmasq` was tested over loopback-forwarded TCP/UDP
with truncated DNS headers/questions, compression loops, an overlong label,
maximum QDCOUNT, malformed EDNS data, and malformed TCP length framing. QEMU
UDP forwarding did not return control responses in this configuration, so
daemon health was independently checked with a valid TCP DNS query after every
case. Each TCP control returned a valid 50-byte framed DNS response and the
daemon remained available. No DNS parser DoS was observed.

## Public-prior-art check

Searches on 2026-07-24 for RAXE290 with `ippd`, port 631, unauthenticated DoS,
RCE, and CVE terms found no matching public disclosure. NETGEAR's current
V1.0.9.82 support article only states generically that the release addresses
security vulnerabilities:

- https://kb.netgear.com/000066680/RAXE290-Firmware-Version-1-0-9-82
- https://www.netgear.com/about/security

This search does not exclude a private or embargoed duplicate.

## Artifacts

- UPnP builder: `scripts/emulate_raxe290_upnp_full_system.py`
- UPnP guest init:
  `known_firmware/emulation/RAXE290/full_system_upnp_init`
- UPnP control:
  `known_firmware/emulation/RAXE290/full-system-lab/upnp-guest-control.log`
- UPnP candidate:
  `known_firmware/emulation/RAXE290/full-system-lab/upnp-guest-candidate.log`
- IPP builder: `scripts/emulate_raxe290_ippd_full_system.py`
- IPP control:
  `known_firmware/emulation/RAXE290/ippd-full-system-lab/ippd-control.log`
- IPP URI candidate:
  `known_firmware/emulation/RAXE290/ippd-full-system-lab/ippd-uri-candidate.log`
- IPP header candidate:
  `known_firmware/emulation/RAXE290/ippd-full-system-lab/ippd-header-candidate.log`
- Corrected production CMS helper:
  `known_firmware/emulation/RAXE290/cms_start_ippd.c`
- Clean production guest init:
  `known_firmware/emulation/RAXE290/full_system_ippd_production_init`
- Clean production control:
  `known_firmware/emulation/RAXE290/ippd-full-system-lab/ippd-production-control-clean.log`
- Clean production URI candidate:
  `known_firmware/emulation/RAXE290/ippd-full-system-lab/ippd-production-uri-clean.log`
- SOAP pivot builder: `scripts/emulate_raxe290_soap_full_system.py`
- SOAP pivot serial evidence:
  `known_firmware/emulation/RAXE290/soap-full-system-lab/serial.log`
- Unauthenticated web matrix:
  `known_firmware/emulation/RAXE290/soap-full-system-lab/unauth-http-matrix.json`
- Web/IPP boundary probe: `scripts/probe_raxe290_unauth_http.py`
- Extended lighttpd DoS matrix:
  `known_firmware/emulation/RAXE290/soap-full-system-lab/lighttpd-dos-matrix.json`
- DNS DoS matrix:
  `known_firmware/emulation/RAXE290/soap-full-system-lab/dnsmasq-dos-matrix.log`

## Next confirmation steps

1. Reproduce on a factory-reset physical RAXE290 V1.0.9.82 with an attached
   USB printer in a network-isolated lab.
2. Confirm whether the USB-printer UI or hotplug flow exposes TCP/631 on every
   LAN/guest segment or only the primary LAN.
3. Continue separate pre-authentication review of lighttpd/PHP, SOAP, and
   non-HTTP listeners for RCE candidates.
