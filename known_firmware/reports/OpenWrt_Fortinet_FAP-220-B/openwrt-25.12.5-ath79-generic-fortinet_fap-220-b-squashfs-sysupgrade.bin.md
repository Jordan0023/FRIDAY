# Firmware Audit: OpenWrt Fortinet FAP-220-B / openwrt-25.12.5-ath79-generic-fortinet_fap-220-b-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-fortinet_fap-220-b-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Fortinet_FAP-220-B/openwrt-25.12.5-ath79-generic-fortinet_fap-220-b-squashfs-sysupgrade.bin
- SHA-256: `12c6df4e04002efcb52ff60e2686ab64f3ab3c0970a382cf6f9634dc9a9ad16c`
- Size: 7009476 bytes
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

Evidence: `BOA, cgi-bin, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/12c6df4e04002efc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/12c6df4e04002efc/_openwrt-25.12.5-ath79-generic-fortinet_fap-220-b-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-ar71xx-generic-ens1750-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
