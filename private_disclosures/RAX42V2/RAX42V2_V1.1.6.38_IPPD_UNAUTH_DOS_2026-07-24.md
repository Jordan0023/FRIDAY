# RAX42v2 V1.1.6.38 unauthenticated IPP service DoS

Date: 2026-07-24

## Result

Two independent unauthenticated heap-corruption paths were reproduced in the
exact ARM `/bin/ippd` shipped with NETGEAR RAX42v2 firmware V1.1.6.38. Each
bounded request terminates the IPP daemon and leaves TCP/631 unavailable in
the isolated full-system lab.

This confirms a latent unauthenticated IPP daemon denial of service in
emulation. A subsequent production-path test found that the shipping SMD
metadata comments out EID 45 (`ippd`) and refuses the firmware's real
`START_APP` request. The current evidence therefore does **not** confirm a
network-reachable RAX42v2 product vulnerability in the shipping configuration.
It does not establish remote code execution, whole-router denial of service,
or physical-device impact.

## Firmware

- Product: NETGEAR RAX42v2
- Version: V1.1.6.38
- Package: `RAX42v2-V1.1.6.38.zip`
- Package SHA-256:
  `e6f2fe38e6ad0fa00eb6602f5b1925a7b0710c2f160ef2ab2c9f311ae6875bf8`
- `/bin/ippd` SHA-256:
  `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e`

The RAX42v2 `ippd` is not byte-identical to the previously tested RAX30
binary. The result was therefore reproduced directly against the RAX42v2
implementation rather than transferred by binary identity.

The original lab build accidentally staged the manually recovered RAX54S
V1.0.17.144 root filesystem. A clean extraction of the actual RAX42v2 package
later established that `/bin/ippd` and `/bin/smd` are byte-identical between
those two images, and that both images comment out the same EID 45 entity
block. The harness now points at the RAX42v2 extraction rooted at
`known_firmware/extracted/e6f2fe38e6ad0fa0/manual-rootfs`. The earlier dynamic
IPP behavior remains applicable by exact binary identity, while subsequent
RAX42v2 testing must use the corrected root filesystem because `upnpd`,
`httpd`, and other components differ.

## Isolated lab

The lab uses:

- the extracted RAX42v2 V1.1.6.38 ARM root filesystem;
- an ARM `virt` guest and stock Debian ARM kernel under QEMU;
- QEMU user networking with `restrict=on`;
- host forwarding only from `127.0.0.1:25142` to guest TCP/631;
- a synthetic printer definition named `lab`, backed by a regular disposable
  file; and
- a tracing preload that preserves `strcpy` copy semantics while recording
  long-copy call sites and fatal ARM register state.

The preload does not replace the request parser or suppress the crashing
copies.

At baseline, the exact daemon:

- started as PID 94;
- listened without authentication on `0.0.0.0:631`;
- returned `HTTP/1.1 200 OK` for `POST /printers/lab`; and
- retained its PID and remained reachable through repeated control requests.

## Reproduction

### Control

A normal request survived:

```text
baseline=HTTP/1.1 200 OK
candidate=HTTP/1.1 200 OK
post=HTTP/1.1 200 OK
service_available_after_candidate=true
```

### 257-byte URI

On a clean boot, a request whose complete URI was 257 bytes reached an
unbounded copy and terminated the daemon:

```text
baseline=HTTP/1.1 200 OK
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00011c64 length=0x00000101
FRIDAY_RAX29_FATAL signal=0x0000000b pc=0x00012614 lr=0x00012600
fault=0x41414241 r0=0x41414141
IPPD_EXITED=1
```

The `FRIDAY_RAX30_*` and `FRIDAY_RAX29_*` prefixes are legacy labels in the
shared tracing shim; this run used the RAX42v2 binary identified above.

The same URI behavior was observed on an earlier clean boot using a slightly
longer first-pass candidate. The reduced 257-byte case is the canonical
reproduction.

### 256-byte header value

On another clean boot, an independent 256-byte HTTP header value reached a
second unbounded copy and terminated the daemon:

```text
baseline=HTTP/1.1 200 OK
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00012600 length=0x00000100
FRIDAY_RAX29_FATAL signal=0x0000000b pc=0x00012614 lr=0x00012600
fault=0x42424342 r0=0x42424242 r3=0x42424242
```

Both failures are input-specific invalid dereferences with attacker-shaped
pointer state. They are not generic resource exhaustion.

## Classification

- Authentication: none in the IPP request parser.
- Reachability in the lab: TCP/631 on all guest interfaces.
- Confirmed impact: `ippd` termination and persistent loss of its listener
  within the unsupervised lab boot.
- Scope: IPP printing service DoS.
- Whole-router DoS: not demonstrated.
- Remote code execution: not demonstrated.
- Default physical-device exposure: not established.

## Production activation and supervision

The shipping image contains two apparently inconsistent pieces:

- `/etc/RAX50` declares `BUILD_IPPD=dynamic`, and
  `libcms_core.so:rcl_ippCfgObject` writes `/var/printers.ini` and sends CMS
  message `0x10000809` to EID 45 with that path.
- `/etc/cms_entity_info.d/eid_bcm_base.txt` comments out the complete EID 45
  entity block between `Foxconn removed` markers.

The exact production `/bin/smd` was booted with the unmodified shipping IPP
metadata. A guest CMS client sent the same message type, destination, and
`/var/printers.ini` body used by `rcl_ippCfgObject`. SMD received the 18-byte
body but produced:

```text
cmsEid_getEntityInfo: eid 45 (0x2d) not found.
cmsEid_getEntityInfoAutoCreate: Could not find eid 45, create a blank one
sendMessageByState: launching unknown to receive msg 0x10000809
launchApp: Could not find requested app unknown (eid=45), not launched!
IPPD_ALIVE=no
IPPD_LISTENING=no
```

No other shipping startup script or entity definition launches `ippd`.
Production restart-after-crash is consequently not applicable in the tested
shipping path: the supervisor cannot start the daemon in the first place.

For characterization only, restoring the exact commented entity block caused
SMD to resolve EID 45 to `/bin/ippd`. That block contains only
`EIF_MESSAGING_CAPABLE`; it does not contain `EIF_AUTO_RELAUNCH`. This
conditional experiment is not evidence of the shipping default.

## LAN-side or WAN-side

When launched directly with a valid printer file, the exact daemon binds
`0.0.0.0:631`, and its request parser accepts IPP HTTP requests without
authentication. The preload does not intercept `bind`, `listen`, or
authentication.

That establishes all-interface binding at the daemon level, not routed-WAN
reachability. In the shipping production-path test no listener exists at all.
If another runtime condition or vendor customization restores the entity, LAN
exposure is the plausible scope; WAN exposure would still require firewall or
management-plane reachability that has not been demonstrated.

## Revised classification

- Vulnerable exact RAX42v2 daemon code: confirmed.
- Unauthenticated crash when the daemon is manually active: confirmed.
- Shipping SMD activation: tested and rejected because EID 45 is removed.
- Shipping TCP/631 exposure: not present in the emulated production path.
- Production auto-relaunch: not applicable while activation is removed;
  the removed entity also lacks `EIF_AUTO_RELAUNCH`.
- Product-level unauthenticated DoS: **not confirmed**.
- Best wording: “RAX42v2 V1.1.6.38 contains a latent vulnerable `ippd`, but
  shipping supervisor metadata prevents activation in firmware emulation.”

## Corrected stock-service follow-up

The actual RAX42v2 archive was independently recovered through the CHK, UBI,
and SquashFS layers. The corrected root filesystem contains 2,716 regular
files. Relevant hashes are:

- `/bin/ippd`:
  `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e`
- `/bin/smd`:
  `5de758f60e88de862f5a8d105c58772044fd68d2f9e31341598a14faf71c64d2`
- `/usr/sbin/upnpd`:
  `590c2ad4564b68f82f2241237d8bd6ead413e1a0e610f54d08bbe08abd0ca8d1`
- `/usr/sbin/httpd`:
  `93881747b464384203309bf42dad4eb20ad9b8950e5b7850da06ac9cb57cc862`

The RAX42v2 `upnpd` and `httpd` differ from the accidentally staged RAX54S
versions, so those surfaces were retested rather than transferred.

The exact RAX42v2 `upnpd` was launched in a privileged but externally
networkless disposable container with a synthetic `br0`, initialized ACOS
NVRAM, UPnP enabled, and the expected empty NAT shared-memory segment. It
opened unauthenticated TCP/56688. Bounded tests found:

- command-shaped `SOAPAction`, NTP, firmware URL, and OOKLA fields returned
  SOAP faults; no command marker was created;
- a 16 KiB action and a 256 KiB XML value reset only their own connections;
- 512 XML levels and `DeviceInfo:GetInfo` bodies through 1,024 bytes returned
  SOAP faults;
- GENA callback paths through 256 bytes returned HTTP 200, 512 through 4,096
  returned HTTP 400, and 8,192/16,384 reset only their connections; and
- after every case the same QEMU-hosted daemon process remained present and
  TCP/56688 passed a fresh unauthenticated baseline.

This rejects direct transfer of the RAX30 GENA callback DoS and does not
confirm RCE or persistent DoS in the tested RAX42v2 UPnP surface. The
proprietary `/usr/sbin/httpd` remains a separate high-value surface because it
contains `/soap/server_sa/` and numerous command-bearing administrative
handlers; stable stock-path emulation and route-specific authentication/sink
tracing remain required.

## Artifacts

- Builder: `scripts/emulate_rax42v2_ippd_full_system.py`
- Bounded probe: `scripts/probe_rax42v2_ippd_dos.py`
- Guest init:
  `known_firmware/emulation/RAX42V2/full_system_ippd_init`
- Production supervisor init:
  `known_firmware/emulation/RAX42V2/full_system_ippd_supervisor_init`
- Guest CMS activation client:
  `known_firmware/emulation/RAX42V2/cms_start_ippd.c`
- Shipping supervisor evidence:
  `known_firmware/emulation/RAX42V2/full-system-lab/ippd-shipping-supervisor-serial.log`
- Conditional restored-entity evidence:
  `known_firmware/emulation/RAX42V2/full-system-lab/ippd-conditional-entity-serial.log`
- Reduced URI evidence:
  `known_firmware/emulation/RAX42V2/full-system-lab/ippd-uri-repro-serial.log`
- Header evidence:
  `known_firmware/emulation/RAX42V2/full-system-lab/ippd-header-serial.log`
- First-pass URI evidence:
  `known_firmware/emulation/RAX42V2/full-system-lab/ippd-uri-first-serial.log`
