# Firmware Audit: OpenWrt ELECOM WRC-X3000GS3 / openwrt-25.12.5-mediatek-filogic-elecom_wrc-x3000gs3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-elecom_wrc-x3000gs3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ELECOM_WRC-X3000GS3/openwrt-25.12.5-mediatek-filogic-elecom_wrc-x3000gs3-squashfs-sysupgrade.bin
- SHA-256: `8197575765f71adee564506b2731004d87fbdb8c100ac89f2a5b230cbad3c0a8`
- Size: 9390358 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8197575765f71ade exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8197575765f71ade/_openwrt-25.12.5-mediatek-filogic-elecom_wrc-x3000gs3-squashfs-sysupgrade.bin.extracted/sysupgrade-elecom_wrc-x3000gs3/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
