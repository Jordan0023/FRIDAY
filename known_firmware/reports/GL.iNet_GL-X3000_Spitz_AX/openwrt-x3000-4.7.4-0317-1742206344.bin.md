# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.7.4-0317-1742206344.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.7.4-0317-1742206344.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.7.4-0317-1742206344.bin
- SHA-256: `1b8ba38275c7f23f57f51c6492d7d16575db4737d865e639121ba62931d0eaa0`
- Size: 62100783 bytes
- Version: 4.7.4
- Release date: 2025-03-17 17:47:44

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

- binwalk -eM --directory known_firmware/extracted/1b8ba38275c7f23f stopped: extraction exceeded 768 MB: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1b8ba38275c7f23f/_openwrt-x3000-4.7.4-0317-1742206344.bin.extracted/sysupgrade-glinet_gl-x3000/_root.extracted/squashfs-root-0/bin/sleep -> /usr/libexec/sleep-coreutils; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
