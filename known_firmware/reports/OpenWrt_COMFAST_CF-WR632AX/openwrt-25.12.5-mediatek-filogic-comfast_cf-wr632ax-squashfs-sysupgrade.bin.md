# Firmware Audit: OpenWrt COMFAST CF-WR632AX / openwrt-25.12.5-mediatek-filogic-comfast_cf-wr632ax-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-comfast_cf-wr632ax-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_COMFAST_CF-WR632AX/openwrt-25.12.5-mediatek-filogic-comfast_cf-wr632ax-squashfs-sysupgrade.bin
- SHA-256: `0ef234de428b7deed5c2d8bb813f5bb8ee1af4c556587b33a9d99d6996ce9b11`
- Size: 9554209 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0ef234de428b7dee exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0ef234de428b7dee/_openwrt-25.12.5-mediatek-filogic-comfast_cf-wr632ax-squashfs-sysupgrade.bin.extracted/sysupgrade-comfast_cf-wr632ax/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
