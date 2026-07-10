# Firmware Audit: OpenWrt Cetron CT3003 / openwrt-25.12.5-mediatek-filogic-cetron_ct3003-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cetron_ct3003-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cetron_CT3003/openwrt-25.12.5-mediatek-filogic-cetron_ct3003-squashfs-sysupgrade.bin
- SHA-256: `5c81a0248b750acd168a3a54601154c8223bf0158bbf41cc158ee89ea1a918ea`
- Size: 9390379 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5c81a0248b750acd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5c81a0248b750acd/_openwrt-25.12.5-mediatek-filogic-cetron_ct3003-squashfs-sysupgrade.bin.extracted/sysupgrade-cetron_ct3003/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
