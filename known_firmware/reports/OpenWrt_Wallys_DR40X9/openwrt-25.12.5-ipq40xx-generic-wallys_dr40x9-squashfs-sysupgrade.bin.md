# Firmware Audit: OpenWrt Wallys DR40X9 / openwrt-25.12.5-ipq40xx-generic-wallys_dr40x9-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-wallys_dr40x9-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Wallys_DR40X9/openwrt-25.12.5-ipq40xx-generic-wallys_dr40x9-squashfs-sysupgrade.bin
- SHA-256: `19724947212f7d9acfef7dd34350e7c91666918e386e16f145f50c7e74821f66`
- Size: 9462306 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/19724947212f7d9a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/19724947212f7d9a/_openwrt-25.12.5-ipq40xx-generic-wallys_dr40x9-squashfs-sysupgrade.bin.extracted/sysupgrade-wallys_dr40x9/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
