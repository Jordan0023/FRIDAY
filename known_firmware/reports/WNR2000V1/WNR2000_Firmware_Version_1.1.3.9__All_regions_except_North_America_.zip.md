# Firmware Audit: WNR2000V1 / WNR2000_Firmware_Version_1.1.3.9__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v1/WNR2000%20Firmware%20Version%201.1.3.9%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR2000V1/WNR2000_Firmware_Version_1.1.3.9__All_regions_except_North_America_.zip
- SHA-256: `d01e03700f67dcd40cf06d4140dc72466bb6b4feb215d52712c8d7699c4fae6f`
- Size: 2561419 bytes
- Version: 1.3.9__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d01e03700f67dcd4 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
