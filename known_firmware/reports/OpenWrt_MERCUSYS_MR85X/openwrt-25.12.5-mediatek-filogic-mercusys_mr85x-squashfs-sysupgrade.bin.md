# Firmware Audit: OpenWrt MERCUSYS MR85X / openwrt-25.12.5-mediatek-filogic-mercusys_mr85x-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mercusys_mr85x-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MERCUSYS_MR85X/openwrt-25.12.5-mediatek-filogic-mercusys_mr85x-squashfs-sysupgrade.bin
- SHA-256: `fee53e4e04f1972d7f4a0b083d75ef8edcc9ce89cdc8f1f9d127d039579fd22c`
- Size: 9513228 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fee53e4e04f1972d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fee53e4e04f1972d/_openwrt-25.12.5-mediatek-filogic-mercusys_mr85x-squashfs-sysupgrade.bin.extracted/sysupgrade-mercusys_mr85x/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
