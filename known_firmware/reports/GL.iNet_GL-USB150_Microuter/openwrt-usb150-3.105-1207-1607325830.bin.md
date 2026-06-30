# Firmware Audit: GL.iNet GL-USB150 Microuter / openwrt-usb150-3.105-1207-1607325830.bin

- Source URL: https://fw.gl-inet.com/firmware/usb150/v1/openwrt-usb150-3.105-1207-1607325830.bin
- Local path: known_firmware/firmware/GL.iNet_GL-USB150_Microuter/openwrt-usb150-3.105-1207-1607325830.bin
- SHA-256: `2547a4a0ca2e5a4e912af0b24807c627886b84a9eac66a20153a0830f47ae916`
- Size: 11010222 bytes
- Version: 3.105
- Release date: 2020-12-07 15:23:50

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2547a4a0ca2e5a4e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2547a4a0ca2e5a4e/_openwrt-usb150-3.105-1207-1607325830.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
