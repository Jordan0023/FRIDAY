# Firmware Audit: OpenWrt NETGEAR Nighthawk XR450 / openwrt-25.12.5-ipq806x-generic-netgear_xr450-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-netgear_xr450-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_Nighthawk_XR450/openwrt-25.12.5-ipq806x-generic-netgear_xr450-squashfs-sysupgrade.bin
- SHA-256: `c1b3d7699d54fe16c708fb1453d632db4cae87ff8647fb8750a95c40af256c12`
- Size: 8305186 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c1b3d7699d54fe16 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c1b3d7699d54fe16/_openwrt-25.12.5-ipq806x-generic-netgear_xr450-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_xr450/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
