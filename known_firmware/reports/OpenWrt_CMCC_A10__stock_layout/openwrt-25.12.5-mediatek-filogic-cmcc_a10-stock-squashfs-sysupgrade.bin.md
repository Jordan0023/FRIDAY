# Firmware Audit: OpenWrt CMCC A10 (stock layout) / openwrt-25.12.5-mediatek-filogic-cmcc_a10-stock-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cmcc_a10-stock-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_CMCC_A10__stock_layout/openwrt-25.12.5-mediatek-filogic-cmcc_a10-stock-squashfs-sysupgrade.bin
- SHA-256: `65291ba6571149a15c26bae26a4d5cf4dcf46d6e9f21798e3c3af626f24893fa`
- Size: 9390381 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/65291ba6571149a1 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/65291ba6571149a1/_openwrt-25.12.5-mediatek-filogic-cmcc_a10-stock-squashfs-sysupgrade.bin.extracted/sysupgrade-cmcc_a10-stock/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
