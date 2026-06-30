# Firmware Audit: ASUS WL-520gU / FW_WL520gU_2008_EN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FW_WL520gU_2008_EN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FW_WL520gU_2008_EN.zip
- SHA-256: `cb9209610515e32ed2c1289d70b9f3a4a9df7be22e91149aef8267361c1ef5cf`
- Size: 3737483 bytes
- Version: 2.0.0.8
- Release date: 2008/04/16

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, Secret, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

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

- binwalk -eM --directory known_firmware/extracted/cb9209610515e32e exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/cb9209610515e32e/_FW_WL520gU_2008_EN.zip.extracted/FW_WL520gU_2008_EN/_WL520gu_2.0.0.8_EN.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
