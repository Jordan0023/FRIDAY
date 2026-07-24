# RT-AX82U native pre-authentication surface hunt

## Scope

- Firmware: ASUS RT-AX82U `3.0.0.4.388_25101`
- SHA-256: `00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916`
- Guest: exact extracted ARM firmware under QEMU in an internal-only Docker network
- Goal: identify an unconditional, LAN-reachable, unauthenticated memory-safety or command-execution primitive

This pass deliberately excluded the already-confirmed authenticated web importers
and the conditional IFTTT token-recovery chain. Those findings are documented
separately and do not establish a new unconditional pre-authentication zero-day.

## `u2ec` (TCP 3394/5473 and UDP 5474)

The exact firmware daemon was launched with its LAN interface modeled as loopback.
It opened UDP 5474 and TCP 3394/5473. A bounded corpus exercised the recognized
`GETIP`, `GETCONFIG`, and `GETNAME` commands, malformed commands, embedded NULs,
and lengths from 1 through 4096 bytes.

Observed bounds from the system-call trace:

- UDP 5474 receives at most 5 bytes per datagram;
- TCP 5473 reads at most 9 bytes per connection;
- malformed TCP requests were closed without terminating the daemon;
- the daemon remained alive with all three listeners present after the corpus.

TCP 3394 accumulated connections because the emulated guest has no USB printer.
The resulting backlog was not a crash: the process remained alive and its other
listeners continued accepting traffic. This surface produced no vulnerability
candidate in the tested command and length classes. The reusable bounded driver
is `scripts/audit_asus_u2ec.py`.

## `wsdd2` (WS-Discovery and LLMNR)

The exact binary reached interface discovery and netlink initialization but did
not open UDP 3702 or 5355 in this guest. Its trace stopped waiting on firmware
network-state behavior after successful loopback discovery. Consequently no
dynamic parser claim is made for this surface.

Static inspection confirmed explicit HTTP content-length rejection paths,
including an upper-bound diagnostic, and numerous LLMNR structural checks
(minimum packet length, one-question restriction, compression rejection, and
record type/class validation). The binary still imports `strcpy`, `sscanf`, and
raw receive functions, so this is an emulation-limited residual review area—not
a confirmed vulnerability.

## `networkmap` and ASUS discovery

`networkmap` receives raw ARP data into 512-byte buffers; both identified
`recvfrom` call sites pass `0x200` as the receive bound. Its main input depends on
raw LAN-interface and ARP-table state that the loopback guest cannot reproduce
faithfully. No oversized receive primitive was identified in the first-pass
static review.

`asusdiscovery` bound UDP 9999, emitted a single 512-byte discovery request, and
exited. It behaved as a discovery client rather than a persistent remotely
reachable parser, so it was removed from the listening-service target set.

## Result

This native-service pass did **not** confirm a new zero-day vulnerability. It
eliminated several apparent targets and preserved two residual areas for future
hardware-backed work: `wsdd2` with real bridge/netlink state and `networkmap`
with a controlled raw-Ethernet LAN harness. A zero-day label remains inappropriate
without a reproducible security effect, unauthenticated reachability, affected
version analysis, and a novelty check against public prior art.
