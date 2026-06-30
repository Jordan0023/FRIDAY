# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-0409release3-0615-1718434173.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-0409release3-0615-1718434173.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-0409release3-0615-1718434173.bin
- SHA-256: `a14853f59db9f05e7dec926eeb7ad81e6e3a4edd0e2af7f15b497c4f90d87eb1`
- Size: 59783090 bytes
- Version: 4.4.9
- Release date: 2024-06-15 14:46:48

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

- binwalk -eM --directory known_firmware/extracted/a14853f59db9f05e stopped: extraction exceeded 768 MB: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a14853f59db9f05e/_openwrt-xe3000-4.0-0409release3-0615-1718434173.bin.extracted/sysupgrade-glinet_gl-xe3000/_root.extracted/squashfs-root/bin/sleep -> /usr/libexec/sleep-coreutils; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
