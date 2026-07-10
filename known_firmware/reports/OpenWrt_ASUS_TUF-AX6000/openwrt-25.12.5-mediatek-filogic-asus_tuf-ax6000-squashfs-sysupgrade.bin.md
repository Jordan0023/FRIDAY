# Firmware Audit: OpenWrt ASUS TUF-AX6000 / openwrt-25.12.5-mediatek-filogic-asus_tuf-ax6000-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_tuf-ax6000-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_TUF-AX6000/openwrt-25.12.5-mediatek-filogic-asus_tuf-ax6000-squashfs-sysupgrade.bin
- SHA-256: `57b9a85c9059f2c35dc23a45324e14d724068f92f929853a82b13b91747b691f`
- Size: 10045710 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/57b9a85c9059f2c3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/57b9a85c9059f2c3/_openwrt-25.12.5-mediatek-filogic-asus_tuf-ax6000-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_tuf-ax6000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
