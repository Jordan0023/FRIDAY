# Firmware Audit: OpenWrt YouHua WR1200JS / openwrt-25.12.5-ramips-mt7621-youhua_wr1200js-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-youhua_wr1200js-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_YouHua_WR1200JS/openwrt-25.12.5-ramips-mt7621-youhua_wr1200js-squashfs-sysupgrade.bin
- SHA-256: `15b78653ea9137ad90b1ec2877d13c6a43a6a93bf5ac5aa737c53a3e89bdc33b`
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

- binwalk -eM --directory known_firmware/extracted/15b78653ea9137ad exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/15b78653ea9137ad/_openwrt-25.12.5-ramips-mt7621-youhua_wr1200js-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
