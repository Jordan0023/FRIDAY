# Firmware Audit: OpenWrt Netcraze NAP-630 / openwrt-25.12.5-mediatek-filogic-netcraze_nap-630-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-netcraze_nap-630-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Netcraze_NAP-630/openwrt-25.12.5-mediatek-filogic-netcraze_nap-630-squashfs-sysupgrade.bin
- SHA-256: `7db7cf4a03ac5792db4e7d4c29f8966c8dd7d788b6871bcbd45746c6bc1bb0d1`
- Size: 9441552 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7db7cf4a03ac5792 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7db7cf4a03ac5792/_openwrt-25.12.5-mediatek-filogic-netcraze_nap-630-squashfs-sysupgrade.bin.extracted/sysupgrade-netcraze_nap-630/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
