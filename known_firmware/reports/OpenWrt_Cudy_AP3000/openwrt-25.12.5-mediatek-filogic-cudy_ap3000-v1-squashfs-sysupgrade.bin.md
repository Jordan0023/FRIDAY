# Firmware Audit: OpenWrt Cudy AP3000 / openwrt-25.12.5-mediatek-filogic-cudy_ap3000-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_ap3000-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_AP3000/openwrt-25.12.5-mediatek-filogic-cudy_ap3000-v1-squashfs-sysupgrade.bin
- SHA-256: `cb5a0d60289a195de681ca410c2f425dd59c647fe4415f61424e4e0eb48b639f`
- Size: 9400594 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cb5a0d60289a195d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cb5a0d60289a195d/_openwrt-25.12.5-mediatek-filogic-cudy_ap3000-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_ap3000-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
