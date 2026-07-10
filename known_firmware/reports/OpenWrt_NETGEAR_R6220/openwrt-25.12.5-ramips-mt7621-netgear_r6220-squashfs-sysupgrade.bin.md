# Firmware Audit: OpenWrt NETGEAR R6220 / openwrt-25.12.5-ramips-mt7621-netgear_r6220-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_r6220-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_R6220/openwrt-25.12.5-ramips-mt7621-netgear_r6220-squashfs-sysupgrade.bin
- SHA-256: `8d9750f9b65d625332c7246d7ab70480ddeb44c424f847ee96ab16e0abaad2e5`
- Size: 7782958 bytes
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

- binwalk -eM --directory known_firmware/extracted/8d9750f9b65d6253 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8d9750f9b65d6253/_openwrt-25.12.5-ramips-mt7621-netgear_r6220-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_r6220/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
