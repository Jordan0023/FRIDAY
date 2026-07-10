# Firmware Audit: OpenWrt Zbtlink ZBT-Z8106AX-T / openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-t-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-t-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zbtlink_ZBT-Z8106AX-T/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-t-squashfs-sysupgrade.bin
- SHA-256: `038c6121e4e4010fe582926d2e8ed54961d6ce9a4f5e2d1d2786bd170daee018`
- Size: 9595185 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/038c6121e4e4010f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/038c6121e4e4010f/_openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8106ax-t-squashfs-sysupgrade.bin.extracted/sysupgrade-zbtlink_zbt-z8106ax-t/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
