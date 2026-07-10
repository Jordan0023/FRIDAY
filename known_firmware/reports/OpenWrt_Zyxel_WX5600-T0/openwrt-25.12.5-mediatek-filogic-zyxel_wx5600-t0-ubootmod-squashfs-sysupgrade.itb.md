# Firmware Audit: OpenWrt Zyxel WX5600-T0 / openwrt-25.12.5-mediatek-filogic-zyxel_wx5600-t0-ubootmod-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zyxel_wx5600-t0-ubootmod-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_Zyxel_WX5600-T0/openwrt-25.12.5-mediatek-filogic-zyxel_wx5600-t0-ubootmod-squashfs-sysupgrade.itb
- SHA-256: `abb9482684903f837cb9f41520d62db3393c29fb59961d50b8005637a1b1120d`
- Size: 9879840 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/abb9482684903f83 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/abb9482684903f83/_openwrt-25.12.5-mediatek-filogic-zyxel_wx5600-t0-ubootmod-squashfs-sysupgrade.itb.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
