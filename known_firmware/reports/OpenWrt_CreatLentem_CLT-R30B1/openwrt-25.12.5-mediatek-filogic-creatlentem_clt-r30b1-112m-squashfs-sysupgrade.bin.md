# Firmware Audit: OpenWrt CreatLentem CLT-R30B1 / openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-112m-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-112m-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_CreatLentem_CLT-R30B1/openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-112m-squashfs-sysupgrade.bin
- SHA-256: `76607c8af2473a53a82a2148db8d087c4b4904a958755aea2e5ad465ab851f69`
- Size: 9390401 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/76607c8af2473a53 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/76607c8af2473a53/_openwrt-25.12.5-mediatek-filogic-creatlentem_clt-r30b1-112m-squashfs-sysupgrade.bin.extracted/sysupgrade-creatlentem_clt-r30b1-112m/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
