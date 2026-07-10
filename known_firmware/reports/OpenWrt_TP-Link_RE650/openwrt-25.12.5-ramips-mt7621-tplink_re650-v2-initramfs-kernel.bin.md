# Firmware Audit: OpenWrt TP-Link RE650 / openwrt-25.12.5-ramips-mt7621-tplink_re650-v2-initramfs-kernel.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-tplink_re650-v2-initramfs-kernel.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_RE650/openwrt-25.12.5-ramips-mt7621-tplink_re650-v2-initramfs-kernel.bin
- SHA-256: `2c24d13b1f913abeae4485037786ead8d7fab5f5a8883fb4d8357cbead777fe6`
- Size: 7903516 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2c24d13b1f913abe exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2c24d13b1f913abe/_openwrt-25.12.5-ramips-mt7621-tplink_re650-v2-initramfs-kernel.bin.extracted/_200.extracted/_A77ED4.extracted/cpio-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
