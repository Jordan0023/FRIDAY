# Firmware Audit: OpenWrt NETGEAR Nighthawk X4 R7500 / openwrt-25.12.5-ipq806x-generic-netgear_r7500-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-netgear_r7500-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_Nighthawk_X4_R7500/openwrt-25.12.5-ipq806x-generic-netgear_r7500-squashfs-sysupgrade.bin
- SHA-256: `3b6f1f65bd52385852e88041e6aa362fd3f5e07463b8092a9d971cb54e11afae`
- Size: 8018472 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3b6f1f65bd523858 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3b6f1f65bd523858/_openwrt-25.12.5-ipq806x-generic-netgear_r7500-squashfs-sysupgrade.bin.extracted/sysupgrade-r7500/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
