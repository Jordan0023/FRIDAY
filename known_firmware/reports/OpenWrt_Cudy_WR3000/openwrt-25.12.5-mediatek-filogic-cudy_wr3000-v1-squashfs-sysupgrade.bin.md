# Firmware Audit: OpenWrt Cudy WR3000 / openwrt-25.12.5-mediatek-filogic-cudy_wr3000-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/mediatek/filogic/openwrt-25.12.5-mediatek-filogic-cudy_wr3000-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Cudy_WR3000/openwrt-25.12.5-mediatek-filogic-cudy_wr3000-v1-squashfs-sysupgrade.bin
- SHA-256: `be876cf5335ab757874cd19f806b01f2271d8c20a1a0e68f1680019346c4408a`
- Size: 9699606 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/be876cf5335ab757 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/be876cf5335ab757/_openwrt-25.12.5-mediatek-filogic-cudy_wr3000-v1-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
