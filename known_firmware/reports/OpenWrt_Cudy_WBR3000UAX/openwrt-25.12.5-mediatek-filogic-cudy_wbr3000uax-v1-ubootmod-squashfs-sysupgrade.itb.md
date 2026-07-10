# Firmware Audit: OpenWrt Cudy WBR3000UAX / openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-ubootmod-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-ubootmod-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_Cudy_WBR3000UAX/openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-ubootmod-squashfs-sysupgrade.itb
- SHA-256: `60edbb6fa6e35d0a60bc0837fb79067d1d94fb13dbc807f89326dafe45204815`
- Size: 11129126 bytes
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

- binwalk -eM --directory known_firmware/extracted/60edbb6fa6e35d0a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/60edbb6fa6e35d0a/_openwrt-25.12.5-mediatek-filogic-cudy_wbr3000uax-v1-ubootmod-squashfs-sysupgrade.itb.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
