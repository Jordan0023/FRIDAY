# Firmware Audit: OpenWrt NETGEAR Nighthawk X4S R7800 / openwrt-25.12.5-ipq806x-generic-netgear_r7800-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-netgear_r7800-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_Nighthawk_X4S_R7800/openwrt-25.12.5-ipq806x-generic-netgear_r7800-squashfs-sysupgrade.bin
- SHA-256: `3814218bde5f15bace94515f95aed4238a6dbb72b6eefbeea4fc6b0a128e12a0`
- Size: 8305192 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3814218bde5f15ba exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3814218bde5f15ba/_openwrt-25.12.5-ipq806x-generic-netgear_r7800-squashfs-sysupgrade.bin.extracted/sysupgrade-r7800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
