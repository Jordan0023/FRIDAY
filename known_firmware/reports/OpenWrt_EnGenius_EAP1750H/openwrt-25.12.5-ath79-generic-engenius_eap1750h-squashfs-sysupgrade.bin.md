# Firmware Audit: OpenWrt EnGenius EAP1750H / openwrt-25.12.5-ath79-generic-engenius_eap1750h-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-engenius_eap1750h-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EnGenius_EAP1750H/openwrt-25.12.5-ath79-generic-engenius_eap1750h-squashfs-sysupgrade.bin
- SHA-256: `b3b1039b37249bb70c6c295d753af86f391e5cfff654d8af2d1113fbc551145f`
- Size: 7265839 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boa, cgi-bin, httpd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b3b1039b37249bb7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b3b1039b37249bb7/_openwrt-25.12.5-ath79-generic-engenius_eap1750h-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-ar71xx-generic-eap1750h-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
