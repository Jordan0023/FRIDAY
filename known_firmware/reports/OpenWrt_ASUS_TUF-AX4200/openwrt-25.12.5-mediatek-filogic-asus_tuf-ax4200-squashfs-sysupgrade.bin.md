# Firmware Audit: OpenWrt ASUS TUF-AX4200 / openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_TUF-AX4200/openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200-squashfs-sysupgrade.bin
- SHA-256: `4fc1934f51e4b773da147af73d412137c23243580ce245efa181ab99fad6da65`
- Size: 10035470 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4fc1934f51e4b773 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/4fc1934f51e4b773/_openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_tuf-ax4200/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
