# Firmware Audit: OpenWrt NETGEAR Nighthawk XR500 / openwrt-25.12.5-ipq806x-generic-netgear_xr500-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-netgear_xr500-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_Nighthawk_XR500/openwrt-25.12.5-ipq806x-generic-netgear_xr500-squashfs-sysupgrade.bin
- SHA-256: `cb79b46b16e278509f505df7d2fbc262ae564592117e545a4ec7f992e0c9d41a`
- Size: 8305186 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cb79b46b16e27850 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cb79b46b16e27850/_openwrt-25.12.5-ipq806x-generic-netgear_xr500-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_xr500/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
