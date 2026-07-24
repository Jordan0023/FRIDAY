# RAX49S V1.1.6.38 pre-authentication RCE/DoS triage

Date: 2026-07-24

## Result

No product-level unauthenticated RCE or denial of service is confirmed in this
pass.

The exact RAX49S IPP daemon contains two already-reproduced unauthenticated
heap-corruption paths. A bounded 257-byte URI was reproduced directly against
the RAX49S root filesystem and terminated the daemon with attacker-shaped
register and fault state. However, the genuine shipping supervisor metadata
comments out the IPP entity. The real production activation message therefore
does not start the daemon or expose TCP/631.

The best current classification is a latent vulnerable component, not a
network-reachable RAX49S zero-day.

## Firmware and extraction correction

- Product: NETGEAR RAX49S
- Version: V1.1.6.38
- Package: `RAX49-V1.1.6.38.zip`
- Package SHA-256:
  `fe7d6c417177572b7a1aad6bf3ebfb679e8cef9f50178d650927f7de06551b9e`

The earlier automated audit stopped after exceeding its 768 MB recursive
extraction allowance. It had discovered only one executable and did not
represent full firmware coverage.

The firmware payload begins with a 58-byte wrapper followed by a 647-PEB UBI
image. UBI volume `rootfs_ubifs` is actually a SquashFS filesystem. Manual
recovery produced 2,716 files, 293 directories, and 460 symlinks. The recovered
filesystem is at:

`known_firmware/extracted/fe7d6c417177572b/manual-rootfs`

## Network attack surface

The complete image contains the principal network-facing components:

- `/usr/sbin/httpd`
- `/usr/sbin/upnpd`
- `/bin/ippd`
- `/usr/sbin/telnetenabled`
- `/usr/sbin/utelnetd`
- `/sbin/lighttpd`
- `/opt/xagent/xagent`

RAX49S V1.1.6.38 is byte-identical to RAX54Sv2 V1.1.6.38 for all three
high-priority local-service parsers:

| Component | SHA-256 |
|---|---|
| `httpd` | `93881747b464384203309bf42dad4eb20ad9b8950e5b7850da06ac9cb57cc862` |
| `upnpd` | `590c2ad4564b68f82f2241237d8bd6ead413e1a0e610f54d08bbe08abd0ca8d1` |
| `ippd` | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` |

The shared `libhttpdshared.so` is also byte-identical to the earlier RAX54S
image:

`4bff75ee39491a8d678c3b475cb4f541f7c1a822fa5f7e24272fdae379208f9e`

## Direct IPP component result

The exact RAX49S `/bin/ippd` was started in an ARM full-system guest with a
disposable printer file. QEMU networking used `restrict=on`, and TCP/631 was
forwarded only to host loopback.

Baseline:

```text
baseline=HTTP/1.1 200 OK
```

A request with a complete 257-byte URI then terminated the service:

```text
candidate=no response
post=ConnectionResetError: [Errno 104] Connection reset by peer
service_available_after_candidate=false
FRIDAY_RAX30_LONG_STRCPY caller=0x00011c64 length=0x00000101
FRIDAY_RAX29_FATAL signal=0x0000000b pc=0x00012614 lr=0x00012600
fault=0x41414241 r0=0x41414141
IPPD_EXITED=1
```

The `FRIDAY_RAX30_*` and `FRIDAY_RAX29_*` names are legacy labels in the shared
tracing preload. The tested binary and filesystem were RAX49S V1.1.6.38.

This proves:

- unauthenticated parser reachability when `ippd` is active;
- an input-specific unbounded copy;
- attacker-shaped pointer state; and
- persistent loss of the unsupervised IPP listener.

It does not prove default RAX49S exposure.

## Shipping activation result

The shipping image has the same internally inconsistent IPP configuration seen
in related Broadcom/Foxconn images:

- `/etc/RAX50` sets `BUILD_IPPD=dynamic`;
- the configuration path sends CMS message `0x10000809` to EID 45; but
- `/etc/cms_entity_info.d/eid_bcm_base.txt` comments out the EID 45 `ippd`
  entity between `Foxconn removed` markers.

The exact production `/bin/smd` was booted with unmodified shipping metadata.
A guest CMS helper sent the genuine activation message and
`/var/printers.ini` body. SMD rejected activation:

```text
cmsEid_getEntityInfo: eid 45 (0x2d) not found.
cmsEid_getEntityInfoAutoCreate: Could not find eid 45, create a blank one
sendMessageByState: launching unknown to receive msg 0x10000809
launchApp: Could not find requested app unknown (eid=45), not launched!
IPPD_ALIVE=no
IPPD_LISTENING=no
```

No TCP listener existed after the production message.

### Firmware-lineage activation test

The activation question was extended across every downloaded RAX49S release,
not only V1.1.6.38:

| Version | `BUILD_IPPD` | EID 45 | `/bin/ippd` SHA-256 |
|---|---|---|---|
| V1.1.2.16 | `dynamic` | commented out | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` |
| V1.1.3.18 | `dynamic` | commented out | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` |
| V1.1.4.28 | `dynamic` | commented out | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` |
| V1.1.6.36 | `dynamic` | commented out | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` |
| V1.1.6.38 | `dynamic` | commented out | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` |

The complete UBI/SquashFS payload was inspected for each release. In every
version, `eid_bcm_base.txt` contains:

```text
#BEGIN
#  eid         = EID_IPPD
#  name        = ippd
#  flags       = EIF_MESSAGING_CAPABLE
#END
```

This rejects the hypothesis that an older downloaded RAX49S firmware enabled
the entity and could leave an upgrade-preserved supervisor definition.

For characterization only, restoring the commented entity allowed SMD to
resolve EID 45 and spawn `//bin/ippd`. The entity has no explicit path or
arguments. The exact daemon immediately reported:

```text
Missing argument pointing to location of printer definition file.
IPPD_LISTENING=no
```

Thus two independent shipping barriers exist in the recovered lineage:

1. EID 45 is absent from the active supervisor table; and
2. the removed entity definition does not supply the command-line printer
   file required by this `ippd`.

Within firmware emulation, the latent IPP crash cannot be promoted to a
stock-reachable product DoS.

## Current classification

- Vulnerable RAX49S daemon code: confirmed.
- Unauthenticated daemon crash when manually active: confirmed.
- Shipping supervisor activation: tested negative.
- Default TCP/631 exposure: not present in the emulated production path.
- Product-level unauthenticated DoS: not confirmed.
- Unauthenticated RCE: not demonstrated.
- Zero-day status: not established.

## Remaining high-priority work

Because `httpd` and `upnpd` are exact matches to RAX54Sv2, RAX49S should reuse
the RAX54Sv2 dispatcher and UPnP call-graph results rather than repeat generic
string scanning. The next validation targets are:

1. configured and unconfigured `httpd` authentication exceptions, especially
   recovery/setup routes;
2. `upnpd` SOAP and GENA boundary matrices, including the RAX30 callback
   method;
3. `telnetenabled` activation requirements and authentication material; and
4. production startup and LAN/WAN binding for every candidate before promotion.

## HTTP and UPnP next-phase validation

### Default-on UPnP

The exact RAX49S `/usr/sbin/upnpd` was launched from the recovered root
filesystem in a disposable Docker container with no external network and a
synthetic LAN.

The public `/Public_UPNP_C3` control endpoint remained available after:

- command-marker syntax in `SOAPAction`;
- marker values in `NewNTPServer1`, `NewFirmwareURL`, and the OOKLA server ID;
- a 16 KiB action;
- 512 XML nesting levels;
- a 256 KiB XML value; and
- `GetInfo` body padding from 0 through 1,024 bytes.

No command marker reached the tracing sink. The 16 KiB action and 256 KiB
value reset only their individual connections. A fresh unauthenticated
WANIPConnection control passed immediately afterward.

The RAX30 GENA callback method was transferred to
`/Public_UPNP_Event_1`:

```text
explicit-port-control: HTTP/1.1 200 OK, daemon alive
no-port-candidate: HTTP/1.1 200 OK, daemon alive
callback paths 64-256 bytes: HTTP/1.1 200 OK, daemon alive
callback paths 512-4096 bytes: HTTP/1.1 400 Bad Request, daemon alive
callback paths 8192-16384 bytes: connection reset, daemon alive
baseline_after=pass
```

The RAX30 callback null dereference therefore does not transfer to RAX49S.
The large-value resets are per-connection behavior, not a service-level DoS.

### Proprietary HTTPS/SOAP daemon

The exact RAX49S `/usr/sbin/httpd` reached a stable request-serving state in
the ARM full-system lab. QEMU networking used `restrict=on`, with ports 80 and
9443 forwarded only to host loopback.

Without credentials:

- `/currentsetting.htm` returned HTTP 200;
- `/unauth.cgi`, `/securityquestions.cgi`, `/passwordrecovered.cgi`,
  `/BRS_index.htm`, and `/recover.cgi` returned HTTP 401;
- unknown URIs through 16 KiB returned HTTP 401;
- a header value through 16 KiB on `/currentsetting.htm` returned HTTP 200;
- negative and overflowing `Content-Length` values closed their individual
  connections; and
- the service answered a fresh control after every case.

The apparent HTTP 200 results for SOAP actions must not be read as successful
authentication or mutation. The XML bodies and daemon trace showed
`ResponseCode 401`. This included empty `SOAPLogin`, `SetNTP`, and
`CheckAndDownloadNewFirmware`. Harmless command markers in the NTP and
firmware URL fields did not reach the `system`/`popen` tracing sink.

`Authenticate`, empty `SOAPLogin`, and `GetInfo` padding through 1,024 bytes
also left the service available. No request-attributed fatal trace was
recorded.

### Revised disposition

- RAX30 UPnP callback DoS transfer: tested negative.
- Public UPnP SOAP RCE markers: tested negative.
- Public UPnP service DoS in the bounded matrix: tested negative.
- Recovery/setup authentication bypass: tested negative in the emulated
  configured state.
- Proprietary SOAP mutation without a valid session: rejected with
  `ResponseCode 401`.
- HTTP parser service DoS through 16 KiB URI/header values: tested negative.
- Confirmed RAX49S unauthenticated RCE or product-level DoS: **no**.

## Telnet production-path closure

The bundled telnet binaries do not establish a factory-default unauthenticated
shell:

- EID 6 (`telnetd`) is commented out in the shipping
  `eid_bcm_mgmt.txt`, like the inactive IPP supervisor entity.
- `/etc/init.d/bcm-wlan-drivers.sh` contains a direct
  `/usr/sbin/utelnetd -d` launch only inside the `WLAN_BTEST=y`
  manufacturing-test branch. The production script has `WLAN_BTEST=` and
  `WLAN_REMOVE_INTERNAL_DEBUG=y`.
- The ordinary production service manager checks the `telnet_enable` NVRAM
  setting before invoking `telnetenabled`; the surviving internal page labels
  the setting as not intended for production images.
- `telnetenabled` contains the `AMBIT_TELNET_ENABLE+` challenge marker and
  reads `lan_hwaddr`, `http_username`, and `http_passwd_digest` before it can
  spawn `utelnetd -d -i br0`. This is an enable mechanism tied to device and
  administrator material, not an unauthenticated listener present at boot.

This closes the remaining bundled-telnet lead at the firmware-evidence level.
Physical factory-default port capture would still be the strongest independent
confirmation of runtime exposure, but no stock activation path in the complete
shipping filesystem supports promotion to unauthenticated RCE.

## Final result of this target pass

- Confirmed latent memory-corruption/daemon DoS in `/bin/ippd`: **yes**, when
  the daemon is manually launched.
- Confirmed factory-default reachability of that daemon: **no**.
- Confirmed transfer of the RAX30 UPnP DoS: **no**.
- Confirmed HTTP/SOAP pre-auth RCE or persistent service DoS: **no**.
- Confirmed factory-default unauthenticated telnet shell: **no**.
- Defensible RAX49S zero-day claim from current evidence: **none**.

## Artifacts

- RAX49S wrapper:
  `scripts/emulate_rax49s_ippd_full_system.py`
- Reusable bounded probe:
  `scripts/probe_rax42v2_ippd_dos.py`
- Direct crash evidence:
  `known_firmware/emulation/RAX49S/full-system-lab/ippd-uri-repro-serial.log`
- Shipping supervisor evidence:
  `known_firmware/emulation/RAX49S/full-system-lab/ippd-shipping-supervisor-serial.log`
- HTTP full-system wrapper:
  `scripts/emulate_rax49s_http_full_system.py`
- HTTP bounded probe:
  `scripts/probe_rax49s_http_security.py`
- HTTP security matrix:
  `known_firmware/emulation/RAX49S/full-system-http-lab/http-security-probe.log`
- HTTP serial evidence:
  `known_firmware/emulation/RAX49S/full-system-http-lab/http-security-serial.log`
- UPnP isolated wrapper:
  `scripts/emulate_rax49s_upnp.py`
