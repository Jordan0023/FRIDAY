# Firmware Audit: OpenWrt Keenetic KN-3911 / openwrt-25.12.5-mediatek-filogic-keenetic_kn-3911-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-keenetic_kn-3911-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KN-3911/openwrt-25.12.5-mediatek-filogic-keenetic_kn-3911-squashfs-sysupgrade.bin
- SHA-256: `2aaaf17eca8d3cc9a66abdfbb62cfa867216e8b612e309adb85e440bebc7298e`
- Size: 9441552 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2aaaf17eca8d3cc9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2aaaf17eca8d3cc9/_openwrt-25.12.5-mediatek-filogic-keenetic_kn-3911-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kn-3911/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
