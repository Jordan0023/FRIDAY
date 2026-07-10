# Firmware Audit: OpenWrt I-O DATA WN-DX2033GR / openwrt-25.12.5-ramips-mt7621-iodata_wn-dx2033gr-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-dx2033gr-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-DX2033GR/openwrt-25.12.5-ramips-mt7621-iodata_wn-dx2033gr-squashfs-sysupgrade.bin
- SHA-256: `0401b14c6cf2a6afd70f97aee90329946436d36babaa5f2b681ccc32fe20c2bd`
- Size: 8202799 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0401b14c6cf2a6af exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0401b14c6cf2a6af/_openwrt-25.12.5-ramips-mt7621-iodata_wn-dx2033gr-squashfs-sysupgrade.bin.extracted/sysupgrade-iodata_wn-dx2033gr/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
