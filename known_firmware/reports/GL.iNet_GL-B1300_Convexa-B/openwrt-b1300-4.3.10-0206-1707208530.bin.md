# Firmware Audit: GL.iNet GL-B1300 Convexa-B / openwrt-b1300-4.3.10-0206-1707208530.bin

- Source URL: https://fw.gl-inet.com/firmware/b1300/release4/openwrt-b1300-4.3.10-0206-1707208530.bin
- Local path: known_firmware/firmware/GL.iNet_GL-B1300_Convexa-B/openwrt-b1300-4.3.10-0206-1707208530.bin
- SHA-256: `7cab38bb7d474b563ad3c114638a28c65a6dd778e29a3bb87bcb41bce8b13b13`
- Size: 17828301 bytes
- Version: 4.3.10
- Release date: 2024-02-06 16:33:59

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7cab38bb7d474b56 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7cab38bb7d474b56/_openwrt-b1300-4.3.10-0206-1707208530.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
