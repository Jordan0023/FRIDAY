# Firmware Audit: OpenWrt Cisco Meraki MR33 / openwrt-25.12.5-ipq40xx-generic-meraki_mr33-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-meraki_mr33-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_MR33/openwrt-25.12.5-ipq40xx-generic-meraki_mr33-squashfs-sysupgrade.bin
- SHA-256: `de62bc0c0621003c6a9ad59ceb4d2b98c3f798fa9b7c488b64459ae2b739832e`
- Size: 9687580 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/de62bc0c0621003c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/de62bc0c0621003c/_openwrt-25.12.5-ipq40xx-generic-meraki_mr33-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_mr33/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
