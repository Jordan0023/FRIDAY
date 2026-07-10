# Firmware Audit: OpenWrt MERCUSYS MR90X v1 / openwrt-25.12.5-mediatek-filogic-mercusys_mr90x-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mercusys_mr90x-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MERCUSYS_MR90X_v1/openwrt-25.12.5-mediatek-filogic-mercusys_mr90x-v1-squashfs-sysupgrade.bin
- SHA-256: `aa9cb8422bc967f556ff75f90fe18075bfb381f37a0826ac6f82aec909fd8921`
- Size: 9881874 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/aa9cb8422bc967f5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/aa9cb8422bc967f5/_openwrt-25.12.5-mediatek-filogic-mercusys_mr90x-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-mercusys_mr90x-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
