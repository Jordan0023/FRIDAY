# Firmware Audit: OpenWrt D-Link DIR-853 / openwrt-25.12.5-ramips-mt7621-dlink_dir-853-a3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-dlink_dir-853-a3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_DIR-853/openwrt-25.12.5-ramips-mt7621-dlink_dir-853-a3-squashfs-sysupgrade.bin
- SHA-256: `19b57dff63b06aaa9445953b9736ce68eb7795fd1b1cc340c91289cadc3dd40b`
- Size: 8233513 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/19b57dff63b06aaa exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/19b57dff63b06aaa/_openwrt-25.12.5-ramips-mt7621-dlink_dir-853-a3-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_dir-853-a3/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
