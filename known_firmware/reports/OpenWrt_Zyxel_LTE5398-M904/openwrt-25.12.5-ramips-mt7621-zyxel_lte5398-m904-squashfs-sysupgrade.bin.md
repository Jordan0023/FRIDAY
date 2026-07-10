# Firmware Audit: OpenWrt Zyxel LTE5398-M904 / openwrt-25.12.5-ramips-mt7621-zyxel_lte5398-m904-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-zyxel_lte5398-m904-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_LTE5398-M904/openwrt-25.12.5-ramips-mt7621-zyxel_lte5398-m904-squashfs-sysupgrade.bin
- SHA-256: `47ef5aa708d45ff73677649777e788c87c6d835cfebbda8127f4eece5f0a8d0f`
- Size: 8407599 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/47ef5aa708d45ff7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/47ef5aa708d45ff7/_openwrt-25.12.5-ramips-mt7621-zyxel_lte5398-m904-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_lte5398-m904/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
