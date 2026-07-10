# Firmware Audit: OpenWrt Zyxel EX5601-T0 / openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-ubootmod-squashfs-sysupgrade.itb

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-ubootmod-squashfs-sysupgrade.itb
- Local path: known_firmware/firmware/OpenWrt_Zyxel_EX5601-T0/openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-ubootmod-squashfs-sysupgrade.itb
- SHA-256: `0cf4cef90bf2b30b404fd6a45dcbebb613ed44b2801ae3d63620a0bc72b2864f`
- Size: 10043680 bytes
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

- binwalk -eM --directory known_firmware/extracted/0cf4cef90bf2b30b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0cf4cef90bf2b30b/_openwrt-25.12.5-mediatek-filogic-zyxel_ex5601-t0-ubootmod-squashfs-sysupgrade.itb.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
