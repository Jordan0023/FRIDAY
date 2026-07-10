# Firmware Audit: OpenWrt Cudy M3000 / openwrt-25.12.5-mediatek-filogic-cudy_m3000-v2-yt8821-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_m3000-v2-yt8821-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_M3000/openwrt-25.12.5-mediatek-filogic-cudy_m3000-v2-yt8821-squashfs-sysupgrade.bin
- SHA-256: `506e2d1c8772f2e6db5eeaf4ce622bd591d27f7e68d5059179612373d79c9257`
- Size: 9400606 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/506e2d1c8772f2e6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/506e2d1c8772f2e6/_openwrt-25.12.5-mediatek-filogic-cudy_m3000-v2-yt8821-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_m3000-v2-yt8821/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
