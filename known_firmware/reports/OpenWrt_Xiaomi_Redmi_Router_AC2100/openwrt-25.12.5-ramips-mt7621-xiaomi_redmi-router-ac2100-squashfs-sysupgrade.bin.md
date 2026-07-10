# Firmware Audit: OpenWrt Xiaomi Redmi Router AC2100 / openwrt-25.12.5-ramips-mt7621-xiaomi_redmi-router-ac2100-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-xiaomi_redmi-router-ac2100-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Redmi_Router_AC2100/openwrt-25.12.5-ramips-mt7621-xiaomi_redmi-router-ac2100-squashfs-sysupgrade.bin
- SHA-256: `ff12dbca8736e9a7f6a2abc0aea68a8d6dab281f251b77236f3ac030dd4ba485`
- Size: 8172103 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ff12dbca8736e9a7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ff12dbca8736e9a7/_openwrt-25.12.5-ramips-mt7621-xiaomi_redmi-router-ac2100-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_redmi-router-ac2100/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
