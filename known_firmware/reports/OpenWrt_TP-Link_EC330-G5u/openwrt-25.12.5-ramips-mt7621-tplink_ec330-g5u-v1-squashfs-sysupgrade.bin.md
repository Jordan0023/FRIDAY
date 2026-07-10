# Firmware Audit: OpenWrt TP-Link EC330-G5u / openwrt-25.12.5-ramips-mt7621-tplink_ec330-g5u-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-tplink_ec330-g5u-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_EC330-G5u/openwrt-25.12.5-ramips-mt7621-tplink_ec330-g5u-v1-squashfs-sysupgrade.bin
- SHA-256: `86f2a457603806c20a84b202aa09dc4934801881d5957563a070b9d240f0f2bb`
- Size: 8243762 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/86f2a457603806c2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/86f2a457603806c2/_openwrt-25.12.5-ramips-mt7621-tplink_ec330-g5u-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-tplink_ec330-g5u-v1/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
