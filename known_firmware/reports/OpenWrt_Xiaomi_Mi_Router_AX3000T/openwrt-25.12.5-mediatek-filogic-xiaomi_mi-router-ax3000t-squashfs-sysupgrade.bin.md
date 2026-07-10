# Firmware Audit: OpenWrt Xiaomi Mi Router AX3000T / openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-ax3000t-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-ax3000t-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_AX3000T/openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-ax3000t-squashfs-sysupgrade.bin
- SHA-256: `a94ac2c7177b451a29c576970cb19ed2d669031f65aca2ded80fc71ae91b9eea`
- Size: 9400608 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a94ac2c7177b451a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a94ac2c7177b451a/_openwrt-25.12.5-mediatek-filogic-xiaomi_mi-router-ax3000t-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_mi-router-ax3000t/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
