# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-0413release2-1025-1729827416.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-0413release2-1025-1729827416.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-0413release2-1025-1729827416.bin
- SHA-256: `b51caad4a7e42183cb3af9d3d215dd0b4861d282468c98bff0c4d95c11dfd463`
- Size: 62752087 bytes
- Version: 4.4.13
- Release date: 2024-10-25 11:31:05

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

- binwalk -eM --directory known_firmware/extracted/b51caad4a7e42183 stopped: extraction exceeded 768 MB: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b51caad4a7e42183/_openwrt-xe3000-4.0-0413release2-1025-1729827416.bin.extracted/sysupgrade-glinet_gl-xe3000/_root.extracted/squashfs-root/bin/sleep -> /usr/libexec/sleep-coreutils; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
