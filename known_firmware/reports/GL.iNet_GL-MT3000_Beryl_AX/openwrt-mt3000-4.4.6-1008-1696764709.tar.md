# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.4.6-1008-1696764709.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.4.6-1008-1696764709.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.4.6-1008-1696764709.tar
- SHA-256: `271457630e8d3ef51c49acfec410715802405cb85491616c94a561a7eb0d9a4e`
- Size: 60899261 bytes
- Version: 4.4.6
- Release date: 2023-10-08 19:29:12

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

- binwalk -eM --directory known_firmware/extracted/271457630e8d3ef5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/271457630e8d3ef5/_openwrt-mt3000-4.4.6-1008-1696764709.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
