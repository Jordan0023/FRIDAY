# Firmware Audit: OpenWrt NETGEAR Nighthawk X4 R7500 / openwrt-25.12.5-ipq806x-generic-netgear_r7500v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-netgear_r7500v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_Nighthawk_X4_R7500/openwrt-25.12.5-ipq806x-generic-netgear_r7500v2-squashfs-sysupgrade.bin
- SHA-256: `675996e89cb4304c902a59848aa04234ed135aafaa13353040fd3f39f1ef3c73`
- Size: 8428082 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/675996e89cb4304c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/675996e89cb4304c/_openwrt-25.12.5-ipq806x-generic-netgear_r7500v2-squashfs-sysupgrade.bin.extracted/sysupgrade-r7500v2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
