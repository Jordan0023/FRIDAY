# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.5.0-0123-1706012955.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.5.0-0123-1706012955.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.5.0-0123-1706012955.tar
- SHA-256: `3c5a568948c9b6a8369f549f4bc38ef4e1d89b93b87924f541072dbad84e8eda`
- Size: 47517857 bytes
- Version: 4.5.0
- Release date: 2024-01-23 20:27:42

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3c5a568948c9b6a8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3c5a568948c9b6a8/_openwrt-ax1800-4.5.0-0123-1706012955.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
