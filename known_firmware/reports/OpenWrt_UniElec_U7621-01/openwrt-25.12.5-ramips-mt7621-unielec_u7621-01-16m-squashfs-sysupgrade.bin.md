# Firmware Audit: OpenWrt UniElec U7621-01 / openwrt-25.12.5-ramips-mt7621-unielec_u7621-01-16m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-unielec_u7621-01-16m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_UniElec_U7621-01/openwrt-25.12.5-ramips-mt7621-unielec_u7621-01-16m-squashfs-sysupgrade.bin
- SHA-256: `ac84180046d77cffd5d1f0e78eeac2b24f46596093eceaa1774e2478659a5c9d`
- Size: 7799353 bytes
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

- binwalk -eM --directory known_firmware/extracted/ac84180046d77cff exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ac84180046d77cff/_openwrt-25.12.5-ramips-mt7621-unielec_u7621-01-16m-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
