# Firmware Audit: OpenWrt TP-Link RE350 / openwrt-25.12.5-ramips-mt7621-tplink_re350-v1-initramfs-kernel.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-tplink_re350-v1-initramfs-kernel.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_RE350/openwrt-25.12.5-ramips-mt7621-tplink_re350-v1-initramfs-kernel.bin
- SHA-256: `1449e2c61c006b6302c181ad9ee6441a49a59297d75793f40a1570d62b620ee7`
- Size: 7437148 bytes
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

- binwalk -eM --directory known_firmware/extracted/1449e2c61c006b63 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1449e2c61c006b63/_openwrt-25.12.5-ramips-mt7621-tplink_re350-v1-initramfs-kernel.bin.extracted/_200.extracted/_A77ED4.extracted/cpio-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
