# Firmware Audit: RAX29 / RAX29-V1.0.5.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX29/RAX29-V1.0.5.70.zip
- Local path: known_firmware/firmware/RAX29/RAX29-V1.0.5.70.zip
- SHA-256: `965e8f0a9fc4bc8f2d7102924ff04ac35f821e42c5336da2adae7753e06d822b`
- Size: 63314819 bytes
- Version: 1.0.5.70
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

- binwalk -eM --directory known_firmware/extracted/965e8f0a9fc4bc8f exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/965e8f0a9fc4bc8f/_RAX29-V1.0.5.70.zip.extracted/_RAX29-V1.0.5.70_1.img.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
