# Firmware Audit: OpenWrt Rostelecom RT-SF-1 / openwrt-25.12.5-ramips-mt7621-rostelecom_rt-sf-1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-rostelecom_rt-sf-1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Rostelecom_RT-SF-1/openwrt-25.12.5-ramips-mt7621-rostelecom_rt-sf-1-squashfs-sysupgrade.bin
- SHA-256: `0e34b72fc93d44460bb3f409e660cfb2151bd9d0d0eab75a5062919da7d56ffa`
- Size: 8366639 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0e34b72fc93d4446 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0e34b72fc93d4446/_openwrt-25.12.5-ramips-mt7621-rostelecom_rt-sf-1-squashfs-sysupgrade.bin.extracted/sysupgrade-rostelecom_rt-sf-1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
