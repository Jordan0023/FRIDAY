# Firmware Audit: RAX29 / RAX29-V1.0.6.74.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX29/RAX29-V1.0.6.74.zip
- Local path: known_firmware/firmware/RAX29/RAX29-V1.0.6.74.zip
- SHA-256: `2c1c3360056e7ca7471890bb9eef91d6be9cf15bebd308d75328e5c1cb69f47d`
- Size: 62252978 bytes
- Version: 1.0.6.74
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Token, password, token`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sshd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Lighttpd, httpd, lighttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval, SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2c1c3360056e7ca7 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/2c1c3360056e7ca7/_RAX29-V1.0.6.74.zip.extracted/_RAX29-V1.0.6.74_1.img.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
