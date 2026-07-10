# Firmware Audit: OpenWrt OpenFi 5Pro / openwrt-25.12.5-ramips-mt7621-openfi_5pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-openfi_5pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_OpenFi_5Pro/openwrt-25.12.5-ramips-mt7621-openfi_5pro-squashfs-sysupgrade.bin
- SHA-256: `3c0cae9e9dcfdc7d82b755a76cb8882c6c71b705bfec0f46fe53cd9718d299fd`
- Size: 8323614 bytes
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

- binwalk -eM --directory known_firmware/extracted/3c0cae9e9dcfdc7d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3c0cae9e9dcfdc7d/_openwrt-25.12.5-ramips-mt7621-openfi_5pro-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
