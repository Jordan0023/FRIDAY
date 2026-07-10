# Firmware Audit: OpenWrt Beeline SmartBox PRO / openwrt-25.12.5-ramips-mt7621-beeline_smartbox-pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-beeline_smartbox-pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Beeline_SmartBox_PRO/openwrt-25.12.5-ramips-mt7621-beeline_smartbox-pro-squashfs-sysupgrade.bin
- SHA-256: `0f9f506669f0d98f1130e0cf93df909b28a28bb2fff97488568448aebe4bd8e2`
- Size: 7762485 bytes
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

- binwalk -eM --directory known_firmware/extracted/0f9f506669f0d98f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0f9f506669f0d98f/_openwrt-25.12.5-ramips-mt7621-beeline_smartbox-pro-squashfs-sysupgrade.bin.extracted/sysupgrade-beeline_smartbox-pro/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
