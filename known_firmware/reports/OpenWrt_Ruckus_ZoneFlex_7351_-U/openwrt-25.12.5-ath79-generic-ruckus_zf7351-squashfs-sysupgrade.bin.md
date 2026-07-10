# Firmware Audit: OpenWrt Ruckus ZoneFlex 7351[-U] / openwrt-25.12.5-ath79-generic-ruckus_zf7351-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-ruckus_zf7351-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ruckus_ZoneFlex_7351_-U/openwrt-25.12.5-ath79-generic-ruckus_zf7351-squashfs-sysupgrade.bin
- SHA-256: `b20bc54fbf492571e13d306949b51b079572c4b1cf2d39fd783fb514b83931b1`
- Size: 7340299 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b20bc54fbf492571 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b20bc54fbf492571/_openwrt-25.12.5-ath79-generic-ruckus_zf7351-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
