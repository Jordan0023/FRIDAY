# Firmware Audit: OpenWrt ASUS TUF-AX4200Q / openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200q-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200q-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ASUS_TUF-AX4200Q/openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200q-squashfs-sysupgrade.bin
- SHA-256: `6b298731506a0621a9e3d76de00478f8d8bac9dea5859d19ea0627d9e8c37b13`
- Size: 10035472 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6b298731506a0621 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6b298731506a0621/_openwrt-25.12.5-mediatek-filogic-asus_tuf-ax4200q-squashfs-sysupgrade.bin.extracted/sysupgrade-asus_tuf-ax4200q/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
