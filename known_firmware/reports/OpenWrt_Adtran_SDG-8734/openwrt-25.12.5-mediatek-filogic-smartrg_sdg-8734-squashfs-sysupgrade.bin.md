# Firmware Audit: OpenWrt Adtran SDG-8734 / openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8734-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8734-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Adtran_SDG-8734/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8734-squashfs-sysupgrade.bin
- SHA-256: `c707d897036dd757c96bdccb5b9e4ddba2da9150df09f567764a777b4b0df22e`
- Size: 12810512 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c707d897036dd757 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c707d897036dd757/_openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8734-squashfs-sysupgrade.bin.extracted/sysupgrade-smartrg_sdg-8734/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
