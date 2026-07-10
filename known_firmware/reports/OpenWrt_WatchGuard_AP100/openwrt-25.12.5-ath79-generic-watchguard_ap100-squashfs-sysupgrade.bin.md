# Firmware Audit: OpenWrt WatchGuard AP100 / openwrt-25.12.5-ath79-generic-watchguard_ap100-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-watchguard_ap100-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_WatchGuard_AP100/openwrt-25.12.5-ath79-generic-watchguard_ap100-squashfs-sysupgrade.bin
- SHA-256: `e41c3c96f196a86ec98841daa16b9a0756a153da175f250b6bd9464a19f44c65`
- Size: 6899199 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e41c3c96f196a86e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e41c3c96f196a86e/_openwrt-25.12.5-ath79-generic-watchguard_ap100-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-senao-ap100-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
