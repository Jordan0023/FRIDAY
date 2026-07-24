# NETGEAR RAX30 V1.0.14.108 Unauthenticated UPnP Service DoS

Date: 2026-07-23  
Status: Emulation-confirmed vulnerability candidate; physical validation pending  
Firmware SHA-256: `6e7f95ab08e7b70280c3c97944e18d0895903b3cf836b8397fe1a20cd395e658`

## Executive summary

The exact ARM `/bin/upnp` binary shipped in NETGEAR RAX30 firmware
V1.0.14.108 terminates after processing a single unauthenticated UPnP event
subscription containing an oversized callback path. A normal short callback
control does not terminate the daemon.

The crashing run ended with shell wait status `139`, consistent with SIGSEGV.
The firmware service manager recorded the loss of the `upnp` process, and the
service did not restart in the isolated environment. This caused loss of the
UPnP HTTP service until restart or reboot.

This path is independent of `/bin/ippd` and does not require USB printer or IPP
support. It does require the UPnP daemon to be enabled and reachable from the
attacker's network position.

## Classification

- Product: NETGEAR RAX30
- Firmware tested: V1.0.14.108
- Component: `/bin/upnp`
- Attack surface: UPnP event subscription over the daemon's LAN HTTP listener
- Authentication: none
- User interaction: none
- Required feature: UPnP enabled
- USB printer/IPP prerequisite: none
- Confirmed impact: UPnP daemon termination in emulation
- Not demonstrated: whole-router outage or remote code execution
- Likely weakness class: memory-safety error during callback processing
- Precise CWE: pending root-cause confirmation
- Novelty: apparently unpublished; vendor/CNA duplicate determination pending

The suggested pre-disclosure description is:

> Apparently unpublished, emulation-confirmed unauthenticated UPnP service
> denial-of-service vulnerability candidate in NETGEAR RAX30 V1.0.14.108.

## Affected environment

Testing used:

- the exact RAX30 V1.0.14.108 ARM userland;
- full-system ARM QEMU;
- kernel-backed fixed-address SysV shared memory;
- a synthetic LAN interface at `10.0.2.15`;
- loopback-only host forwarding to the UPnP HTTP listener;
- restricted user-mode networking with no public Internet exposure;
- the firmware `/bin/smd` service manager; and
- the exact firmware `/bin/upnp` daemon.

The emulation supplied hardware-dependent state required to bring up the
firmware daemon. It did not replace the UPnP parser or request-handling binary.

## Service exposure

During the clean boot:

- `/bin/upnp` registered with `smd`;
- SSDP listened without authentication on UDP/1900;
- the daemon selected a TCP HTTP listener on port 56688;
- SSDP discovery returned a generated device UUID;
- the discovered service tree exposed `Layer3Forwarding:1`; and
- ordinary HTTP requests reached the daemon without credentials.

This establishes an unauthenticated LAN parser boundary in emulation.
Production interface binding, default feature state, and firewall reachability
remain subject to physical-device confirmation.

## Test method

Two independent clean boots were compared.

### Control boot

The control sent an unauthenticated UPnP `SUBSCRIBE` request to the discovered
`Layer3Forwarding:1` service using an ordinary short HTTP callback URL.

Observed result:

- the daemon accepted the request path;
- the UPnP PID remained present;
- RSS remained stable;
- repeated five-second health checks continued to report the same PID; and
- the UPnP HTTP service remained available.

### Candidate boot

The candidate used the same request type, discovered UUID, service path, and
event-subscription headers. The meaningful difference was a longer callback
path composed only of inert marker and repeated bytes.

Observed result:

- no authentication or prior session was used;
- no SOAP action was required;
- no event-producing follow-up request was required;
- `smd` detected the exit of `upnp`;
- the init process recorded `UPNP_WAIT_STATUS=139`;
- the health loop stopped reporting the UPnP PID;
- `UPNP_EXITED=1` was recorded; and
- the service was not automatically restarted in the lab.

The short control and longer candidate therefore produced different process
outcomes from separate clean boots.

## Impact

The confirmed emulated impact is denial of the router's UPnP service. UPnP
discovery, description, control, and event-subscription functionality become
unavailable while the daemon is stopped.

The following impacts have not been demonstrated:

- router reboot;
- loss of routing, Wi-Fi, DNS, DHCP, or administrative HTTP service;
- persistent configuration damage;
- arbitrary code execution;
- data disclosure; or
- Internet/WAN reachability.

This should be described as a service-level DoS, not a whole-router DoS.

## Reproducibility evidence

- Control serial log:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-control-confirmation.log`
- Candidate serial log:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-crash-confirmation.log`
- Bounded reproducer:
  `scripts/reproduce_rax30_upnp_event_dos.py`
- Full-system launcher:
  `scripts/emulate_rax30_upnp_full_system.py`
- Guest init:
  `known_firmware/emulation/RAX30/full_system_upnp_init`

Key candidate evidence:

```text
smd ... detected exit of upnp
UPNP_WAIT_STATUS=139
UPNP_EXITED=1
```

Key control evidence consists of repeated `UPNP_HEALTH_PID` records with an
unchanged PID and stable RSS after the ordinary subscription.

## Root-cause status

The process outcome is confirmed, but the exact faulting instruction has not
yet been captured. The available evidence is consistent with a memory-safety
failure in UPnP callback/event-subscription processing, but it does not yet
establish:

- the destination object and its exact size;
- whether the fault is a heap overflow, stack overflow, invalid dereference,
  or another parser error;
- control of a data pointer or program counter;
- exploitability beyond daemon termination; or
- the smallest failing callback length.

The earlier apparent fixed-size-copy candidates at addresses `0x14da4` and
`0x14e08` were disproved as string-table data and are not the root cause of
this result.

## Zero-day assessment

No reviewed public advisory or CVE was found describing this exact RAX30 UPnP
event-subscription daemon exit. That makes the finding an apparently
unpublished zero-day candidate.

Public absence does not prove vendor novelty. The issue could be privately
reported, embargoed, silently fixed elsewhere, or tracked under a
non-descriptive NETGEAR PSV identifier. A confirmed zero-day claim requires a
NETGEAR or CNA duplicate determination, preferably after physical-device
reproduction.

## Limitations

1. The crash was reproduced in full-system emulation, not on a physical RAX30.
2. The physical router's default UPnP state and listener binding were not
   measured.
3. Production `smd` restart policy may differ from the laboratory startup
   path because the daemon was not originally launched by `smd`.
4. Only V1.0.14.108 was dynamically tested.
5. The exact faulting instruction and root cause remain unresolved.
6. No whole-router availability impact was demonstrated.
7. No RCE claim is supported.

The third limitation is particularly important: the lab proves process
termination, but it may overstate outage duration if production firmware
automatically relaunches a normally managed UPnP daemon.

## Physical validation plan

Physical testing should be performed only on an owned RAX30 in an isolated
LAN/WAN laboratory:

1. Install and hash the exact tested firmware.
2. Confirm the router's UPnP configuration state.
3. Use SSDP to verify the production UUID, service path, and interface binding.
4. Record baseline UPnP availability and router functions.
5. Send the ordinary short subscription control.
6. Confirm that the service remains healthy.
7. From a fresh state, send the smallest bounded candidate request.
8. Observe process restart behavior and continued router functionality.
9. Reboot or restart the service immediately if required.
10. Repeat once to establish reproducibility without prolonged disruption.

Testing should not be performed against an Internet-facing or third-party
device.

## Recommended remediation

NETGEAR should:

- enforce a strict maximum length on the `CALLBACK` header and parsed URL;
- validate callback URL syntax before allocation or copying;
- use destination-size-aware copying throughout event-subscription handling;
- reject malformed subscriptions without altering daemon availability;
- add regression tests around callback boundaries and repeated headers;
- supervise the daemon with bounded automatic restart behavior; and
- restrict UPnP listeners to intended trusted LAN interfaces.

Users can reduce exposure by disabling UPnP when it is unnecessary and
preventing untrusted LAN clients from reaching router management services.

## Disclosure recommendation

Submit this report privately to NETGEAR with the firmware hash, short control,
bounded candidate, and both clean-boot serial logs. Request:

- physical confirmation;
- affected-version analysis;
- root-cause confirmation;
- existing-PSV/duplicate determination;
- CVE assignment if novel;
- a firmware remediation timeline; and
- coordinated publication after a fix is available.

A non-weaponized bounded reproducer using inert bytes is sufficient for vendor
validation. Publication should avoid exploit-development details beyond what
is necessary to reproduce the service crash safely.

## Final disposition

- Unauthenticated boundary: **confirmed in emulation**
- Input-specific daemon termination: **confirmed in emulation**
- UPnP service DoS: **confirmed in the isolated lab**
- USB printer/IPP required: **no**
- Whole-router DoS: **not demonstrated**
- RCE: **not demonstrated**
- Physical RAX30 impact: **pending**
- Confirmed zero-day: **pending vendor/CNA duplicate determination**
