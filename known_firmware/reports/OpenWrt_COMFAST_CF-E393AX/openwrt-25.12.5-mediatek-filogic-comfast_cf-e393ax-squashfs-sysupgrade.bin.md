# Firmware Audit: OpenWrt COMFAST CF-E393AX / openwrt-25.12.5-mediatek-filogic-comfast_cf-e393ax-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-comfast_cf-e393ax-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_COMFAST_CF-E393AX/openwrt-25.12.5-mediatek-filogic-comfast_cf-e393ax-squashfs-sysupgrade.bin
- SHA-256: `b845bf1df9e8ade9a792a286460dededc5c4eddce3f0b34a8ff9fc7ad08e5ff9`
- Size: 9400594 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b845bf1df9e8ade9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b845bf1df9e8ade9/_openwrt-25.12.5-mediatek-filogic-comfast_cf-e393ax-squashfs-sysupgrade.bin.extracted/sysupgrade-comfast_cf-e393ax/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
