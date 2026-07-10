# Firmware Audit: OpenWrt GL.iNet GL-MT6000 / openwrt-25.12.5-mediatek-filogic-glinet_gl-mt6000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt6000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_GL.iNet_GL-MT6000/openwrt-25.12.5-mediatek-filogic-glinet_gl-mt6000-squashfs-sysupgrade.bin
- SHA-256: `4b506982cc4ae2e1ebdee85be637fdfd59ed7df83e9995e03ffd641c58954390`
- Size: 10578240 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4b506982cc4ae2e1 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4b506982cc4ae2e1/_openwrt-25.12.5-mediatek-filogic-glinet_gl-mt6000-squashfs-sysupgrade.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
