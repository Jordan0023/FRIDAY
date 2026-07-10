# Firmware Audit: OpenWrt Gemtek WVRTM-130ACN / openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-130acn-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-130acn-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Gemtek_WVRTM-130ACN/openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-130acn-squashfs-sysupgrade.bin
- SHA-256: `1cfbbeb2fcfeb2b42ca7568f26ec022a4e42daa4630caffab446d922d76552a5`
- Size: 8243762 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1cfbbeb2fcfeb2b4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1cfbbeb2fcfeb2b4/_openwrt-25.12.5-ramips-mt7621-gemtek_wvrtm-130acn-squashfs-sysupgrade.bin.extracted/sysupgrade-gemtek_wvrtm-130acn/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
