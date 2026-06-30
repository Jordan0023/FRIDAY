# Firmware Audit: GL.iNet microuter-N300 / openwrt-n300-3.216-0321-1679391221.bin

- Source URL: https://fw.gl-inet.com/firmware/n300/release/openwrt-n300-3.216-0321-1679391221.bin
- Local path: known_firmware/firmware/GL.iNet_microuter-N300/openwrt-n300-3.216-0321-1679391221.bin
- SHA-256: `ab284dd45f5c2b0cb6d8c3efebac271e091ab8d68b701ef538f8c97b75a8893f`
- Size: 12583200 bytes
- Version: 3.216
- Release date: 2023-03-21 17:33:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ab284dd45f5c2b0c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ab284dd45f5c2b0c/_openwrt-n300-3.216-0321-1679391221.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
