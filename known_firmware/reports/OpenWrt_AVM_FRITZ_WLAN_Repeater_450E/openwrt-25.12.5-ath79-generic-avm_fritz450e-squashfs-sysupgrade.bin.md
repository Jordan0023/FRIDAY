# Firmware Audit: OpenWrt AVM FRITZ!WLAN Repeater 450E / openwrt-25.12.5-ath79-generic-avm_fritz450e-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-avm_fritz450e-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_AVM_FRITZ_WLAN_Repeater_450E/openwrt-25.12.5-ath79-generic-avm_fritz450e-squashfs-sysupgrade.bin
- SHA-256: `a0257566dc0ab7107c86e2506c3dc279546e32105db8520ebb8183a660ea5741`
- Size: 6947095 bytes
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

- binwalk -eM --directory known_firmware/extracted/a0257566dc0ab710 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a0257566dc0ab710/_openwrt-25.12.5-ath79-generic-avm_fritz450e-squashfs-sysupgrade.bin.extracted/squashfs-root-1/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
