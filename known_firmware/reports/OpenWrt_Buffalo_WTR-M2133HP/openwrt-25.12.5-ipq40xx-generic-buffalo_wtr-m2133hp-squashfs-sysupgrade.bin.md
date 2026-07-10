# Firmware Audit: OpenWrt Buffalo WTR-M2133HP / openwrt-25.12.5-ipq40xx-generic-buffalo_wtr-m2133hp-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-buffalo_wtr-m2133hp-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Buffalo_WTR-M2133HP/openwrt-25.12.5-ipq40xx-generic-buffalo_wtr-m2133hp-squashfs-sysupgrade.bin
- SHA-256: `6c68fa9f818c183894db3f31cf0b517ddfc419da54a2ae551ae9fcc6b91e20b1`
- Size: 9943604 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6c68fa9f818c1838 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6c68fa9f818c1838/_openwrt-25.12.5-ipq40xx-generic-buffalo_wtr-m2133hp-squashfs-sysupgrade.bin.extracted/sysupgrade-buffalo_wtr-m2133hp/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
