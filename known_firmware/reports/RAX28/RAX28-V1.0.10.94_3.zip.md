# Firmware Audit: RAX28 / RAX28-V1.0.10.94_3.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX28/RAX28-V1.0.10.94_3.zip
- Local path: known_firmware/firmware/RAX28/RAX28-V1.0.10.94_3.zip
- SHA-256: `e925a2b0670ef1b8f37d80552fe2819653ec1f3e9b3785bd226206aef7b66a06`
- Size: 66257494 bytes
- Version: 1.0.10.94_3
- Release date: unknown

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN DSA PRIVATE KEY-----, -----BEGIN EC PRIVATE KEY-----, -----BEGIN PRIVATE KEY-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Token, password, token`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sshd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval, SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e925a2b0670ef1b8 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/e925a2b0670ef1b8/_RAX28-V1.0.10.94_3.zip.extracted/_RAX28-V1.0.10.94_3.img.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
