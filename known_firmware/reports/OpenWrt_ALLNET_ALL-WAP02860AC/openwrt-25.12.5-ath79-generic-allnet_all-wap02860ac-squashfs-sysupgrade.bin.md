# Firmware Audit: OpenWrt ALLNET ALL-WAP02860AC / openwrt-25.12.5-ath79-generic-allnet_all-wap02860ac-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-allnet_all-wap02860ac-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ALLNET_ALL-WAP02860AC/openwrt-25.12.5-ath79-generic-allnet_all-wap02860ac-squashfs-sysupgrade.bin
- SHA-256: `c2337aada073ce19bd403f9e321f62590a09ec4b7a80bd10ecba333ba7f57a5e`
- Size: 7265857 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

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

- binwalk -eM --directory known_firmware/extracted/c2337aada073ce19 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c2337aada073ce19/_openwrt-25.12.5-ath79-generic-allnet_all-wap02860ac-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-senao-allwap02860ac-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
