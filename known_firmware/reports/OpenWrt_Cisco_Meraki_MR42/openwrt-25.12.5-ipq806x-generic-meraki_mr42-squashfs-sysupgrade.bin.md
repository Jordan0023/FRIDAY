# Firmware Audit: OpenWrt Cisco Meraki MR42 / openwrt-25.12.5-ipq806x-generic-meraki_mr42-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-meraki_mr42-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_MR42/openwrt-25.12.5-ipq806x-generic-meraki_mr42-squashfs-sysupgrade.bin
- SHA-256: `c0c4c529997552b32e62357c1cdb097ae3cd74e4d208a7bdd81c9676a7ab6967`
- Size: 9851141 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c0c4c529997552b3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c0c4c529997552b3/_openwrt-25.12.5-ipq806x-generic-meraki_mr42-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_mr42/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
