#!/usr/bin/env bash
set -euo pipefail

root=${EX2800_EMULATION_ROOT:-/tmp/ex2800-telnet-root}
exec env PROOT_NO_SECCOMP=1 proot \
  -R "$root" \
  -b /dev/null:/dev/null \
  -b /dev/pts:/dev/pts \
  -b /dev/ptmx:/dev/ptmx \
  -b /dev/tty:/dev/tty \
  -q /usr/bin/qemu-mipsel-static \
  /usr/sbin/telnetd telnetd
