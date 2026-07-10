# Firmware Audit: OpenWrt D-Link DAP-X1860 / openwrt-25.12.5-ramips-mt7621-dlink_dap-x1860-a1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-dlink_dap-x1860-a1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_DAP-X1860/openwrt-25.12.5-ramips-mt7621-dlink_dap-x1860-a1-squashfs-sysupgrade.bin
- SHA-256: `032e3d262dd8a77cf183f09e3f61e892f3d35ec769c1b426ff44f9479c4adf27`
- Size: 7997999 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/032e3d262dd8a77c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/032e3d262dd8a77c/_openwrt-25.12.5-ramips-mt7621-dlink_dap-x1860-a1-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_dap-x1860-a1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
