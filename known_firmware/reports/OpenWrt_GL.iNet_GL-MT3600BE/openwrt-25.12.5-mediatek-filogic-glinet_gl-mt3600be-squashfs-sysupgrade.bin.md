# Firmware Audit: OpenWrt GL.iNet GL-MT3600BE / openwrt-25.12.5-mediatek-filogic-glinet_gl-mt3600be-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt3600be-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-MT3600BE/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt3600be-squashfs-sysupgrade.bin
- SHA-256: `0749dba4b2c04b9ccc91d4d9187034923b619c63b29d206e89e8504af724914d`
- Size: 10322196 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0749dba4b2c04b9c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0749dba4b2c04b9c/_openwrt-25.12.5-mediatek-filogic-glinet_gl-mt3600be-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-mt3600be/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
