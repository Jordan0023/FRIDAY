# Firmware Audit: OpenWrt Cudy M3000 / openwrt-25.12.5-mediatek-filogic-cudy_m3000-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_m3000-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_M3000/openwrt-25.12.5-mediatek-filogic-cudy_m3000-v1-squashfs-sysupgrade.bin
- SHA-256: `08946ac1be99936657de31f24014a7f226d1ce9e70643b523efed8eb5e4c288e`
- Size: 9390352 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/08946ac1be999366 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/08946ac1be999366/_openwrt-25.12.5-mediatek-filogic-cudy_m3000-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_m3000-v1/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
