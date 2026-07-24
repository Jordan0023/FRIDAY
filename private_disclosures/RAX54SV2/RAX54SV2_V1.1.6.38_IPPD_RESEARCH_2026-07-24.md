# RAX54Sv2 V1.1.6.38 unauthenticated IPP parser research

Date: 2026-07-24

## Result

The exact ARM `/bin/ippd` in NETGEAR RAX54Sv2 firmware V1.1.6.38 contains two
reproducible unauthenticated memory-corruption paths. In a network-isolated
full-system lab, either a 257-byte request URI or an independent 256-byte HTTP
header value terminated the daemon and left TCP/631 unavailable. A normal
control request did not affect availability.

The shipping product path was also tested. The unmodified SMD metadata comments
out EID 45 (`ippd`). When a guest CMS client sent the firmware's real
`START_APP` request to EID 45, SMD refused to launch the daemon. Therefore this
is a **latent vulnerable daemon, not a confirmed product-level unauthenticated
DoS in the shipping configuration**.

No RCE was demonstrated. No physical RAX54Sv2 was tested.

## Firmware and extraction

- Product: NETGEAR RAX54Sv2
- Version: V1.1.6.38
- Package: `RAX54Sv2-V1.1.6.38.zip`
- Package SHA-256:
  `c9b1ed79f8f766b583969f1a2cd3f849a8d788f7053a0d845c39db425ef56110`
- `/bin/ippd` SHA-256:
  `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e`

The earlier automated extraction stopped at its size limit and produced a
misleadingly sparse attack-surface report. The package contains a UBI image at
offset 58. Its `rootfs_ubifs` volume is actually an XZ-compressed SquashFS
filesystem. The complete extracted root is:

`known_firmware/extracted/c9b1ed79f8f766b5/manual-rootfs`

The RAX54Sv2 `ippd` is byte-identical to the RAX54S V1.0.17.144 and RAX42v2
V1.1.6.38 copies. It is not byte-identical to the earlier RAX30 implementation,
so the impact was reproduced directly against the v2 rootfs.

## Isolated lab

The direct-daemon impact lab used:

- the exact extracted RAX54Sv2 root filesystem;
- an ARM `virt` guest with a stock Debian ARM kernel under QEMU;
- QEMU user networking with `restrict=on`;
- host forwarding only from `127.0.0.1:25155` to guest TCP/631;
- a synthetic printer named `lab`, backed by a disposable regular file; and
- a preload that preserves the genuine `strcpy` behavior while logging long
  copies and fatal ARM register state.

The exact daemon started as PID 94, bound `0.0.0.0:631`, and returned
`HTTP/1.1 200 OK` without authentication for a normal
`POST /printers/lab`.

Harness:

- `scripts/emulate_rax54sv2_ippd_full_system.py`
- `scripts/probe_rax42v2_ippd_dos.py`

## Dynamic reproduction

### Control

```text
baseline=HTTP/1.1 200 OK
candidate=HTTP/1.1 200 OK
post=HTTP/1.1 200 OK
service_available_after_candidate=true
```

Evidence:
`known_firmware/emulation/RAX54SV2/full-system-lab/ippd-control-serial.log`

### 257-byte URI

The complete URI was 257 bytes and contained only inert repeated bytes.

```text
baseline=HTTP/1.1 200 OK
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00011c64 length=0x00000101
malloc(): memory corruption
FRIDAY_RAX29_FATAL signal=0x00000006
IPPD_EXITED=1
```

Evidence:
`known_firmware/emulation/RAX54SV2/full-system-lab/ippd-uri-serial.log`

### 256-byte header value

On a separate clean boot, an independent HTTP header value containing only
repeated bytes reached the second unbounded copy.

```text
baseline=HTTP/1.1 200 OK
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00012600 length=0x00000100
FRIDAY_RAX29_FATAL signal=0x0000000b pc=0x00012614 lr=0x00012600
fault=0x42424342 r0=0x42424242 r3=0x42424242
IPPD_EXITED=1
```

The `FRIDAY_RAX30_*` and `FRIDAY_RAX29_*` prefixes are legacy names in the
shared tracing shim. This run used the RAX54Sv2 binary and root filesystem
identified above.

Evidence:
`known_firmware/emulation/RAX54SV2/full-system-lab/ippd-header-serial.log`

## Shipping activation test

The shipping image contains `BUILD_IPPD=dynamic`, but the entire EID 45 block
in `/etc/cms_entity_info.d/eid_bcm_base.txt` is commented out between
`Foxconn removed` markers.

The exact production `/bin/smd` was booted with the unmodified metadata. A
guest CMS client sent message `0x10000809` to EID 45 with
`/var/printers.ini`, matching the firmware's IPP configuration path. SMD
received the message but produced:

```text
cmsEid_getEntityInfo: eid 45 (0x2d) not found.
cmsEid_getEntityInfoAutoCreate: Could not find eid 45, create a blank one
sendMessageByState: launching unknown to receive msg 0x10000809
launchApp: Could not find requested app unknown (eid=45), not launched!
```

No other shipping startup definition found during this review launches
`ippd`.

Evidence:
`known_firmware/emulation/RAX54SV2/full-system-lab/ippd-shipping-supervisor-serial.log`

## Classification

- Vulnerable exact RAX54Sv2 daemon code: confirmed.
- Authentication in the active daemon's HTTP parser: none.
- Input-specific memory corruption and daemon exit: confirmed in emulation.
- Independent URI and header paths: confirmed on clean boots.
- Remote code execution: not demonstrated.
- Whole-router denial of service: not demonstrated.
- Shipping SMD activation: tested and rejected because EID 45 is removed.
- Shipping TCP/631 exposure: not established and absent in the tested
  production path.
- Product-level unauthenticated DoS: **not confirmed**.

Best current wording:

> RAX54Sv2 V1.1.6.38 contains a latent unauthenticated IPP parser
> memory-corruption/daemon-DoS vulnerability, but the shipping supervisor
> metadata prevents activation in firmware emulation.

This should not be called a RAX54Sv2 zero-day unless physical testing or vendor
confirmation establishes a stock runtime condition that activates and exposes
TCP/631.

## Public-prior-art check

Searches performed on 2026-07-24 for RAX54Sv2 together with `ippd`, IPP,
buffer overflow, denial of service, and the binary SHA-256 did not identify a
public disclosure of these two parser copies.

Public RAX54Sv2 results reviewed included:

- CVE-2025-12946, a different speed-test/DNS-manipulation command-execution
  issue:
  https://nvd.nist.gov/vuln/detail/CVE-2025-12946
- CVE-2026-0410, a different authenticated router-software modification
  issue:
  https://nvd.nist.gov/vuln/detail/CVE-2026-0410
- NETGEAR's July 2026 security advisory:
  https://kb.netgear.com/000070859/July-2026-NETGEAR-Security-Advisory

Public searching cannot exclude a private report, embargoed issue, or
non-descriptive NETGEAR PSV duplicate.

## Next steps

1. On a factory-reset RAX54Sv2 in an isolated LAN, determine whether any USB
   printer workflow, hidden configuration, or upgrade-preserved state starts
   `ippd`.
2. If TCP/631 appears, verify unauthenticated LAN reachability and repeat only
   the bounded URI case.
3. Record whether a production supervisor restarts the daemon and whether
   printing remains unavailable.
4. Ask NETGEAR whether EID 45 can be activated on this product and whether the
   parser issue duplicates an existing PSV.
5. Continue hunting the default-on `upnpd`, `httpd`, and other exposed daemons;
   those are stronger product-level targets than the disabled IPP component.

