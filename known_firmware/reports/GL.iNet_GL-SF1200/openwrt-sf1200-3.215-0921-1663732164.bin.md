# Firmware Audit: GL.iNet GL-SF1200 / openwrt-sf1200-3.215-0921-1663732164.bin

- Source URL: https://fw.gl-inet.com/firmware/sf1200/release/openwrt-sf1200-3.215-0921-1663732164.bin
- Local path: known_firmware/firmware/GL.iNet_GL-SF1200/openwrt-sf1200-3.215-0921-1663732164.bin
- SHA-256: `e44d4e241224bbf6523e718fc92af4a90ea8b87e81c997950d9611676fe9d4ed`
- Size: 12058912 bytes
- Version: 3.215
- Release date: 2022-09-21 11:49:24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVAl`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e44d4e241224bbf6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e44d4e241224bbf6/_openwrt-sf1200-3.215-0921-1663732164.bin.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
