# Firmware Audit: OpenWrt WAVLINK WL-WN536AX6 / openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn536ax6-a-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn536ax6-a-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_WAVLINK_WL-WN536AX6/openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn536ax6-a-squashfs-sysupgrade.bin
- SHA-256: `6644c075c8e69c2921c4c6a51356554b90f240793dff61a0d64c3643a9b09b80`
- Size: 10045722 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6644c075c8e69c29 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6644c075c8e69c29/_openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn536ax6-a-squashfs-sysupgrade.bin.extracted/sysupgrade-wavlink_wl-wn536ax6-a/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
