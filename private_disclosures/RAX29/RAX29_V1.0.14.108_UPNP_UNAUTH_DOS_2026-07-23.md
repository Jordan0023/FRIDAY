# RAX29 V1.0.14.108 Unauthenticated UPnP Daemon DoS

Date: 2026-07-23  
Status: confirmed in isolated full-system emulation; physical-hardware
validation pending; zero-day status not established

## Result

A single unauthenticated LAN `SUBSCRIBE` request reliably terminates the
genuine RAX29 V1.0.14.108 UPnP daemon with `SIGSEGV`.

The request targets the advertised `Layer3Forwarding:1` event endpoint and
uses a syntactically valid `CALLBACK` URL without an explicit TCP port. It
supplies no administrator session, cookie, bearer token, or prior SOAP action.

Crash-case observations:

```text
baseline=HTTP/1.1 404 Not Found
subscribe=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
daemon_exit=True
UPNP_WAIT_STATUS=139
UPNP_EXITED=1
```

This establishes an unauthenticated LAN-reachable UPnP service denial of
service under emulation. It does not establish whole-router denial of service,
WAN reachability, remote code execution, or physical-hardware behavior.

## Firmware and Component Identity

- Product: NETGEAR RAX29
- Version: V1.0.14.108
- Firmware SHA-256:
  `a5a6fe34b78d4f5274393e3bebd676eb2751d32b9dfa52fb38f4763bdd945970`
- Genuine RAX29 `/bin/upnp` SHA-256:
  `9157ba342159c23cd83f685d84bca12ce40a40fe05f642919b5b056a96ef22a2`
- Validation initramfs SHA-256:
  `b23b7199c2fda8d63153dd4c155d0fcaa4270b112f004ecdd2fb96a30e773058`

The RAX29 UPnP binary is byte-for-byte identical to the RAX30 V1.0.14.108
binary on which the original crash was confirmed. The RAX29 lab was
nevertheless rebuilt from the RAX29 firmware image and booted separately.

## Root Cause

Fatal-signal register capture and the process memory map resolve the crash to:

```text
signal=SIGSEGV
PC=libc.so.6+0x75d20 (strchr)
LR=/bin/upnp+0xeff0
fault_address=0x00000000
r0=0x00000000
r1=0x0000002f ('/')
```

Disassembly of the callback URL parser at `/bin/upnp+0xefa8` shows:

1. it skips the `http://` prefix;
2. it searches the remaining URL for `':'`, treating a match as an explicit
   port separator;
3. on the no-port branch, it fails to restore the URL pointer left in `r0`;
4. it then calls `strchr(r0, '/')` with `r0 == NULL`.

The faulting instruction is the first load in `strchr`:

```text
libc.so.6+0x75d20: ldrb r2, [r0]
```

This is a deterministic null-pointer dereference, not the originally
hypothesized long-header overflow. An explicit `:port` avoids the faulty
branch. UPnP Device Architecture specifies that the delivery URL port is
optional and that port 80 is assumed when it is absent, so the crashing
callback is protocol-valid.

## Differential Control

On the first clean RAX29 boot, the short non-crashing callback produced:

```text
baseline=HTTP/1.1 404 Not Found
subscribe=HTTP/1.1 200 OK
post=HTTP/1.1 404 Not Found
daemon_exit=False
```

On a second clean boot, a callback without an explicit port terminated the
daemon with status 139. A further clean boot reduced the trigger to the short
URL `http://10.0.2.2/event`, which produced the same null dereference. This
rules out ordinary service instability and proves that URL structure—not
length—is the deciding input difference.

## Novelty Disposition

Root-cause attribution makes this a stronger zero-day candidate than the
initial overflow hypothesis:

- RAX29 and RAX30 use the identical vulnerable daemon binary;
- CVE-2016-8863 and CVE-2021-35393 concern unsafe copy/overflow behavior,
  whereas this fault is a missing-optional-port null dereference;
- the public search performed on 2026-07-24 found the general CALLBACK
  overflows but no disclosure matching this no-port parser branch;
- a vendor/CNA duplicate assessment has not been obtained.

Correct current classification:

**confirmed latest-firmware unauthenticated LAN DoS and distinct unpublished
zero-day candidate affecting RAX29/RAX30; final zero-day status requires
vendor/CNA duplicate assessment.**

## Evidence

- Benign-control serial transcript:
  `known_firmware/emulation/RAX29/full-system-lab/upnp-control-serial.log`
  - SHA-256:
    `5b7036b0c95ef422595d82c306d73ea476e8ffc40abd91efc6019a9a748f83ee`
- Crash serial transcript:
  `known_firmware/emulation/RAX29/full-system-lab/upnp-crash-serial.log`
  - SHA-256:
    `4c1be7407c8a13e03b1f67d78fdf3142e55594f3b653d5d02836433cf3cd3d09`
- Reduced no-port fault-attribution transcript:
  `known_firmware/emulation/RAX29/full-system-lab/upnp-no-port-fault-serial.log`
  - SHA-256:
    `82615d263e162f1e2305da5f8116563ea1dddbac439f365bb652eb097ab0921b`
- RAX29 full-system wrapper:
  `scripts/emulate_rax29_upnp_full_system.py`
- Reduced reproducer:
  `scripts/reproduce_rax30_upnp_event_dos.py`

## Remaining Validation

1. Reproduce on physical RAX29 hardware running V1.0.14.108.
2. Determine whether the production supervisor restarts UPnP.
3. Confirm stock LAN/WAN binding and firewall behavior on hardware.
4. Submit RAX29/RAX30 product scope privately to NETGEAR for duplicate
   assessment.

### Static WAN-policy follow-up (2026-07-24)

The extracted RAX29 production `AccessLocal_Deny.sh` explicitly drops
restricted-interface IPv4 traffic to TCP/56688 and UDP/1900 at lines 68-69,
and applies the equivalent IPv6 drops at lines 109-110. This matches the
barrier already documented for RAX30 and rules out a simple shipped-policy
IPv6 bypass.

This strengthens the classification to **LAN-only under the shipped static
policy**, but does not replace the model-specific two-interface physical
runtime check requested above.
