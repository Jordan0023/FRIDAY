# Firmware Audit: OpenWrt TP-Link ER605 / openwrt-25.12.5-ramips-mt7621-tplink_er605-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-tplink_er605-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_ER605/openwrt-25.12.5-ramips-mt7621-tplink_er605-v2-squashfs-sysupgrade.bin
- SHA-256: `021348609958caabbc267aa1b13937acb19144f967620b179543618d396ac04a`
- Size: 6574662 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/021348609958caab exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/021348609958caab/_openwrt-25.12.5-ramips-mt7621-tplink_er605-v2-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_er605-v2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
