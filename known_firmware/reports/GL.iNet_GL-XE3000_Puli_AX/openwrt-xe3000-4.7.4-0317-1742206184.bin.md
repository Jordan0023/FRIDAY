# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.7.4-0317-1742206184.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.7.4-0317-1742206184.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.7.4-0317-1742206184.bin
- SHA-256: `a518d0aebe0406f7f033a460cbd66d73c947f3f875f961f245109950ba28233f`
- Size: 61127985 bytes
- Version: 4.7.4
- Release date: 2025-03-17 17:45:12

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

- binwalk -eM --directory known_firmware/extracted/a518d0aebe0406f7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a518d0aebe0406f7/_openwrt-xe3000-4.7.4-0317-1742206184.bin.extracted/sysupgrade-glinet_gl-xe3000/_root.extracted/squashfs-root-0/bin/sleep -> /usr/libexec/sleep-coreutils; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
