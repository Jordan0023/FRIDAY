# Firmware Audit: OpenWrt Cudy WBR3000UAX / openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_WBR3000UAX/openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-squashfs-sysupgrade.bin
- SHA-256: `e6df8d1eea7b86fc41bc3480a4e27397530e1a7b153b8d2bccb1856204829ca0`
- Size: 9554203 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e6df8d1eea7b86fc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e6df8d1eea7b86fc/_openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_wbr3000uax-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
