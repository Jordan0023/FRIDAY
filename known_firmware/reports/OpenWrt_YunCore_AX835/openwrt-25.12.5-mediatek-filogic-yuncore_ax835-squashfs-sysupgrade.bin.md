# Firmware Audit: OpenWrt YunCore AX835 / openwrt-25.12.5-mediatek-filogic-yuncore_ax835-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-yuncore_ax835-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_YunCore_AX835/openwrt-25.12.5-mediatek-filogic-yuncore_ax835-squashfs-sysupgrade.bin
- SHA-256: `bb0a9e5ba94fdcac7170784fcbb43779a928ed8354d23fd19eb0b5462aff9bd9`
- Size: 9699629 bytes
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

- binwalk -eM --directory known_firmware/extracted/bb0a9e5ba94fdcac exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bb0a9e5ba94fdcac/_openwrt-25.12.5-mediatek-filogic-yuncore_ax835-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
