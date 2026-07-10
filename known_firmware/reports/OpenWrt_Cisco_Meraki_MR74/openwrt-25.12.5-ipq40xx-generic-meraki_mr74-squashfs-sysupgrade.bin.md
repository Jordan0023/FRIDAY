# Firmware Audit: OpenWrt Cisco Meraki MR74 / openwrt-25.12.5-ipq40xx-generic-meraki_mr74-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-meraki_mr74-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_MR74/openwrt-25.12.5-ipq40xx-generic-meraki_mr74-squashfs-sysupgrade.bin
- SHA-256: `2a790167c028908ae85a0a9c54098b9d67bb729218d4da3de7b8e36f14048cdd`
- Size: 9687580 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2a790167c028908a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2a790167c028908a/_openwrt-25.12.5-ipq40xx-generic-meraki_mr74-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_mr74/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
