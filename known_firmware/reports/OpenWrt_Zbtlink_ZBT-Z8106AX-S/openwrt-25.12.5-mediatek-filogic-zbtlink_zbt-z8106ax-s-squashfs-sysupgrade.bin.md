# Firmware Audit: OpenWrt Zbtlink ZBT-Z8106AX-S / openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-s-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-s-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zbtlink_ZBT-Z8106AX-S/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-s-squashfs-sysupgrade.bin
- SHA-256: `65a035cd8496171a87928290cd2e44f3ac8645cb0f9e169a263e8b059ab23945`
- Size: 9595185 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/65a035cd8496171a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/65a035cd8496171a/_openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-s-squashfs-sysupgrade.bin.extracted/sysupgrade-zbtlink_zbt-z8106ax-s/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
