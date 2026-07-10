# Firmware Audit: OpenWrt Zyxel NWA1100 / openwrt-25.12.5-ath79-generic-zyxel_nwa1100-nh-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-zyxel_nwa1100-nh-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_NWA1100/openwrt-25.12.5-ath79-generic-zyxel_nwa1100-nh-squashfs-sysupgrade.bin
- SHA-256: `d5f842350ac54af9d71c37a73888825c92b9dc3570f3628fcee6bc3d46e00d0a`
- Size: 6947089 bytes
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

- binwalk -eM --directory known_firmware/extracted/d5f842350ac54af9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d5f842350ac54af9/_openwrt-25.12.5-ath79-generic-zyxel_nwa1100-nh-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
