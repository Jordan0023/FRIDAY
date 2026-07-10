# Firmware Audit: OpenWrt Widelantech WAP430X / openwrt-25.12.5-mediatek-filogic-widelantech_wap430x-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-widelantech_wap430x-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Widelantech_WAP430X/openwrt-25.12.5-mediatek-filogic-widelantech_wap430x-squashfs-sysupgrade.bin
- SHA-256: `f8c28d3ccc5793ae72c60ce536a94b86226b7b16b822475044d513fc0b908f9d`
- Size: 9699630 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f8c28d3ccc5793ae exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f8c28d3ccc5793ae/_openwrt-25.12.5-mediatek-filogic-widelantech_wap430x-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
