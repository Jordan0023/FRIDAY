# Firmware Audit: OpenWrt Zyxel NWA50AX / openwrt-25.12.5-ramips-mt7621-zyxel_nwa50ax-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-zyxel_nwa50ax-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Zyxel_NWA50AX/openwrt-25.12.5-ramips-mt7621-zyxel_nwa50ax-squashfs-sysupgrade.bin
- SHA-256: `d4ac1042c4f3a37965bacb253377301ef757191f8171fab3026efd2d3e4b8a20`
- Size: 8008224 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d4ac1042c4f3a379 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d4ac1042c4f3a379/_openwrt-25.12.5-ramips-mt7621-zyxel_nwa50ax-squashfs-sysupgrade.bin.extracted/sysupgrade-zyxel_nwa50ax/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
