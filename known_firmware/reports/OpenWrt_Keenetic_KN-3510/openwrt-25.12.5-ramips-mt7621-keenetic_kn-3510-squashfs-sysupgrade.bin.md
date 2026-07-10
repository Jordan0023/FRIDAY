# Firmware Audit: OpenWrt Keenetic KN-3510 / openwrt-25.12.5-ramips-mt7621-keenetic_kn-3510-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-keenetic_kn-3510-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KN-3510/openwrt-25.12.5-ramips-mt7621-keenetic_kn-3510-squashfs-sysupgrade.bin
- SHA-256: `ca503fb7fd2050e0a824133c796a1a52f958384155907809ac5ece7f3d74211e`
- Size: 7987753 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ca503fb7fd2050e0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ca503fb7fd2050e0/_openwrt-25.12.5-ramips-mt7621-keenetic_kn-3510-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kn-3510/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
