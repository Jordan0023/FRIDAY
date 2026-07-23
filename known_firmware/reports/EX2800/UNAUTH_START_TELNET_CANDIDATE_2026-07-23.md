# EX2800 unauthenticated `start_telnet` candidate

Date: 2026-07-23
Firmware: `EX2800-V1.0.1.84.zip`
SHA-256: `8d9a63c1224b5d8137833b861e9d0ba44a1202a892d927f942cf1e740cf02163`

## Status

Confirmed unauthenticated Telnet exposure and acceptance of the shipped root
credential in isolated component-level emulation. Root command execution was
also reproduced after adding a disposable shell-path compatibility shim.
Device-level RCE and zero-day status remain unconfirmed.

## Isolated test boundary

The original MIPS `mini_httpd` was run with QEMU and PRoot in a disposable
firmware copy inside a Docker container configured with `--network none`.
Only the missing firmware-wide message bus was stubbed. HTTP parsing, route
handling, authentication logic, filesystem actions, `inetd`, `telnetd`, and
`login` remained original firmware binaries. The HTTP service and `inetd` were
run as separate processes because full root-mode initialization crashes under
this component-level setup. Docker's file-descriptor limit was reduced to 1024
because the original `telnetd` closes every descriptor up to that limit.

## Reproduced unauthenticated behavior

An HTTP request without an `Authorization` header was sent to:

```text
GET /start_telnet HTTP/1.1
Host: [::1]
```

The server returned HTTP 302 but performed the following actions before the
redirect:

1. Wrote this root service rule through `/etc/inetd.conf`:

   ```text
   telnet stream tcp nowait root /usr/sbin/telnetd telnetd
   ```

2. Created `/var/telnetd` containing `1`.
3. Invoked fixed commands that kill and restart `inetd`.

The result reproduced from a clean disposable filesystem state.

## Root credential evidence

`/usr/sbin/telnetd` resolves to BusyBox and launches `/bin/login`. The shipped
root entry uses this password hash:

```text
root:$1$BOYmzSKq$ePjEPSpkQGeBcZjlEeLqI.:13796:0:99999:7:::
```

The hash matches the literal password `root`.

## Negative controls

- A harmless command marker placed in a `debug.htm` query parameter was not
  created; direct CGI command injection was not demonstrated.
- A bounded 4 KiB request path returned an empty response, but the parent HTTP
  service remained alive; persistent DoS was not demonstrated.
- Complete Ghidra decompilation of `mini_httpd` covered 56 of 56 discovered
  functions and produced no generic function-local attacker-source-to-command
  or memory-safety correlation.

## Dynamic Telnet validation

Launching the original firmware `inetd` with root privileges made TCP port 23
reachable. The original BusyBox `telnetd` and `/bin/login` accepted
`root`/`root`.

The extracted password file contains a commented root record using
`/bin/bash`, followed by the active root record using `/bin/sh`:

```text
#root:x:0:0:root:/root:/bin/bash
root:x:0:0:root:/root:/bin/sh
```

In this emulation, `login` selected `/bin/bash`, which is absent from the
image, and terminated after successful authentication. Adding a disposable
`/bin/bash` wrapper that execs the shipped `/bin/sh` allowed the same original
login path to reach a shell. A harmless probe then read
`Uid: 0 0 0 0` from `/proc/self/status`, wrote a marker under `/root`, and
printed `FRIDAY_TELNET_VALIDATED`.

The wrapper was added only to the disposable extracted root and is not part of
the firmware or reproduction assets. Therefore the test proves that the
enabled service accepts the shipped root credential and that the resulting
session is UID 0 when a valid configured shell is available. It does not prove
that an unmodified production device resolves the conflicting password records
the same way as this component-level environment.

A standalone, loopback-restricted proof of concept reproduced the chain and
reported:

```text
root_session=true
harmless_command_executed=true
Uid:    0       0       0       0
```

The proof refuses targets that do not resolve to a loopback address.

## Unmodified-root control and DoS results

Repeating the Telnet proof after removing the disposable `/bin/bash` wrapper
confirmed that the original login accepts `root`/`root`, then closes the
connection because it cannot run `/bin/bash`. The unmodified extracted root
therefore did **not** reproduce command execution. The UID-0 RCE result remains
conditional on resolving the firmware's conflicting root-shell records.

A separate loopback-restricted, bounded HTTP DoS proof exercised 8 KiB and
32 KiB paths, a 32 KiB header, a negative content length, and a deliberately
stalled request. After every case, the original HTTP service accepted a fresh
request. One stalled client did not starve other requests, and the service
recovered after the connection closed:

```text
path_8k_service_recovered=true
path_32k_service_recovered=true
header_32k_service_recovered=true
negative_content_length_service_recovered=true
single_stalled_client_starves_service=false
service_recovers_after_stall=true
persistent_dos_reproduced=false
```

An expanded bounded test held 16, 32, 64, 96, and 128 deliberately incomplete,
unauthenticated HTTP connections. A fresh health request failed at every
tested level, beginning at 16; after each group was closed, the service
recovered:

```text
connections_16_exhausted=true
connections_16_recovered=true
first_bounded_exhaustion=16
persistent_dos_reproduced=false
```

This reproduces a transient connection-exhaustion DoS, not a process crash or
persistent DoS. Additional comparison against the intended connection limit
and physical-device behavior is required to determine whether the threshold is
a product vulnerability rather than ordinary finite-capacity exhaustion.

Passwordless Telnet probes using `root`, the commented `#root` record, a
login-option-shaped username, and an empty username all failed to reach UID 0:

```text
authentication_bypass_reproduced=false
```

Accordingly, no strictly unauthenticated RCE was reproduced. The demonstrated
execution chain still requires the shipped `root`/`root` credential and the
shell-path compatibility condition described above.

The Telnet matrix was subsequently expanded to include separated and joined
login-option-shaped usernames, preserve-environment and double-dash inputs,
trailing whitespace, embedded NUL and carriage-return boundaries, 256- and
1024-byte usernames, and Telnet `NEW-ENVIRON` negotiation for `USER`,
`LOGNAME`, and `SHELL`. Every passwordless case failed:

```text
authentication_bypass_reproduced=false
telnet_service_survived_matrix=true
```

The disposable shell wrapper was present only as a success detector during
this matrix and was removed afterward. No case received the valid root
password.

## Impact assessment

If the production device resolves the root account to a valid shell, the
observed chain is:

```text
unauthenticated LAN HTTP request
  -> enable root telnet service
  -> authenticate with shipped root/root credential
  -> root command execution
```

Port exposure and root-password acceptance are dynamically confirmed. Treat
end-to-end device RCE as a high-impact LAN-adjacent candidate until the shell
selection is reproduced in faithful full-system emulation or on
vendor-authorized hardware.

## Known-vulnerability check

NETGEAR lists CVE-2026-0407 as an authentication bypass affecting EX2800
versions earlier than 1.0.1.82. The analyzed 1.0.1.84 build is newer than that
fix boundary. No public record matching this exact `/start_telnet` behavior was
identified during the 2026-07-23 check. That does not prove novelty.

Firmware 1.0.1.64, 1.0.1.82, and 1.0.1.84 were compared locally. Their
`/etc/passwd` and `/etc/shadow` files are identical, including the root hash
and conflicting shell records. Each `mini_httpd` contains `start_telnet`, the
root Telnet `inetd` rule, and the `/var/telnetd` action. The 1.0.1.82 build
substantially changes the web server and password-reset assets associated with
the published authentication fix, but retains this Telnet path. No official
EX2800 1.0.1.80 image was located.

The image includes an MT7628-specific Linux 2.6.36 kernel, but the available
full-system QEMU supports only Malta/MIPSsim and has no MT7628 board model.
Faithful full-system boot is therefore not available in this environment.

## Historical bypass-class comparison

Public NETGEAR advisories describe several relevant historical classes:
pre-authentication command injection in extender/Orbi handlers,
authentication-exempt setup or debug routes, path traversal that exposes
management credentials, and command execution dependent on attacker-controlled
DNS/MITM responses. The advisories generally do not publish the vulnerable
parameters.

The EX2800 image does not contain the commonly cited `boardDataWW.php`,
`setup.cgi?todo=debug`, or `BRS_02_genieHelp.html` handlers. Requests for those
legacy paths, `super_setting.htm`, and a direct GET of `/cgi-bin/webupg` were
rejected or closed without reproducing command execution. In the same run,
`/start_telnet` returned its redirect and installed the Telnet configuration,
confirming that it is a distinct authentication-exempt path.

The image does expose configuration objects for ping/traceroute diagnostics,
NTP servers, hostnames, and firmware upload. Those are appropriate targets for
continued authorization-boundary and data-flow review, but current testing has
not shown that they are reachable pre-authentication or command-injectable.

A loopback-only dynamic matrix also tested path dot segments, double and
encoded slashes, encoded traversal, path-info and semicolon variants, internal
proxy headers, original/rewrite URL headers, malformed or empty Basic
authorization, forged empty session cookies, alternate and overridden HTTP
methods, setup/password-reset pages, direct `webupg` submission, and harmless
command-marker parameters. None disclosed credentials, created the marker, or
performed another privileged action:

```text
authentication_bypass_with_privileged_effect=false
```

Several CGI cases closed without a response because the component emulator
stubs the firmware-wide message bus. They were not counted as secure merely
because of a status code; the test required an observable privileged effect.

## Original configuration-backend restoration

Follow-up work identified `/usr/bin/logic` as the original configuration and
message-bus daemon. It loads `/etc/config.xml`, creates the Unix datagram
endpoint `/var/pid/0x01`, and contains the diagnostic command construction:

```text
diagtest -m ping -d %s
```

The daemon cannot initialize unchanged under QEMU user mode because it expects
MT7628 bridge, procfs, flash, LED, and wireless interfaces. A disposable
emulation copy was therefore used with:

- no-op wrappers for hardware-only `brctl` and `ifconfig` setup;
- a narrowly scoped preload shim that succeeds only for the unsupported
  `0xc0104704` flash ioctl; and
- two control-flow changes that skip the aggregate failure assertion and exit
  for unavailable optional hardware modules.

No message-bus or configuration functions were stubbed in this run. With
those hardware-init accommodations, the original daemon reported:

```text
*** All module init OK ***
```

It remained in its message loop for the complete 20-second bounded test and
exited only when the harness delivered the timeout signal.

The initial coupled HTTP tests used an incomplete command line. Debugging the
root-mode SIGSEGV showed a null username passed to uClibc `initgroups()`.
The vendor startup script at `/etc/init.d/daemon.rc` supplies `-u root` and
uses `/cgi-bin/*` as the CGI pattern. Repeating the test with that exact launch
mode resolved the crash and produced complete HTTP responses with the original
HTTP daemon, original `webproc`, and original configuration backend active.

The unauthenticated route matrix then completed without a credential leak or
privileged command effect:

```text
authentication_bypass_with_privileged_effect=false
```

Four additional unauthenticated POST cases targeted the plausible diagnostic
objects:

- `InternetGatewayDevice.IPPingDiagnostics.Host` with
  `DiagnosticsState=Requested`;
- the same object with a lowercase state variant;
- `InternetGatewayDevice.X_TWSZ-COM_Diagnostics.Interface`; and
- `InternetGatewayDevice.X_TWSZ-COM_Diagnostics.CheckWanConnection`.

Each used a distinct harmless file marker as the command-injection detector.
All four CGI connections closed without a response, the original parent HTTP
service remained healthy, the corresponding values in `/etc/config.xml`
remained unchanged, and no marker was created. This is evidence that these
writes did not cross the unauthenticated authorization boundary in the tested
firmware state.

The static `diagtest -m ping -d %s` construction remains a post-authentication
data-flow review target, but current dynamic evidence does **not** establish
pre-authentication reachability, command injection, or unauthenticated RCE.

## Reproduction assets

- `scripts/ex2800_local_probe.sh`
- `scripts/ex2800_start_telnet_poc.py`
- `scripts/ex2800_http_dos_poc.py`
- `scripts/ex2800_telnet_auth_bypass_probe.py`
- `scripts/ex2800_auth_bypass_matrix.py`
- `scripts/emulation_shims/ex2800_msg_shim.c`
- `scripts/emulation_shims/ex2800_mtd_ioctl_shim.c`
