# Firmware Audit: RAXE450 / RAXE450-V1.0.11.94_2.0.44.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE450/RAXE450-V1.0.11.94_2.0.44.zip
- Local path: known_firmware/firmware/RAXE450/RAXE450-V1.0.11.94_2.0.44.zip
- SHA-256: `fd5c0983ca8b028c1c2c40585ff47c2b01f1760c86e429853b2f51089dfdc172`
- Size: 80484554 bytes
- Version: 1.0.11.94_2.0.44
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

- binwalk -eM --directory known_firmware/extracted/fd5c0983ca8b028c exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/fd5c0983ca8b028c/_RAXE450-V1.0.11.94_2.0.44.zip.extracted/_RAXE450-V1.0.11.94_2.0.44.chk.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
