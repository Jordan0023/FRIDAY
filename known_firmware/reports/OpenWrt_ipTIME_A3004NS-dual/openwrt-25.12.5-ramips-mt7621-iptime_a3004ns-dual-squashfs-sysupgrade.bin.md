# Firmware Audit: OpenWrt ipTIME A3004NS-dual / openwrt-25.12.5-ramips-mt7621-iptime_a3004ns-dual-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iptime_a3004ns-dual-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_A3004NS-dual/openwrt-25.12.5-ramips-mt7621-iptime_a3004ns-dual-squashfs-sysupgrade.bin
- SHA-256: `fd72127c093a5c7be9d909e917d209125d0ea2e46b04d08a076f84a176bc5c53`
- Size: 7733814 bytes
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

- binwalk -eM --directory known_firmware/extracted/fd72127c093a5c7b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fd72127c093a5c7b/_openwrt-25.12.5-ramips-mt7621-iptime_a3004ns-dual-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
