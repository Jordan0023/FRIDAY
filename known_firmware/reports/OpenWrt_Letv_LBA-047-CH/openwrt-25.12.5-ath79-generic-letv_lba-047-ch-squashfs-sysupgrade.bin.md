# Firmware Audit: OpenWrt Letv LBA-047-CH / openwrt-25.12.5-ath79-generic-letv_lba-047-ch-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-letv_lba-047-ch-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Letv_LBA-047-CH/openwrt-25.12.5-ath79-generic-letv_lba-047-ch-squashfs-sysupgrade.bin
- SHA-256: `9f4a4b3877f21aea9b327a162bc640970e07f50dfc573a79ac6881bece57bcdf`
- Size: 6947087 bytes
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

- binwalk -eM --directory known_firmware/extracted/9f4a4b3877f21aea exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9f4a4b3877f21aea/_openwrt-25.12.5-ath79-generic-letv_lba-047-ch-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
