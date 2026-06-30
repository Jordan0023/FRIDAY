# Firmware Audit: WNR2000V2 / WNR2000v2_Firmware_Version_1.2.0.4_35.0.57__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v2/WNR2000v2%20Firmware%20Version%201.2.0.4_35.0.57%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR2000V2/WNR2000v2_Firmware_Version_1.2.0.4_35.0.57__All_regions_except_North_America_.zip
- SHA-256: `fdb52ef4d7a1d8d8a973e2df56f4040d1fb000e28fc5f2f48184563c7a04c6c2`
- Size: 3457281 bytes
- Version: 2.0.4_35.0.57__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fdb52ef4d7a1d8d8 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
