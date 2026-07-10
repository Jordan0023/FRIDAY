# Firmware Audit: OpenWrt Rostelecom RT-FE-1A / openwrt-25.12.5-ramips-mt7621-rostelecom_rt-fe-1a-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-rostelecom_rt-fe-1a-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Rostelecom_RT-FE-1A/openwrt-25.12.5-ramips-mt7621-rostelecom_rt-fe-1a-squashfs-sysupgrade.bin
- SHA-256: `30b98092e91a6fc4e0e5c2be3796bb19aad86ee2225cf2059c1af85aa44ae4be`
- Size: 8223282 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/30b98092e91a6fc4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/30b98092e91a6fc4/_openwrt-25.12.5-ramips-mt7621-rostelecom_rt-fe-1a-squashfs-sysupgrade.bin.extracted/sysupgrade-rostelecom_rt-fe-1a/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
