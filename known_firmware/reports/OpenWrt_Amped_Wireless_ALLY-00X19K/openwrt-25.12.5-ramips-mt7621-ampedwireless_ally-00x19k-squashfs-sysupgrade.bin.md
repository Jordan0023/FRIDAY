# Firmware Audit: OpenWrt Amped Wireless ALLY-00X19K / openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-00x19k-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-00x19k-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Amped_Wireless_ALLY-00X19K/openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-00x19k-squashfs-sysupgrade.bin
- SHA-256: `d80bef01b229d29ead530b49ecbad7b8655d00d0dcbbcf8c031badd8d05296db`
- Size: 8100420 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d80bef01b229d29e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d80bef01b229d29e/_openwrt-25.12.5-ramips-mt7621-ampedwireless_ally-00x19k-squashfs-sysupgrade.bin.extracted/sysupgrade-ampedwireless_ally-00x19k/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
