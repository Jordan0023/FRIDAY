# Firmware Audit: OpenWrt ASUS RT-AX53U / openwrt-25.12.5-ramips-mt7621-asus_rt-ax53u-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-asus_rt-ax53u-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AX53U/openwrt-25.12.5-ramips-mt7621-asus_rt-ax53u-squashfs-sysupgrade.bin
- SHA-256: `2407f2154c04bdb70fe98c92a50067410c44484875515f7346446b5338c1b1f4`
- Size: 8141344 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2407f2154c04bdb7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2407f2154c04bdb7/_openwrt-25.12.5-ramips-mt7621-asus_rt-ax53u-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ax53u/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
