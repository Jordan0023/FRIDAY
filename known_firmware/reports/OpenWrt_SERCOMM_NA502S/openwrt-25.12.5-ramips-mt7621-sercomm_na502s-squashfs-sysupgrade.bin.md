# Firmware Audit: OpenWrt SERCOMM NA502S / openwrt-25.12.5-ramips-mt7621-sercomm_na502s-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-sercomm_na502s-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_SERCOMM_NA502S/openwrt-25.12.5-ramips-mt7621-sercomm_na502s-squashfs-sysupgrade.bin
- SHA-256: `24ed2aa96e759581e391c1d4b12e5bda70982dd3a2f4550ecddf734ac0125fdf`
- Size: 7793187 bytes
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

- binwalk -eM --directory known_firmware/extracted/24ed2aa96e759581 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/24ed2aa96e759581/_openwrt-25.12.5-ramips-mt7621-sercomm_na502s-squashfs-sysupgrade.bin.extracted/sysupgrade-sercomm_na502s/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
