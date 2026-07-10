# Firmware Audit: OpenWrt HiWiFi HC5962 / openwrt-25.12.5-ramips-mt7621-hiwifi_hc5962-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-hiwifi_hc5962-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_HiWiFi_HC5962/openwrt-25.12.5-ramips-mt7621-hiwifi_hc5962-squashfs-sysupgrade.bin
- SHA-256: `c47a05c326c1cd0c10c6928d9d0a0f27803edf246bb92367a592592c9ad55ec7`
- Size: 7782944 bytes
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

- binwalk -eM --directory known_firmware/extracted/c47a05c326c1cd0c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c47a05c326c1cd0c/_openwrt-25.12.5-ramips-mt7621-hiwifi_hc5962-squashfs-sysupgrade.bin.extracted/sysupgrade-hiwifi_hc5962/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
