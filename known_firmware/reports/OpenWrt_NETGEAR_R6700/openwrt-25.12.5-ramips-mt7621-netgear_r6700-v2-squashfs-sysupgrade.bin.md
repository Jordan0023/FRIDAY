# Firmware Audit: OpenWrt NETGEAR R6700 / openwrt-25.12.5-ramips-mt7621-netgear_r6700-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_r6700-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_R6700/openwrt-25.12.5-ramips-mt7621-netgear_r6700-v2-squashfs-sysupgrade.bin
- SHA-256: `ca6cfb80855b024ebbbadab5f2a54a1b4cb8f5419f3117927b0243c3bbb1c528`
- Size: 8315433 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ca6cfb80855b024e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ca6cfb80855b024e/_openwrt-25.12.5-ramips-mt7621-netgear_r6700-v2-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_r6700-v2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
