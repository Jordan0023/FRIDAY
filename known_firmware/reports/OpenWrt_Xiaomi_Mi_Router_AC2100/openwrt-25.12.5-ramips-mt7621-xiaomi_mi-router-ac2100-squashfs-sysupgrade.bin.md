# Firmware Audit: OpenWrt Xiaomi Mi Router AC2100 / openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-ac2100-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-ac2100-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_AC2100/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-ac2100-squashfs-sysupgrade.bin
- SHA-256: `b618f68d04f2dd27785faf3cde74cedb773913d5b00e794068b680cb5cd7ee60`
- Size: 8172094 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b618f68d04f2dd27 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b618f68d04f2dd27/_openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-ac2100-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_mi-router-ac2100/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
