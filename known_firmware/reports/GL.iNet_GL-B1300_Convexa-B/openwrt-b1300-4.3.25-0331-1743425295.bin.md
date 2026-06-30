# Firmware Audit: GL.iNet GL-B1300 Convexa-B / openwrt-b1300-4.3.25-0331-1743425295.bin

- Source URL: https://fw.gl-inet.com/firmware/b1300/release4/openwrt-b1300-4.3.25-0331-1743425295.bin
- Local path: known_firmware/firmware/GL.iNet_GL-B1300_Convexa-B/openwrt-b1300-4.3.25-0331-1743425295.bin
- SHA-256: `af57a7ca1e49d0e71b8d26b93a1641a24a793c7f2da5c2512af361d985f6ae02`
- Size: 17302386 bytes
- Version: 4.3.25
- Release date: 2025-03-31 20:47:19

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/af57a7ca1e49d0e7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/af57a7ca1e49d0e7/_openwrt-b1300-4.3.25-0331-1743425295.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
