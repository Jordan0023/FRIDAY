# Firmware Audit: OpenWrt Cudy AP3000 Wall / openwrt-25.12.5-mediatek-filogic-cudy_ap3000wall-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_ap3000wall-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_AP3000_Wall/openwrt-25.12.5-mediatek-filogic-cudy_ap3000wall-v1-squashfs-sysupgrade.bin
- SHA-256: `7092d06f1556436f70cc938e5226b259298e32262161c4e8f8451c23e39d205c`
- Size: 9390362 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7092d06f1556436f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7092d06f1556436f/_openwrt-25.12.5-mediatek-filogic-cudy_ap3000wall-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_ap3000wall-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
