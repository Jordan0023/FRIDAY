# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.1.0-1114-1668412657.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.1.0-1114-1668412657.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.1.0-1114-1668412657.tar
- SHA-256: `744fa302d5b5432507b3e119065d762ede94b379bccda74c7fe715a7fc303da7`
- Size: 51971189 bytes
- Version: 4.1.0
- Release date: 2022-11-14 15:56:24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/744fa302d5b54325 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/744fa302d5b54325/_openwrt-ax1800-4.1.0-1114-1668412657.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
