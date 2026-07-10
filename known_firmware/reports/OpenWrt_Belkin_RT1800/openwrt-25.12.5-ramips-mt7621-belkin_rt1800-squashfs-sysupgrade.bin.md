# Firmware Audit: OpenWrt Belkin RT1800 / openwrt-25.12.5-ramips-mt7621-belkin_rt1800-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-belkin_rt1800-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Belkin_RT1800/openwrt-25.12.5-ramips-mt7621-belkin_rt1800-squashfs-sysupgrade.bin
- SHA-256: `274d84cade57afef766e4f08867ff7f02e26513311e68d77c7a131d945eb54d8`
- Size: 8151584 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/274d84cade57afef exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/274d84cade57afef/_openwrt-25.12.5-ramips-mt7621-belkin_rt1800-squashfs-sysupgrade.bin.extracted/sysupgrade-belkin_rt1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
