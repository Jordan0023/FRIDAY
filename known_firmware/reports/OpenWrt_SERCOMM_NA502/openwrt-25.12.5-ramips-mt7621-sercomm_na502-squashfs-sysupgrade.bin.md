# Firmware Audit: OpenWrt SERCOMM NA502 / openwrt-25.12.5-ramips-mt7621-sercomm_na502-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-sercomm_na502-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_SERCOMM_NA502/openwrt-25.12.5-ramips-mt7621-sercomm_na502-squashfs-sysupgrade.bin
- SHA-256: `526434ed35e4fc2e6d892671e18c20054c74d769acb63db13d0c501a835230f3`
- Size: 7782944 bytes
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

- binwalk -eM --directory known_firmware/extracted/526434ed35e4fc2e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/526434ed35e4fc2e/_openwrt-25.12.5-ramips-mt7621-sercomm_na502-squashfs-sysupgrade.bin.extracted/sysupgrade-sercomm_na502/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
