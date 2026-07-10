# Firmware Audit: OpenWrt AsiaRF AP7986 003 / openwrt-25.12.5-mediatek-filogic-asiarf_ap7986-003-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asiarf_ap7986-003-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_AsiaRF_AP7986_003/openwrt-25.12.5-mediatek-filogic-asiarf_ap7986-003-squashfs-sysupgrade.bin
- SHA-256: `6e9d12ad7406e7becbfb0b32d4d309da05ebd6dba0c0ecb6dc92581f6d4fd733`
- Size: 10035474 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6e9d12ad7406e7be exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6e9d12ad7406e7be/_openwrt-25.12.5-mediatek-filogic-asiarf_ap7986-003-squashfs-sysupgrade.bin.extracted/sysupgrade-asiarf_ap7986-003/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
