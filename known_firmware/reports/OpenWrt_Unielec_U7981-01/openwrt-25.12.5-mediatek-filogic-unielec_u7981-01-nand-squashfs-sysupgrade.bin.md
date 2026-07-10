# Firmware Audit: OpenWrt Unielec U7981-01 / openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-nand-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-nand-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Unielec_U7981-01/openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-nand-squashfs-sysupgrade.bin
- SHA-256: `bfb2ab380c026eb06dc0d18dc6eb6c8b1ea563a3b4b8bbbcd9bf3af427fcd67f`
- Size: 10486042 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bfb2ab380c026eb0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bfb2ab380c026eb0/_openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-nand-squashfs-sysupgrade.bin.extracted/sysupgrade-unielec_u7981-01-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
