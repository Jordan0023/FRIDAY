# Firmware Audit: OpenWrt D-Link DIR-3060 / openwrt-25.12.5-ramips-mt7621-dlink_dir-3060-a1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-dlink_dir-3060-a1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_DIR-3060/openwrt-25.12.5-ramips-mt7621-dlink_dir-3060-a1-squashfs-sysupgrade.bin
- SHA-256: `9fb49eff5cb2d06e4ef53f37f138ddf5ce22f135b8c6edf1a218fcdc0c63b197`
- Size: 8233516 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9fb49eff5cb2d06e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9fb49eff5cb2d06e/_openwrt-25.12.5-ramips-mt7621-dlink_dir-3060-a1-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_dir-3060-a1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
