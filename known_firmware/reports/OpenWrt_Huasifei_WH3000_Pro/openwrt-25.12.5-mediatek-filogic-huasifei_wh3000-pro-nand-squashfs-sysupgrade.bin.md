# Firmware Audit: OpenWrt Huasifei WH3000 Pro / openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-nand-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-nand-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Huasifei_WH3000_Pro/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-nand-squashfs-sysupgrade.bin
- SHA-256: `62262b79ce68a69a0ee7db5375111f81049cb3271b7313c25fbbe26f9e1ad1d3`
- Size: 9554208 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/62262b79ce68a69a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/62262b79ce68a69a/_openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-nand-squashfs-sysupgrade.bin.extracted/sysupgrade-huasifei_wh3000-pro-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
