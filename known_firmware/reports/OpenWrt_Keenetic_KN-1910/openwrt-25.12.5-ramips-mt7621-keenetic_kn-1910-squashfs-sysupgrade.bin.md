# Firmware Audit: OpenWrt Keenetic KN-1910 / openwrt-25.12.5-ramips-mt7621-keenetic_kn-1910-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-keenetic_kn-1910-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Keenetic_KN-1910/openwrt-25.12.5-ramips-mt7621-keenetic_kn-1910-squashfs-sysupgrade.bin
- SHA-256: `03f5417853cfbf0f61deb634a6f590179ae0f771e208a43134b6f46b87e83c62`
- Size: 8243753 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/03f5417853cfbf0f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/03f5417853cfbf0f/_openwrt-25.12.5-ramips-mt7621-keenetic_kn-1910-squashfs-sysupgrade.bin.extracted/sysupgrade-keenetic_kn-1910/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
