# Firmware Audit: OpenWrt Linksys E8350 / openwrt-25.12.5-ipq806x-generic-linksys_e8350-v1-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-linksys_e8350-v1-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Linksys_E8350/openwrt-25.12.5-ipq806x-generic-linksys_e8350-v1-squashfs-sysupgrade.bin
- SHA-256: `6a4c099f2529bad40e8c197df7105ce4699f39d7a70672adc6909b4f562999b0`
- Size: 7966991 bytes
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

- binwalk -eM --directory known_firmware/extracted/6a4c099f2529bad4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6a4c099f2529bad4/_openwrt-25.12.5-ipq806x-generic-linksys_e8350-v1-squashfs-sysupgrade.bin.extracted/sysupgrade-linksys_e8350-v1/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
