# EX2800 Telnet/login bounded fuzz validation

Date: 2026-07-25

## Scope

- Firmware: NETGEAR EX2800 V1.0.1.84
- Firmware SHA-256:
  `8d9a63c1224b5d8137833b861e9d0ba44a1202a892d927f942cf1e740cf02163`
- Boundary: disposable Docker container with `--network none`; Telnet bound
  only to `127.0.0.1` inside the container
- Components: original firmware BusyBox `telnetd` and `/bin/login`, executed
  with QEMU MIPS user emulation and PRoot
- Privilege: root, matching the firmware's generated inetd rule
- Credentials supplied by the fuzz corpus: no valid credential

The container used a disposable copy of the extracted firmware root. A
loopback-only `socat` wrapper supplied the connected socket normally provided
by inetd because an inetd child did not survive the component-level PRoot
boundary. Telnet parsing, PTY allocation, and login authentication remained in
the original firmware BusyBox binary.

## Corpus

The deterministic 91-case corpus covered:

- blank and login-option-shaped usernames;
- format-string and shell-metacharacter tokens;
- high bytes;
- ASCII, percent, and Telnet-IAC repetitions at boundaries from 1 through
  4096 bytes; and
- Telnet WILL and subnegotiation frames for options 0, 1, 3, 24, 31, 32, 34,
  36, 39, and 255.

The harness checked for a possible shell prompt and opened a fresh connection
after every case. Two consecutive failed health checks were required to record
a crash/hang lead.

## Result

```text
cases_attempted=91
consecutive_health_failures=0
crash_or_hang_lead=false
possible_auth_bypass_lead=false
rce_confirmed=false
```

All 4096-byte ASCII and percent cases completed and the service remained
healthy. Repeated raw `0xff` username cases timed out as Telnet control-stream
inputs, but the service remained healthy after each case. All explicit WILL
and subnegotiation cases completed without a bypass or health failure.

## Classification

No unauthenticated Telnet authentication bypass, crash lead, or RCE was found
by this corpus. This negative result does not alter the separately confirmed
factory-unconfigured HTTP RCE chain. It specifically rejects promotion of the
`/start_telnet` behavior to unauthenticated RCE through the tested Telnet/login
parsing paths.

Reproduction assets:

- `scripts/ex2800_telnet_login_fuzzer.py`
- `scripts/ex2800_telnetd_emulation_wrapper.sh`
- `tests/fixtures/ex2800-start-telnet-inetd.conf`
- `tests/test_ex2800_telnet_login_fuzzer.py`
