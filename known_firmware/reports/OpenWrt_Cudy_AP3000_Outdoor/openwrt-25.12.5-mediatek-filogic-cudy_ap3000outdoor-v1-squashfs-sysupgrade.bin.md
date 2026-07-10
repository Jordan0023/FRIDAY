# Firmware Audit: OpenWrt Cudy AP3000 Outdoor / openwrt-25.12.5-mediatek-filogic-cudy_ap3000outdoor-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_ap3000outdoor-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_AP3000_Outdoor/openwrt-25.12.5-mediatek-filogic-cudy_ap3000outdoor-v1-squashfs-sysupgrade.bin
- SHA-256: `30ef3337c6f5c8a49e27c9d7dee0ec259f7eb1a07bd5e645dbce25a573f4e680`
- Size: 9390368 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/30ef3337c6f5c8a4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/30ef3337c6f5c8a4/_openwrt-25.12.5-mediatek-filogic-cudy_ap3000outdoor-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_ap3000outdoor-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
