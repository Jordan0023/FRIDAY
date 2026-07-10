# Firmware Audit: OpenWrt I-O DATA WN-AX1167GR / openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-AX1167GR/openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr-squashfs-sysupgrade.bin
- SHA-256: `808ea38e94248f18c52861a5ed75c588e7638a1b9ee714991a1924670eb47d67`
- Size: 7668275 bytes
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

- binwalk -eM --directory known_firmware/extracted/808ea38e94248f18 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/808ea38e94248f18/_openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
