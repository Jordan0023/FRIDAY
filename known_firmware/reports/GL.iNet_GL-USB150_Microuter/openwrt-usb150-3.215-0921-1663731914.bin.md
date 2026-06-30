# Firmware Audit: GL.iNet GL-USB150 Microuter / openwrt-usb150-3.215-0921-1663731914.bin

- Source URL: https://fw.gl-inet.com/firmware/usb150/v1/openwrt-usb150-3.215-0921-1663731914.bin
- Local path: known_firmware/firmware/GL.iNet_GL-USB150_Microuter/openwrt-usb150-3.215-0921-1663731914.bin
- SHA-256: `88fa0a91c9815bdf8a4351ffcc8e5041329610e2189460f7a105a645a4316259`
- Size: 11075904 bytes
- Version: 3.215
- Release date: 2022-09-21 11:45:14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/88fa0a91c9815bdf exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/88fa0a91c9815bdf/_openwrt-usb150-3.215-0921-1663731914.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
