# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.0-0403release7-1115-1700033424.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.0-0403release7-1115-1700033424.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.0-0403release7-1115-1700033424.bin
- SHA-256: `c1a156982997b4d28ffc28d6535ad77150d59b45b4f5ed22f73e792475def60c`
- Size: 62331809 bytes
- Version: 4.4.3
- Release date: 2023-11-15 15:27:36

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

- binwalk -eM --directory known_firmware/extracted/c1a156982997b4d2 stopped: extraction exceeded 768 MB: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c1a156982997b4d2/_openwrt-x3000-4.0-0403release7-1115-1700033424.bin.extracted/sysupgrade-glinet_gl-x3000/_root.extracted/squashfs-root/bin/sleep -> /usr/libexec/sleep-coreutils; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
