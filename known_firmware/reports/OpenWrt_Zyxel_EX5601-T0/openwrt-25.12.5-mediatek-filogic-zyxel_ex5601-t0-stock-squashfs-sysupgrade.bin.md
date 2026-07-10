# Firmware Audit: OpenWrt Zyxel EX5601-T0 / openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-stock-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-stock-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_EX5601-T0/openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-stock-squashfs-sysupgrade.bin
- SHA-256: `9c085b4c49427aafb7829f94bbafb8560df2f6810b2c13f83f334f3931119399`
- Size: 10045722 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9c085b4c49427aaf exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9c085b4c49427aaf/_openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-stock-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_ex5601-t0-stock/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
