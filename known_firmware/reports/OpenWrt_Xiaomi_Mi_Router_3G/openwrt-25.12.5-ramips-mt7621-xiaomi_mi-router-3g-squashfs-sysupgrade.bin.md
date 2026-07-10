# Firmware Audit: OpenWrt Xiaomi Mi Router 3G / openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3g-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3g-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_3G/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3g-squashfs-sysupgrade.bin
- SHA-256: `cdde5ceea7b4c5c044b23b34f1d93c332697fbafc7aac1c7eee8323904b12c21`
- Size: 7793254 bytes
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

- binwalk -eM --directory known_firmware/extracted/cdde5ceea7b4c5c0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cdde5ceea7b4c5c0/_openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3g-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_mi-router-3g/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
