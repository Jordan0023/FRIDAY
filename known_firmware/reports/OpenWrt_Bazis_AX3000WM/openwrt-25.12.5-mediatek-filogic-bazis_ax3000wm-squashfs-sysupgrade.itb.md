# Firmware Audit: OpenWrt Bazis AX3000WM / openwrt-25.12.5-mediatek-filogic-bazis_ax3000wm-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-bazis_ax3000wm-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_Bazis_AX3000WM/openwrt-25.12.5-mediatek-filogic-bazis_ax3000wm-squashfs-sysupgrade.itb
- SHA-256: `98018661b2a1f7e93a465998958adf350471e839e4f908588195938d7d070b69`
- Size: 11129100 bytes
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

- binwalk -eM --directory known_firmware/extracted/98018661b2a1f7e9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/98018661b2a1f7e9/_openwrt-25.12.5-mediatek-filogic-bazis_ax3000wm-squashfs-sysupgrade.itb.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
