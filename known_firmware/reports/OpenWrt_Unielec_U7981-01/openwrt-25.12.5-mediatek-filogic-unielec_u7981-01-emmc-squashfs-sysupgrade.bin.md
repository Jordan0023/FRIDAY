# Firmware Audit: OpenWrt Unielec U7981-01 / openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-emmc-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-emmc-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Unielec_U7981-01/openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-emmc-squashfs-sysupgrade.bin
- SHA-256: `a5832abfd92d5211d19063af0c45f0f58784385cd73803386a9f21453f2b3a40`
- Size: 10486042 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a5832abfd92d5211 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a5832abfd92d5211/_openwrt-25.12.5-mediatek-filogic-unielec_u7981-01-emmc-squashfs-sysupgrade.bin.extracted/sysupgrade-unielec_u7981-01-emmc/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
