# Firmware Audit: OpenWrt ASUS ZenWiFi BT8 / openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-ubootmod-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-ubootmod-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_ASUS_ZenWiFi_BT8/openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-ubootmod-squashfs-sysupgrade.itb
- SHA-256: `5da2768c1a43967cfb9f418957f4803e4871143cb6b23d6d70bff23120e7a0c3`
- Size: 13893926 bytes
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

- binwalk -eM --directory known_firmware/extracted/5da2768c1a43967c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5da2768c1a43967c/_openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-ubootmod-squashfs-sysupgrade.itb.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
