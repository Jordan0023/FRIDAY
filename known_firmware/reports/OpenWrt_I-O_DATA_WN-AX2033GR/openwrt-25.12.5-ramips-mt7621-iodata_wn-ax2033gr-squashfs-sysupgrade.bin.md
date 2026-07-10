# Firmware Audit: OpenWrt I-O DATA WN-AX2033GR / openwrt-25.12.5-ramips-mt7621-iodata_wn-ax2033gr-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-ax2033gr-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-AX2033GR/openwrt-25.12.5-ramips-mt7621-iodata_wn-ax2033gr-squashfs-sysupgrade.bin
- SHA-256: `40dbf7eca24cb3ae5042c00255d86b9ab85f1f1985d4e28d55b507f1f4f69c46`
- Size: 8202799 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/40dbf7eca24cb3ae exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/40dbf7eca24cb3ae/_openwrt-25.12.5-ramips-mt7621-iodata_wn-ax2033gr-squashfs-sysupgrade.bin.extracted/sysupgrade-iodata_wn-ax2033gr/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
