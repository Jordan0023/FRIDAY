# Firmware Audit: OpenWrt MediaTek MTK7986 rfbb AP / openwrt-25.12.5-mediatek-filogic-mediatek_mt7986b-rfb-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mediatek_mt7986b-rfb-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MediaTek_MTK7986_rfbb_AP/openwrt-25.12.5-mediatek-filogic-mediatek_mt7986b-rfb-squashfs-sysupgrade.bin
- SHA-256: `88737084eae9630e293694d095f2d7487df11fca67b7e5c5e569c74dca6912d7`
- Size: 9881880 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/88737084eae9630e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/88737084eae9630e/_openwrt-25.12.5-mediatek-filogic-mediatek_mt7986b-rfb-squashfs-sysupgrade.bin.extracted/sysupgrade-mediatek_mt7986b-rfb/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
