# Firmware Audit: OpenWrt ASUS RT-AX52 / openwrt-25.12.5-mediatek-filogic-asus_rt-ax52-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_rt-ax52-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AX52/openwrt-25.12.5-mediatek-filogic-asus_rt-ax52-squashfs-sysupgrade.bin
- SHA-256: `56f89baec61a034b5ca543e4eb1dc9861e686c80e3e80ece1a4331084a807a4a`
- Size: 9390344 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/56f89baec61a034b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/56f89baec61a034b/_openwrt-25.12.5-mediatek-filogic-asus_rt-ax52-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ax52/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
