# Firmware Audit: OpenWrt ASUS RT-AX59U / openwrt-25.12.5-mediatek-filogic-asus_rt-ax59u-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_rt-ax59u-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_RT-AX59U/openwrt-25.12.5-mediatek-filogic-asus_rt-ax59u-squashfs-sysupgrade.bin
- SHA-256: `d2abff53027b10008dcc958d3ea62809aa7d42cc662f29eb7f9b3cae10f28aee`
- Size: 10035466 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d2abff53027b1000 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d2abff53027b1000/_openwrt-25.12.5-mediatek-filogic-asus_rt-ax59u-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_rt-ax59u/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
