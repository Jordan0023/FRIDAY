# Firmware Audit: OpenWrt Keenetic KN-1812 / openwrt-25.12.5-mediatek-filogic-keenetic_kn-1812-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-keenetic_kn-1812-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KN-1812/openwrt-25.12.5-mediatek-filogic-keenetic_kn-1812-squashfs-sysupgrade.bin
- SHA-256: `fa87d14478b3a9756cbd6453a52021e432cda746878388f58e5da2ee50eb2da4`
- Size: 11397392 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fa87d14478b3a975 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fa87d14478b3a975/_openwrt-25.12.5-mediatek-filogic-keenetic_kn-1812-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kn-1812/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
