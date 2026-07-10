# Firmware Audit: OpenWrt Zyxel WSM20 / openwrt-25.12.5-ramips-mt7621-zyxel_wsm20-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-zyxel_wsm20-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_WSM20/openwrt-25.12.5-ramips-mt7621-zyxel_wsm20-squashfs-sysupgrade.bin
- SHA-256: `546c06e22bd7a9f645cf3a1a6218007410126fc3601149101be2c862008d416a`
- Size: 8264218 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/546c06e22bd7a9f6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/546c06e22bd7a9f6/_openwrt-25.12.5-ramips-mt7621-zyxel_wsm20-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_wsm20/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
