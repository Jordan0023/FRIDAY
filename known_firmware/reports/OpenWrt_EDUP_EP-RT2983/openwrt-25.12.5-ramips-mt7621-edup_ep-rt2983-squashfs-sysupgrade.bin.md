# Firmware Audit: OpenWrt EDUP EP-RT2983 / openwrt-25.12.5-ramips-mt7621-edup_ep-rt2983-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-edup_ep-rt2983-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EDUP_EP-RT2983/openwrt-25.12.5-ramips-mt7621-edup_ep-rt2983-squashfs-sysupgrade.bin
- SHA-256: `7bb58586d3d05fbb23d05a926e637915228d9e2ec22a2a2760306053582d2c51`
- Size: 8008227 bytes
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

- binwalk -eM --directory known_firmware/extracted/7bb58586d3d05fbb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7bb58586d3d05fbb/_openwrt-25.12.5-ramips-mt7621-edup_ep-rt2983-squashfs-sysupgrade.bin.extracted/sysupgrade-edup_ep-rt2983/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
