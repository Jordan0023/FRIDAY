# Firmware Audit: OpenWrt netis N6 / openwrt-25.12.5-ramips-mt7621-netis_n6-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netis_n6-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_netis_N6/openwrt-25.12.5-ramips-mt7621-netis_n6-squashfs-sysupgrade.bin
- SHA-256: `3545805e24dc78fa900485c258e70593fd74bd116f18866d76a5b36bb68e3053`
- Size: 8151569 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3545805e24dc78fa exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3545805e24dc78fa/_openwrt-25.12.5-ramips-mt7621-netis_n6-squashfs-sysupgrade.bin.extracted/sysupgrade-netis_n6/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
