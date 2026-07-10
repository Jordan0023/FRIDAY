# Firmware Audit: OpenWrt Ubiquiti UniFi U6+ / openwrt-25.12.5-mediatek-filogic-ubnt_unifi-6-plus-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-ubnt_unifi-6-plus-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Ubiquiti_UniFi_U6/openwrt-25.12.5-mediatek-filogic-ubnt_unifi-6-plus-squashfs-sysupgrade.bin
- SHA-256: `7f8f645883e62383eda54cedb4fd87c9e44c8b4cea68771c169402fbe67b65c8`
- Size: 10332434 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7f8f645883e62383 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7f8f645883e62383/_openwrt-25.12.5-mediatek-filogic-ubnt_unifi-6-plus-squashfs-sysupgrade.bin.extracted/sysupgrade-ubnt_unifi-6-plus/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
