# Firmware Audit: GL.iNet GL-B1300 Convexa-B / openwrt-b1300-4.3.11-0320-1710946063.bin

- Source URL: https://fw.gl-inet.com/firmware/b1300/release4/openwrt-b1300-4.3.11-0320-1710946063.bin
- Local path: known_firmware/firmware/GL.iNet_GL-B1300_Convexa-B/openwrt-b1300-4.3.11-0320-1710946063.bin
- SHA-256: `2dfab1bacd5b329a3f510f15081bb7824489292187b18ba3f86909ebdfa2ed72`
- Size: 17303335 bytes
- Version: 4.3.11
- Release date: 2024-03-20 22:46:13

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

- binwalk -eM --directory known_firmware/extracted/2dfab1bacd5b329a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2dfab1bacd5b329a/_openwrt-b1300-4.3.11-0320-1710946063.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
