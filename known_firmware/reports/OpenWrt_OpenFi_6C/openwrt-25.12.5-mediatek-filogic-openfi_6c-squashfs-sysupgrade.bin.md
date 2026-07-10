# Firmware Audit: OpenWrt OpenFi 6C / openwrt-25.12.5-mediatek-filogic-openfi_6c-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-openfi_6c-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_OpenFi_6C/openwrt-25.12.5-mediatek-filogic-openfi_6c-squashfs-sysupgrade.bin
- SHA-256: `64339f18edd656a537756d36916aa9a88b0f7c1cb11058d47eb5f15a6482b7d1`
- Size: 9554178 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/64339f18edd656a5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/64339f18edd656a5/_openwrt-25.12.5-mediatek-filogic-openfi_6c-squashfs-sysupgrade.bin.extracted/sysupgrade-openfi_6c/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
