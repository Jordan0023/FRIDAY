# Firmware Audit: OpenWrt Zbtlink ZBT-Z8102AX-V2 / openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8102ax-v2-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8102ax-v2-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zbtlink_ZBT-Z8102AX-V2/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8102ax-v2-squashfs-sysupgrade.bin
- SHA-256: `dbc36e55ef5443cbb31b4e3c9a2a5f5e1374ca309628487ef2a7528c0c5255d3`
- Size: 9595472 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dbc36e55ef5443cb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/dbc36e55ef5443cb/_openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8102ax-v2-squashfs-sysupgrade.bin.extracted/sysupgrade-zbtlink_zbt-z8102ax-v2/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
