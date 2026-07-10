# Firmware Audit: OpenWrt Winstars WS-WN583A6 / openwrt-25.12.5-ramips-mt7621-winstars_ws-wn583a6-initramfs-WN583A6-kernel.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-winstars_ws-wn583a6-initramfs-WN583A6-kernel.bin
- Local path: known_firmware/firmware/OpenWrt_Winstars_WS-WN583A6/openwrt-25.12.5-ramips-mt7621-winstars_ws-wn583a6-initramfs-WN583A6-kernel.bin
- SHA-256: `1692eaffff869484cab1065937c3907da1e6f2c9702a447d58698d09328a9da4`
- Size: 7975903 bytes
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

- binwalk -eM --directory known_firmware/extracted/1692eaffff869484 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1692eaffff869484/_openwrt-25.12.5-ramips-mt7621-winstars_ws-wn583a6-initramfs-WN583A6-kernel.bin.extracted/_168C.extracted/_A77ED4.extracted/cpio-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
