# Firmware Audit: RAX36S / RAX36S_V1.0.4.46.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36S/RAX36S_V1.0.4.46.zip
- Local path: known_firmware/firmware/RAX36S/RAX36S_V1.0.4.46.zip
- SHA-256: `743aba117a2070c7bf340f7c5550e40347c3744dfabc28b4c00a1da15805ea85`
- Size: 58925104 bytes
- Version: 0.4.46
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, token`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/743aba117a2070c7 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/743aba117a2070c7/_RAX36S_V1.0.4.46.zip.extracted/_RAX36S-V1.0.4.46.img.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
