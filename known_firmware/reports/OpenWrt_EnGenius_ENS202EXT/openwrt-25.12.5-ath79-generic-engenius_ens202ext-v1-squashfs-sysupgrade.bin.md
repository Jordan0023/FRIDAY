# Firmware Audit: OpenWrt EnGenius ENS202EXT / openwrt-25.12.5-ath79-generic-engenius_ens202ext-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-engenius_ens202ext-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EnGenius_ENS202EXT/openwrt-25.12.5-ath79-generic-engenius_ens202ext-v1-squashfs-sysupgrade.bin
- SHA-256: `a03acb04dd1b78ad7ee85455ee840177ffb8fd5dc8329b209b30f6386b1c4e06`
- Size: 6901038 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a03acb04dd1b78ad exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a03acb04dd1b78ad/_openwrt-25.12.5-ath79-generic-engenius_ens202ext-v1-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-senao-ens202ext-root.squashfs.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
