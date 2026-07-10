# Firmware Audit: OpenWrt CreatLentem CLT-R30B1 / openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_CreatLentem_CLT-R30B1/openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-squashfs-sysupgrade.bin
- SHA-256: `aa0c2d9b3fcf2df946b7bf53564ffb02f84592e2872802e01dc7681fd68f3914`
- Size: 9390395 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/aa0c2d9b3fcf2df9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/aa0c2d9b3fcf2df9/_openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-squashfs-sysupgrade.bin.extracted/sysupgrade-creatlentem_clt-r30b1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
