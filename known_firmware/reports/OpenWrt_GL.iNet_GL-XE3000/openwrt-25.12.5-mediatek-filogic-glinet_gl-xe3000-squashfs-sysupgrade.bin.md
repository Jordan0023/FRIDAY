# Firmware Audit: OpenWrt GL.iNet GL-XE3000 / openwrt-25.12.5-mediatek-filogic-glinet_gl-xe3000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-glinet_gl-xe3000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-XE3000/openwrt-25.12.5-mediatek-filogic-glinet_gl-xe3000-squashfs-sysupgrade.bin
- SHA-256: `a14f16c4ac5e2a8ee016eabba6fe1970707de828d31d9d0f084dae730d4e2c5f`
- Size: 9738512 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a14f16c4ac5e2a8e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a14f16c4ac5e2a8e/_openwrt-25.12.5-mediatek-filogic-glinet_gl-xe3000-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-xe3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
