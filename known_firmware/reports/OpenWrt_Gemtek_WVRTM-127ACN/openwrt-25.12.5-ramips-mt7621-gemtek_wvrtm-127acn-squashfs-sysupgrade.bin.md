# Firmware Audit: OpenWrt Gemtek WVRTM-127ACN / openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-127acn-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-127acn-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Gemtek_WVRTM-127ACN/openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-127acn-squashfs-sysupgrade.bin
- SHA-256: `9726b8a88e2ae2657e9ce5705587981e93da4c6f0331502b476ec9cd8fbe888a`
- Size: 7793202 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9726b8a88e2ae265 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9726b8a88e2ae265/_openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-127acn-squashfs-sysupgrade.bin.extracted/sysupgrade-gemtek_wvrtm-127acn/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
