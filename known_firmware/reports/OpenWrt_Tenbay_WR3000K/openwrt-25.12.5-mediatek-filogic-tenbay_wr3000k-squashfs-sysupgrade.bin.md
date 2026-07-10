# Firmware Audit: OpenWrt Tenbay WR3000K / openwrt-25.12.5-mediatek-filogic-tenbay_wr3000k-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-tenbay_wr3000k-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Tenbay_WR3000K/openwrt-25.12.5-mediatek-filogic-tenbay_wr3000k-squashfs-sysupgrade.bin
- SHA-256: `d9bd744025214d35f6a9235f9adc98bcc53d64337d64edbc892c70fc00f46ad8`
- Size: 9390348 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d9bd744025214d35 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d9bd744025214d35/_openwrt-25.12.5-mediatek-filogic-tenbay_wr3000k-squashfs-sysupgrade.bin.extracted/sysupgrade-tenbay_wr3000k/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
