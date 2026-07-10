# Firmware Audit: OpenWrt ELECOM WMC-X1800GST / openwrt-25.12.5-ramips-mt7621-elecom_wmc-x1800gst-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-elecom_wmc-x1800gst-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_ELECOM_WMC-X1800GST/openwrt-25.12.5-ramips-mt7621-elecom_wmc-x1800gst-squashfs-sysupgrade.bin
- SHA-256: `6aa11fe627c710a4d1bb16a3ed91f01a681b4f30f34857d67738431283a587a5`
- Size: 7998002 bytes
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

- binwalk -eM --directory known_firmware/extracted/6aa11fe627c710a4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6aa11fe627c710a4/_openwrt-25.12.5-ramips-mt7621-elecom_wmc-x1800gst-squashfs-sysupgrade.bin.extracted/sysupgrade-elecom_wmc-x1800gst/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
