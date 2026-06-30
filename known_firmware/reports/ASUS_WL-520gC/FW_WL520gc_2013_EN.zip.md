# Firmware Audit: ASUS WL-520gC / FW_WL520gc_2013_EN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520gc_2013_EN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520gc_2013_EN.zip
- SHA-256: `a7a0784b0c71e44c411c4aca232de0f843bd075f907f10a6c25a5e348138f4ab`
- Size: 1858230 bytes
- Version: 2.0.1.3
- Release date: 2009/08/27

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a7a0784b0c71e44c exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/a7a0784b0c71e44c/_FW_WL520gc_2013_EN.zip.extracted/_WL520gc_2.0.1.3_EN.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
