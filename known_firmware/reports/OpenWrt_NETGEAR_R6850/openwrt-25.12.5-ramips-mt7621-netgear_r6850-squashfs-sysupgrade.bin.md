# Firmware Audit: OpenWrt NETGEAR R6850 / openwrt-25.12.5-ramips-mt7621-netgear_r6850-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_r6850-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_R6850/openwrt-25.12.5-ramips-mt7621-netgear_r6850-squashfs-sysupgrade.bin
- SHA-256: `1bcd853b001613f24f0bdc413cdf027e737df9f18c3bc374007e245b43fe3ce9`
- Size: 8315424 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1bcd853b001613f2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1bcd853b001613f2/_openwrt-25.12.5-ramips-mt7621-netgear_r6850-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_r6850/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
