# Firmware Audit: OpenWrt Amped Wireless ALLY-R1900K / openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-r1900k-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-r1900k-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Amped_Wireless_ALLY-R1900K/openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-r1900k-squashfs-sysupgrade.bin
- SHA-256: `1e63534349199a8341ab925bc51df7c126b7a6883bc510a6d44d5596bd66ca0a`
- Size: 8243780 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1e63534349199a83 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1e63534349199a83/_openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-r1900k-squashfs-sysupgrade.bin.extracted/sysupgrade-ampedwireless_ally-r1900k/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
