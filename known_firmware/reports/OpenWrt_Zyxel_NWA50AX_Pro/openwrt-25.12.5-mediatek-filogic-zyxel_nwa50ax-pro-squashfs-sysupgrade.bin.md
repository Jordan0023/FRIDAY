# Firmware Audit: OpenWrt Zyxel NWA50AX Pro / openwrt-25.12.5-mediatek-filogic-zyxel_nwa50ax-pro-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-zyxel_nwa50ax-pro-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_NWA50AX_Pro/openwrt-25.12.5-mediatek-filogic-zyxel_nwa50ax-pro-squashfs-sysupgrade.bin
- SHA-256: `a71cbd590c595b7dbfd75138510b1e8895f6f9b5f9bb3941a10eb17878c1897b`
- Size: 9390354 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a71cbd590c595b7d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a71cbd590c595b7d/_openwrt-25.12.5-mediatek-filogic-zyxel_nwa50ax-pro-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_nwa50ax-pro/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
