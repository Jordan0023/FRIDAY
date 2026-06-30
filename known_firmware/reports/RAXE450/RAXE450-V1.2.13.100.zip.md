# Firmware Audit: RAXE450 / RAXE450-V1.2.13.100.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE450/RAXE450-V1.2.13.100.zip
- Local path: known_firmware/firmware/RAXE450/RAXE450-V1.2.13.100.zip
- SHA-256: `86240efab9b5cb922847387353fa66433b6bb279e4b23ae9def0cc20cedde0a6`
- Size: 81004573 bytes
- Version: 1.2.13.100
- Release date: unknown

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN OPENSSH PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password, token`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SShd, sshd, telnetd`

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

- binwalk -eM --directory known_firmware/extracted/86240efab9b5cb92 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/86240efab9b5cb92/_RAXE450-V1.2.13.100.zip.extracted/_RAXE450-V1.2.13.100_2.0.54.chk.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
