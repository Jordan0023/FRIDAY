# Firmware Audit: OpenWrt Linksys EA7500 / openwrt-25.12.5-ramips-mt7621-linksys_ea7500-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-linksys_ea7500-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_EA7500/openwrt-25.12.5-ramips-mt7621-linksys_ea7500-v2-squashfs-sysupgrade.bin
- SHA-256: `7ddb44e739bc18ee997807bb859b12c90a2840d8ab9b962ad5bf58ff84eed892`
- Size: 8243756 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7ddb44e739bc18ee exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7ddb44e739bc18ee/_openwrt-25.12.5-ramips-mt7621-linksys_ea7500-v2-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_ea7500-v2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
