# Firmware Audit: OpenWrt Qxwlan E2600AC / openwrt-25.12.5-ipq40xx-generic-qxwlan_e2600ac-c2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-qxwlan_e2600ac-c2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Qxwlan_E2600AC/openwrt-25.12.5-ipq40xx-generic-qxwlan_e2600ac-c2-squashfs-sysupgrade.bin
- SHA-256: `61c7921de83cbceeaa423cb0c5e1674bf4ac39b72f4f0980aa4404eabd0a54b4`
- Size: 9503278 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/61c7921de83cbcee exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/61c7921de83cbcee/_openwrt-25.12.5-ipq40xx-generic-qxwlan_e2600ac-c2-squashfs-sysupgrade.bin.extracted/sysupgrade-qxwlan_e2600ac-c2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
