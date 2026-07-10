# Firmware Audit: OpenWrt ALFA Network AP120C-AC / openwrt-25.12.5-ipq40xx-generic-alfa-network_ap120c-ac-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-alfa-network_ap120c-ac-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ALFA_Network_AP120C-AC/openwrt-25.12.5-ipq40xx-generic-alfa-network_ap120c-ac-squashfs-sysupgrade.bin
- SHA-256: `3a6dc689a2247c94aaade08ceb23f8668b38d55cc08b21518db22ea8acc7c02a`
- Size: 9534013 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a6dc689a2247c94 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3a6dc689a2247c94/_openwrt-25.12.5-ipq40xx-generic-alfa-network_ap120c-ac-squashfs-sysupgrade.bin.extracted/sysupgrade-alfa-network_ap120c-ac/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
