# Firmware Audit: OpenWrt Araknis AN-700-AP-I-AC / openwrt-25.12.5-ath79-generic-araknis_an-700-ap-i-ac-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-araknis_an-700-ap-i-ac-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Araknis_AN-700-AP-I-AC/openwrt-25.12.5-ath79-generic-araknis_an-700-ap-i-ac-squashfs-sysupgrade.bin
- SHA-256: `3d264d45799d350005a24136df308c3fd26a9575768e403a4aba24a12ca5718b`
- Size: 7265843 bytes
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

Evidence: `BOA, boa, cgi-bin, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3d264d45799d3500 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3d264d45799d3500/_openwrt-25.12.5-ath79-generic-araknis_an-700-ap-i-ac-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-senao-generic-v1-an700-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
