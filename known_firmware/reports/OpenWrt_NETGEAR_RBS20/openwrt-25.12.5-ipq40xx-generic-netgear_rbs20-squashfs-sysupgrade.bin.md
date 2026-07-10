# Firmware Audit: OpenWrt NETGEAR RBS20 / openwrt-25.12.5-ipq40xx-generic-netgear_rbs20-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-netgear_rbs20-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_RBS20/openwrt-25.12.5-ipq40xx-generic-netgear_rbs20-squashfs-sysupgrade.bin
- SHA-256: `ba04ab66d82d7ee68b6328bd1ef8c826968c1ddfa55a13d31f5a8e2e42e2a6f9`
- Size: 8499746 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ba04ab66d82d7ee6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ba04ab66d82d7ee6/_openwrt-25.12.5-ipq40xx-generic-netgear_rbs20-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_rbs20/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
