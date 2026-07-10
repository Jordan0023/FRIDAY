# Firmware Audit: OpenWrt I-O DATA WN-DEAX1800GR / openwrt-25.12.5-ramips-mt7621-iodata_wn-deax1800gr-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-deax1800gr-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-DEAX1800GR/openwrt-25.12.5-ramips-mt7621-iodata_wn-deax1800gr-squashfs-sysupgrade.bin
- SHA-256: `d8f6b9f15eed467ca0d9d4ca18596f50a6ed244ee761d8fdc3f415d2723d3401`
- Size: 8008245 bytes
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

- binwalk -eM --directory known_firmware/extracted/d8f6b9f15eed467c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d8f6b9f15eed467c/_openwrt-25.12.5-ramips-mt7621-iodata_wn-deax1800gr-squashfs-sysupgrade.bin.extracted/sysupgrade-iodata_wn-deax1800gr/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
