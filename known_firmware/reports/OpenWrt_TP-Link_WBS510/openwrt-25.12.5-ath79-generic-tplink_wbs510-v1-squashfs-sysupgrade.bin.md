# Firmware Audit: OpenWrt TP-Link WBS510 / openwrt-25.12.5-ath79-generic-tplink_wbs510-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-tplink_wbs510-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_WBS510/openwrt-25.12.5-ath79-generic-tplink_wbs510-v1-squashfs-sysupgrade.bin
- SHA-256: `a2f3e4ef59cb5f74bbb9271da5f7ecc982a2988f47665ead0a0c9e4ec2a0eca2`
- Size: 7803309 bytes
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

- binwalk -eM --directory known_firmware/extracted/a2f3e4ef59cb5f74 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a2f3e4ef59cb5f74/_openwrt-25.12.5-ath79-generic-tplink_wbs510-v1-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
