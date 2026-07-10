# Firmware Audit: OpenWrt NETGEAR WAX220 / openwrt-25.12.5-mediatek-filogic-netgear_wax220-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-netgear_wax220-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_WAX220/openwrt-25.12.5-mediatek-filogic-netgear_wax220-squashfs-sysupgrade.bin
- SHA-256: `4a345fe45d2a062c7b0de3ae6b6115326fcde6af43206794f831c66dc7328f03`
- Size: 9881868 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4a345fe45d2a062c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4a345fe45d2a062c/_openwrt-25.12.5-mediatek-filogic-netgear_wax220-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_wax220/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
