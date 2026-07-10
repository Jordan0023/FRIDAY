# Firmware Audit: OpenWrt Beeline SmartBox TURBO / openwrt-25.12.5-ramips-mt7621-beeline_smartbox-turbo-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-beeline_smartbox-turbo-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Beeline_SmartBox_TURBO/openwrt-25.12.5-ramips-mt7621-beeline_smartbox-turbo-squashfs-sysupgrade.bin
- SHA-256: `0dad72047922f69d1cc8d160ae8cf1384abacddf97afa4047e7522e504aee6b8`
- Size: 8366651 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0dad72047922f69d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0dad72047922f69d/_openwrt-25.12.5-ramips-mt7621-beeline_smartbox-turbo-squashfs-sysupgrade.bin.extracted/sysupgrade-beeline_smartbox-turbo/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
