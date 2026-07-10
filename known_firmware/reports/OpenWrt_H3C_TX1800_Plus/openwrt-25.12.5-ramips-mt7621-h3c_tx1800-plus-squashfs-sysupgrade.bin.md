# Firmware Audit: OpenWrt H3C TX1800 Plus / openwrt-25.12.5-ramips-mt7621-h3c_tx1800-plus-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-h3c_tx1800-plus-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_H3C_TX1800_Plus/openwrt-25.12.5-ramips-mt7621-h3c_tx1800-plus-squashfs-sysupgrade.bin
- SHA-256: `337c94895bbd53343d53e1a43e0b6643a84edd75dfd5d5f3d9c76f7d0ea3d768`
- Size: 8008230 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/337c94895bbd5334 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/337c94895bbd5334/_openwrt-25.12.5-ramips-mt7621-h3c_tx1800-plus-squashfs-sysupgrade.bin.extracted/sysupgrade-h3c_tx1800-plus/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
