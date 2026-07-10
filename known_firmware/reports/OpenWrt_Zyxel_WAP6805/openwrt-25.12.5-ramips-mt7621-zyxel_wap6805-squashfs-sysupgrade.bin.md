# Firmware Audit: OpenWrt Zyxel WAP6805 / openwrt-25.12.5-ramips-mt7621-zyxel_wap6805-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-zyxel_wap6805-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_WAP6805/openwrt-25.12.5-ramips-mt7621-zyxel_wap6805-squashfs-sysupgrade.bin
- SHA-256: `e8561d67b8b593265710c5eb0b3119f5f59d9d448ef7d6e340c7f9dc098444c5`
- Size: 7547424 bytes
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

- binwalk -eM --directory known_firmware/extracted/e8561d67b8b59326 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e8561d67b8b59326/_openwrt-25.12.5-ramips-mt7621-zyxel_wap6805-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_wap6805/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
