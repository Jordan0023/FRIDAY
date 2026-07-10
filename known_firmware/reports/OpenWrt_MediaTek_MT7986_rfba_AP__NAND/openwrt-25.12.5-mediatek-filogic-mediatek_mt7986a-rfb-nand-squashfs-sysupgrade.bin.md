# Firmware Audit: OpenWrt MediaTek MT7986 rfba AP (NAND) / openwrt-25.12.5-mediatek-filogic-mediatek_mt7986a-rfb-nand-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-mediatek_mt7986a-rfb-nand-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_MediaTek_MT7986_rfba_AP__NAND/openwrt-25.12.5-mediatek-filogic-mediatek_mt7986a-rfb-nand-squashfs-sysupgrade.bin
- SHA-256: `79c90745d89d1c66931fdaac36f626e5e5ef26de0e52178e2b8a7cfbefe18ada`
- Size: 9881891 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/79c90745d89d1c66 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/79c90745d89d1c66/_openwrt-25.12.5-mediatek-filogic-mediatek_mt7986a-rfb-nand-squashfs-sysupgrade.bin.extracted/sysupgrade-mediatek_mt7986a-rfb-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
