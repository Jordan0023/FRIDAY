# Firmware Audit: OpenWrt ipTIME A3004T / openwrt-25.12.5-ramips-mt7621-iptime_a3004t-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-iptime_a3004t-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ipTIME_A3004T/openwrt-25.12.5-ramips-mt7621-iptime_a3004t-squashfs-sysupgrade.bin
- SHA-256: `a767fe85595cd6aa73e3d9bd544c31a4e77392bb4b0f2762e8b27e3be540e070`
- Size: 8233504 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a767fe85595cd6aa exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a767fe85595cd6aa/_openwrt-25.12.5-ramips-mt7621-iptime_a3004t-squashfs-sysupgrade.bin.extracted/sysupgrade-iptime_a3004t/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
