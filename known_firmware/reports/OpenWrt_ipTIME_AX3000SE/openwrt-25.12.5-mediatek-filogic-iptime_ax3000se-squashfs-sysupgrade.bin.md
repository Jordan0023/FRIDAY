# Firmware Audit: OpenWrt ipTIME AX3000SE / openwrt-25.12.5-mediatek-filogic-iptime_ax3000se-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-iptime_ax3000se-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_AX3000SE/openwrt-25.12.5-mediatek-filogic-iptime_ax3000se-squashfs-sysupgrade.bin
- SHA-256: `f02e0985a2d0d2ba5166d344adcaacf351fe1806e896a12beb8a2b9dfc08ee2f`
- Size: 9390383 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f02e0985a2d0d2ba exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f02e0985a2d0d2ba/_openwrt-25.12.5-mediatek-filogic-iptime_ax3000se-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_ax3000se/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
