# Firmware Audit: OpenWrt Acer Predator Connect W6x (Stock Layout) / openwrt-25.12.5-mediatek-filogic-acer_predator-w6x-stock-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-acer_predator-w6x-stock-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Acer_Predator_Connect_W6x__Stock_Layout/openwrt-25.12.5-mediatek-filogic-acer_predator-w6x-stock-squashfs-sysupgrade.bin
- SHA-256: `82ad17fbcc90a109f1b6b9595fe6b983ba388f07e8b191334caebcfc6a7a03e1`
- Size: 10035506 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/82ad17fbcc90a109 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/82ad17fbcc90a109/_openwrt-25.12.5-mediatek-filogic-acer_predator-w6x-stock-squashfs-sysupgrade.bin.extracted/sysupgrade-acer_predator-w6x-stock/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
