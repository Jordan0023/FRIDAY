# Firmware Audit: OpenWrt Huasifei WH3000R / openwrt-25.12.5-mediatek-filogic-huasifei_wh3000r-nand-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000r-nand-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Huasifei_WH3000R/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000r-nand-squashfs-sysupgrade.bin
- SHA-256: `e7e436648c7b0fe7a3202268d1d5614f3e439e1861edaefc92d6371de490f15f`
- Size: 9554202 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e7e436648c7b0fe7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e7e436648c7b0fe7/_openwrt-25.12.5-mediatek-filogic-huasifei_wh3000r-nand-squashfs-sysupgrade.bin.extracted/sysupgrade-huasifei_wh3000r-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
