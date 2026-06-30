# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.0-release10301-0512-1683887727.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.0-release10301-0512-1683887727.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.0-release10301-0512-1683887727.bin
- SHA-256: `55c03c8c1cf6b36397004cf16df263bf0a02c76034c53b6ac89fdb17e00fc5d6`
- Size: 62219397 bytes
- Version: 4.3.1
- Release date: 2023-05-12 18:32:32

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

- binwalk -eM --directory known_firmware/extracted/55c03c8c1cf6b363 stopped: extraction exceeded 768 MB: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/55c03c8c1cf6b363/_openwrt-x3000-4.0-release10301-0512-1683887727.bin.extracted/sysupgrade-glinet_gl-x3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
