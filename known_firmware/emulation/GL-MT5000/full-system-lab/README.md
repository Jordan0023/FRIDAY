# MT5000 4.9.0 hybrid full-system lab

This lab boots the genuine GL-MT5000 4.9.0 AArch64 userspace under an official
OpenWrt `armvirt/64` kernel in QEMU `virt`, with separate virtio LAN and WAN
interfaces.

It is not a hardware-faithful MT7987 emulation. QEMU does not implement the
MT7987 SoC, and the shipped kernel lacks QEMU PL011/virtio support. The hybrid
design retains the genuine GL.iNet services, configuration, firewall scripts,
BusyBox `udhcpc`, and `odhcp6c`, while substituting only the kernel and network
drivers.

`lab-init` repairs `/sbin/ip`, which the extraction tool represented as a
`/dev/null` link, and supplies deterministic mappings:

- `eth0`: LAN, `192.168.8.1/24`
- `eth1`: WAN, DHCP/DHCPv6

The lab must use isolated QEMU networks. It is not intended for probing public
or third-party devices.

## Verified result (2026-07-24)

The hybrid boot was exercised with the genuine GL.iNet Nginx, `netifd`,
`fw3`, `udhcpc`, and `odhcp6c` binaries:

- Nginx listened on `0.0.0.0:80`, `0.0.0.0:443`, `[::]:80`, and `[::]:443`.
- The stock firewall attached `eth0` to `zone_lan_input` and `eth1` to
  `zone_wan_input`.
- A localhost-only QEMU forward through LAN returned HTTP 200 and 749 bytes.
- The equivalent forward through WAN timed out with no response.
- WAN input allowed DHCP renewal, ping, IGMP, and established/DNAT traffic,
  then entered `zone_wan_src_REJECT`; it did not permit TCP 80 or 443.
- Genuine `udhcpc` completed a DHCP exchange on the isolated WAN.
- Genuine `odhcp6c` remained running after IPv6 was re-enabled. No malformed
  DHCPv6 response was injected in this run.

These results confirm the default WAN firewall boundary in emulation. They do
not establish hardware fidelity, a WAN bypass, or WAN reachability of the
WebUI lockout behavior.
