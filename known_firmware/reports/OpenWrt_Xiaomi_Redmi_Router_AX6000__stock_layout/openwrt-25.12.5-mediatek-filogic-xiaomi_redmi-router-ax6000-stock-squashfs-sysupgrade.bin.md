# Firmware Audit: OpenWrt Xiaomi Redmi Router AX6000 (stock layout) / openwrt-25.12.5-mediatek-filogic-xiaomi_redmi-router-ax6000-stock-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-xiaomi_redmi-router-ax6000-stock-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Redmi_Router_AX6000__stock_layout/openwrt-25.12.5-mediatek-filogic-xiaomi_redmi-router-ax6000-stock-squashfs-sysupgrade.bin
- SHA-256: `08bea88e06cd580576c4ce70a30a569f7ddb3a942453599244e685e375e0a25f`
- Size: 9881904 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/08bea88e06cd5805 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/08bea88e06cd5805/_openwrt-25.12.5-mediatek-filogic-xiaomi_redmi-router-ax6000-stock-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_redmi-router-ax6000-stock/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
