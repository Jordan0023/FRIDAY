# Firmware Audit: OpenWrt ASUS 4G-AX56 / openwrt-25.12.5-ramips-mt7621-asus_4g-ax56-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-asus_4g-ax56-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_4G-AX56/openwrt-25.12.5-ramips-mt7621-asus_4g-ax56-squashfs-sysupgrade.bin
- SHA-256: `af70bf3ac6b9af3a5ac91b37e497a9edb505b705b721ff2ea4086f6f678aef75`
- Size: 8182301 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/af70bf3ac6b9af3a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/af70bf3ac6b9af3a/_openwrt-25.12.5-ramips-mt7621-asus_4g-ax56-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_4g-ax56/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
