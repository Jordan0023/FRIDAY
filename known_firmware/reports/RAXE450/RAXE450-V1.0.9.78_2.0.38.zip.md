# Firmware Audit: RAXE450 / RAXE450-V1.0.9.78_2.0.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE450/RAXE450-V1.0.9.78_2.0.38.zip
- Local path: known_firmware/firmware/RAXE450/RAXE450-V1.0.9.78_2.0.38.zip
- SHA-256: `acef0f3a4637a5eb8a914dd32b5e24447ecd878aa7f2df9520a00f48c35cf938`
- Size: 77780126 bytes
- Version: 1.0.9.78_2.0.38
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password, token`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SShd, sshd`

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

- binwalk -eM --directory known_firmware/extracted/acef0f3a4637a5eb exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/acef0f3a4637a5eb/_RAXE450-V1.0.9.78_2.0.38.zip.extracted/_RAXE450-V1.0.9.78_2.0.38.chk.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
