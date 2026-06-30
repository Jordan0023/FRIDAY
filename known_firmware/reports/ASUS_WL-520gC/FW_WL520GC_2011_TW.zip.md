# Firmware Audit: ASUS WL-520gC / FW_WL520GC_2011_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GC/FW_WL520GC_2011_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-520gC/FW_WL520GC_2011_TW.zip
- SHA-256: `cc3ec3db157e2f19f82168fd8bde7970cb19cbdfad50b8b9ee285dff28be538a`
- Size: 1857440 bytes
- Version: 2.0.1.1
- Release date: 2008/04/25

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

- binwalk -eM --directory known_firmware/extracted/cc3ec3db157e2f19 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/cc3ec3db157e2f19/_FW_WL520GC_2011_TW.zip.extracted/FW_WL520GC_2011_TW/_WL520gc_2.0.1.1_TW.trx.extracted/squashfs-root/etc/hosts -> /tmp/hosts; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
