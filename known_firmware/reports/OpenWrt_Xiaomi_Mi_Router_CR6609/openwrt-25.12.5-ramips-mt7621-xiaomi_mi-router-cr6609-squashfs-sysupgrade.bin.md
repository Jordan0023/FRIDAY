# Firmware Audit: OpenWrt Xiaomi Mi Router CR6609 / openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-cr6609-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-cr6609-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Xiaomi_Mi_Router_CR6609/openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-cr6609-squashfs-sysupgrade.bin
- SHA-256: `f7fa350a9c5b83df7398e3b693551de218aef307333c63da35500823b5a50a61`
- Size: 7998014 bytes
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

- binwalk -eM --directory known_firmware/extracted/f7fa350a9c5b83df exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f7fa350a9c5b83df/_openwrt-25.12.5-ramips-mt7621-xiaomi_mi-router-cr6609-squashfs-sysupgrade.bin.extracted/sysupgrade-xiaomi_mi-router-cr6609/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
