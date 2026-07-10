# Firmware Audit: OpenWrt Adtran SDG-8622 / openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8622-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8622-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Adtran_SDG-8622/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8622-squashfs-sysupgrade.bin
- SHA-256: `e383c27f637fd105abe8be45ee53d0c01347904de313f20b490cd7ba1226eb13`
- Size: 10864912 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e383c27f637fd105 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e383c27f637fd105/_openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8622-squashfs-sysupgrade.bin.extracted/sysupgrade-smartrg_sdg-8622/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
