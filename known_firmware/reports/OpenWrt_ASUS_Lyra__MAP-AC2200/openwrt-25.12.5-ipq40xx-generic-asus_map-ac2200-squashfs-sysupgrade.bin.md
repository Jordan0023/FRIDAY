# Firmware Audit: OpenWrt ASUS Lyra (MAP-AC2200) / openwrt-25.12.5-ipq40xx-generic-asus_map-ac2200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-asus_map-ac2200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_Lyra__MAP-AC2200/openwrt-25.12.5-ipq40xx-generic-asus_map-ac2200-squashfs-sysupgrade.bin
- SHA-256: `611c5b846d985299afca3ed14dc9b18e4d9bfca84eb7e1fd99ee2ccf8822014d`
- Size: 9820712 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/611c5b846d985299 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/611c5b846d985299/_openwrt-25.12.5-ipq40xx-generic-asus_map-ac2200-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_map-ac2200/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
