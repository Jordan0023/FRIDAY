# Firmware Audit: OpenWrt Netcraze NC-1812 / openwrt-25.12.5-mediatek-filogic-netcraze_nc-1812-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-netcraze_nc-1812-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Netcraze_NC-1812/openwrt-25.12.5-mediatek-filogic-netcraze_nc-1812-squashfs-sysupgrade.bin
- SHA-256: `7a4ad0d74a86149507675c113e8f74b2810bb634242a2b39fcd3263c3b406803`
- Size: 11397392 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7a4ad0d74a861495 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7a4ad0d74a861495/_openwrt-25.12.5-mediatek-filogic-netcraze_nc-1812-squashfs-sysupgrade.bin.extracted/sysupgrade-netcraze_nc-1812/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
