# Firmware Audit: OpenWrt Buffalo WSR-2533DHPL / openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Buffalo_WSR-2533DHPL/openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl-squashfs-sysupgrade.bin
- SHA-256: `9360c41d13af13592dae31d49358fe2eb37ef0189ed81423a4047307dfef3224`
- Size: 8127033 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9360c41d13af1359 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9360c41d13af1359/_openwrt-25.12.5-ramips-mt7621-buffalo_wsr-2533dhpl-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
