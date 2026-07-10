# Firmware Audit: OpenWrt Acer Connect Vero W6m / openwrt-25.12.5-mediatek-filogic-acer_vero-w6m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-acer_vero-w6m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Acer_Connect_Vero_W6m/openwrt-25.12.5-mediatek-filogic-acer_vero-w6m-squashfs-sysupgrade.bin
- SHA-256: `235c45bd28675f2567341a9506b62ffc479c2f196feaa1ad674d38ddaebed06f`
- Size: 11008266 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/235c45bd28675f25 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/235c45bd28675f25/_openwrt-25.12.5-mediatek-filogic-acer_vero-w6m-squashfs-sysupgrade.bin.extracted/sysupgrade-acer_vero-w6m/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
