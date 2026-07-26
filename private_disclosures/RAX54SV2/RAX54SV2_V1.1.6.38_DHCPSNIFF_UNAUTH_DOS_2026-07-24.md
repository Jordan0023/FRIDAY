# RAX54Sv2 V1.1.6.38 `dhcpsniff` unauthenticated parser DoS

The exact ARM Circle `dhcpsniff` callback trusts the packet-declared UDP
length while walking DHCP options without constraining that walk to libpcap's
captured length.

A guard-page harness invoked the genuine callback without transmitting a
packet. The valid 283-byte control placed DHCP END inside the capture and
exited normally. The 282-byte candidate ended immediately before the option
area, declared a 1,500-byte UDP length, and faulted on the protected page:

```text
FRIDAY_DHCPSNIFF_CONTROL_STATUS=0
FRIDAY_DHCPSNIFF_CANDIDATE_STATUS=139
```

This confirms an unauthenticated packet-triggered daemon DoS in the shipped
component. It is not yet a default product-level or WAN DoS: `dhcpsniff`
belongs to the optional Circle subsystem and captures DHCP on a selected local
interface.

Evidence:
`known_firmware/emulation/RAX54SV2/dhcpsniff-guard-page-confirmation.log`

Evidence SHA-256:
`9a5da7a7faed0e5f6c23a36af483d953bfac395f811dfcf5ef252ed6f2fbf7ab`

## Reproducibility confirmation

Three additional clean QEMU boots reproduced the differential result:

| Run | Valid control | Truncated candidate |
|---|---:|---:|
| 1 | exit 0 | SIGSEGV / exit 139 |
| 2 | exit 0 | SIGSEGV / exit 139 |
| 3 | exit 0 | SIGSEGV / exit 139 |

Evidence:

- `known_firmware/emulation/RAX54SV2/dhcpsniff-confirmation-run-1.log`
  (`9a077c15762ddc93cd0108660d12370007de03bcb90824344fa1fd9037d22128`)
- `known_firmware/emulation/RAX54SV2/dhcpsniff-confirmation-run-2.log`
  (`6ab5ad9df1603a0a4c049bbedba07a1502285428255350227f708c820c96b8df`)
- `known_firmware/emulation/RAX54SV2/dhcpsniff-confirmation-run-3.log`
  (`25873ae6751a028ee17adee1e50536ebb91c1cb47e65fb6d942bf635a2f400f9`)

The component-level daemon DoS is therefore confirmed and repeatable. Product
activation and network-interface exposure remain separate gates.

## Activation and exposure review

The complete RAX54Sv2 root filesystem was searched for references to
`dhcpsniff`. Apart from the binary itself, the only reference is Circle's
`lsproc` monitoring script. No init script, runit service, supervisor entity,
Circle `service/*/run` file, or executable command string starts it.

The binary's built-in default interface is `eth1`. The RAX54Sv2 Circle platform
configuration declares `br0` as its bridge, but no shipped launcher was found
that supplies `-i br0` (or any other interface) to `dhcpsniff`.

Consequently:

- a packet needs no application authentication if the callback is active;
- the likely attacker position would be an adjacent LAN/L2 segment;
- WAN reachability is not supported by the firmware evidence; and
- stock or feature-enabled product activation is not established.

This remains a confirmed vulnerable shipped component, not a confirmed
RAX54Sv2 product-level DoS.

## Public prior-art review

Public searches on 2026-07-24 for combinations of RAX54Sv2, `dhcpsniff`,
Circle, DHCP parser, buffer overflow, and denial of service found no matching
disclosure. The closest NETGEAR/Circle records concern different flaws:

- CVE-2021-40847: Circle update-process RCE;
- CVE-2025-12946: RAX54Sv2 speedtest/DNS command execution; and
- CVE-2023-40480: a RAX30 DHCP-server command-injection issue.

This supports apparent public novelty, but cannot exclude a private,
embargoed, or differently described report.
