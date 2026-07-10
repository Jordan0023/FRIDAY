# Firmware Audit: OpenWrt SNR SNR-CPE-ME2-Lite / openwrt-25.12.5-ramips-mt7621-snr_snr-cpe-me2-lite-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-snr_snr-cpe-me2-lite-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_SNR_SNR-CPE-ME2-Lite/openwrt-25.12.5-ramips-mt7621-snr_snr-cpe-me2-lite-squashfs-sysupgrade.bin
- SHA-256: `fea01e25f419b859a64e1165584c3443fc1c301ddb6f56b346546758ce349806`
- Size: 8061497 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fea01e25f419b859 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fea01e25f419b859/_openwrt-25.12.5-ramips-mt7621-snr_snr-cpe-me2-lite-squashfs-sysupgrade.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
