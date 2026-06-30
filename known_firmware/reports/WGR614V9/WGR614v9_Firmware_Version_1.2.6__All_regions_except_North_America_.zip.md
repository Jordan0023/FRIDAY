# Firmware Audit: WGR614V9 / WGR614v9_Firmware_Version_1.2.6__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V9/WGR614v9%20Firmware%20Version%201.2.6%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WGR614V9/WGR614v9_Firmware_Version_1.2.6__All_regions_except_North_America_.zip
- SHA-256: `362afeca67d87db42ab6c354b215ad198c21f638209a414aa718caac63b5bd8e`
- Size: 1926208 bytes
- Version: 2.6__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/362afeca67d87db4 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/362afeca67d87db4/_WGR614v9_Firmware_Version_1.2.6__All_regions_except_North_America_.zip.extracted/_WGR614v9-V1.2.6_18.0.17.chk.extracted/squashfs-root/etc/resolv.conf -> /tmp/resolv.conf; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
