# Firmware Audit: OpenWrt Keenetic KN-3711 / openwrt-25.12.5-mediatek-filogic-keenetic_kn-3711-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-keenetic_kn-3711-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KN-3711/openwrt-25.12.5-mediatek-filogic-keenetic_kn-3711-squashfs-sysupgrade.bin
- SHA-256: `ae39690f97f926780a20ab8137b08491161c0cdddb50990114305b1f42e35dc1`
- Size: 9390352 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ae39690f97f92678 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ae39690f97f92678/_openwrt-25.12.5-mediatek-filogic-keenetic_kn-3711-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kn-3711/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
