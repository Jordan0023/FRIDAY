# Firmware Audit: OpenWrt Netgear WAC510 / openwrt-25.12.5-ipq40xx-generic-netgear_wac510-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-netgear_wac510-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Netgear_WAC510/openwrt-25.12.5-ipq40xx-generic-netgear_wac510-squashfs-sysupgrade.bin
- SHA-256: `94a897272d6929c4353aeb0652b2a7226b5fbcbeec81a7fd1f770ed1839db0df`
- Size: 9503269 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/94a897272d6929c4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/94a897272d6929c4/_openwrt-25.12.5-ipq40xx-generic-netgear_wac510-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_wac510/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
