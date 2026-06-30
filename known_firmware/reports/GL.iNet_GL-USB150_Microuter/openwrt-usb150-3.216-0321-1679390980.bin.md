# Firmware Audit: GL.iNet GL-USB150 Microuter / openwrt-usb150-3.216-0321-1679390980.bin

- Source URL: https://fw.gl-inet.com/firmware/usb150/v1/openwrt-usb150-3.216-0321-1679390980.bin
- Local path: known_firmware/firmware/GL.iNet_GL-USB150_Microuter/openwrt-usb150-3.216-0321-1679390980.bin
- SHA-256: `75ea7363b5ae0d538d37e6da78cea509499c5f724ea0451902657998d7e03d69`
- Size: 11075904 bytes
- Version: 3.216
- Release date: 2023-03-21 17:29:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/75ea7363b5ae0d53 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/75ea7363b5ae0d53/_openwrt-usb150-3.216-0321-1679390980.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
