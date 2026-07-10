# Firmware Audit: OpenWrt I-O DATA WN-AX1167GR2 / openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_I-O_DATA_WN-AX1167GR2/openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr2-squashfs-sysupgrade.bin
- SHA-256: `55fbd905131d106ba236b5f4de819fb24af37380d8bd4c64ee9a110a1ee22428`
- Size: 8131122 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Pwd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/55fbd905131d106b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/55fbd905131d106b/_openwrt-25.12.5-ramips-mt7621-iodata_wn-ax1167gr2-squashfs-sysupgrade.bin.extracted/sysupgrade-iodata_wn-ax1167gr2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
