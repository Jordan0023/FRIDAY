# Firmware Audit: GL.iNet GL-AR750 Creta / openwrt-ar750-4.3.7-0913-1694590565.bin

- Source URL: https://fw.gl-inet.com/firmware/ar750/release4/openwrt-ar750-4.3.7-0913-1694590565.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR750_Creta/openwrt-ar750-4.3.7-0913-1694590565.bin
- SHA-256: `16312e117c274ddb3d34b451ee6aafa42d95eea41e25b516ee6f0107ee7a6d46`
- Size: 14485816 bytes
- Version: 4.3.7
- Release date: 2023-09-13 15:34:55

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/16312e117c274ddb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/16312e117c274ddb/_openwrt-ar750-4.3.7-0913-1694590565.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
