# Firmware Audit: OpenWrt Beeline SmartBox Flash / openwrt-25.12.5-ramips-mt7621-beeline_smartbox-flash-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-beeline_smartbox-flash-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Beeline_SmartBox_Flash/openwrt-25.12.5-ramips-mt7621-beeline_smartbox-flash-squashfs-sysupgrade.bin
- SHA-256: `9db76383941043240034a2b4aa6f3760f2d0642be862f3c38bb1d995211f1487`
- Size: 9380411 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9db7638394104324 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9db7638394104324/_openwrt-25.12.5-ramips-mt7621-beeline_smartbox-flash-squashfs-sysupgrade.bin.extracted/sysupgrade-beeline_smartbox-flash/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
