# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.2.1-0414-1681481817.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.2.1-0414-1681481817.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.2.1-0414-1681481817.tar
- SHA-256: `42a357d3afe6c3084480bf2a3eda696a17c27a0b369316db781dd0603ee7f018`
- Size: 59373121 bytes
- Version: 4.2.1
- Release date: 2023-04-14 22:15:11

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/42a357d3afe6c308 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/42a357d3afe6c308/_openwrt-ax1800-4.2.1-0414-1681481817.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
