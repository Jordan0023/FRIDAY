# Firmware Audit: OpenWrt Luma Home WRTQ-329ACN / openwrt-25.12.5-ipq40xx-generic-luma_wrtq-329acn-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-luma_wrtq-329acn-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Luma_Home_WRTQ-329ACN/openwrt-25.12.5-ipq40xx-generic-luma_wrtq-329acn-squashfs-sysupgrade.bin
- SHA-256: `e2551de688f46dbddd67b5d292fe646be0265cf2b48ce654b7b4009bb6fe6e53`
- Size: 10670635 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e2551de688f46dbd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e2551de688f46dbd/_openwrt-25.12.5-ipq40xx-generic-luma_wrtq-329acn-squashfs-sysupgrade.bin.extracted/sysupgrade-luma_wrtq-329acn/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
