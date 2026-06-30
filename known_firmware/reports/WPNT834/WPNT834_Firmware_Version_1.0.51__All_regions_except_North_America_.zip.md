# Firmware Audit: WPNT834 / WPNT834_Firmware_Version_1.0.51__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WPNT834/WPNT834%20Firmware%20Version%201.0.51%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WPNT834/WPNT834_Firmware_Version_1.0.51__All_regions_except_North_America_.zip
- SHA-256: `441286811e1a1b529b7a0a56ac5a9eaad8e1561040b68cd0b6e2ee2823832594`
- Size: 3395709 bytes
- Version: 0.51__All_regions_except_North_America_
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

Evidence: `boa, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/441286811e1a1b52 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/441286811e1a1b52/_WPNT834_Firmware_Version_1.0.51__All_regions_except_North_America_.zip.extracted/_wpnt834_1_0_51_non_na.img.extracted/squashfs-root/bin/ip-down -> /usr/bin/webs; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
