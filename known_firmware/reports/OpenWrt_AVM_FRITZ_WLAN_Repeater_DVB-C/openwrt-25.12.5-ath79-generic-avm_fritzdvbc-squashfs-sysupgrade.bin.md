# Firmware Audit: OpenWrt AVM FRITZ!WLAN Repeater DVB-C / openwrt-25.12.5-ath79-generic-avm_fritzdvbc-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-avm_fritzdvbc-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_AVM_FRITZ_WLAN_Repeater_DVB-C/openwrt-25.12.5-ath79-generic-avm_fritzdvbc-squashfs-sysupgrade.bin
- SHA-256: `7788d7a5dc42ff0fcb8218f2cac1bd0e79bb65a92266fa332a5fabab67f77a1d`
- Size: 7274763 bytes
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

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7788d7a5dc42ff0f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7788d7a5dc42ff0f/_openwrt-25.12.5-ath79-generic-avm_fritzdvbc-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
