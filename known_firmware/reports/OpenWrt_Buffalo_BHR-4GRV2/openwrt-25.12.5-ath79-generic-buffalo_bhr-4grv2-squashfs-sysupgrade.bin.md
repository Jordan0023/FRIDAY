# Firmware Audit: OpenWrt Buffalo BHR-4GRV2 / openwrt-25.12.5-ath79-generic-buffalo_bhr-4grv2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-buffalo_bhr-4grv2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Buffalo_BHR-4GRV2/openwrt-25.12.5-ath79-generic-buffalo_bhr-4grv2-squashfs-sysupgrade.bin
- SHA-256: `7811d933c0979903dda76614c8287d928d37f1eed9945bf9b72cda32f2c8173d`
- Size: 6947091 bytes
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

- binwalk -eM --directory known_firmware/extracted/7811d933c0979903 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7811d933c0979903/_openwrt-25.12.5-ath79-generic-buffalo_bhr-4grv2-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
