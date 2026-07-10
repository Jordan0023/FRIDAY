# Firmware Audit: OpenWrt Huasifei WH3000 / openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Huasifei_WH3000/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-squashfs-sysupgrade.bin
- SHA-256: `c788a8507144c4cc78a711f57637f03c5e04a7b6691e985b444aa894c0ce0b8c`
- Size: 9677093 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c788a8507144c4cc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c788a8507144c4cc/_openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-squashfs-sysupgrade.bin.extracted/sysupgrade-huasifei_wh3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
