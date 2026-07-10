# Firmware Audit: OpenWrt D-Link AQUILA PRO AI M60 / openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m60-a1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m60-a1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_D-Link_AQUILA_PRO_AI_M60/openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m60-a1-squashfs-sysupgrade.bin
- SHA-256: `a571e40c02692d5c240b6eeb5c987b6a8bfe4896220f56618cdf0ebd703f02cd`
- Size: 9881892 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a571e40c02692d5c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a571e40c02692d5c/_openwrt-25.12.5-mediatek-filogic-dlink_aquila-pro-ai-m60-a1-squashfs-sysupgrade.bin.extracted/sysupgrade-dlink_aquila-pro-ai-m60-a1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
