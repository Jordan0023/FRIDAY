# Firmware Audit: GL.iNet GL-USB150 Microuter / openwrt-usb150-3.218-0709-1720515319.bin

- Source URL: https://fw.gl-inet.com/firmware/usb150/v4/openwrt-usb150-3.218-0709-1720515319.bin
- Local path: known_firmware/firmware/GL.iNet_GL-USB150_Microuter/openwrt-usb150-3.218-0709-1720515319.bin
- SHA-256: `c4f3f7b857589e0b84335b5c602076c0318ffbe7a074056ab4eca54163117338`
- Size: 11075904 bytes
- Version: 3.218
- Release date: 2024-07-09 16:55:19

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c4f3f7b857589e0b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c4f3f7b857589e0b/_openwrt-usb150-3.218-0709-1720515319.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
