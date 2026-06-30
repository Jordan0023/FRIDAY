# Firmware Audit: RAX30 / RAX30-V1.0.7.78.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX30/RAX30-V1.0.7.78.zip
- Local path: known_firmware/firmware/RAX30/RAX30-V1.0.7.78.zip
- SHA-256: `ac8d0860d0a6adca891a5598beb237c145c4d2d55b076f232d4280ef066dfcac`
- Size: 62355730 bytes
- Version: 1.0.7.78
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

- binwalk -eM --directory known_firmware/extracted/ac8d0860d0a6adca exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/ac8d0860d0a6adca/_RAX30-V1.0.7.78.zip.extracted/_RAX30-V1.0.7.78_1.img.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
