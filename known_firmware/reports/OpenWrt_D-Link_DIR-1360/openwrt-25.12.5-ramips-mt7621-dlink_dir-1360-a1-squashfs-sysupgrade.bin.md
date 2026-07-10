# Firmware Audit: OpenWrt D-Link DIR-1360 / openwrt-25.12.5-ramips-mt7621-dlink_dir-1360-a1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-dlink_dir-1360-a1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_DIR-1360/openwrt-25.12.5-ramips-mt7621-dlink_dir-1360-a1-squashfs-sysupgrade.bin
- SHA-256: `c59bfa2904a4bc16d6cac35b435e10f21e7105fb4b7581e5093899e520d91a86`
- Size: 8243756 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c59bfa2904a4bc16 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c59bfa2904a4bc16/_openwrt-25.12.5-ramips-mt7621-dlink_dir-1360-a1-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_dir-1360-a1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
