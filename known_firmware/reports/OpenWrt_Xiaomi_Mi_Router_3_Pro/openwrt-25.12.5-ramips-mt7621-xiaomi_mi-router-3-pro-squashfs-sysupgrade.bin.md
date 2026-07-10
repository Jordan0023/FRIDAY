# Firmware Audit: OpenWrt Xiaomi Mi Router 3 Pro / openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3-pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3-pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_3_Pro/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3-pro-squashfs-sysupgrade.bin
- SHA-256: `41cf853136412255f99a1650db27ef7edbad50d7fdb96ff661eb301a64201342`
- Size: 8243799 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/41cf853136412255 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/41cf853136412255/_openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-3-pro-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_mi-router-3-pro/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
