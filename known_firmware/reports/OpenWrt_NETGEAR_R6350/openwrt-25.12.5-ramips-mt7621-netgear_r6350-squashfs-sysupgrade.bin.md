# Firmware Audit: OpenWrt NETGEAR R6350 / openwrt-25.12.5-ramips-mt7621-netgear_r6350-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_r6350-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_R6350/openwrt-25.12.5-ramips-mt7621-netgear_r6350-squashfs-sysupgrade.bin
- SHA-256: `fb91d473f7a5ef9cbcb88950885732f4e428934bcce58a5f5997b5223192610a`
- Size: 8315424 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fb91d473f7a5ef9c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fb91d473f7a5ef9c/_openwrt-25.12.5-ramips-mt7621-netgear_r6350-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_r6350/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
