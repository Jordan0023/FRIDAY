# RAX9/RAX5-family V1.0.9.44 negative control

Date: 2026-07-24 UTC

The production V1.0.9.44 root filesystem was booted with
`qemu-system-mipsel` and the same unauthenticated request used against
RAX9 V1.0.3.32 was sent to `/pwd_reset/reset_pwd.plua`.

The tested image was independently matched to the image inside NETGEAR's
official `RAX9_V1.0.9.44_1.zip` download. Both image SHA-256 values are
`e603430bf8fa9d8d813cd9703a9bf4a00b5e90c0a36be4c7acb7be20425abc72`.

Result:

- HTTP reached the production `lighttpd`/CGI stack without authentication.
- The serial trace logs: `accessCtrlDev is not contained in password reset flow.`
- `/tmp/rax9-preauth-rce-marker` remained absent.
- The test harness emitted:
  `FRIDAY_RAX9_V10944_FIXED=confirmed marker=absent`.

The runtime trace is in `serial.log`, with readiness at line 228 and the
dispatcher rejection at line 229. The guest was stopped after the test.

Source comparison:

- V1.0.3.32 `reset_pwd.plua` SHA-256:
  `bd62b134347c8d8844bd4e69c1a72bc185c100d5a560abbd68bc1af4fa9e01f5`
- V1.0.9.44 `reset_pwd.plua` SHA-256:
  `76184c2728fff0533627cfed68787f72e8c0abccde8533f85af9d4c1b64b9549`
- V1.0.9.44 adds an allowlist containing only `checkSN`, `checkAnswer`, and
  `setPassword2`.
- `accessCtrlDev.lua` and `commonFunc/fork.lua` are byte-identical across
  the two versions. The effective fix is the new dispatcher allowlist.

Reproduction:

```sh
python3 scripts/emulate_rax9_pwdreset_full_system.py build \
  --rootfs /tmp/rax9-10944/root \
  --lab-dir known_firmware/emulation/RAX9/full-system-web-lab-v10944
python3 scripts/emulate_rax9_pwdreset_full_system.py start \
  --rootfs /tmp/rax9-10944/root \
  --lab-dir known_firmware/emulation/RAX9/full-system-web-lab-v10944 \
  --port 35919
python3 scripts/emulate_rax9_pwdreset_full_system.py verify-fixed \
  --rootfs /tmp/rax9-10944/root \
  --lab-dir known_firmware/emulation/RAX9/full-system-web-lab-v10944 \
  --port 35919
python3 scripts/emulate_rax9_pwdreset_full_system.py stop \
  --lab-dir known_firmware/emulation/RAX9/full-system-web-lab-v10944
```
