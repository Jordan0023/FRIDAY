# Firmware Audit: OpenWrt Buffalo WXR-2533DHP / openwrt-25.12.5-ipq806x-generic-buffalo_wxr-2533dhp-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-buffalo_wxr-2533dhp-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Buffalo_WXR-2533DHP/openwrt-25.12.5-ipq806x-generic-buffalo_wxr-2533dhp-squashfs-sysupgrade.bin
- SHA-256: `b378a0ed3f6bf866fd07fce982e11b65df1c3789c04a312eb2ec3689f2170d1a`
- Size: 8213044 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b378a0ed3f6bf866 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b378a0ed3f6bf866/_openwrt-25.12.5-ipq806x-generic-buffalo_wxr-2533dhp-squashfs-sysupgrade.bin.extracted/sysupgrade-buffalo_wxr-2533dhp/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
