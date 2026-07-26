# EX6110 physical-validation handoff

Prepared: 2026-07-24  
Target firmware: NETGEAR EX6110 V1.0.1.84

## Resume objective

Physically validate whether the configured-state `mini_httpd` route named
`start_telnet` changes TCP/23 from closed to reachable on an owned EX6110.
The included validator deliberately stops at port exposure: it does not log
in, execute commands, or attempt to obtain a shell.

## Important current assessment

- Static analysis found `start_telnet` handled directly by `mini_httpd`,
  separately from the `/var/unconfig`-gated `webupg` issue.
- Isolated emulation confirmed that the route replaces runtime
  `/etc/inetd.conf`, restarts `inetd`, and exposes Telnet.
- The runtime change is tmpfs-backed and should disappear after reboot.
- The original Telnet login accepted the shipped root password in emulation
  but attempted missing `/bin/bash`; stock-device command execution was not
  confirmed.
- Physical validation should therefore measure only whether TCP/23 becomes
  reachable and then reboot the device.

## Physical device and network details observed

The first tested address, `10.134.1.1`, was not the extender. It returned:

```text
HTTP/1.0 307 Temporary Redirect
Location: /ui/local/ustatic/http_blocking
```

and returned an HTTPS 404. That path is associated with a Linksys management
interface, so those results do not test the EX6110.

The probable EX6110 address is `10.134.1.122`. Forcing HTTPS produced:

```text
OSError: [Errno 65] No route to host
```

The browser can open the interface, so it most likely uses ordinary HTTP on
TCP/80. The next test should use HTTP, not forced HTTPS.

## Exact next command

From the extracted bundle directory on a computer connected to the extender's
management network:

```bash
python3 scripts/ex2800_physical_start_telnet_validator.py \
  --target 10.134.1.122 \
  --transport http \
  --acknowledge I_OWN_THIS_DEVICE_AND_WILL_REBOOT_IT
```

Before testing, explicitly open `http://10.134.1.122/` and verify that it is
the NETGEAR EX6110 interface. TCP/23 should be closed before the test.

Successful confirmation is:

```text
telnet_reachable_before=false
telnet_reachable_after=true
start_telnet_effect_confirmed=true
```

If it remains false, preserve the complete validator output, confirm the
firmware version in the UI, and note whether the device is in extender or
access-point mode.

## Recovery

Reboot the extender after every trigger attempt, including ambiguous results.
Do not expose its management or Telnet ports to the internet.

## Bundle contents

- `firmware/EX6110-V1.0.1.84.zip`: official firmware package.
- `scripts/ex2800_physical_start_telnet_validator.py`: bounded validator.
- `reports/UNAUTH_START_TELNET_CANDIDATE_2026-07-23.md`: detailed research.
- `reports/CONFIGURED_STATE_ALTERNATE_PATH_AUDIT_2026-07-24.md`: marker and
  configured-state audit.
- `TRANSCRIPT_SUMMARY.md`: this handoff document copied under a descriptive
  name.
- `SHA256SUMS`: integrity hashes.

## Resuming in Codex

Open a terminal in the extracted bundle directory and start Codex there. Use:

```text
Read TRANSCRIPT_SUMMARY.md and the two files under reports/. Continue the
owned-device EX6110 physical validation from the documented next command.
Treat port exposure as the validation endpoint; do not attempt shell access.
```

The native chat transcript is not exportable from the workspace filesystem,
so this document preserves the material decisions and observed outputs needed
to resume.
