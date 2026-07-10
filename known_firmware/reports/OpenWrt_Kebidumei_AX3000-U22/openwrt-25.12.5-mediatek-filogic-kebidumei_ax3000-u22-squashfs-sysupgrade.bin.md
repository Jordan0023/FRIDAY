# Firmware Audit: OpenWrt Kebidumei AX3000-U22 / openwrt-25.12.5-mediatek-filogic-kebidumei_ax3000-u22-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-kebidumei_ax3000-u22-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Kebidumei_AX3000-U22/openwrt-25.12.5-mediatek-filogic-kebidumei_ax3000-u22-squashfs-sysupgrade.bin
- SHA-256: `9c3b7963783d2eaf453ce36f9e0ea6339dd04754a5ad3295c78dcc1123a6189d`
- Size: 9699643 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9c3b7963783d2eaf exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9c3b7963783d2eaf/_openwrt-25.12.5-mediatek-filogic-kebidumei_ax3000-u22-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
