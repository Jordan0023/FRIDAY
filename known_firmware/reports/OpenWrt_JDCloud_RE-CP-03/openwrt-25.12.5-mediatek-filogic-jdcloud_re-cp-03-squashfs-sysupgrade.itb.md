# Firmware Audit: OpenWrt JDCloud RE-CP-03 / openwrt-25.12.5-mediatek-filogic-jdcloud_re-cp-03-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-jdcloud_re-cp-03-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_JDCloud_RE-CP-03/openwrt-25.12.5-mediatek-filogic-jdcloud_re-cp-03-squashfs-sysupgrade.itb
- SHA-256: `cfbe6baca9d2cede824632b9faca00a361871c480f23143a20e386e0cf535c7f`
- Size: 12058900 bytes
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

- binwalk -eM --directory known_firmware/extracted/cfbe6baca9d2cede exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cfbe6baca9d2cede/_openwrt-25.12.5-mediatek-filogic-jdcloud_re-cp-03-squashfs-sysupgrade.itb.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
