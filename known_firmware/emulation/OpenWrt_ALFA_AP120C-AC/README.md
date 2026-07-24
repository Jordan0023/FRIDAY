# ALFA AP120C-AC full-system analysis lab

This lab boots the exact OpenWrt 25.12.5 AP120C-AC user space under a complete
ARM Linux/QEMU system and exposes its genuine services through loopback-only
forwards.

## Fidelity

Preserved:

- the complete AP120C-AC OpenWrt root filesystem;
- `/sbin/procd` and the stock preinit/rc.d sequence;
- ubusd, rpcd, netifd, odhcpd, uhttpd/LuCI, Dropbear, hostapd,
  wpa_supplicant, and dnsmasq binaries and libraries;
- service configuration and privilege/jail behavior;
- 32-bit ARM EABI5 execution.

Substituted because upstream QEMU has no IPQ4019/IPQ40xx machine:

- generic ARMv7 `virt` board and Debian ARMMP boot kernel;
- VirtIO Ethernet in place of the IPQ4019 ESS/QCA8337 network hardware;
- initramfs/tmpfs in place of NAND/UBI overlay storage;
- no ath10k radio or firmware/driver transport.

The init wrapper lets the stock boot run first. QEMU has no mac80211 PHY, so
after 50 seconds it terminates the stalled radio-discovery `ucode` process and
starts the later stock services. If the stock dnsmasq init script cannot bind
without the real DSA topology, the wrapper starts the image's exact dnsmasq
binary on the emulated LAN with no upstream resolver.

This is firmware- and service-faithful, but not hardware-faithful enough for
ath10k/mac80211, switch-driver, MTD/UBI, or kernel-device-driver findings.

## Isolation

QEMU user networking uses `restrict=on`. All host forwards bind to
`127.0.0.1`; the guest is not bridged onto the host LAN.

| Service | Host endpoint | Guest endpoint |
|---|---|---|
| LuCI/uhttpd | `127.0.0.1:28085` | `10.0.2.15:80` |
| Dropbear | `127.0.0.1:22223` | `10.0.2.15:22` |
| DNS UDP/TCP | `127.0.0.1:25356` | `10.0.2.15:53` |

## Usage

```sh
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py build
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py start
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py wait
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py status
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py stop
```

`run` combines build, start, and wait. Generated artifacts are stored in
`full-system-stock-init-lab/`:

- `ap120c-stock-rootfs.cpio.gz`
- `serial.log`
- `qemu.log`
- `qemu.pid`

The current environment uses:

- `/tmp/qemu-system-arm-local/usr/bin/qemu-system-arm`
- `/tmp/ad7200-armmp-vmlinuz`
- `/tmp/ad7200-kmods/lib/modules`

The launcher fails closed if any prerequisite is absent.

## Isolated DHCPv6/RA lab

The strongest network-state test runs QEMU and a host-side DHCPv6 client
inside an unprivileged user/network namespace. A TAP connects only those two
endpoints; it is not bridged or routed to the host or an external network.

```sh
unshare -Urn --map-root-user \
  scripts/run_ap120c_odhcpd_namespace_lab.sh
```

The runner builds the guest, creates `friday-ap120c6`, assigns
`fd42:120c::2/64` to the client side, identifies the guest TAP NIC by its fixed
MAC address, configures `fd42:120c::1/64`, enables the genuine odhcpd as a
DHCPv6/RA server, verifies ICMPv6, and runs the bounded DHCPv6 corpus.

Evidence:

- `full-system-stock-init-lab/odhcpd-ipv6-probe.log`
- `full-system-stock-init-lab/serial.log`

The exact firmware package is
`odhcpd-ipv6only 2026.06.29~5d7be43f-r1`; upstream commit
`5d7be43f8b9dec0eb47e245cfab81108bb131273` was independently resolved.

## Virtual-radio management-frame lab

Run:

```sh
python3 scripts/emulate_openwrt_alfa_ap120c_full_system.py run-hwsim
```

This mode boots the exact 32-bit AP120C-AC userspace under a local ARM64
kernel with `CONFIG_COMPAT` and two `mac80211_hwsim` radios. Before stock
netifd claims the radios, the shipped wpad starts an AP and station,
establishes a valid association, and sends ten bounded malformed management
frame cases plus a 128-frame burst from an in-guest monitor interface.

The run is accepted only when every case is followed by hostapd liveness and
a fresh successful station association. Success markers are:

```text
FRIDAY_AP120C_HWSIM_TEST_PASS=1
FRIDAY_AP120C_EARLY_HWSIM_RESULT=0
```

## Validation

The confirmed boot markers are:

```text
FRIDAY_AP120C_FULL_SYSTEM_KERNEL_BOOT=1
FRIDAY_AP120C_HANDOFF_TO_STOCK_INIT=1
FRIDAY_AP120C_UHTTPD_READY=1
FRIDAY_AP120C_DNSMASQ_READY=1
FRIDAY_AP120C_FULL_SYSTEM_READY=1
```

Validated processes include `procd`, `ubusd`, `rpcd`, `netifd`, `odhcpd`,
`uhttpd`, `dropbear`, `hostapd`, `wpa_supplicant`, and `dnsmasq`.

The existing bounded HTTP and DNS corpora can be run against the lab:

```sh
python3 scripts/probe_openwrt_uhttpd_security.py \
  --url http://127.0.0.1:28085

python3 scripts/probe_openwrt_dnsmasq_security.py \
  --host 127.0.0.1 --port 25356 --health-transport any
```

The factory-unconfigured blank-password behavior can be validated end to end
with a disposable SSH key and harmless in-guest marker:

```sh
python3 scripts/probe_ap120c_blank_password_rce.py
```

The validator also sets a temporary root password and verifies that a blank
login is then denied. Restart the initramfs guest afterward to discard all
changes. OpenWrt documents the initial blank-password login as intended
first-boot behavior; this test is a configuration-state control, not a claimed
zero-day.
