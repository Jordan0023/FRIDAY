# Firmware Audit: OpenWrt Wodesys WD-R1802U / openwrt-25.12.5-ramips-mt7621-wodesys_wd-r1802u-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-wodesys_wd-r1802u-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Wodesys_WD-R1802U/openwrt-25.12.5-ramips-mt7621-wodesys_wd-r1802u-squashfs-sysupgrade.bin
- SHA-256: `89c6076b3551c0496d475f95d7cabaa7e2dc46cc70dc79d750df19e4e68d76dc`
- Size: 7995990 bytes
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

- binwalk -eM --directory known_firmware/extracted/89c6076b3551c049 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/89c6076b3551c049/_openwrt-25.12.5-ramips-mt7621-wodesys_wd-r1802u-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
