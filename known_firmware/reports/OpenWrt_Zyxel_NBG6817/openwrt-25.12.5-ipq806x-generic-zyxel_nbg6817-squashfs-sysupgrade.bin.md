# Firmware Audit: OpenWrt Zyxel NBG6817 / openwrt-25.12.5-ipq806x-generic-zyxel_nbg6817-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-zyxel_nbg6817-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_NBG6817/openwrt-25.12.5-ipq806x-generic-zyxel_nbg6817-squashfs-sysupgrade.bin
- SHA-256: `8ac4817c7caf60582dfe6d1e213986921f9572c76387f61e30bd3131a46b8a71`
- Size: 9708078 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8ac4817c7caf6058 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8ac4817c7caf6058/_openwrt-25.12.5-ipq806x-generic-zyxel_nbg6817-squashfs-sysupgrade.bin.extracted/sysupgrade-nbg6817/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
