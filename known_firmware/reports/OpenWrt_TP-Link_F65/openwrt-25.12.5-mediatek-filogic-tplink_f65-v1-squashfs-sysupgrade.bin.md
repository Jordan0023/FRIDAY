# Firmware Audit: OpenWrt TP-Link F65 / openwrt-25.12.5-mediatek-filogic-tplink_f65-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_f65-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_F65/openwrt-25.12.5-mediatek-filogic-tplink_f65-v1-squashfs-sysupgrade.bin
- SHA-256: `bb7b634f33abb76bacf107e789c3f93f4299131991774c28e4142797c8797a13`
- Size: 9390346 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bb7b634f33abb76b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bb7b634f33abb76b/_openwrt-25.12.5-mediatek-filogic-tplink_f65-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_f65-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
