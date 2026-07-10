# Firmware Audit: OpenWrt Linksys WHW01 / openwrt-25.12.5-ipq40xx-generic-linksys_whw01-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-linksys_whw01-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_WHW01/openwrt-25.12.5-ipq40xx-generic-linksys_whw01-squashfs-sysupgrade.bin
- SHA-256: `a42b2f1615ecf7b7689ee314a4ad81dfe4d3a980ea2dd9648bae46cce0416758`
- Size: 7997986 bytes
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

- binwalk -eM --directory known_firmware/extracted/a42b2f1615ecf7b7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a42b2f1615ecf7b7/_openwrt-25.12.5-ipq40xx-generic-linksys_whw01-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_whw01/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
