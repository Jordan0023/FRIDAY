# Firmware Audit: GL.iNet GL-B1300 Convexa-B / openwrt-b1300-4.3.18-0823-1724395234.bin

- Source URL: https://fw.gl-inet.com/firmware/b1300/release4/openwrt-b1300-4.3.18-0823-1724395234.bin
- Local path: known_firmware/firmware/GL.iNet_GL-B1300_Convexa-B/openwrt-b1300-4.3.18-0823-1724395234.bin
- SHA-256: `0bfdd14ca067eb5bc0f48f2d9c9682167b423ba985d3858897244e4ac62a68e9`
- Size: 17302329 bytes
- Version: 4.3.18
- Release date: 2024-08-23 14:39:02

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0bfdd14ca067eb5b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0bfdd14ca067eb5b/_openwrt-b1300-4.3.18-0823-1724395234.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
