# Firmware Audit: GL.iNet microuter-N300 / openwrt-n300-3.215-0921-1663732103.bin

- Source URL: https://fw.gl-inet.com/firmware/n300/release/openwrt-n300-3.215-0921-1663732103.bin
- Local path: known_firmware/firmware/GL.iNet_microuter-N300/openwrt-n300-3.215-0921-1663732103.bin
- SHA-256: `be1b522acf4362d84f2e6bfac7bb9ab0ffe91dfc762dac27ff2377689ab1c2b2`
- Size: 12583200 bytes
- Version: 3.215
- Release date: 2022-09-21 11:48:23

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

- binwalk -eM --directory known_firmware/extracted/be1b522acf4362d8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/be1b522acf4362d8/_openwrt-n300-3.215-0921-1663732103.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
