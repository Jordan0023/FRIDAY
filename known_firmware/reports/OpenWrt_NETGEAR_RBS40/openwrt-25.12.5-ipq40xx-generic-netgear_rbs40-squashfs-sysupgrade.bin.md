# Firmware Audit: OpenWrt NETGEAR RBS40 / openwrt-25.12.5-ipq40xx-generic-netgear_rbs40-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-netgear_rbs40-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_RBS40/openwrt-25.12.5-ipq40xx-generic-netgear_rbs40-squashfs-sysupgrade.bin
- SHA-256: `0727656d8ff6492fcedf7cc0ca0b953da8917ee4c5d9e59cbd6051e841943cec`
- Size: 9155106 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0727656d8ff6492f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0727656d8ff6492f/_openwrt-25.12.5-ipq40xx-generic-netgear_rbs40-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_rbs40/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
