# Firmware Audit: OpenWrt NETGEAR WAC124 / openwrt-25.12.5-ramips-mt7621-netgear_wac124-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_wac124-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_WAC124/openwrt-25.12.5-ramips-mt7621-netgear_wac124-squashfs-sysupgrade.bin
- SHA-256: `16c19962a48a051f557998fef25034a8474fe503155bceb698f104c539a0c7ac`
- Size: 8315427 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/16c19962a48a051f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/16c19962a48a051f/_openwrt-25.12.5-ramips-mt7621-netgear_wac124-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_wac124/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
