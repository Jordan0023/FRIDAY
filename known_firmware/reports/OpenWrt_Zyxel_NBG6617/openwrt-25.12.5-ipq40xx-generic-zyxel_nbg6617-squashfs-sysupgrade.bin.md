# Firmware Audit: OpenWrt Zyxel NBG6617 / openwrt-25.12.5-ipq40xx-generic-zyxel_nbg6617-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-zyxel_nbg6617-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_NBG6617/openwrt-25.12.5-ipq40xx-generic-zyxel_nbg6617-squashfs-sysupgrade.bin
- SHA-256: `fab26ad53eeff528f0d9a38d3b9ae5bd87ad04ace605453d41e8821dd6dad0f0`
- Size: 8356386 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fab26ad53eeff528 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fab26ad53eeff528/_openwrt-25.12.5-ipq40xx-generic-zyxel_nbg6617-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_nbg6617/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
