# Firmware Audit: OpenWrt Routerich AX3000 / openwrt-25.12.5-mediatek-filogic-routerich_ax3000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-routerich_ax3000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Routerich_AX3000/openwrt-25.12.5-mediatek-filogic-routerich_ax3000-squashfs-sysupgrade.bin
- SHA-256: `12e757658d7b8c4b1619f97285c5c1cdca221a4622d3e18af1fe43e8919febf6`
- Size: 9554846 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/12e757658d7b8c4b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/12e757658d7b8c4b/_openwrt-25.12.5-mediatek-filogic-routerich_ax3000-squashfs-sysupgrade.bin.extracted/sysupgrade-routerich_ax3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
