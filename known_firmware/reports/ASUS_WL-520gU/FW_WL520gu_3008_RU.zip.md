# Firmware Audit: ASUS WL-520gU / FW_WL520gu_3008_RU.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FW_WL520gu_3008_RU.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FW_WL520gu_3008_RU.zip
- SHA-256: `7688b54bf967f7341c4ebc9f11f260dd324f66dbbf7ae338b5975eb72a0f750d`
- Size: 3949580 bytes
- Version: 3.0.0.8_RU
- Release date: 2009/04/29

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `HTTPD, bOa, cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7688b54bf967f734 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/7688b54bf967f734/_FW_WL520gu_3008_RU.zip.extracted/_WL520gu_3.0.0.8_RU.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
