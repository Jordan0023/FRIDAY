# RAX9 pre-authentication password-reset dispatcher command injection

## Status

- Product/firmware analyzed: NETGEAR RAX9, V1.0.3.32 filesystem
- Reachability: adjacent network/LAN over the normal web service
- Authentication: not required by the lighttpd route
- Impact: confirmed arbitrary root shell command injection / RCE
- Dynamic evidence: genuine lighttpd, CGILua, dispatcher, validator, handler,
  `/bin/sh`, and `touch` executed natively in full-system MIPS emulation
- Physical-device execution: pending
- Zero-day classification: unresolved; do not claim

## Root cause and chain

The normal lighttpd configuration excludes the entire `/pwd_reset` prefix from
HTTP Basic authentication.

`/www/pwd_reset/reset_pwd.plua` accepts a caller-controlled `function` member,
constructs both a filesystem path and Lua module name from it, and calls the
export named `<function>_handler`. There is no allowlist restricting dispatch
to `checkSN`, `checkAnswer`, or password-recovery handlers. The dispatcher
therefore exposes all matching modules under
`/usr/lib/lua/webPostHandler/` without HTTP authentication.

Selecting `accessCtrlDev` reaches `accessCtrlDev_handler`. Its validator
callback returns `true` for `devName` after the ordinary hostname validator
rejects the value. The accepted value is concatenated into:

`/bin/pudil -m <mac> 9 <devName>`

`commonFunc.fork.fork_exec` passes that complete string to:

`nixio.exec("/bin/sh", "-c", command)`

This yields shell metacharacter injection as root.

## Full-system confirmation

The clean V1.0.3.32 SquashFS was repackaged as an initramfs and booted under
`qemu-system-mipsel` with a Debian 6.1.0-50-4kc-malta kernel. Only a minimal
init, lab-only lighttpd configuration, and matching PCnet/MII kernel modules
were added. The vulnerable dispatcher, handler, validator, shell, and command
utilities were unchanged firmware files.

The isolated lab accepted this fixed marker value without HTTP authentication:

`FRIDAY;touch /tmp/rax9-preauth-rce-marker;#`

The genuine endpoint returned HTTP 200:

`{"status":"success","message":"Finish accessCtrlDev"}`

The guest serial log recorded the rejected ordinary hostname validation,
followed by acceptance through the handler override:

`devName=FRIDAY;touch /tmp/rax9-preauth-rce-marker;# validate error false`

The unmodified `commonFunc.fork.fork_exec` then invoked the genuine firmware
`/bin/sh -c` path. Guest PID 1 observed:

`FRIDAY_RAX9_PREAUTH_RCE_MARKER=present`

and:

`-rw-r--r-- 1 0 0 0 Jul 24 02:36 /tmp/rax9-preauth-rce-marker`

This confirms native command execution as UID 0.

The same unauthenticated dispatcher can also select `reboot` and
`restoreDefault`, whose handlers invoke reboot and factory-reset commands
without inspecting input. Those destructive paths were not dynamically
triggered.

## Prior-art disposition

Public searches found multiple older NETGEAR pre-authentication command
injection advisories affecting related WiFi 6 products, including
CVE-2021-45616 / PSV-2020-0576 and PSV-2021-0076. Public vendor/CVE descriptions
do not identify the endpoint or parameter, and RAX9 is not named in the located
affected-product lists.

Until the historical fixes are diffed or NETGEAR confirms root-cause identity,
this must not be represented as a zero-day. It may be an unpatched product
exposure or recurrence of an already-public vulnerability class/root cause.

## Safe reproducer

`scripts/reproduce_rax9_pwd_reset_preauth_rce.py`

The reproducer accepts only loopback/private/link-local targets, requires an
explicit ownership acknowledgement, and has a fixed `/tmp` marker command.

## Next confirmation steps

1. Reconfirm the fixed marker on a factory-reset physical RAX9 over an isolated
   LAN.
2. Diff the dispatcher and `accessCtrlDev.lua` against firmware immediately
   before and after the fixes listed in PSV-2020-0576 and PSV-2021-0076.
3. If the exact chain is not covered by prior art, submit privately to NETGEAR
   with the physical-device trace and request a PSV/CVE determination.

## Full-system evidence

- `known_firmware/emulation/RAX9/full-system-web-lab/serial.log`
- `known_firmware/emulation/RAX9/full-system-web-lab/rax9-web-rootfs.cpio.gz`
- `scripts/emulate_rax9_pwdreset_full_system.py`
- Production `fork.lua` SHA-256:
  `4d7a827dd6a229fe82c97bce57a96b6e2e22f9479ca3742e147ee5274c9d1f7b`
- Serial log SHA-256:
  `322028e1258cf5aeb84baf32b9ab8f9bb1d951061ac6a8edcbf7042409313905`
