# Firmware Audit: OpenWrt ipTIME AX3000Q / openwrt-25.12.5-mediatek-filogic-iptime_ax3000q-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-iptime_ax3000q-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_AX3000Q/openwrt-25.12.5-mediatek-filogic-iptime_ax3000q-squashfs-sysupgrade.bin
- SHA-256: `ae2a7ca2124199c952a2698374087a1e3e7eb47238c078f1f49289201fce639b`
- Size: 9390381 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ae2a7ca2124199c9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ae2a7ca2124199c9/_openwrt-25.12.5-mediatek-filogic-iptime_ax3000q-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_ax3000q/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
