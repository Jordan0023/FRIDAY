# Firmware Audit: OpenWrt ipTIME AX3000SM / openwrt-25.12.5-mediatek-filogic-iptime_ax3000sm-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-iptime_ax3000sm-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_AX3000SM/openwrt-25.12.5-mediatek-filogic-iptime_ax3000sm-squashfs-sysupgrade.bin
- SHA-256: `c412acd8fef2a5ba5bf4c65e5262a8791aaf75ec0cb1fb42d4525b81e7cfd22f`
- Size: 9390383 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c412acd8fef2a5ba exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c412acd8fef2a5ba/_openwrt-25.12.5-mediatek-filogic-iptime_ax3000sm-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_ax3000sm/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
