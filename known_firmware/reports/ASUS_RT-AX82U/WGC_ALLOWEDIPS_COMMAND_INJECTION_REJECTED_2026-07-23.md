# Rejected RT-AX82U WireGuard `AllowedIPs` command-injection candidate

## Decision

The command-injection hypothesis is **rejected**. Firmware
`3.0.0.4.388_25101` accepts shell metacharacters in an imported WireGuard
`AllowedIPs` value, but the real startup path passes that value to `_eval` as a
single argument. It does not interpolate the value into a shell command.

Debugger-assisted execution of the exact `/sbin/rc` WireGuard function reached
the route helper and confirmed that its `system()` calls are limited to routes
read from the kernel route table. The attacker-controlled `aips` branch uses
`_eval`; no marker was created.

## Corrected source-to-sink analysis

1. `POST /upload_wgc_config.cgi` writes the uploaded profile to
   `/tmp/wgc_upload_config`.
2. The handler calls `read_wgc_config_file` from `libshared.so` at `0x64a1c`.
3. `AllowedIPs` is stored in the per-client `aips` NVRAM field.
4. The WireGuard startup path in `/sbin/rc` reads `aips`, separates entries on
   commas, and trims whitespace through function `0x700a8`.
5. Function `0x1a5dd0` does contain `system()` at `0x1a6014`, but that loop
   formats routes read from `ip route show table main`.
6. When the local token buffer contains a nonempty attacker-controlled
   `AllowedIPs` entry, the branch at `0x1a5fdc` jumps to `0x1a601c`.
7. The nonempty-entry path validates special default-route cases and constructs
   an `ip` argument vector passed to `_eval` at `0x1a60e8`, `0x1a6134`, or
   related call sites. Shell metacharacters remain inside one argument.

The earlier static review incorrectly conflated the kernel-route `system()`
loop with the subsequent attacker-controlled `aips` loop.

## Dynamic evidence

The exact firmware HTTP service was run in the internal-only
`asus-rtax82u-e2e` emulator. An authenticated multipart upload containing:

```text
AllowedIPs = 10.23.42.0/24;:>/tmp/friday-proof/wgc-rce-marker;#
```

returned HTTP 200 and produced:

```text
wgc1_aips=10.23.42.0/24;:>/tmp/friday-proof/wgc-rce-marker;#
wgc_upload_state=0
```

Executing a manually reconstructed shell command created an empty marker, but
that reconstruction was not representative of the real nonempty-`aips` branch
and is not vulnerability evidence.

The exact `/sbin/rc` function at `0x1a91e8` was subsequently invoked under
QEMU/GDB with WireGuard unit 3. Greenhouse lacked a VPN policy-table mapping, so
the debugger supplied table ID `200` at the real helper call at `0x1a9820`.
The helper:

- read `wgc3_aips` and returned the complete malicious string;
- reached `system()` for two existing kernel routes;
- branched to the `_eval` path for the malicious nonempty entry; and
- returned without creating `/tmp/friday-proof/wgc-rce-marker`.

## Authentication boundary

A direct cookie-free multipart request was sent to a fresh WireGuard unit 4.
The HTTP service closed the connection and created no `wgc4_*` NVRAM state.
The importer is therefore not directly unauthenticated.

The conditional no-login chain was separately reproduced:

1. The lab guest was placed in the modeled post-reboot state with retained
   `ifttt_stoken` and a generation uptime greater than current uptime.
2. A cookie-free `get_IFTTTtoken.cgi` request with the IFTTT user agent returned
   `error_status=0` and a 31-byte administrator-equivalent token.
3. No administrator username, password, or login request was supplied.
4. That recovered token was immediately used on WireGuard unit 3.
5. The exact HTTP importer stored the injection string in `wgc3_aips`.

This confirms a conditional no-administrator-credentials path to the WireGuard
importer. It does not establish command injection, does not make
`upload_wgc_config.cgi` itself unauthenticated, and the IFTTT stage remains
public prior art (CVE-2022-35401).

## Final classification

- Direct unauthenticated importer: rejected by cookie-free control.
- Conditional no-login access to importer: confirmed through the known IFTTT
  weakness.
- WireGuard `AllowedIPs` command injection: rejected.
- RCE or zero-day claim from this path: not supported.

## Reproducer

The inert profile is:

```text
known_firmware/reports/ASUS_RT-AX82U/pocs/wgc_command_injection_test.conf
```

It attempts to write only an empty file below `/tmp/friday-proof`. The real
WireGuard route path did not interpret that string through a shell.
