# Firmware Audit: OpenWrt TP-Link EAP683-LR / openwrt-25.12.5-mediatek-filogic-tplink_eap683-lr-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_eap683-lr-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_EAP683-LR/openwrt-25.12.5-mediatek-filogic-tplink_eap683-lr-squashfs-sysupgrade.bin
- SHA-256: `63012d2feb75cbd55089e77bf1bde55974c00a8889742318307b339babd3c104`
- Size: 9881872 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/63012d2feb75cbd5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/63012d2feb75cbd5/_openwrt-25.12.5-mediatek-filogic-tplink_eap683-lr-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_eap683-lr/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
