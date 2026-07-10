# Firmware Audit: OpenWrt Cudy TR3000 / openwrt-25.12.5-mediatek-filogic-cudy_tr3000-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_tr3000-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_TR3000/openwrt-25.12.5-mediatek-filogic-cudy_tr3000-v1-squashfs-sysupgrade.bin
- SHA-256: `8d482ea1855edd6a72357ecd2b7cc5ab38548d2a5eb83f6b533b9bedaf2f77b4`
- Size: 9554194 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8d482ea1855edd6a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8d482ea1855edd6a/_openwrt-25.12.5-mediatek-filogic-cudy_tr3000-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_tr3000-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
