# Firmware Audit: OpenWrt CMCC A10 (OpenWrt U-Boot layout) / openwrt-25.12.5-mediatek-filogic-cmcc_a10-ubootmod-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cmcc_a10-ubootmod-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_CMCC_A10__OpenWrt_U-Boot_layout/openwrt-25.12.5-mediatek-filogic-cmcc_a10-ubootmod-squashfs-sysupgrade.itb
- SHA-256: `e520dccf8edd8c13988a689e9083d8a9984495f8591312d4fef5e6ddf02b01d9`
- Size: 10969373 bytes
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

- binwalk -eM --directory known_firmware/extracted/e520dccf8edd8c13 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e520dccf8edd8c13/_openwrt-25.12.5-mediatek-filogic-cmcc_a10-ubootmod-squashfs-sysupgrade.itb.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
