# Firmware Audit: OpenWrt TP-Link BE450 / openwrt-25.12.5-mediatek-filogic-tplink_be450-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_be450-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_BE450/openwrt-25.12.5-mediatek-filogic-tplink_be450-squashfs-sysupgrade.bin
- SHA-256: `a3ac3960d434fdf96d3221feeb448ea783c7d3d39e86f0ee9eba5c643bd15eb2`
- Size: 11387144 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3ac3960d434fdf9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a3ac3960d434fdf9/_openwrt-25.12.5-mediatek-filogic-tplink_be450-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_be450/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
