# Firmware Audit: OpenWrt I-O DATA WN-DX1167R / openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1167r-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1167r-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-DX1167R/openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1167r-squashfs-sysupgrade.bin
- SHA-256: `2022bdbb32a0b6bbe0e0452f8d3a725fc22ab5e74fc59fd8aec70b9ea569f2f4`
- Size: 8131116 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2022bdbb32a0b6bb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2022bdbb32a0b6bb/_openwrt-25.12.5-ramips-mt7621-iodata_wn-dx1167r-squashfs-sysupgrade.bin.extracted/sysupgrade-iodata_wn-dx1167r/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
