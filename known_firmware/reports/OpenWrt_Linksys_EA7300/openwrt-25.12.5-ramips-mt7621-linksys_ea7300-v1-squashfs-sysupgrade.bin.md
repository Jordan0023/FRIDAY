# Firmware Audit: OpenWrt Linksys EA7300 / openwrt-25.12.5-ramips-mt7621-linksys_ea7300-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-linksys_ea7300-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_EA7300/openwrt-25.12.5-ramips-mt7621-linksys_ea7300-v1-squashfs-sysupgrade.bin
- SHA-256: `56f0c8d8b39251a21e401cda6094e605c29cc5b0725089154811c0a5515e9442`
- Size: 8243756 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/56f0c8d8b39251a2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/56f0c8d8b39251a2/_openwrt-25.12.5-ramips-mt7621-linksys_ea7300-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_ea7300-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
