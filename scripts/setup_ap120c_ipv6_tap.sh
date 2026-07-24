#!/bin/sh
set -eu

TAP=friday-ap120c6
OWNER="${SUDO_USER:-$(id -un)}"

if ip link show dev "$TAP" >/dev/null 2>&1; then
	ip link delete dev "$TAP"
fi
ip tuntap add dev "$TAP" mode tap user "$OWNER"
ip -6 addr add fd42:120c::2/64 dev "$TAP"
ip link set dev "$TAP" up
ip -brief address show dev "$TAP"
