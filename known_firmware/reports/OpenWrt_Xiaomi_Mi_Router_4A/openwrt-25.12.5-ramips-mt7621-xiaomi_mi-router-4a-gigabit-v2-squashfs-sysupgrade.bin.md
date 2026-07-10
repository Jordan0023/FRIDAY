# Firmware Audit: OpenWrt Xiaomi Mi Router 4A / openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-4a-gigabit-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-4a-gigabit-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_4A/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-4a-gigabit-v2-squashfs-sysupgrade.bin
- SHA-256: `c56e593931458ce3ba5f78d9461d837bc62b7c1a9c7e3d2162b45046aa69b8c1`
- Size: 8061527 bytes
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

- binwalk -eM --directory known_firmware/extracted/c56e593931458ce3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c56e593931458ce3/_openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-4a-gigabit-v2-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
