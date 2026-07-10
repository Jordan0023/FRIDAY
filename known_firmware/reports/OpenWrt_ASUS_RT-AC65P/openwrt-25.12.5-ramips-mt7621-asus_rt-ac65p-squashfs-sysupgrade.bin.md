# Firmware Audit: OpenWrt ASUS RT-AC65P / openwrt-25.12.5-ramips-mt7621-asus_rt-ac65p-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-asus_rt-ac65p-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AC65P/openwrt-25.12.5-ramips-mt7621-asus_rt-ac65p-squashfs-sysupgrade.bin
- SHA-256: `8f7b9dbd95094f5e4fd2cc47ea736e378e252f293e6b37b86288788ebbfe7bb7`
- Size: 8243744 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8f7b9dbd95094f5e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8f7b9dbd95094f5e/_openwrt-25.12.5-ramips-mt7621-asus_rt-ac65p-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ac65p/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
