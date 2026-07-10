# Firmware Audit: OpenWrt Zyxel LTE7490-M904 / openwrt-25.12.5-ramips-mt7621-zyxel_lte7490-m904-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-zyxel_lte7490-m904-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_LTE7490-M904/openwrt-25.12.5-ramips-mt7621-zyxel_lte7490-m904-squashfs-sysupgrade.bin
- SHA-256: `0db109d8663211e06a1e0dc7e1e708c876e2adddb09c9b3b8ad69a1145747823`
- Size: 7782959 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0db109d8663211e0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0db109d8663211e0/_openwrt-25.12.5-ramips-mt7621-zyxel_lte7490-m904-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_lte7490-m904/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
