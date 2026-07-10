# Firmware Audit: OpenWrt TP-Link FR365 / openwrt-25.12.5-mediatek-filogic-tplink_fr365-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_fr365-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_FR365/openwrt-25.12.5-mediatek-filogic-tplink_fr365-v1-squashfs-sysupgrade.bin
- SHA-256: `a4c3983d05cf22937979c8d0612f647e07222aba8486e6ca054f36a67c19f22e`
- Size: 9564430 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a4c3983d05cf2293 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a4c3983d05cf2293/_openwrt-25.12.5-mediatek-filogic-tplink_fr365-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_fr365-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
