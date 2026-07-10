# Firmware Audit: OpenWrt EnGenius EWS660AP / openwrt-25.12.5-ath79-generic-engenius_ews660ap-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-engenius_ews660ap-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EnGenius_EWS660AP/openwrt-25.12.5-ath79-generic-engenius_ews660ap-squashfs-sysupgrade.bin
- SHA-256: `24ba08939c3cb0860399c78e38aeca88c4ee2206c268113c3e53ae3b578315f6`
- Size: 7265827 bytes
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

Evidence: `BOA, boa, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/24ba08939c3cb086 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/24ba08939c3cb086/_openwrt-25.12.5-ath79-generic-engenius_ews660ap-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-ar71xx-generic-ews660ap-root.squashfs.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
