# Firmware Audit: WNDR3700V1 / WNDR3700_Firmware_Version_1.0.4.68__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V1/WNDR3700%20Firmware%20Version%201.0.4.68%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNDR3700V1/WNDR3700_Firmware_Version_1.0.4.68__All_regions_except_North_America_.zip
- SHA-256: `5474f75bf2da724fdeec080c0d529e0ac7ca7cfdb19f940944dacfc2618a98e1`
- Size: 5968936 bytes
- Version: 0.4.68__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5474f75bf2da724f exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
