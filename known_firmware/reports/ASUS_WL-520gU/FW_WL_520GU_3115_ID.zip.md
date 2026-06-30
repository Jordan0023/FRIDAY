# Firmware Audit: ASUS WL-520gU / FW_WL_520GU_3115_ID.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FW_WL_520GU_3115_ID.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FW_WL_520GU_3115_ID.zip
- SHA-256: `1d3ed59940649fdb80d775eec20460bc4a25b55ebfd7518259c2bd6f9e2d6966`
- Size: 3947110 bytes
- Version: 3.1.1.5_ID
- Release date: 2010/09/30

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, HTTPD, bOa, cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1d3ed59940649fdb exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/1d3ed59940649fdb/_FW_WL_520GU_3115_ID.zip.extracted/_WL520gu_3.1.1.5_ID.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
