# Firmware Audit: OpenWrt ipTIME AX2002MESH / openwrt-25.12.5-ramips-mt7621-iptime_ax2002m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iptime_ax2002m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_AX2002MESH/openwrt-25.12.5-ramips-mt7621-iptime_ax2002m-squashfs-sysupgrade.bin
- SHA-256: `f4bf5967f9cc1c18ed36daeb8255d2b103f3b3060f24d3ed29c9ee75648d25fb`
- Size: 8008487 bytes
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

- binwalk -eM --directory known_firmware/extracted/f4bf5967f9cc1c18 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f4bf5967f9cc1c18/_openwrt-25.12.5-ramips-mt7621-iptime_ax2002m-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_ax2002m/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
