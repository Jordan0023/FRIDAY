# Firmware Audit: OpenWrt MediaTek MT7621 EVB / openwrt-25.12.5-ramips-mt7621-mediatek_mt7621-eval-board-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-mediatek_mt7621-eval-board-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MediaTek_MT7621_EVB/openwrt-25.12.5-ramips-mt7621-mediatek_mt7621-eval-board-squashfs-sysupgrade.bin
- SHA-256: `defa0805dfe00147c600666860b4d2fd2e25df9eefcdc1cf101496bacc909ce7`
- Size: 6423131 bytes
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

- binwalk -eM --directory known_firmware/extracted/defa0805dfe00147 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/defa0805dfe00147/_openwrt-25.12.5-ramips-mt7621-mediatek_mt7621-eval-board-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
