# Firmware Audit: OpenWrt Plasma Cloud PAX1800-Lite / openwrt-25.12.5-ramips-mt7621-plasmacloud_pax1800-lite-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-plasmacloud_pax1800-lite-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Plasma_Cloud_PAX1800-Lite/openwrt-25.12.5-ramips-mt7621-plasmacloud_pax1800-lite-squashfs-sysupgrade.bin
- SHA-256: `6b6c4b4b53e88488981f7300ac940adeb664dfd42be2299f590f49ed6bf9fb3c`
- Size: 8233537 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6b6c4b4b53e88488 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6b6c4b4b53e88488/_openwrt-25.12.5-ramips-mt7621-plasmacloud_pax1800-lite-squashfs-sysupgrade.bin.extracted/sysupgrade-plasmacloud_pax1800-lite/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
