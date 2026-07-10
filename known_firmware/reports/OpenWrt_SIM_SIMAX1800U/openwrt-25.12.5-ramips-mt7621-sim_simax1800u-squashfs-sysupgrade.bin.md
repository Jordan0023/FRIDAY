# Firmware Audit: OpenWrt SIM SIMAX1800U / openwrt-25.12.5-ramips-mt7621-sim_simax1800u-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-sim_simax1800u-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_SIM_SIMAX1800U/openwrt-25.12.5-ramips-mt7621-sim_simax1800u-squashfs-sysupgrade.bin
- SHA-256: `d27e622a07ea48cf183b817a3ef87c121e7daa91ebab083597fc291d8ec78a5d`
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

- binwalk -eM --directory known_firmware/extracted/d27e622a07ea48cf exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d27e622a07ea48cf/_openwrt-25.12.5-ramips-mt7621-sim_simax1800u-squashfs-sysupgrade.bin.extracted/sysupgrade-sim_simax1800u/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
