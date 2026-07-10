# Firmware Audit: OpenWrt ASUS Lyra Mini (MAP-AC1300) / openwrt-25.12.5-ipq40xx-generic-asus_map-ac1300-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-asus_map-ac1300-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_Lyra_Mini__MAP-AC1300/openwrt-25.12.5-ipq40xx-generic-asus_map-ac1300-squashfs-sysupgrade.bin
- SHA-256: `91feda52d7139ebabb3c35b7932f5c9b8d22811183ee295fec7fc9b67f54def3`
- Size: 9349672 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/91feda52d7139eba exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/91feda52d7139eba/_openwrt-25.12.5-ipq40xx-generic-asus_map-ac1300-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_map-ac1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
