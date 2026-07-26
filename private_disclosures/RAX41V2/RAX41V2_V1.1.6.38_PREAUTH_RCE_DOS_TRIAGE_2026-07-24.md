# RAX41v2 V1.1.6.38 pre-authentication RCE/DoS triage

Date: 2026-07-24

## Result

No product-level unauthenticated RCE or denial of service is confirmed by this
pass.

The current firmware contains the exact `ippd` binary whose two independent
unauthenticated heap-corruption crashes were reproduced in the RAX42v2 lab.
RAX41v2 also ships the service disabled in its production SMD entity metadata.
This is a confirmed latent vulnerable component, but it is not a
network-reachable RAX41v2 vulnerability in the tested shipping configuration.

The RAX30 UPnP and EX2800 unconfigured-web-server findings do not transfer by
binary identity or software architecture. RAX41v2 has distinct ARM PIE
`httpd` and `upnpd` executables and does not contain the EX2800 `webupg` /
`mini_httpd` chain.

## Firmware

- Product: NETGEAR RAX41v2
- Version: V1.1.6.38
- Package: `RAX41v2-V1.1.6.38.zip`
- Package SHA-256:
  `c52efe4a322909d7806b29863b601ad4aa4b6b608d033572b1f0c23b7e63eae6`
- Package image: `RAX41v2-V1.1.6.38_2.1.34.chk`
- Root filesystem: SquashFS/XZ inside UBI, created 2025-09-20

The package was extracted from the UBI image beginning at CHK offset `0x3a`.
The `rootfs_ubifs` UBI volume is actually a SquashFS filesystem.

## Network-component identity

| Component | RAX41v2 V1.1.6.38 SHA-256 | Assessment |
|---|---|---|
| `/bin/ippd` | `b34d60198d4196455793319134bad1e5ecc458e6e365e1a7bbb1b68d1f5d2c1e` | Byte-identical to RAX42v2 V1.1.6.38 vulnerable daemon |
| `/bin/smd` | `5de758f60e88de862f5a8d105c58772044fd68d2f9e31341598a14faf71c64d2` | Byte-identical to tested RAX42v2 supervisor |
| `/usr/sbin/httpd` | `93881747b464384203309bf42dad4eb20ad9b8950e5b7850da06ac9cb57cc862` | RAX41v2-specific in the compared set |
| `/usr/sbin/upnpd` | `590c2ad4564b68f82f2241237d8bd6ead413e1a0e610f54d08bbe08abd0ca8d1` | Not identical to RAX30 or tested RAX42v2 binary |

Both RAX41v2 web/UPnP executables are 32-bit little-endian ARM PIE files.

## RAX30-method transfer

The RAX30 finding used NETGEAR's Broadcom-derived UPnP daemon and a bounded
GENA `SUBSCRIBE` callback that reproducibly terminated that exact daemon.
RAX41v2's `upnpd` exposes GENA and SOAP strings, including `SUBSCRIBE`,
`callback`, and `gena_response_subscribe`, but it is not byte-identical to the
RAX30 daemon. String-level feature similarity is not enough to transfer the
finding.

Status:

- parser feature present: yes;
- vulnerable-binary identity: no;
- request-to-fault reproduction: not yet established;
- RAX41v2 UPnP DoS: not confirmed.

The next dynamic test should use the genuine RAX41v2 daemon in the isolated
ARM full-system lab and run the bounded 72/73/76-byte callback boundary matrix,
normal controls, and post-request liveness checks.

## EX2800-method transfer

The EX2800 result depends on the unconfigured-state `mini_httpd` dispatcher
launching the separate `webupg` executable and accepting the `twmode` shell
operation before setup.

RAX41v2 instead ships a monolithic ARM `httpd`; no `webupg`, `mini_httpd`,
EX2800 query-string loader, or `/start_telnet` chain was found in the extracted
root filesystem. The EX2800 exploit path therefore does not transfer.

RAX41v2 does have an unauthenticated/password-recovery surface in `httpd`,
including:

- `unauth.cgi`;
- `securityquestions.cgi`;
- `passwordrecovered.cgi`;
- `reset_admin_account.cgi`; and
- the SOAP login/logout dispatcher.

These are follow-up authentication-boundary targets, not findings. A route
string near global `system`, `popen`, or unsafe-copy imports is not accepted as
evidence without function-local data flow and live pre-authentication proof.

## Latent IPP crash transfer

RAX41v2 `/bin/ippd` is byte-for-byte identical to the RAX42v2 daemon for which
the isolated lab reproduced:

1. termination from a complete 257-byte request URI; and
2. termination from a 256-byte HTTP header value.

The RAX41v2 production metadata has the same material activation state:

- `/etc/RAX50` declares `BUILD_IPPD=dynamic`;
- `/etc/cms_entity_info.d/eid_bcm_base.txt` comments out the `EID_IPPD` block
  between the `Foxconn removed` markers; and
- the commented entity lacks `EIF_AUTO_RELAUNCH`.

The exact RAX41v2 `smd` hash also matches the RAX42v2 supervisor that rejected
the production-shaped EID 45 start request. Consequently:

- vulnerable component code: confirmed by binary identity;
- unauthenticated crash if manually launched: transferred by exact binary
  identity from the isolated RAX42v2 reproduction;
- shipping activation/listener: disabled by production metadata;
- product-level unauthenticated DoS: not confirmed;
- RCE: not demonstrated.

## Public-prior-art boundary

Searches performed on 2026-07-24 found public RAX41v2 issues that must not be
misclassified as new:

- CVE-2025-12946 covers a speedtest command-execution issue in RAX41v2 versions
  before V1.1.6.36. V1.1.6.38 is outside its affected range.
- CVE-2026-0410 covers authenticated-administrator privilege abuse in RAX41v2
  versions before V1.1.4.28. It is a different authentication and impact
  boundary.

No public result located in this pass described the disabled `ippd` component
or a V1.1.6.38 unauthenticated `httpd`/`upnpd` RCE or DoS. This does not
exclude private or embargoed duplicates.

## Current classification

- Confirmed zero-day: no.
- Confirmed product vulnerability: no.
- Strongest lead: latent, exact vulnerable `ippd`, disabled in production.
- Genuine `upnpd` GENA target: dynamically tested negative as described below.
- `httpd` password-recovery/unauthenticated target: genuine server now boots
  with a stable isolated HTTPS listener after correcting a semantic
  instrumentation interposer in the lab.
- Physical-device validation: still required for any product-level claim.

## Focused dynamic validation (2026-07-24)

### Genuine UPnP daemon

The exact V1.1.6.38 `/usr/sbin/upnpd` was booted in an ARM full-system guest
with:

- QEMU user networking restricted from external access;
- only `127.0.0.1:25341` forwarded to the guest listener;
- production-style `br0` at `10.0.2.15`;
- the genuine `acos_nvram` and `smd`;
- `upnp_turn_on=1`, matching the daemon's dispatcher gate; and
- fatal-signal and long-copy tracing that does not replace the parser.

The daemon joined SSDP multicast, advertised
`http://10.0.2.15:56688/Public_UPNP_gatedesc.xml`, and listened on
`10.0.2.15:56688`. The declared event route
`/Public_UPNP_Event_1` accepted a normal unauthenticated subscription:

```text
control request_bytes=179 status=HTTP/1.1 200 OK alive=True
```

The RAX30 eventing boundaries reached the same accepted path without
terminating the daemon:

```text
rax30-shape-72 request_bytes=228 status=HTTP/1.1 200 OK alive=True
rax30-shape-73 request_bytes=229 status=HTTP/1.1 200 OK alive=True
rax30-shape-76 request_bytes=232 status=HTTP/1.1 200 OK alive=True
```

The extended matrix also covered a missing-scheme callback and 8,192-byte
`CALLBACK`, `TIMEOUT`, `NT`, renewal SID, and unsubscribe SID values. Oversized
cases received no response but the daemon remained reachable after every
candidate. A callback containing a harmless shell-shaped marker received
`HTTP/1.1 200 OK`; no command-sink trace, fatal signal, or daemon exit appeared.

Result: no observable unauthenticated eventing RCE or input-specific DoS in
this bounded campaign. This is a meaningful negative because the control and
RAX30-shaped requests reached the enabled, firmware-declared GENA route.

The complete 279-function decompilation succeeded with no timeouts. Six broad
function-local candidates were emitted. Focused review showed the event parser
uses bounded `strncpy` operations and stack canaries. The four apparent
`fgets` plus `system`/`popen` candidates process local command output or fixed
daemon workflows; the automated evidence did not identify a network route or
authentication marker in those functions.

Artifacts:

- `scripts/emulate_rax41v2_upnp_full_system.py`
- `scripts/probe_rax41v2_upnp_eventing.py`
- `known_firmware/emulation/RAX41V2/full_system_upnp_init`
- `known_firmware/emulation/RAX41V2/full-system-upnp-lab/serial.log`

### Genuine HTTP server

The first exact V1.1.6.38 `/usr/sbin/httpd` and production `smd` boot used an
inherited global `strcpy` tracing interposer. The daemon briefly bound its
listeners and then faulted without any network request:

```text
HTTPD_LISTENING=no
FRIDAY_RAX29_FATAL signal=0x0000000b pc=0x004b40ac
fault=0x00000000
HTTPD_EXITED=1
```

This was a baseline emulation failure, not a remotely triggered DoS.

The reported PIE address was subsequently rebased and inspected directly.
Runtime `0x004b40ac` corresponds to file-relative `0x000b40ac`, which is a
literal-pool word immediately after a small initialization routine's return
epilogue at `0x000b40a8`, not a request parser instruction. The fault occurs
after repeated platform semaphore and `/dev/acos_nat_cli` initialization and
without any request. This further supports an instrumentation/platform-state
return-path failure rather than remotely triggered HTTP corruption. It cannot
be counted as a product DoS.

Follow-up isolated boot work resolved the baseline. The inherited `strcpy`
interposer was disabled for RAX41v2 because it replaced libc semantics
globally rather than merely observing a specific candidate call site. Fatal
signal and command-sink tracing remain enabled. The harness's listener check
was also corrected to avoid shell expansion of AWK's `$4`, and its stability
criterion now follows the settled HTTP worker instead of a transient startup
PID.

On a clean rebuilt guest, the genuine daemon remained stable and returned two
HTTPS controls separated by the stability interval:

```text
HTTPD_LISTENING=yes
tls_ready=true pid=123 pid_rotated=false
first='HTTP/1.0 200 OK' second='HTTP/1.0 200 OK'
```

The startup issue is therefore resolved. The genuine unauthenticated recovery
routes can now be tested with request-specific marker/crash probes; successful
baseline emulation alone does not establish an RCE or DoS.

### Stable HTTP security matrix

The stable genuine daemon was subsequently exercised without an administrator
session. The SOAP matrix covered login/authentication actions, marker-shaped
NTP, firmware URL, and Ookla server parameters, and `GetInfo` bodies from zero
through 16,384 bytes. Raw parser cases covered `SOAPAction` through 65,536
bytes, 16,384-byte `Host` and `X-Forwarded-For` values, a 16,384-byte path, a
65,536-byte XML body, and conflicting `Content-Length` headers.

All normal and marker-shaped SOAP requests returned HTTP 200. No marker
reached the instrumented `system`, `popen`, or `fopen` sinks. Oversized cases
were either answered or closed without a response; the genuine daemon
remained responsive after every case. No fatal signal or daemon exit occurred.

The password-recovery routes were tested separately with normal, shell-shaped
marker, and 8,192-byte fields:

```text
securityquestions.cgi      HTTP/1.0 401 Unauthorized
passwordrecovered.cgi      HTTP/1.0 401 Unauthorized
reset_admin_account.cgi    HTTP/1.0 401 Unauthorized
```

The result was identical for control, marker, and oversized cases, with the
service alive after each request and no command-sink or fatal-signal trace.
In this emulated device state, these routes did not provide an
authentication bypass, RCE, or request-specific DoS.

Artifacts:

- `scripts/probe_rax41v2_recovery_routes.py`

Artifacts:

- `scripts/emulate_rax41v2_http_full_system.py`
- `known_firmware/emulation/RAX41V2/full-system-http-lab/serial.log`
