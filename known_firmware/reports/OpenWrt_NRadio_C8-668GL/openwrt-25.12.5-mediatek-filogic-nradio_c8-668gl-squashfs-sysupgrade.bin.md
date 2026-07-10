# Firmware Audit: OpenWrt NRadio C8-668GL / openwrt-25.12.5-mediatek-filogic-nradio_c8-668gl-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-nradio_c8-668gl-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NRadio_C8-668GL/openwrt-25.12.5-mediatek-filogic-nradio_c8-668gl-squashfs-sysupgrade.bin
- SHA-256: `3d5107f07fcadc6c3dc64b05155f1f374b840cf1ba8a1a25e33cefd4bd5a08e4`
- Size: 9595150 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3d5107f07fcadc6c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3d5107f07fcadc6c/_openwrt-25.12.5-mediatek-filogic-nradio_c8-668gl-squashfs-sysupgrade.bin.extracted/sysupgrade-nradio_c8-668gl/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
