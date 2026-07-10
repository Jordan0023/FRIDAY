# Firmware Audit: OpenWrt Acer Predator Connect W6 / openwrt-25.12.5-mediatek-filogic-acer_predator-w6-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-acer_predator-w6-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Acer_Predator_Connect_W6/openwrt-25.12.5-mediatek-filogic-acer_predator-w6-squashfs-sysupgrade.bin
- SHA-256: `b38c291adbe024d5a8986965a48e01deaafddc826446752e849273b562276674`
- Size: 11172112 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b38c291adbe024d5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b38c291adbe024d5/_openwrt-25.12.5-mediatek-filogic-acer_predator-w6-squashfs-sysupgrade.bin.extracted/sysupgrade-acer_predator-w6/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
