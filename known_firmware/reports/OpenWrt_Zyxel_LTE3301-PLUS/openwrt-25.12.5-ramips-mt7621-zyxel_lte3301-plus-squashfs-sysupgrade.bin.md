# Firmware Audit: OpenWrt Zyxel LTE3301-PLUS / openwrt-25.12.5-ramips-mt7621-zyxel_lte3301-plus-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-zyxel_lte3301-plus-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_LTE3301-PLUS/openwrt-25.12.5-ramips-mt7621-zyxel_lte3301-plus-squashfs-sysupgrade.bin
- SHA-256: `2cf14f8e5252795115be8a068942801baba6b70559ba8ee637ab1a1bb06e26e7`
- Size: 8335919 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2cf14f8e52527951 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2cf14f8e52527951/_openwrt-25.12.5-ramips-mt7621-zyxel_lte3301-plus-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_lte3301-plus/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
