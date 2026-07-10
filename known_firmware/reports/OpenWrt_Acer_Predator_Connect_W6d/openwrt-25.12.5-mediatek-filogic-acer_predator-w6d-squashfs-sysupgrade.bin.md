# Firmware Audit: OpenWrt Acer Predator Connect W6d / openwrt-25.12.5-mediatek-filogic-acer_predator-w6d-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-acer_predator-w6d-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Acer_Predator_Connect_W6d/openwrt-25.12.5-mediatek-filogic-acer_predator-w6d-squashfs-sysupgrade.bin
- SHA-256: `c3e62d963b30f1b1d023c5977e161dbda2afb65d48d04c185eb0301eba3c6bd4`
- Size: 11172114 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c3e62d963b30f1b1 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c3e62d963b30f1b1/_openwrt-25.12.5-mediatek-filogic-acer_predator-w6d-squashfs-sysupgrade.bin.extracted/sysupgrade-acer_predator-w6d/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
