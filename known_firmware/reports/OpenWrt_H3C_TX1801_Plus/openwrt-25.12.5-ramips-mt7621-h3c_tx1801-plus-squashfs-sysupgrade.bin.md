# Firmware Audit: OpenWrt H3C TX1801 Plus / openwrt-25.12.5-ramips-mt7621-h3c_tx1801-plus-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-h3c_tx1801-plus-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_H3C_TX1801_Plus/openwrt-25.12.5-ramips-mt7621-h3c_tx1801-plus-squashfs-sysupgrade.bin
- SHA-256: `b3cba3c506bb53b76d965273bc7cd4e91c9edc97f262b0d7d2fdb5ef25684526`
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

- binwalk -eM --directory known_firmware/extracted/b3cba3c506bb53b7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b3cba3c506bb53b7/_openwrt-25.12.5-ramips-mt7621-h3c_tx1801-plus-squashfs-sysupgrade.bin.extracted/sysupgrade-h3c_tx1801-plus/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
