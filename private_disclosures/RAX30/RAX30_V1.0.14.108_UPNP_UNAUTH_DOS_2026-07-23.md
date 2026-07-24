# RAX30 V1.0.14.108 Unauthenticated UPnP Daemon DoS

Date: 2026-07-23  
Status: confirmed in the latest publicly available firmware under full-system
emulation; **not classified as a zero-day because closely matching public
prior art exists**; physical-hardware validation pending

## Result

A single unauthenticated LAN request reliably terminates the genuine RAX30
V1.0.14.108 UPnP daemon with `SIGSEGV`.

The trigger is an HTTP `SUBSCRIBE` request to the advertised
`Layer3Forwarding:1` event URL with a 73-byte `CALLBACK` URL. No administrator
session, cookie, bearer token, or prior SOAP action is required.

After the request:

- the triggering connection returns no HTTP response;
- the UPnP TCP listener on port 56688 becomes unavailable;
- SMD records the UPnP process disconnect;
- the init supervisor records `UPNP_WAIT_STATUS=139`;
- subsequent baseline requests fail with connection reset;
- the service does not recover during the observation period.

This establishes an unauthenticated LAN-reachable UPnP service denial of
service in the emulated firmware. It does not yet establish whole-router
denial of service, remote code execution, public novelty, or behavior on
physical hardware.

## Firmware Identity

- Product: NETGEAR RAX30
- Version: V1.0.14.108
- Firmware SHA-256:
  `6e7f95ab08e7b70280c3c97944e18d0895903b3cf836b8397fe1a20cd395e658`
- Genuine `/bin/upnp` SHA-256:
  `9157ba342159c23cd83f685d84bca12ce40a40fe05f642919b5b056a96ef22a2`
- Validation initramfs SHA-256:
  `add356ceeb2585698c35f9d35ce095fa6a0a93e6c38d4ab3167d7eb98a7381c1`

## Latest-Firmware Verification

On 2026-07-23, NETGEAR's RAX30 support material identified V1.0.14.108 as the
current release. The package was downloaded again directly from:

`https://www.downloads.netgear.com/files/GDC/RAX30/RAX30-V1.0.14.108.zip`

The fresh download and tested local package had the identical SHA-256:

`6e7f95ab08e7b70280c3c97944e18d0895903b3cf836b8397fe1a20cd395e658`

The archive contains `RAX30-V1.0.14.108_1.img`, dated 2025-04-09. NETGEAR's
November 2025 security advisory also directs RAX30 users to V1.0.14.108. No
newer official RAX30 package was found in the vendor support page, download
index searches, or subsequent NETGEAR security advisories reviewed through
2026-07-23.

## Public-Prior-Art Disposition

The finding must not presently be labeled a zero-day. Public disclosures
predating this work closely match both protocol location and vulnerability
class:

- CVE-2016-8863: Portable UPnP SDK `create_url_list()` heap overflow reached
  through a `SUBSCRIBE` `CALLBACK` header; reported impact includes crash and
  possible code execution.
- CVE-2021-35393: unauthenticated stack overflow caused by unsafe parsing of
  UPnP `SUBSCRIBE`/`UNSUBSCRIBE` `Callback` headers in the Realtek Jungle SDK.
- CVE-2023-40479 and CVE-2023-35722: previously disclosed unauthenticated
  RAX30 UPnP command-injection vulnerabilities.
- CVE-2023-27853: a previously disclosed unauthenticated RAX30 SOAP parser
  overflow; it is a different daemon and input field but establishes prior
  public RAX30 pre-authentication parser-crash research.

The current RAX30 binary is a stripped, vendor-specific Broadcom-derived UPnP
daemon, and the available evidence does not yet prove that its crashing
routine is the same code as CVE-2016-8863 or CVE-2021-35393. A debugger trace
and function-level comparison could establish whether this is an unfixed
known vulnerability, a vendor fork/variant, or a distinct implementation.
Until that attribution is complete and a CNA/vendor assesses duplication, the
correct classification is:

**confirmed latest-firmware vulnerability candidate with strong public prior
art; zero-day status not established.**

## Authentication and Reachability

The daemon advertises itself over SSDP without credentials:

```text
Location: http://10.0.2.15:56688/dyndev/<generated-uuid>
```

The device description advertises the unauthenticated event endpoint:

```text
/<generated-uuid>/Layer3Forwarding:1
```

The reproducer supplies no authentication material.

### WAN exposure assessment

A separate two-interface boot assigned `br0` the LAN address `10.0.2.15` and
`eth1` the WAN address `198.51.100.15`, then started the genuine daemon with
`-L br0 -W eth1 -W2 eth1`. The only port-56688 listener recorded in
`/proc/net/tcp` was:

```text
0F02000A:DD70
```

This decodes to `10.0.2.15:56688`; there was no WAN-address or wildcard
listener. SSDP likewise advertised only `10.0.2.15`. A request forwarded to
the WAN address produced no response, and the daemon remained alive.

The extracted production firmware independently installs restricted-interface
drops for TCP/56688 and UDP/1900 in both its IPv4 and IPv6 paths
(`AccessLocal_Deny.sh`).

Accordingly, the available evidence supports **unauthenticated LAN
reachability, not stock WAN reachability**. This does not exclude exposure
created by a non-default firewall rule, explicit port forwarding, an
unrelated authentication bypass, or a production-hardware integration
difference. The two-NIC QEMU host forwards did not provide a clean positive
LAN transport control, so the binding and firewall conclusions should still
be validated on physical hardware.

## Differential Control

On a clean boot using the same uninstrumented-copy validation image:

- a 23-byte callback URL returned `HTTP/1.1 200 OK`;
- a subsequent baseline returned `HTTP/1.1 404 Not Found`;
- the UPnP daemon remained alive;
- no `UPNP_EXITED` marker appeared.

On a separate clean boot:

- the 73-byte callback URL returned no response;
- the next baseline was reset;
- `UPNP_WAIT_STATUS=139` and `UPNP_EXITED=1` were recorded.

The crash was reproduced on three clean boots during reduction, followed by
an additional final evidence run. The final validation shim was compiled with
`FRIDAY_DISABLE_STRCPY`, completely omitting the lab's `strcpy` interceptor.
The resulting crash therefore occurs on the vendor binary/libc copy path, not
inside the copy tracer.

## Reproduction

The isolated emulator is loopback-only and uses QEMU user networking with
`restrict=on`.

```bash
python3 scripts/emulate_rax30_upnp_full_system.py build
python3 scripts/emulate_rax30_upnp_full_system.py foreground
python3 scripts/emulate_rax30_upnp_full_system.py wait
python3 scripts/reproduce_rax30_upnp_event_dos.py
```

Negative control:

```bash
python3 scripts/reproduce_rax30_upnp_event_dos.py --control
```

The generated UUID changes on each boot. The reproducer recovers it from the
guest's genuine SSDP response before constructing the event URL.

## Evidence

- Crash transcript:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-crash-confirmation.log`
  - SHA-256:
    `d93efe76e669f44a6de712ab0a4bb941c4ea190547d19ea353c502072f985a3a`
- Negative-control transcript:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-control-confirmation.log`
  - SHA-256:
    `a3cec75c173b124c9fabe25359f286ab1fdb659fef76134c5eec13bf35f83232`
- Reproducer:
  `scripts/reproduce_rax30_upnp_event_dos.py`
- Full-system harness:
  `scripts/emulate_rax30_upnp_full_system.py`
- Two-interface WAN exposure transcript:
  `known_firmware/emulation/RAX30/full-system-lab/upnp-wan-exposure-assessment.log`
- Guest SSDP discovery helper:
  `known_firmware/emulation/RAX30/rax30_ssdp_guest_probe.c`

## Remaining Validation

Before describing this as a zero-day or submitting it as a final vendor
finding:

1. reproduce on a physical RAX30 running V1.0.14.108;
2. determine whether production supervision automatically restarts UPnP;
3. capture the faulting PC/backtrace and identify the exact vulnerable copy or
   parser operation;
4. establish the minimum crashing callback length;
5. obtain vendor/CNA duplicate assessment against CVE-2016-8863,
   CVE-2021-35393, CVE-2023-40479, and CVE-2023-35722;
6. report privately to NETGEAR before publishing trigger details.
