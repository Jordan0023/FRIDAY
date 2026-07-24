# NETGEAR IPP parser fleet reachability investigation

Date: 2026-07-24

## Objective

Find a NETGEAR product that combines:

1. one of the two confirmed vulnerable `ippd` parser families;
2. an active production supervisor entity;
3. correct production launch arguments; and
4. an unauthenticated TCP/631 listener.

This is the fleet-wide follow-up to the latent RAX49S IPP finding.

## Recovered vulnerable families

Two `ippd` hashes occur in the recovered firmware corpus:

| SHA-256 | Confirmed behavior |
|---|---|
| `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` | 257-byte URI and 256-byte header corruption/daemon exit |
| `4ccd2b74d91c37d71542fdde6227b3dff50404dbffbffb542463f52774a8f88d` | related RAX30-family URI and header corruption/daemon exit |

Exact `b34d...` matches:

- RAX41v2 V1.1.6.38
- RAX42v2 V1.1.6.38
- RAX49S V1.1.6.38
- RAX54S V1.0.17.144
- RAX54Sv2 V1.1.6.38

All five comment out EID 45 in `eid_bcm_base.txt`. Their production
supervisor cannot activate `ippd`.

Recovered active-EID candidates using `4ccd...`:

- RAX28 V1.0.14.108
- RAX29 V1.0.14.108
- MK93S/MS90 V1.0.2.38

RAXE500 also has an active EID 45 definition, but its build configuration says
`BUILD_IPPD is not set` and the recovered root does not provide the candidate
`/bin/ippd`.

## Genuine supervisor tests

### RAX29 V1.0.14.108

The exact production `/bin/smd`, unmodified active EID 45 metadata, production
libraries, and `4ccd...` daemon were booted in an isolated ARM guest.

A CMS client sent the exact `0x10000809` start/restart message with
`/var/printers.ini`, matching `rcl_ippCfgObject`.

SMD resolved and launched the entity:

```text
Got msg type 0x10000809 src=0x14 dst=0x14
startApp: setting optional args /var/printers.ini
launchApp: spawning //bin/ippd args  /var/printers.ini
parseArgs: argv[0] = ippd
parseArgs: argv[1] = /var/printers.ini
ippd launched
```

The daemon bound all interfaces on TCP/631:

```text
IPPD_ALIVE=yes
IPPD_LISTENING=yes
00000000:0277 ... 0A
```

A bounded unauthenticated 257-byte URI then reached the known unbounded copy:

```text
baseline=HTTP/1.1 404 Not Found
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00011b68 length=0x00000101
malloc(): corrupted top size
FRIDAY_RAX29_FATAL signal=0x00000006
```

The listener did not return. The entity lacks `EIF_AUTO_RELAUNCH`.

Evidence:

`known_firmware/emulation/RAX29/ippd-production-lab/ippd-stock-path-confirmed.log`

### MK93S/MS90 V1.0.2.38

The same test was repeated with the genuine MS90 supervisor, active entity,
libraries, and daemon.

SMD again accepted the production-shaped message, supplied
`/var/printers.ini` as `argv[1]`, and the exact daemon listened on all
interfaces at TCP/631. Because MS90 ships the same daemon hash, the RAX29
parser-crash reproduction applies byte for byte.

Evidence:

`known_firmware/emulation/MK93S/ippd-production-lab/ippd-stock-path-confirmed.log`

RAX28 and RAX29 ship the same `ippd` hash, RAX30 platform configuration, and
active entity definition. RAX29 directly covers that shared supervisor shape.

## Result

The prior uncertainty is resolved: recovered products do combine vulnerable
code with a working production activation path:

- the newer `b34d...` family removes EID 45;
- RAX28/RAX29 and MK93S/MS90 retain active EID 45;
- their shipping `rcl_ippCfgObject` constructs `/var/printers.ini` and sends it
  as the optional body of `CMS_MSG_START_APP`;
- genuine RAX29 and MS90 SMD emulation confirms an all-interface TCP/631
  listener; and
- the RAX29 stock-path listener is remotely terminated by the unauthenticated
  257-byte URI and is not automatically relaunched.

This establishes a product-level unauthenticated persistent service DoS when
IPP printer configuration is enabled.

## Correction to the earlier negative

The first supervisor experiment addressed the correct message type but carried
no body. That tested an incomplete synthetic request, not the full production
callback. Static recovery of `rcl_ippCfgObject` showed the missing
`/var/printers.ini` argument and the corrected experiment confirmed it end to
end. No separate hotplug helper or runtime entity override is required.

A physical-device USB-printer workflow remains useful for vendor-facing
confirmation of the exact UI trigger and default exposure state, but it is no
longer needed to establish the firmware launch mechanism.

## Artifacts

- `scripts/emulate_rax29_ippd_production.py`
- `scripts/emulate_ms90_ippd_production.py`
- `scripts/emulate_rax42v2_ippd_full_system.py`
- `scripts/probe_rax42v2_ippd_dos.py`
