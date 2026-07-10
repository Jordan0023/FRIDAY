# Firmware Audit: OpenWrt EDUP EP-RT2960S / openwrt-25.12.5-ramips-mt7621-edup_ep-rt2960s-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-edup_ep-rt2960s-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_EDUP_EP-RT2960S/openwrt-25.12.5-ramips-mt7621-edup_ep-rt2960s-squashfs-sysupgrade.bin
- SHA-256: `de28529f1bd2140acfafe8bf693d19069ca783b45db3a790730956b51dcbcbbc`
- Size: 8008230 bytes
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

- binwalk -eM --directory known_firmware/extracted/de28529f1bd2140a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/de28529f1bd2140a/_openwrt-25.12.5-ramips-mt7621-edup_ep-rt2960s-squashfs-sysupgrade.bin.extracted/sysupgrade-edup_ep-rt2960s/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
