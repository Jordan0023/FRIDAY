# Firmware Audit: ASUS WL-520gC / FW_WL520gc_2010_CN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520gc_2010_CN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520gc_2010_CN.zip
- SHA-256: `4d481b91a7c0764c5bd13a71a0552552ae476d17b00241fb995108b6ec51fcd2`
- Size: 1840301 bytes
- Version: 2.0.1.0
- Release date: 2008/04/15

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

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

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4d481b91a7c0764c exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/4d481b91a7c0764c/_FW_WL520gc_2010_CN.zip.extracted/_WL520gc_2.0.1.0_CN.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
