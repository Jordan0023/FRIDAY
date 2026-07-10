# Firmware Audit: OpenWrt WAVLINK WL-WN586X3B / openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn586x3b-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn586x3b-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_WAVLINK_WL-WN586X3B/openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn586x3b-squashfs-sysupgrade.bin
- SHA-256: `bcff85f3e1fec74b171df3efeb70277a6c70e998d97ba6d5459cb5cd491bb92e`
- Size: 9390358 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bcff85f3e1fec74b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bcff85f3e1fec74b/_openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn586x3b-squashfs-sysupgrade.bin.extracted/sysupgrade-wavlink_wl-wn586x3b/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
