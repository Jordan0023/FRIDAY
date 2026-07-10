# Firmware Audit: OpenWrt Zbtlink ZBT-Z8103AX / openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8103ax-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8103ax-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zbtlink_ZBT-Z8103AX/openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8103ax-squashfs-sysupgrade.bin
- SHA-256: `05b10b04d441a0db3380c206287f4a0219f50c14dea257575a1166942577fc40`
- Size: 9390358 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/05b10b04d441a0db exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/05b10b04d441a0db/_openwrt-25.12.5-mediatek-filogic-zbtlink_zbt-z8103ax-squashfs-sysupgrade.bin.extracted/sysupgrade-zbtlink_zbt-z8103ax/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
