# Firmware Audit: OpenWrt Qxwlan E1700AC / openwrt-25.12.5-ath79-generic-qxwlan_e1700ac-v2-8m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-qxwlan_e1700ac-v2-8m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Qxwlan_E1700AC/openwrt-25.12.5-ath79-generic-qxwlan_e1700ac-v2-8m-squashfs-sysupgrade.bin
- SHA-256: `ca32372c9fb446962aa48d5bac74185ee4af34c8642476b0495d9b5f4ed30bdc`
- Size: 7405862 bytes
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

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ca32372c9fb44696 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ca32372c9fb44696/_openwrt-25.12.5-ath79-generic-qxwlan_e1700ac-v2-8m-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
