# Firmware Audit: RAX36S / RAX36S_V1.0.3.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36S/RAX36S_V1.0.3.34.zip
- Local path: known_firmware/firmware/RAX36S/RAX36S_V1.0.3.34.zip
- SHA-256: `6924dfacbf2128979985b01ef68f4ae782025883a3bab5191a2e76c144f22b32`
- Size: 58907833 bytes
- Version: 0.3.34
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

- binwalk -eM --directory known_firmware/extracted/6924dfacbf212897 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/6924dfacbf212897/_RAX36S_V1.0.3.34.zip.extracted/_RAX36S-V1.0.3.34.img.extracted/squashfs-root/bin/dhdctl -> /usr/sbin/dhd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
