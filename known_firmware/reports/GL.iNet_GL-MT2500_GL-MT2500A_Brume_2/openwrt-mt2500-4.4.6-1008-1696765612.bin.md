# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.4.6-1008-1696765612.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.4.6-1008-1696765612.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.4.6-1008-1696765612.bin
- SHA-256: `26f67e3f231f9b7cffb2686ed5af315a3210eee01d97bfa0f8cb7144e324ac15`
- Size: 58021820 bytes
- Version: 4.4.6
- Release date: 2023-10-08 19:44:19

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

- binwalk -eM --directory known_firmware/extracted/26f67e3f231f9b7c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/26f67e3f231f9b7c/_openwrt-mt2500-4.4.6-1008-1696765612.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
