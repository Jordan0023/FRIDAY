# Firmware Audit: OpenWrt Acelink EW-7886CAX / openwrt-25.12.5-mediatek-filogic-acelink_ew-7886cax-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-acelink_ew-7886cax-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Acelink_EW-7886CAX/openwrt-25.12.5-mediatek-filogic-acelink_ew-7886cax-squashfs-sysupgrade.bin
- SHA-256: `7b44ca7f5358eb3c5cb1bd3fdcb0208caf320a74b1c1ac19fe88d4d5feb96687`
- Size: 9881876 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7b44ca7f5358eb3c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7b44ca7f5358eb3c/_openwrt-25.12.5-mediatek-filogic-acelink_ew-7886cax-squashfs-sysupgrade.bin.extracted/sysupgrade-acelink_ew-7886cax/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
