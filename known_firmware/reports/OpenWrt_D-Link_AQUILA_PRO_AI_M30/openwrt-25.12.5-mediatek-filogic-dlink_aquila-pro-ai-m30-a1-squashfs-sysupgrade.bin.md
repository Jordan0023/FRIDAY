# Firmware Audit: OpenWrt D-Link AQUILA PRO AI M30 / openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m30-a1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m30-a1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_AQUILA_PRO_AI_M30/openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m30-a1-squashfs-sysupgrade.bin
- SHA-256: `a246023469b1cb3546c0cb8ed3f57e579252b47c0b96d136d9d0ae36e90e3789`
- Size: 9390372 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a246023469b1cb35 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a246023469b1cb35/_openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m30-a1-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_aquila-pro-ai-m30-a1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
