# Firmware Audit: OpenWrt TOTOLINK X6000R / openwrt-25.12.5-mediatek-filogic-totolink_x6000r-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-totolink_x6000r-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TOTOLINK_X6000R/openwrt-25.12.5-mediatek-filogic-totolink_x6000r-squashfs-sysupgrade.bin
- SHA-256: `bb72be2f153bc6d26dc82e64ea727e3c8ec0c9a4702d96b4e0669cb26cae0807`
- Size: 9699602 bytes
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

- binwalk -eM --directory known_firmware/extracted/bb72be2f153bc6d2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bb72be2f153bc6d2/_openwrt-25.12.5-mediatek-filogic-totolink_x6000r-squashfs-sysupgrade.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
