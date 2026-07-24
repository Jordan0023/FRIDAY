# RP-AX56 `cfg_server` Validation Evidence

Date: 2026-07-24

## Outcome

No new unauthenticated RCE or DoS was confirmed.

The 51891 binary contains a concrete fix for the historical ConnDiag
short-packet class: after `recvfrom`, its UDP caller compares the received byte
count with 11 and reaches the ConnDiag queue only when the count is at least 12.
The corresponding 42860 receive path lacks that caller-side minimum-length
check.

The published eight-byte CVE-2022-38393-family packet
`00 00 00 06 ff ff ff fc` did not terminate either emulated daemon. On the old
build, the synthetic profile did not establish the encrypted group-key state
needed to drive the vulnerable downstream processing. The old result is
therefore a static vulnerable-code match with an incomplete dynamic trigger,
not a newly confirmed RP-AX56 DoS.

## Firmware identity

| Firmware | Exact `cfg_server` SHA-256 |
| --- | --- |
| 3.0.0.4.386_42860 | `c659d4637c34dc18a3aaad33dc534b8d4f062e8c5229c96f616a5e064e89dc92` |
| 3.0.0.4.386_51891 | `4578801e3b86a5171181d1ef95764b4d028e0e8a214e2d6852ab17a1f2957a67` |

## Static differential

In 51891, the network receive function contains:

```text
1c720: cmp r4, #11
1c724: bhi 1c7c0
```

Here `r4` is the `recvfrom` return count. Datagrams shorter than 12 bytes take
the explicit `error on received size(%d)` path. The old receive path proceeds
from its received-length handling without this comparison. The newer binary
also adds `Checking length error !!!` diagnostics in packet-processing
functions.

The 51891 unauthenticated key-exchange parser additionally verifies that a
message contains a complete 12-byte header before comparing its declared
payload length with `received_length - 12`.

## Dynamic method

Both ARM binaries were started in separate Docker containers with network mode
`none`, a dummy `br0`, synthetic NVRAM, and an ephemeral RSA keypair. To reach
the otherwise unchanged packet handlers, labeled lab copies applied the same
two startup-only scaffolds to both versions:

- force the AiMesh controller-support result; and
- bypass the hardware-authorization failure branch.

Neither edit touches the UDP/TCP receive functions or packet processors.
Both daemons then bound TCP and UDP port 7788.

Each live parser received 75 bounded cases:

- the published eight-byte ConnDiag packet;
- 14 UDP datagram lengths from 0 through 2047 bytes; and
- 60 TCP headers combining opcodes 1, 3, 4, 5, and 8 with declared lengths
  from zero through `0xffffffff`.

Both original parser PIDs and both listeners remained alive. The syscall traces
show no terminating `SIGSEGV`, `SIGABRT`, or `SIGBUS`.

## Artifacts

- `42860/` and `51891/`: JSON probe output, syscall traces, and receive-handler
  disassembly.
- `42860/startup-gate-decompile.c`: decompiler evidence for the two startup
  gates.
- Probe: `scripts/probe_asus_rpax56_cfg_server.py`.

## Limitations

This is component emulation, not physical-device validation. In particular,
the old daemon did not complete a real AiMesh key exchange, so this run cannot
prove whether the historical eight-byte trigger crashes a configured 42860
device. The latest caller-side check is independent of key state and directly
blocks that packet before the vulnerable downstream arithmetic.
