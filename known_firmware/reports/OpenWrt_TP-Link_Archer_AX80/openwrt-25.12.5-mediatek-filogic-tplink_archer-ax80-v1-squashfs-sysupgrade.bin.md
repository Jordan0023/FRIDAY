# Firmware Audit: OpenWrt TP-Link Archer AX80 / openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_Archer_AX80/openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-squashfs-sysupgrade.bin
- SHA-256: `e8928d4b6dbcc4371e12382238146c1f5b4b82de9a9bda2c421a993a9323d123`
- Size: 10045722 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e8928d4b6dbcc437 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e8928d4b6dbcc437/_openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_archer-ax80-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
