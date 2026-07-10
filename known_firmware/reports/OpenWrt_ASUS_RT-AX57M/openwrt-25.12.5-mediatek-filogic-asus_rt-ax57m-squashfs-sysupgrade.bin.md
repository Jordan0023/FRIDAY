# Firmware Audit: OpenWrt ASUS RT-AX57M / openwrt-25.12.5-mediatek-filogic-asus_rt-ax57m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_rt-ax57m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AX57M/openwrt-25.12.5-mediatek-filogic-asus_rt-ax57m-squashfs-sysupgrade.bin
- SHA-256: `3c9e320a9357c5e391512ab64a534dab607a9deb60d33bc124b51ddf0e9fe129`
- Size: 9390346 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3c9e320a9357c5e3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3c9e320a9357c5e3/_openwrt-25.12.5-mediatek-filogic-asus_rt-ax57m-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ax57m/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
