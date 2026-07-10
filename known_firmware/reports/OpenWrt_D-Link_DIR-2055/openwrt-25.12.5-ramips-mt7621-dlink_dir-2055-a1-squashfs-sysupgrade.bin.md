# Firmware Audit: OpenWrt D-Link DIR-2055 / openwrt-25.12.5-ramips-mt7621-dlink_dir-2055-a1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-dlink_dir-2055-a1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_DIR-2055/openwrt-25.12.5-ramips-mt7621-dlink_dir-2055-a1-squashfs-sysupgrade.bin
- SHA-256: `53a84dc41eec799c2cc0dcaaf9b78a5959cfe1bb2c3438ef7d4f6ddc755c46e7`
- Size: 8223276 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/53a84dc41eec799c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/53a84dc41eec799c/_openwrt-25.12.5-ramips-mt7621-dlink_dir-2055-a1-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_dir-2055-a1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
