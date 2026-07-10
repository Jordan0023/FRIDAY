# Firmware Audit: OpenWrt NETGEAR WAC104 / openwrt-25.12.5-ramips-mt7621-netgear_wac104-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-netgear_wac104-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_NETGEAR_WAC104/openwrt-25.12.5-ramips-mt7621-netgear_wac104-squashfs-sysupgrade.bin
- SHA-256: `79b3052108b5b075d97a259582959551221f9588cc5b5153bdeae693a9a44704`
- Size: 7782947 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/79b3052108b5b075 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/79b3052108b5b075/_openwrt-25.12.5-ramips-mt7621-netgear_wac104-squashfs-sysupgrade.bin.extracted/sysupgrade-netgear_wac104/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
