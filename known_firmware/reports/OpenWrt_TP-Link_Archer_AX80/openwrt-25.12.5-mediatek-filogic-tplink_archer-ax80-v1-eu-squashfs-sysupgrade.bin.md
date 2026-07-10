# Firmware Audit: OpenWrt TP-Link Archer AX80 / openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-eu-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-eu-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_Archer_AX80/openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-eu-squashfs-sysupgrade.bin
- SHA-256: `832f724227ce015b429ad33dbb0776ceb868ec3f61eb66440215d40d2a9de9a5`
- Size: 10035488 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/832f724227ce015b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/832f724227ce015b/_openwrt-25.12.5-mediatek-filogic-tplink_archer-ax80-v1-eu-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_archer-ax80-v1-eu/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
