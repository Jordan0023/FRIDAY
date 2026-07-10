# Firmware Audit: OpenWrt MERCUSYS MR80X / openwrt-25.12.5-mediatek-filogic-mercusys_mr80x-v3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mercusys_mr80x-v3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MERCUSYS_MR80X/openwrt-25.12.5-mediatek-filogic-mercusys_mr80x-v3-squashfs-sysupgrade.bin
- SHA-256: `d711a45433d7b7bdfa6d4aadd82aacc1c3f4f328ccf15e1f10e51e1a3025961b`
- Size: 9390354 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d711a45433d7b7bd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d711a45433d7b7bd/_openwrt-25.12.5-mediatek-filogic-mercusys_mr80x-v3-squashfs-sysupgrade.bin.extracted/sysupgrade-mercusys_mr80x-v3/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
