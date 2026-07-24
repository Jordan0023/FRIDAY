# GL.iNet default-WAN DHCPv6 OOB-read candidate

Date: 2026-07-24

## Status

Confirmed source-level memory-safety defect in the exact upstream revision used
by all three firmware images, with a local AddressSanitizer reproduction.
Network-level impact against the genuine firmware binary remains unconfirmed.
Do not yet describe this as a remotely exploitable crash or as a path to the
WebUI lockout.

## Affected images

| Product | Firmware |
|---|---|
| GL-MT5000 | 4.8.6 |
| GL-MT5000 | 4.9.0 |
| GL-MT2500/MT2500A | 4.7.4 |

All three contain the identical `/usr/sbin/odhcp6c`:

`SHA-256 672eae33a42dcb1a0c09205ac246a63873f78d68761c854bef289d3ba246f6ab`

The package database identifies it as `odhcp6c
2021-01-09-53f07e90-16`.

## Default WAN reachability

Each image contains an enabled `Allow-DHCPv6` rule accepting IPv6 UDP traffic
to router-local port 546 from the WAN zone. This makes `odhcp6c` a genuine
factory-WAN parser surface even though TCP/80 and TCP/443 are rejected.

Practical reachability is narrower than arbitrary Internet reachability.
DHCPv6 transaction and message validation still applies, and the most credible
attacker is on the upstream link or controls the DHCPv6 server.

## Defect

The shipped source revision calls its IA parser from the Advertise handler with
an end pointer equivalent to:

`odata + olen + sizeof(*ia_hdr)`

Because `odata` already points past the four-byte option header and `olen`
describes the data, the legitimate end is `odata + olen`. The additional
structure size lets the nested option iterator read beyond the IA option and,
when the IA is last, beyond the received packet buffer.

OpenWrt upstream commit `b6f0c70f5fc26632d8a6c748efec5aa335aa4fde`
fixes this by removing the extra `sizeof(*ia_hdr)`. Its commit description
states that the old boundary can read beyond the receive buffer and parse
adjacent bytes as bogus IA sub-options.

## Local validation

`known_firmware/emulation/GL-MT5000/odhcp6c_advert_oob_harness.c` models the
unchanged iterator macro and exact faulty boundary from revision `53f07e90`.
Clang AddressSanitizer reports a one-byte heap-buffer-overflow read immediately
after a 16-byte IA allocation. Passing the corrected boundary completes with
exit status zero.

### Genuine receive-buffer qualification

Follow-up source tracing found that the genuine client receives DHCPv6 packets
into a 1,536-byte stack array and passes the packet's logical end to the
handlers. The faulty Advertise call extends that logical end by 16 bytes, but
those bytes ordinarily remain inside the allocated 1,536-byte array. The
exact-size sanitizer harness therefore proves the invalid logical boundary but
does not model the surrounding storage of the production receive path.

The likely production effects are reading stale/uninitialized bytes and
possibly adding bogus IA state. A direct process crash is substantially less
likely than the original exact-allocation harness suggested. This candidate
must not be classified as a denial of service without genuine-process evidence.

Evidence:

- `private_disclosures/GL-MT5000/ODHCP6C_ADVERTISE_OOB_ASAN_2026-07-24.txt`
- upstream fix `b6f0c70f5fc26632d8a6c748efec5aa335aa4fde`

## Remaining validation

The next step is a disposable network namespace or full-system emulation
running the genuine AArch64 `odhcp6c`, with a researcher-controlled DHCPv6
server. Record whether a minimally malformed Advertise causes:

1. a detectable process crash or restart;
2. state pollution without a crash; or
3. no externally observable effect because surrounding receive-buffer storage
   remains mapped and benign.

Only outcome 1 would presently support a default-WAN denial-of-service claim.
Even then, the likely vector is adjacent/upstream WAN, not arbitrary routed
Internet access and not automatic reachability of `/rpc`.
