# RP-AX56 `dnsmasq` Validation Evidence

Date: 2026-07-24

## Result

The 42860 and 51891 firmware images contain the exact same `dnsmasq` file:

`5645f92fd7030840cfc232d07a5ea9347d2dde315f6785441e2439369c06081d`

The executable identifies itself as dnsmasq 2.84 with both DHCP and DHCPv6
compiled in. This version predates the upstream dnsmasq 2.87 fix for
CVE-2022-0934, a remotely reachable DHCPv6 single-byte write-after-free with
potential denial-of-service impact. The preserved upstream patch shows that
the stale pointer is used after output-buffer reallocation.

RP-AX56 `rc` contains active configuration generators for `enable-ra`,
`ra-param`, stateful DHCPv6 ranges, and stateless DHCPv6 ranges. Reachability
of the vulnerable parser is therefore conditional on IPv6/DHCPv6 being
enabled in the device configuration.

Factory-default analysis found `ipv6_service=disabled` in the exact
`router_defaults` tables from both releases. The exact 51891 `rc` skips all
IPv6 dnsmasq directives when `get_ipv6_service()` returns zero. Consequently,
the affected DHCPv6 path is not shown reachable at factory defaults. See
`FACTORY_DEFAULT_REACHABILITY.md`.

## Dynamic matrix

The exact 51891 binary was run on an isolated bridge. A valid DNS control query
and DHCPDISCOVER/DHCPOFFER exchange confirmed that the real DNS and DHCPv4
parsers were active. It survived 17 bounded cases:

- Eight DNS/UDP header, label, compression, count, and EDNS cases.
- Four DNS/TCP length-framing cases.
- Five DHCPv4 fixed-header and option-length cases.

Every post-case DNS health check passed. This matrix found no additional
unauthenticated DNS or DHCPv4 denial of service.

DHCPv6 could not be dynamically exercised in this ARM user-mode runtime because
QEMU returned `EOPNOTSUPP` while dnsmasq created its required raw ICMPv6 socket.
That emulator limitation is not evidence that a physical RP-AX56 lacks the
path.

## Files

- `51891/results.json`: packet-by-packet results and health checks.
- `51891/runtime.log`: daemon startup and request log, including DHCP offer.
- `upstream-CVE-2022-0934.patch`: official dnsmasq maintainer patch.
- `FACTORY_DEFAULT_REACHABILITY.md`: defaults and boot-branch assessment.
- `factory-ipv6-xrefs.c`: focused decompilation of the exact 51891 `rc`.
- Probe: `scripts/probe_asus_rpax56_dnsmasq.py`.

## Upstream references

- dnsmasq 2.87 release announcement:
  https://lists.thekelleys.org.uk/pipermail/dnsmasq-discuss/2022q3/016599.html
- Original report and maintainer analysis:
  https://lists.thekelleys.org.uk/pipermail/dnsmasq-discuss/2022q1/016272.html
- Official patch:
  https://lists.thekelleys.org.uk/pipermail/dnsmasq-discuss/2022q1/016274.html
