# Firmware Audit: OpenWrt Cisco Meraki MR30H / openwrt-25.12.5-ipq40xx-generic-meraki_mr30h-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-meraki_mr30h-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_MR30H/openwrt-25.12.5-ipq40xx-generic-meraki_mr30h-squashfs-sysupgrade.bin
- SHA-256: `a0a73c48f57d5cef1ac77425a87d15919e8e94add39cdb42ecfaa9f9376bd1d4`
- Size: 9646623 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a0a73c48f57d5cef exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a0a73c48f57d5cef/_openwrt-25.12.5-ipq40xx-generic-meraki_mr30h-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_mr30h/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
