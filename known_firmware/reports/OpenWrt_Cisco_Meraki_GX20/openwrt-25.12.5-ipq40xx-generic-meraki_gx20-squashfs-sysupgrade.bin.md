# Firmware Audit: OpenWrt Cisco Meraki GX20 / openwrt-25.12.5-ipq40xx-generic-meraki_gx20-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-meraki_gx20-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cisco_Meraki_GX20/openwrt-25.12.5-ipq40xx-generic-meraki_gx20-squashfs-sysupgrade.bin
- SHA-256: `078f79440d39cb528ac4a278191a61e77dbcfe72de6ad19599a1eceec57d57d2`
- Size: 9452060 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/078f79440d39cb52 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/078f79440d39cb52/_openwrt-25.12.5-ipq40xx-generic-meraki_gx20-squashfs-sysupgrade.bin.extracted/sysupgrade-meraki_gx20/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
