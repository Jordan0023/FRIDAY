# Firmware Audit: WNR834BV1 / WNR834B_Firmware_Version_1.0.4.2__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR834Bv1/WNR834B%20Firmware%20Version%201.0.4.2%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR834BV1/WNR834B_Firmware_Version_1.0.4.2__All_regions_except_North_America_.zip
- SHA-256: `a3c94c649b22cd215ae5d0c37874b1b691fddf8cd5ff7a00ec8027000077124a`
- Size: 3218074 bytes
- Version: 0.4.2__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3c94c649b22cd21 exited 0: WARNING: Extractor.execute failed to run external extractor 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'': [Errno 2] No such file or directory: 'cramfsswap', 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
