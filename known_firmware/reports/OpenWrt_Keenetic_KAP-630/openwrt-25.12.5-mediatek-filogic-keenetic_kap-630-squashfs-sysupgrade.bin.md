# Firmware Audit: OpenWrt Keenetic KAP-630 / openwrt-25.12.5-mediatek-filogic-keenetic_kap-630-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-keenetic_kap-630-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KAP-630/openwrt-25.12.5-mediatek-filogic-keenetic_kap-630-squashfs-sysupgrade.bin
- SHA-256: `6de37660ac115863a219e9256d8857c44b11dc949db61b932d2463b5313527f1`
- Size: 9441552 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6de37660ac115863 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6de37660ac115863/_openwrt-25.12.5-mediatek-filogic-keenetic_kap-630-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kap-630/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
