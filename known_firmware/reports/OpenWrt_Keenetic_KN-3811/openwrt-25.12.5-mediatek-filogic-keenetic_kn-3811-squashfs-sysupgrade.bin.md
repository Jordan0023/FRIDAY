# Firmware Audit: OpenWrt Keenetic KN-3811 / openwrt-25.12.5-mediatek-filogic-keenetic_kn-3811-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-keenetic_kn-3811-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KN-3811/openwrt-25.12.5-mediatek-filogic-keenetic_kn-3811-squashfs-sysupgrade.bin
- SHA-256: `6d8abd7cda8f505bf6eda091f8f912c851941a4984369984a8ef4e58981de35c`
- Size: 9554192 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6d8abd7cda8f505b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6d8abd7cda8f505b/_openwrt-25.12.5-mediatek-filogic-keenetic_kn-3811-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kn-3811/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
