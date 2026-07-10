# Firmware Audit: OpenWrt WAVLINK WL-WN551X3 / openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn551x3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn551x3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_WAVLINK_WL-WN551X3/openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn551x3-squashfs-sysupgrade.bin
- SHA-256: `3dbb426d696e7e47313b9a4ff33854d690da1795f29c3a2ba2b0ebbd1d3f2ae1`
- Size: 9554229 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3dbb426d696e7e47 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3dbb426d696e7e47/_openwrt-25.12.5-mediatek-filogic-wavlink_wl-wn551x3-squashfs-sysupgrade.bin.extracted/sysupgrade-wavlink_wl-wn551x3/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
