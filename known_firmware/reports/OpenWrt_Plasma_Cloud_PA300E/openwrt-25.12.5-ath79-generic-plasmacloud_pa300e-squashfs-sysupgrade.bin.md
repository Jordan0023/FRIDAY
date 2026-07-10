# Firmware Audit: OpenWrt Plasma Cloud PA300E / openwrt-25.12.5-ath79-generic-plasmacloud_pa300e-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-plasmacloud_pa300e-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Plasma_Cloud_PA300E/openwrt-25.12.5-ath79-generic-plasmacloud_pa300e-squashfs-sysupgrade.bin
- SHA-256: `871fd3c89d77ecad7ec9ca0d549518537da17f8bbb477a9020c7596c1b19e7bd`
- Size: 6953233 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/871fd3c89d77ecad exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/871fd3c89d77ecad/_openwrt-25.12.5-ath79-generic-plasmacloud_pa300e-squashfs-sysupgrade.bin.extracted/sysupgrade-plasmacloud_pa300e/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
