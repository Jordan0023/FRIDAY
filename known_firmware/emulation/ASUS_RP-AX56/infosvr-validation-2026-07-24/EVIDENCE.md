# RP-AX56 `infosvr` Validation Evidence

Date: 2026-07-24

## Result

No unauthenticated command execution or denial of service was reproduced in
either tested RP-AX56 `infosvr` binary.

| Firmware | `infosvr` SHA-256 | Final PID | Result |
| --- | --- | --- | --- |
| 3.0.0.4.386_42860 | `d5d8e0be8067e8118a20cd67929bc23b5ebd4978f64917b3472646d17c411a8d` | 141 | alive |
| 3.0.0.4.386_51891 | `667accc5ab7e13fffa66ad890cd397963c9b213a528c12965d89529ef2a1edc2` | 204 | alive |

Both exact ARM binaries bound UDP port 9999 in network-isolated containers.
A correctly formed unauthenticated opcode-31 discovery request produced a
512-byte response on each build, demonstrating that the parser was live.

The historical opcode-51 command packet carried only this harmless,
loopback-local marker command:

```text
echo FRIDAY_INFOSVR_MARKER >/tmp/friday-infosvr-marker
```

Neither build created the marker, returned a command response, nor issued a
child `execve` in its syscall trace. This behavior is consistent with the
post-2015 `ateCommand_flag` command-dispatch guard.

## Bounded parser coverage

Each build received 65 packets across these groups:

- one valid discovery request;
- one historical opcode-51 command request;
- 16 truncated datagrams from zero through 511 bytes;
- 30 full-size opcode values, including 29 through 55 and `0xffff`;
- 12 opcode-51 declared command lengths from zero through `0xffff`, including
  the 463/464/465-byte payload boundary;
- five service-ID/packet-type combinations.

The opcode-51 length cases used only inert colon bytes. All probe sends
completed without socket errors. Both original process IDs remained alive
after all matrices, and the traces contain no terminating signal. The 51891
trace includes a handled startup `SIGILL` used by its runtime feature probing;
execution resumed under the installed handler well before the packet matrices.

## Artifacts

- `42860/*.json` and `51891/*.json`: machine-readable results for every case.
- `42860/infosvr-trace.log` and `51891/infosvr-trace.log`: syscall traces from
  the exact firmware binaries.
- Probe generator: `scripts/probe_asus_rpax56_infosvr.py`.

## Scope

This is component emulation, not a physical-device test. It strongly rejects
the known historical command-execution packet and simple parser-crash classes
under the tested NVRAM profile, but it does not prove the absence of every
stateful, timing-dependent, or platform-integration flaw.
