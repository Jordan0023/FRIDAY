# Private security disclosure draft: NETGEAR EX2800

Do not publish before vendor coordination.

## Product and firmware

- Product: NETGEAR EX2800 WiFi Range Extender
- Tested firmware: `EX2800-V1.0.1.84.zip`
- SHA-256: `8d9a63c1224b5d8137833b861e9d0ba44a1202a892d927f942cf1e740cf02163`
- Test boundary: isolated Docker container with `--network none`

## Summary

The original firmware `mini_httpd` accepts an unauthenticated request for
`/start_telnet`. Before returning an HTTP redirect it writes an `inetd` rule
that runs the original BusyBox `telnetd` as root, writes `/var/telnetd`, and
attempts to restart `inetd`.

The original `inetd`, `telnetd`, and `/bin/login` accept the password shipped
in the firmware for the root account: `root`. This is an authentication-exempt
HTTP action followed by a fixed firmware credential, not a strictly
passwordless RCE.

The extracted account file contains a commented root entry using `/bin/bash`
before an active root entry using `/bin/sh`. Component emulation selects
`/bin/bash`, which the image does not ship. A disposable `/bin/bash` wrapper
confirmed that the resulting session runs as UID 0, but the unmodified
extracted root terminates after successful password authentication. Physical
device or faithful MT7628 full-system validation is still required.

## Reproduction evidence

Unauthenticated HTTP action:

```text
service_ready=true
start_telnet=302
telnet_enable_marker_created=true
telnet_inetd_rule_installed=true
telnet_port_reachable_after_root_inetd=true
```

Conditional UID-0 session:

```text
root_session=true
harmless_command_executed=true
Uid:    0       0       0       0
```

Unmodified-root control:

```text
login: cannot run /bin/bash: No such file or directory
root_session=false
harmless_command_executed=false
```

Expanded passwordless and Telnet environment matrix:

```text
authentication_bypass_reproduced=false
telnet_service_survived_matrix=true
```

HTTP connection exhaustion:

```text
connections_16_exhausted=true
connections_16_recovered=true
connections_32_exhausted=true
connections_32_recovered=true
connections_64_exhausted=true
connections_64_recovered=true
connections_96_exhausted=true
connections_96_recovered=true
connections_128_exhausted=true
connections_128_recovered=true
first_bounded_exhaustion=16
persistent_dos_reproduced=false
```

This is transient connection starvation while incomplete connections remain
open, not a process crash or persistent DoS.

## Cross-version evidence

Local firmware packages compared:

- `EX5000_EX2800-V1.0.1.64.zip`
- `EX2800-V1.0.1.82.zip`
- `EX2800-V1.0.1.84.zip`

All three contain identical `/etc/passwd` and `/etc/shadow` files. All three
`mini_httpd` binaries contain `start_telnet`, the root `inetd` Telnet rule, and
the `/var/telnetd` action. Firmware 1.0.1.82 changed the web server and
login/password-reset assets associated with the CVE-2026-0407 fix, but did not
remove these Telnet strings.

No official EX2800 1.0.1.80 package was located; the official history available
locally and publicly jumps from earlier releases such as 1.0.1.64/1.0.1.74 to
1.0.1.82.

## Requested vendor actions

1. Confirm whether `/start_telnet` is intended to be reachable without web
   authentication.
2. Confirm production runtime handling of the duplicate/commented root records
   and the configured login shell.
3. Remove or authenticate the Telnet-enabling handler and eliminate the shipped
   root password.
4. Review incomplete-request connection limits and timeouts.
5. Provide a coordinated disclosure identifier and remediation timeline.

## Private reproduction assets

- `scripts/ex2800_local_probe.sh`
- `scripts/ex2800_start_telnet_poc.py`
- `scripts/ex2800_telnet_auth_bypass_probe.py`
- `scripts/ex2800_auth_bypass_matrix.py`
- `scripts/ex2800_http_dos_poc.py`
- `scripts/emulation_shims/ex2800_msg_shim.c`

## Limitations

- No external device or network was tested.
- No physical EX2800 was available.
- QEMU in the test environment has no MT7628 machine model, so the vendor
  kernel cannot be faithfully full-system booted.
- Strictly unauthenticated UID-0 RCE was not reproduced.
- Novelty and zero-day status are not confirmed.
