# Firmware Audit: OpenWrt EnGenius ENS1750 / openwrt-25.12.5-ath79-generic-engenius_ens1750-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-engenius_ens1750-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EnGenius_ENS1750/openwrt-25.12.5-ath79-generic-engenius_ens1750-squashfs-sysupgrade.bin
- SHA-256: `4a78650b7f44e0f3fcb3ebebc3eef4dd38b424b863d3cb2572fd321dacab856b`
- Size: 7265822 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boa, cgi-bin`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4a78650b7f44e0f3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4a78650b7f44e0f3/_openwrt-25.12.5-ath79-generic-engenius_ens1750-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-ar71xx-generic-ens1750-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
