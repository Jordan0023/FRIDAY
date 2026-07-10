# Firmware Audit: OpenWrt Routerich AX3000 / openwrt-25.12.5-mediatek-filogic-routerich_ax3000-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-routerich_ax3000-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Routerich_AX3000/openwrt-25.12.5-mediatek-filogic-routerich_ax3000-v1-squashfs-sysupgrade.bin
- SHA-256: `2f72a1970843f8258a83ad687a9da12e12e8d59d96b64849efd7ec0bd6e9eac2`
- Size: 9554231 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2f72a1970843f825 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2f72a1970843f825/_openwrt-25.12.5-mediatek-filogic-routerich_ax3000-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-routerich_ax3000-v1/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
