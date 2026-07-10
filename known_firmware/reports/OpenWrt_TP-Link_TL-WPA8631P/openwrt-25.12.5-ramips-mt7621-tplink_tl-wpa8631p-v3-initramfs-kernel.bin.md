# Firmware Audit: OpenWrt TP-Link TL-WPA8631P / openwrt-25.12.5-ramips-mt7621-tplink_tl-wpa8631p-v3-initramfs-kernel.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-tplink_tl-wpa8631p-v3-initramfs-kernel.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_TL-WPA8631P/openwrt-25.12.5-ramips-mt7621-tplink_tl-wpa8631p-v3-initramfs-kernel.bin
- SHA-256: `06df20933e0fc29d74b9186d422162fad154a019526e19a0e93ab5e3122dbc34`
- Size: 7858366 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/06df20933e0fc29d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/06df20933e0fc29d/_openwrt-25.12.5-ramips-mt7621-tplink_tl-wpa8631p-v3-initramfs-kernel.bin.extracted/_200.extracted/_A77ED4.extracted/cpio-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
