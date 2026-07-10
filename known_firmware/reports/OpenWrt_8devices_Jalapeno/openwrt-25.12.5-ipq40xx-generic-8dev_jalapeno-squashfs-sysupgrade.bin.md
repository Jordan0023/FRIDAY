# Firmware Audit: OpenWrt 8devices Jalapeno / openwrt-25.12.5-ipq40xx-generic-8dev_jalapeno-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-8dev_jalapeno-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_8devices_Jalapeno/openwrt-25.12.5-ipq40xx-generic-8dev_jalapeno-squashfs-sysupgrade.bin
- SHA-256: `4309d760dc7546001da628be89c7a6aafe947b62ef8dc776994740f7ba2be749`
- Size: 9503266 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4309d760dc754600 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4309d760dc754600/_openwrt-25.12.5-ipq40xx-generic-8dev_jalapeno-squashfs-sysupgrade.bin.extracted/sysupgrade-8dev_jalapeno/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
