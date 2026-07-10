# Firmware Audit: OpenWrt Linksys EA6350 / openwrt-25.12.5-ramips-mt7621-linksys_ea6350-v4-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-linksys_ea6350-v4-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_EA6350/openwrt-25.12.5-ramips-mt7621-linksys_ea6350-v4-squashfs-sysupgrade.bin
- SHA-256: `5adf63a866106ac43a0900e41dab3e4dd990435cce7e9311a5d7c4f7b52a1535`
- Size: 8755756 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5adf63a866106ac4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5adf63a866106ac4/_openwrt-25.12.5-ramips-mt7621-linksys_ea6350-v4-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_ea6350-v4/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
