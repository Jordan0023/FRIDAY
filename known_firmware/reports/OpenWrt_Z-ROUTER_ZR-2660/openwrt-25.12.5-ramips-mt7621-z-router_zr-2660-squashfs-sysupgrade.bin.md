# Firmware Audit: OpenWrt Z-ROUTER ZR-2660 / openwrt-25.12.5-ramips-mt7621-z-router_zr-2660-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-z-router_zr-2660-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Z-ROUTER_ZR-2660/openwrt-25.12.5-ramips-mt7621-z-router_zr-2660-squashfs-sysupgrade.bin
- SHA-256: `6cb6d5a5a1220e7a5746029b4405c85fa2bd60144433788345a4f42b34d35f25`
- Size: 8141353 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6cb6d5a5a1220e7a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6cb6d5a5a1220e7a/_openwrt-25.12.5-ramips-mt7621-z-router_zr-2660-squashfs-sysupgrade.bin.extracted/sysupgrade-z-router_zr-2660/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
