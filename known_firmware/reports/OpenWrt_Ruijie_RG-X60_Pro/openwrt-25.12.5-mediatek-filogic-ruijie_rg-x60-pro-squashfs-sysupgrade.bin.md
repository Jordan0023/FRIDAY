# Firmware Audit: OpenWrt Ruijie RG-X60 Pro / openwrt-25.12.5-mediatek-filogic-ruijie_rg-x60-pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-ruijie_rg-x60-pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ruijie_RG-X60_Pro/openwrt-25.12.5-mediatek-filogic-ruijie_rg-x60-pro-squashfs-sysupgrade.bin
- SHA-256: `f18986bd466dc3a29bf68a77443e5862017a079408fcf489207e343d87c1e47e`
- Size: 9881874 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f18986bd466dc3a2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f18986bd466dc3a2/_openwrt-25.12.5-mediatek-filogic-ruijie_rg-x60-pro-squashfs-sysupgrade.bin.extracted/sysupgrade-ruijie_rg-x60-pro/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
