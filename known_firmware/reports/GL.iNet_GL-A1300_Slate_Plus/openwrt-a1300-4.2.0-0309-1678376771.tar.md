# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.2.0-0309-1678376771.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.2.0-0309-1678376771.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.2.0-0309-1678376771.tar
- SHA-256: `1e58be296816523200ffa598bbd4b71c3fb7a9335c7af191988cd47c287929cf`
- Size: 57724739 bytes
- Version: 4.2.0
- Release date: 2023-03-09 23:44:24

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

- binwalk -eM --directory known_firmware/extracted/1e58be2968165232 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1e58be2968165232/_openwrt-a1300-4.2.0-0309-1678376771.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
