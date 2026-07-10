# Firmware Audit: OpenWrt MoFi Network MOFI5500-5GXeLTE / openwrt-25.12.5-ramips-mt7621-mofinetwork_mofi5500-5gxelte-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-mofinetwork_mofi5500-5gxelte-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MoFi_Network_MOFI5500-5GXeLTE/openwrt-25.12.5-ramips-mt7621-mofinetwork_mofi5500-5gxelte-squashfs-sysupgrade.bin
- SHA-256: `e35ca9d3be7ae0c81d69cb285efb438f24e9b3ea1b9cd81a5f5f5fde48e6d266`
- Size: 8389222 bytes
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

- binwalk -eM --directory known_firmware/extracted/e35ca9d3be7ae0c8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e35ca9d3be7ae0c8/_openwrt-25.12.5-ramips-mt7621-mofinetwork_mofi5500-5gxelte-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
