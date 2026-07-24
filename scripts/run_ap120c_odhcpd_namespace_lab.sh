#!/bin/sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
cd "$ROOT"

cleanup()
{
	python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py stop \
		>/dev/null 2>&1 || true
}
trap cleanup EXIT INT TERM

python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py build
scripts/setup_ap120c_ipv6_tap.sh
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py start-tap
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py wait

if ! rg -q 'FRIDAY_AP120C_ODHCPD_TAP_READY=1' \
	known_firmware/emulation/OpenWrt_ALFA_AP120C-AC/full-system-stock-init-lab/serial.log
then
	echo "AP120C odhcpd TAP readiness marker absent" >&2
	exit 1
fi

ping -6 -c 2 -W 2 fd42:120c::1

LOG=known_firmware/emulation/OpenWrt_ALFA_AP120C-AC/full-system-stock-init-lab/odhcpd-ipv6-probe.log
if python3 scripts/probe_openwrt_odhcpd_security.py \
	--interface friday-ap120c6 >"$LOG" 2>&1
then
	cat "$LOG"
else
	cat "$LOG"
	exit 1
fi
