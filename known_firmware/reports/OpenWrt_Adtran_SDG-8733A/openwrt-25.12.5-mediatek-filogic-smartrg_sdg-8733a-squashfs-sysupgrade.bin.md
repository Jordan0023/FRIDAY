# Firmware Audit: OpenWrt Adtran SDG-8733A / openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733a-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733a-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Adtran_SDG-8733A/openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733a-squashfs-sysupgrade.bin
- SHA-256: `3a6fcc3116ca7adf5deabfc9d4de7e50a047692ca95d6cb2da4a89d09166e3ac`
- Size: 12738834 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a6fcc3116ca7adf exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3a6fcc3116ca7adf/_openwrt-25.12.5-mediatek-filogic-smartrg_sdg-8733a-squashfs-sysupgrade.bin.extracted/sysupgrade-smartrg_sdg-8733a/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
