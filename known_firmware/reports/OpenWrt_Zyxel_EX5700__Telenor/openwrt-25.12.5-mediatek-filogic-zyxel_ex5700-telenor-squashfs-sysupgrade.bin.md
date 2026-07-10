# Firmware Audit: OpenWrt Zyxel EX5700 (Telenor) / openwrt-25.12.5-mediatek-filogic-zyxel_ex5700-telenor-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zyxel_ex5700-telenor-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_EX5700__Telenor/openwrt-25.12.5-mediatek-filogic-zyxel_ex5700-telenor-squashfs-sysupgrade.bin
- SHA-256: `fed6749a4a82792054802e5c2d421a09baad771b5255f9fa12283fcebea1eccd`
- Size: 10629400 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fed6749a4a827920 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fed6749a4a827920/_openwrt-25.12.5-mediatek-filogic-zyxel_ex5700-telenor-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_ex5700-telenor/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
