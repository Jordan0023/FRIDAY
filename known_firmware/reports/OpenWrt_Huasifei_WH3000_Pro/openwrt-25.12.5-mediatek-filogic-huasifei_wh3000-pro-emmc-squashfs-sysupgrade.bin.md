# Firmware Audit: OpenWrt Huasifei WH3000 Pro / openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-emmc-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-emmc-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Huasifei_WH3000_Pro/openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-emmc-squashfs-sysupgrade.bin
- SHA-256: `93f58207c65ee8028f8038c3d00f0b7277acfe0fef9531dbce1675916236ad3a`
- Size: 9677110 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/93f58207c65ee802 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/93f58207c65ee802/_openwrt-25.12.5-mediatek-filogic-huasifei_wh3000-pro-emmc-squashfs-sysupgrade.bin.extracted/sysupgrade-huasifei_wh3000-pro-emmc/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
