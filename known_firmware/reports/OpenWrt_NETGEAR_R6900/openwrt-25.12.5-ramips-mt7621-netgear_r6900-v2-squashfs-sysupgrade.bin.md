# Firmware Audit: OpenWrt NETGEAR R6900 / openwrt-25.12.5-ramips-mt7621-netgear_r6900-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_r6900-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_R6900/openwrt-25.12.5-ramips-mt7621-netgear_r6900-v2-squashfs-sysupgrade.bin
- SHA-256: `d93e3f663375912cd31e19f21a47141de9aeac9bef1b15062dd1186f5d8f2186`
- Size: 8315433 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d93e3f663375912c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d93e3f663375912c/_openwrt-25.12.5-ramips-mt7621-netgear_r6900-v2-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_r6900-v2/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
