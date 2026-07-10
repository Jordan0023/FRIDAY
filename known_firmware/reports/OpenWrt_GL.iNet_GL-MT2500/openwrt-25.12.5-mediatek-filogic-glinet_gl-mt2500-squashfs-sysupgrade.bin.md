# Firmware Audit: OpenWrt GL.iNet GL-MT2500 / openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-MT2500/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-squashfs-sysupgrade.bin
- SHA-256: `ee16b3254ffe225f41a4fbe9240b7de0ed66b68827f8afb8f44dff7665cda750`
- Size: 8345941 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ee16b3254ffe225f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ee16b3254ffe225f/_openwrt-25.12.5-mediatek-filogic-glinet_gl-mt2500-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
