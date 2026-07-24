#!/bin/sh
# Read-only GT-BE98 Pro wl_server_socket activation evidence collector.
# Run locally on an owned router. It does not start, stop, or probe services.

set -u

OUT="/tmp/gtbe98-activation-evidence"
ARCHIVE="/tmp/gtbe98-activation-evidence.tar.gz"

mkdir -p "$OUT"

date -u > "$OUT/collected-at.txt" 2>&1
uname -a > "$OUT/uname.txt" 2>&1

{
	printf 'productid='
	nvram get productid 2>/dev/null
	printf 'odmpid='
	nvram get odmpid 2>/dev/null
	printf 'firmver='
	nvram get firmver 2>/dev/null
	printf 'buildno='
	nvram get buildno 2>/dev/null
	printf 'extendno='
	nvram get extendno 2>/dev/null
	printf 'lan_ifname='
	nvram get lan_ifname 2>/dev/null
	printf 'wan0_ifname='
	nvram get wan0_ifname 2>/dev/null
	printf 'wan_ifname='
	nvram get wan_ifname 2>/dev/null
	printf 'sw_mode='
	nvram get sw_mode 2>/dev/null
	printf 'x_Setting='
	nvram get x_Setting 2>/dev/null
	printf 'rc_support='
	nvram get rc_support 2>/dev/null
} > "$OUT/nonsecret-nvram.txt"

ps w > "$OUT/processes.txt" 2>&1

if command -v ss >/dev/null 2>&1; then
	ss -lntup > "$OUT/listeners.txt" 2>&1
elif command -v netstat >/dev/null 2>&1; then
	netstat -lntup > "$OUT/listeners.txt" 2>&1
fi

ip -4 address show > "$OUT/ip-addresses.txt" 2>&1
ip -4 route show > "$OUT/ip-routes.txt" 2>&1
iptables-save > "$OUT/iptables.txt" 2>&1
dmesg > "$OUT/dmesg.txt" 2>&1

{
	pidof wl_server_socket 2>/dev/null
	grep -i 'wl_server_socket\|/tmp/RWL' "$OUT/processes.txt" 2>/dev/null
	grep -i ':8000' "$OUT/listeners.txt" 2>/dev/null
	grep -i 'wl_server_socket\|/tmp/RWL' "$OUT/dmesg.txt" 2>/dev/null
} > "$OUT/activation-summary.txt"

tar -czf "$ARCHIVE" -C /tmp gtbe98-activation-evidence
printf '%s\n' "$ARCHIVE"
