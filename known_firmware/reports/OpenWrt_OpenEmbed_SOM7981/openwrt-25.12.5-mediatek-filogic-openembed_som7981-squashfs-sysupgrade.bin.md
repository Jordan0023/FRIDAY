# Firmware Audit: OpenWrt OpenEmbed SOM7981 / openwrt-25.12.5-mediatek-filogic-openembed_som7981-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-openembed_som7981-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_OpenEmbed_SOM7981/openwrt-25.12.5-mediatek-filogic-openembed_som7981-squashfs-sysupgrade.bin
- SHA-256: `ac46d47a77b3ebfd65309e33df3d49cb98327b6ff754b026c29665a38706a0e6`
- Size: 9697554 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ac46d47a77b3ebfd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ac46d47a77b3ebfd/_openwrt-25.12.5-mediatek-filogic-openembed_som7981-squashfs-sysupgrade.bin.extracted/sysupgrade-openembed_som7981/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
