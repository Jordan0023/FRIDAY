# Firmware Audit: RAXE500 / RAXE500-V1.0.10.86.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE500/RAXE500-V1.0.10.86.zip
- Local path: known_firmware/firmware/RAXE500/RAXE500-V1.0.10.86.zip
- SHA-256: `db44a5e98bed1b21605212a428426fd9861235331219a7b17614d98161622660`
- Size: 80411882 bytes
- Version: 1.0.10.86
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

- binwalk -eM --directory known_firmware/extracted/db44a5e98bed1b21 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/db44a5e98bed1b21/_RAXE500-V1.0.10.86.zip.extracted/_RAXE500-V1.0.10.86_2.0.40.chk.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
