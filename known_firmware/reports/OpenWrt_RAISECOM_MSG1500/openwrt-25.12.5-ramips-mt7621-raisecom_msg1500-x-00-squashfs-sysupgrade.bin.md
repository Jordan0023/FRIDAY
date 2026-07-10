# Firmware Audit: OpenWrt RAISECOM MSG1500 / openwrt-25.12.5-ramips-mt7621-raisecom_msg1500-x-00-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-raisecom_msg1500-x-00-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_RAISECOM_MSG1500/openwrt-25.12.5-ramips-mt7621-raisecom_msg1500-x-00-squashfs-sysupgrade.bin
- SHA-256: `d16760e42d5438ea9712ec002e4d031408fc5837650d649d9c5c178e34773b35`
- Size: 8243768 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d16760e42d5438ea exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d16760e42d5438ea/_openwrt-25.12.5-ramips-mt7621-raisecom_msg1500-x-00-squashfs-sysupgrade.bin.extracted/sysupgrade-raisecom_msg1500-x-00/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
