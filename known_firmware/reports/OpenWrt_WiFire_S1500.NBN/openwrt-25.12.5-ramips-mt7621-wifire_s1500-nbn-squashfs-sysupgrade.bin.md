# Firmware Audit: OpenWrt WiFire S1500.NBN / openwrt-25.12.5-ramips-mt7621-wifire_s1500-nbn-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-wifire_s1500-nbn-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_WiFire_S1500.NBN/openwrt-25.12.5-ramips-mt7621-wifire_s1500-nbn-squashfs-sysupgrade.bin
- SHA-256: `ca3c2159ae0c60e297b1ddf9f833648e20a8b5d25edae4c2a26ed7b79cd63d69`
- Size: 7762473 bytes
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

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ca3c2159ae0c60e2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ca3c2159ae0c60e2/_openwrt-25.12.5-ramips-mt7621-wifire_s1500-nbn-squashfs-sysupgrade.bin.extracted/sysupgrade-wifire_s1500-nbn/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
