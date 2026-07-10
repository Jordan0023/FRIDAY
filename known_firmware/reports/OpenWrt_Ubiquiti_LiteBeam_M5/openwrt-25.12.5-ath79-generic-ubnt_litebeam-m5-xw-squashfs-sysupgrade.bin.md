# Firmware Audit: OpenWrt Ubiquiti LiteBeam M5 / openwrt-25.12.5-ath79-generic-ubnt_litebeam-m5-xw-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-ubnt_litebeam-m5-xw-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ubiquiti_LiteBeam_M5/openwrt-25.12.5-ath79-generic-ubnt_litebeam-m5-xw-squashfs-sysupgrade.bin
- SHA-256: `35dfb50465bf88e5f584ff933146a946a71481023678b4fc1512df16bb97d80a`
- Size: 6947104 bytes
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

- binwalk -eM --directory known_firmware/extracted/35dfb50465bf88e5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/35dfb50465bf88e5/_openwrt-25.12.5-ath79-generic-ubnt_litebeam-m5-xw-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
