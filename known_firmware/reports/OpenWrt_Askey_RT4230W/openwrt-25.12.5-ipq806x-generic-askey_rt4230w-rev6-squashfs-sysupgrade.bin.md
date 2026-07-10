# Firmware Audit: OpenWrt Askey RT4230W / openwrt-25.12.5-ipq806x-generic-askey_rt4230w-rev6-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-askey_rt4230w-rev6-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Askey_RT4230W/openwrt-25.12.5-ipq806x-generic-askey_rt4230w-rev6-squashfs-sysupgrade.bin
- SHA-256: `fe1e099987b71a8d3b7ac19d7e7b694f336d3e10ef634d92229fd2cc63a0cc0f`
- Size: 8243761 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fe1e099987b71a8d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fe1e099987b71a8d/_openwrt-25.12.5-ipq806x-generic-askey_rt4230w-rev6-squashfs-sysupgrade.bin.extracted/sysupgrade-askey_rt4230w-rev6/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
