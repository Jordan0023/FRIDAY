# Firmware Audit: OpenWrt Cisco Meraki MR52 / openwrt-25.12.5-ipq806x-generic-meraki_mr52-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-meraki_mr52-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_MR52/openwrt-25.12.5-ipq806x-generic-meraki_mr52-squashfs-sysupgrade.bin
- SHA-256: `3c316ea641fd31a2ab63292e4bda7b05c3f01c97f3da9c11b8b5ab23f0ae6ec7`
- Size: 9892101 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3c316ea641fd31a2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3c316ea641fd31a2/_openwrt-25.12.5-ipq806x-generic-meraki_mr52-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_mr52/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
