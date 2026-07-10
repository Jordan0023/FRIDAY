# Firmware Audit: OpenWrt Araknis AN-300-AP-I-N / openwrt-25.12.5-ath79-generic-araknis_an-300-ap-i-n-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-araknis_an-300-ap-i-n-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Araknis_AN-300-AP-I-N/openwrt-25.12.5-ath79-generic-araknis_an-300-ap-i-n-squashfs-sysupgrade.bin
- SHA-256: `d652d8aad70c79bd872c516c48e93ceaa55e76d5991f53ad43152ffeebe5aa27`
- Size: 6899150 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

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

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d652d8aad70c79bd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d652d8aad70c79bd/_openwrt-25.12.5-ath79-generic-araknis_an-300-ap-i-n-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-senao-an300-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
