# Firmware Audit: OpenWrt Plasma Cloud PA1200 / openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa1200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa1200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Plasma_Cloud_PA1200/openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa1200-squashfs-sysupgrade.bin
- SHA-256: `524a2a33402280ea6a328b541b046d454ed47479f9e374da31fea57645627629`
- Size: 8264241 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/524a2a33402280ea exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/524a2a33402280ea/_openwrt-25.12.5-ipq40xx-generic-plasmacloud_pa1200-squashfs-sysupgrade.bin.extracted/sysupgrade-plasmacloud_pa1200/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
