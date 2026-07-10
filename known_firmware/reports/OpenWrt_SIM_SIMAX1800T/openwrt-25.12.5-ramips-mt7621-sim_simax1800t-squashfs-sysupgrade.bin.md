# Firmware Audit: OpenWrt SIM SIMAX1800T / openwrt-25.12.5-ramips-mt7621-sim_simax1800t-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-sim_simax1800t-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_SIM_SIMAX1800T/openwrt-25.12.5-ramips-mt7621-sim_simax1800t-squashfs-sysupgrade.bin
- SHA-256: `252ef2b13d3f6e81f3cf7466944df7642ca94c970ad44a2895c9949da4a7f3e3`
- Size: 8008227 bytes
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

- binwalk -eM --directory known_firmware/extracted/252ef2b13d3f6e81 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/252ef2b13d3f6e81/_openwrt-25.12.5-ramips-mt7621-sim_simax1800t-squashfs-sysupgrade.bin.extracted/sysupgrade-sim_simax1800t/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
