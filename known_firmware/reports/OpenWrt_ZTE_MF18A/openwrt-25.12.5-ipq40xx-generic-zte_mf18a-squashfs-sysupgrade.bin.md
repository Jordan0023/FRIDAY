# Firmware Audit: OpenWrt ZTE MF18A / openwrt-25.12.5-ipq40xx-generic-zte_mf18a-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-zte_mf18a-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ZTE_MF18A/openwrt-25.12.5-ipq40xx-generic-zte_mf18a-squashfs-sysupgrade.bin
- SHA-256: `12a566de4c2611aa8e0e1ca50cf23266b72808d150f8f87b2f6a3e8e0be690d1`
- Size: 9912854 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/12a566de4c2611aa exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/12a566de4c2611aa/_openwrt-25.12.5-ipq40xx-generic-zte_mf18a-squashfs-sysupgrade.bin.extracted/sysupgrade-zte_mf18a/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
