# Firmware Audit: OpenWrt Huasifei WS1208V2 / openwrt-25.12.5-ramips-mt7621-huasifei_ws1208v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-huasifei_ws1208v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Huasifei_WS1208V2/openwrt-25.12.5-ramips-mt7621-huasifei_ws1208v2-squashfs-sysupgrade.bin
- SHA-256: `a2772c7853161c9b15a7bca254d66ff8ca17074cfb5ae54c62d679e440a599e8`
- Size: 8061488 bytes
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

- binwalk -eM --directory known_firmware/extracted/a2772c7853161c9b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a2772c7853161c9b/_openwrt-25.12.5-ramips-mt7621-huasifei_ws1208v2-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
