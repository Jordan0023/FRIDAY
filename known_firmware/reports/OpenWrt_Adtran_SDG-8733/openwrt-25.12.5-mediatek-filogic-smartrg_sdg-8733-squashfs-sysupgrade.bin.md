# Firmware Audit: OpenWrt Adtran SDG-8733 / openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Adtran_SDG-8733/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733-squashfs-sysupgrade.bin
- SHA-256: `b19ee93cfd3a4cd82614d95d25d166c75bb2e4d98df49c13b1539401be71c1dd`
- Size: 12800272 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b19ee93cfd3a4cd8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b19ee93cfd3a4cd8/_openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733-squashfs-sysupgrade.bin.extracted/sysupgrade-smartrg_sdg-8733/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
