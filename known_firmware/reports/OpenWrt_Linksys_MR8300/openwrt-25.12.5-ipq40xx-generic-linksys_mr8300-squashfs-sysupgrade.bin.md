# Firmware Audit: OpenWrt Linksys MR8300 / openwrt-25.12.5-ipq40xx-generic-linksys_mr8300-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_mr8300-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_MR8300/openwrt-25.12.5-ipq40xx-generic-linksys_mr8300-squashfs-sysupgrade.bin
- SHA-256: `f1647d33c065a2389939b7de579edc5135a6fe9b3ce003c144b34bd665013b3b`
- Size: 8449375 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f1647d33c065a238 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f1647d33c065a238/_openwrt-25.12.5-ipq40xx-generic-linksys_mr8300-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_mr8300/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
