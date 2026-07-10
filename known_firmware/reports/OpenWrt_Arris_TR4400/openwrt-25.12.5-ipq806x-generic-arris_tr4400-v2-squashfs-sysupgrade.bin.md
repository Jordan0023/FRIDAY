# Firmware Audit: OpenWrt Arris TR4400 / openwrt-25.12.5-ipq806x-generic-arris_tr4400-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-arris_tr4400-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Arris_TR4400/openwrt-25.12.5-ipq806x-generic-arris_tr4400-v2-squashfs-sysupgrade.bin
- SHA-256: `bb1032d36f7c449f5a022d5f2a1abf8472bb46fb5605682a35c9dfb0fd28e128`
- Size: 8653352 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bb1032d36f7c449f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bb1032d36f7c449f/_openwrt-25.12.5-ipq806x-generic-arris_tr4400-v2-squashfs-sysupgrade.bin.extracted/sysupgrade-arris_tr4400-v2/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
