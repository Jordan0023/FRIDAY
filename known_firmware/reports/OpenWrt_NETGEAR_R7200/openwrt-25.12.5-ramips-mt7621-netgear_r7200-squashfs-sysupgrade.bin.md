# Firmware Audit: OpenWrt NETGEAR R7200 / openwrt-25.12.5-ramips-mt7621-netgear_r7200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_r7200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_R7200/openwrt-25.12.5-ramips-mt7621-netgear_r7200-squashfs-sysupgrade.bin
- SHA-256: `ae4921ef7e4519e697bcd607a6748501e56b3fb0677ad2fe73fafcb18433bea3`
- Size: 8315424 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ae4921ef7e4519e6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ae4921ef7e4519e6/_openwrt-25.12.5-ramips-mt7621-netgear_r7200-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_r7200/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
