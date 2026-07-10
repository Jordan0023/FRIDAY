# Firmware Audit: OpenWrt GeHua GHL-R-001 / openwrt-25.12.5-ramips-mt7621-gehua_ghl-r-001-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-gehua_ghl-r-001-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GeHua_GHL-R-001/openwrt-25.12.5-ramips-mt7621-gehua_ghl-r-001-squashfs-sysupgrade.bin
- SHA-256: `998837de4cfc819f927fd268da96483ec7e177cd1103a37c611eb2d072280307`
- Size: 7799338 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/998837de4cfc819f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/998837de4cfc819f/_openwrt-25.12.5-ramips-mt7621-gehua_ghl-r-001-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
