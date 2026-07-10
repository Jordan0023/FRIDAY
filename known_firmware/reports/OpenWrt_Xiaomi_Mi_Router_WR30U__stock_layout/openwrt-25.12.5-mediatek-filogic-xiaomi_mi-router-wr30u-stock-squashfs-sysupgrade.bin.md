# Firmware Audit: OpenWrt Xiaomi Mi Router WR30U (stock layout) / openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-wr30u-stock-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-wr30u-stock-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_WR30U__stock_layout/openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-wr30u-stock-squashfs-sysupgrade.bin
- SHA-256: `46af6c7cb643c500870d63e750f7f3343369aa579f227eda88c65ba7b81c3b7c`
- Size: 9400616 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/46af6c7cb643c500 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/46af6c7cb643c500/_openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-wr30u-stock-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_mi-router-wr30u-stock/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
