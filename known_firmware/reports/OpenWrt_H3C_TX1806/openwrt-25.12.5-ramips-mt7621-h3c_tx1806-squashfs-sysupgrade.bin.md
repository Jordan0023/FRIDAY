# Firmware Audit: OpenWrt H3C TX1806 / openwrt-25.12.5-ramips-mt7621-h3c_tx1806-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-h3c_tx1806-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_H3C_TX1806/openwrt-25.12.5-ramips-mt7621-h3c_tx1806-squashfs-sysupgrade.bin
- SHA-256: `a827ca6c8d615b8f858a87a873cf2664574b2144b278322c29930376169583e4`
- Size: 8008215 bytes
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

- binwalk -eM --directory known_firmware/extracted/a827ca6c8d615b8f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a827ca6c8d615b8f/_openwrt-25.12.5-ramips-mt7621-h3c_tx1806-squashfs-sysupgrade.bin.extracted/sysupgrade-h3c_tx1806/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
