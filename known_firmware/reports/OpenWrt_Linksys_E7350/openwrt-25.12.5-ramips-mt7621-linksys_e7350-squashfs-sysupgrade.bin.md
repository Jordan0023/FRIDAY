# Firmware Audit: OpenWrt Linksys E7350 / openwrt-25.12.5-ramips-mt7621-linksys_e7350-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-linksys_e7350-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_E7350/openwrt-25.12.5-ramips-mt7621-linksys_e7350-squashfs-sysupgrade.bin
- SHA-256: `ee2662cd674ebcce47724d62030b58e1cb7f0ed4cee65ec3db8dcf4d69892384`
- Size: 8151584 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ee2662cd674ebcce exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ee2662cd674ebcce/_openwrt-25.12.5-ramips-mt7621-linksys_e7350-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_e7350/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
