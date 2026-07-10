# Firmware Audit: OpenWrt Airpi AP3000M / openwrt-25.12.5-mediatek-filogic-airpi_ap3000m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-airpi_ap3000m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Airpi_AP3000M/openwrt-25.12.5-mediatek-filogic-airpi_ap3000m-squashfs-sysupgrade.bin
- SHA-256: `ce9d1bf545b36686e00f8897fe1dd1a113b5b9c713784e6b8f88296f1911e453`
- Size: 9677066 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ce9d1bf545b36686 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ce9d1bf545b36686/_openwrt-25.12.5-mediatek-filogic-airpi_ap3000m-squashfs-sysupgrade.bin.extracted/sysupgrade-airpi_ap3000m/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
