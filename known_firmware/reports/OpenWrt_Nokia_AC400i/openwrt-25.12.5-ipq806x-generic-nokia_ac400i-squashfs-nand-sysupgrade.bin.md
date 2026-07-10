# Firmware Audit: OpenWrt Nokia AC400i / openwrt-25.12.5-ipq806x-generic-nokia_ac400i-squashfs-nand-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-nokia_ac400i-squashfs-nand-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Nokia_AC400i/openwrt-25.12.5-ipq806x-generic-nokia_ac400i-squashfs-nand-sysupgrade.bin
- SHA-256: `1548578ebbb1aeee4de6f184b6aa71c5b1726175dde4d6178cd7715b24d41ecb`
- Size: 9749017 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1548578ebbb1aeee exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1548578ebbb1aeee/_openwrt-25.12.5-ipq806x-generic-nokia_ac400i-squashfs-nand-sysupgrade.bin.extracted/sysupgrade-ac400i/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
