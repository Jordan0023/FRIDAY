# Firmware Audit: OpenWrt Buffalo WSR-2533DHPL2 / openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Buffalo_WSR-2533DHPL2/openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl2-squashfs-sysupgrade.bin
- SHA-256: `b3d8f523b2b1a39617a4e3c49e582cdb1e8ce488f7bd2cfa82346b4d20c13787`
- Size: 11059768 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b3d8f523b2b1a396 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b3d8f523b2b1a396/_openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl2-squashfs-sysupgrade.bin.extracted/sysupgrade-buffalo_wsr-2533dhpl2/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
