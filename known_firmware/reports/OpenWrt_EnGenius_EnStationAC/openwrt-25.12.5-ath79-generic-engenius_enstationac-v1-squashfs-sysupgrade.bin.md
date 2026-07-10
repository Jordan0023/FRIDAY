# Firmware Audit: OpenWrt EnGenius EnStationAC / openwrt-25.12.5-ath79-generic-engenius_enstationac-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-engenius_enstationac-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EnGenius_EnStationAC/openwrt-25.12.5-ath79-generic-engenius_enstationac-v1-squashfs-sysupgrade.bin
- SHA-256: `98f111a15dbbdd2668dccd7631eb48347ca6d4392a5c8ce3834a4a9745fe7c8f`
- Size: 7267977 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, cgi-bin`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/98f111a15dbbdd26 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/98f111a15dbbdd26/_openwrt-25.12.5-ath79-generic-engenius_enstationac-v1-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-ar71xx-generic-enstationac-root.squashfs.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
