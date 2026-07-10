# Firmware Audit: OpenWrt I-O DATA WN-DX1200GR / openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1200gr-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1200gr-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-DX1200GR/openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1200gr-squashfs-sysupgrade.bin
- SHA-256: `e0fff224837a5a3aebc9517a619df5cb678452d8fdad0b0309a6316be7f39265`
- Size: 8090159 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e0fff224837a5a3a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e0fff224837a5a3a/_openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1200gr-squashfs-sysupgrade.bin.extracted/sysupgrade-iodata_wn-dx1200gr/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
