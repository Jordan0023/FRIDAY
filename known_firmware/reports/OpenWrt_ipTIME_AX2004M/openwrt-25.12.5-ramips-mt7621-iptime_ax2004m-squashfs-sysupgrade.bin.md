# Firmware Audit: OpenWrt ipTIME AX2004M / openwrt-25.12.5-ramips-mt7621-iptime_ax2004m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iptime_ax2004m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_AX2004M/openwrt-25.12.5-ramips-mt7621-iptime_ax2004m-squashfs-sysupgrade.bin
- SHA-256: `e70acb89aa4a9e53e9b7308b1551cc6372086391d62a778bea701921c772c127`
- Size: 8151847 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e70acb89aa4a9e53 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e70acb89aa4a9e53/_openwrt-25.12.5-ramips-mt7621-iptime_ax2004m-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_ax2004m/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
