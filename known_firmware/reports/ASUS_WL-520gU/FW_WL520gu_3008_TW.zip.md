# Firmware Audit: ASUS WL-520gU / FW_WL520gu_3008_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FW_WL520gu_3008_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FW_WL520gu_3008_TW.zip
- SHA-256: `61390fd70bfd8ca8b5a4aa3d9e49e3f787afb723b1607e73ce755d08ea8be86b`
- Size: 3946831 bytes
- Version: 3.0.0.8_TW
- Release date: 2009/04/27

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

- binwalk -eM --directory known_firmware/extracted/61390fd70bfd8ca8 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/61390fd70bfd8ca8/_FW_WL520gu_3008_TW.zip.extracted/_WL520gu_3.0.0.8_TW.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
