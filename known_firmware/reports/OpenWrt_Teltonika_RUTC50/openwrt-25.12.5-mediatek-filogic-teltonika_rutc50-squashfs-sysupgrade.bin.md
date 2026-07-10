# Firmware Audit: OpenWrt Teltonika RUTC50 / openwrt-25.12.5-mediatek-filogic-teltonika_rutc50-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-teltonika_rutc50-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Teltonika_RUTC50/openwrt-25.12.5-mediatek-filogic-teltonika_rutc50-squashfs-sysupgrade.bin
- SHA-256: `5a4d0fffa13d3610c5e249384ad853c7c60944d56e4f26990c001839e489661f`
- Size: 9656592 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5a4d0fffa13d3610 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5a4d0fffa13d3610/_openwrt-25.12.5-mediatek-filogic-teltonika_rutc50-squashfs-sysupgrade.bin.extracted/sysupgrade-teltonika_rutc50/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
