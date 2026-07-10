# Firmware Audit: OpenWrt JioRouter AX6000 / openwrt-25.12.5-mediatek-filogic-jiorouter_ax6000-jidu6101-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-jiorouter_ax6000-jidu6101-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_JioRouter_AX6000/openwrt-25.12.5-mediatek-filogic-jiorouter_ax6000-jidu6101-squashfs-sysupgrade.bin
- SHA-256: `b1782da02c6e4e666ea61d455b05c1eed25b0af55e0345c29fa907c26164922b`
- Size: 10629410 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b1782da02c6e4e66 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b1782da02c6e4e66/_openwrt-25.12.5-mediatek-filogic-jiorouter_ax6000-jidu6101-squashfs-sysupgrade.bin.extracted/sysupgrade-jiorouter_ax6000-jidu6101/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
