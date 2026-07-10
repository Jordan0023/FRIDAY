# Firmware Audit: OpenWrt GL.iNet GL-MT2500 / openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-airoha-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-airoha-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-MT2500/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-airoha-squashfs-sysupgrade.bin
- SHA-256: `29c4d290fd2dfec6e23cbe0c76bebd9ec7020cdde16991ad7b43f2a5bc1b0b10`
- Size: 8397155 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/29c4d290fd2dfec6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/29c4d290fd2dfec6/_openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-airoha-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-mt2500-airoha/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
