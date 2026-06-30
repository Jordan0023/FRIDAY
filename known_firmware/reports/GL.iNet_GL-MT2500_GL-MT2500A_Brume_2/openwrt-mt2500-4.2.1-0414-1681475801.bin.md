# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.2.1-0414-1681475801.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.2.1-0414-1681475801.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.2.1-0414-1681475801.bin
- SHA-256: `977dbc05b88673f7b9e19676ed4c4c01374216abdc88906050f271378a809480`
- Size: 58000969 bytes
- Version: 4.2.1
- Release date: 2023-04-14 20:34:00

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

- binwalk -eM --directory known_firmware/extracted/977dbc05b88673f7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/977dbc05b88673f7/_openwrt-mt2500-4.2.1-0414-1681475801.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
