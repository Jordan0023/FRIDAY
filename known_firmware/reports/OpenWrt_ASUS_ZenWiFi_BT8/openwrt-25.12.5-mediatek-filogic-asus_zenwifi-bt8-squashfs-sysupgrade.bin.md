# Firmware Audit: OpenWrt ASUS ZenWiFi BT8 / openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_ZenWiFi_BT8/openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-squashfs-sysupgrade.bin
- SHA-256: `8514d2d9b3966213345c97ba4e486100007ac4800964fe322cfec04afcfe0717`
- Size: 13885712 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8514d2d9b3966213 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8514d2d9b3966213/_openwrt-25.12.5-mediatek-filogic-asus_zenwifi-bt8-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_zenwifi-bt8/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
