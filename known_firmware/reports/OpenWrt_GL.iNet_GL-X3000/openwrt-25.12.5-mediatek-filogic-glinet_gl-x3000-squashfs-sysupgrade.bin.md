# Firmware Audit: OpenWrt GL.iNet GL-X3000 / openwrt-25.12.5-mediatek-filogic-glinet_gl-x3000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-glinet_gl-x3000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-X3000/openwrt-25.12.5-mediatek-filogic-glinet_gl-x3000-squashfs-sysupgrade.bin
- SHA-256: `8a8530310bde83d826786291797cec65c7a7ced885537848206dd94d90a08d64`
- Size: 9728270 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8a8530310bde83d8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8a8530310bde83d8/_openwrt-25.12.5-mediatek-filogic-glinet_gl-x3000-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-x3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
