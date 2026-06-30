# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-release30401-0707-1688729985.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-release30401-0707-1688729985.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-release30401-0707-1688729985.bin
- SHA-256: `cf172b974c4ab1659342a616be9b1e172bf5aec747f6c36dfcdd02784ba3b3c0`
- Size: 61369214 bytes
- Version: 4.4.1
- Release date: 2023-07-07 19:36:54

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

- binwalk -eM --directory known_firmware/extracted/cf172b974c4ab165 stopped: extraction exceeded 768 MB: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cf172b974c4ab165/_openwrt-xe3000-4.0-release30401-0707-1688729985.bin.extracted/sysupgrade-glinet_gl-xe3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
