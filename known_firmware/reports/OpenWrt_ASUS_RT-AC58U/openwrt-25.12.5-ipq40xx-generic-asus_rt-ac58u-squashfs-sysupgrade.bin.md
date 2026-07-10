# Firmware Audit: OpenWrt ASUS RT-AC58U / openwrt-25.12.5-ipq40xx-generic-asus_rt-ac58u-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-asus_rt-ac58u-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AC58U/openwrt-25.12.5-ipq40xx-generic-asus_rt-ac58u-squashfs-sysupgrade.bin
- SHA-256: `da2e81273bd20f302936102cc22e57807cc0840594fa613689049a5656375fed`
- Size: 8192546 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/da2e81273bd20f30 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/da2e81273bd20f30/_openwrt-25.12.5-ipq40xx-generic-asus_rt-ac58u-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ac58u/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
