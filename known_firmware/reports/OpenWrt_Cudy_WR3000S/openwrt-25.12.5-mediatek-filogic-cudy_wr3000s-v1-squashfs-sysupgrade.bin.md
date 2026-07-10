# Firmware Audit: OpenWrt Cudy WR3000S / openwrt-25.12.5-mediatek-filogic-cudy_wr3000s-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_wr3000s-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_WR3000S/openwrt-25.12.5-mediatek-filogic-cudy_wr3000s-v1-squashfs-sysupgrade.bin
- SHA-256: `b0a26c80fa458b4b743508a6a6de8aa9d19867fa3deb1c3c49e40194d61aa8b2`
- Size: 9390356 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b0a26c80fa458b4b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b0a26c80fa458b4b/_openwrt-25.12.5-mediatek-filogic-cudy_wr3000s-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-cudy_wr3000s-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
