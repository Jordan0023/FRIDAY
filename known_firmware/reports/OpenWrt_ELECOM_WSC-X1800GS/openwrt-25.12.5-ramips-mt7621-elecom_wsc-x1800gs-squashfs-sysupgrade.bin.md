# Firmware Audit: OpenWrt ELECOM WSC-X1800GS / openwrt-25.12.5-ramips-mt7621-elecom_wsc-x1800gs-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-elecom_wsc-x1800gs-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ELECOM_WSC-X1800GS/openwrt-25.12.5-ramips-mt7621-elecom_wsc-x1800gs-squashfs-sysupgrade.bin
- SHA-256: `6612e5533dca4362df33333e293a20ed2a4592acef2a91ebe614c1c8837cba08`
- Size: 7997999 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6612e5533dca4362 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6612e5533dca4362/_openwrt-25.12.5-ramips-mt7621-elecom_wsc-x1800gs-squashfs-sysupgrade.bin.extracted/sysupgrade-elecom_wsc-x1800gs/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
