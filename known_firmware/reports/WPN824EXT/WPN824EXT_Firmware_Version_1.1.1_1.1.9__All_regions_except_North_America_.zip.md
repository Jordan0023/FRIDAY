# Firmware Audit: WPN824EXT / WPN824EXT_Firmware_Version_1.1.1_1.1.9__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WPN824EXT/WPN824EXT%20Firmware%20Version%201.1.1_1.1.9%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WPN824EXT/WPN824EXT_Firmware_Version_1.1.1_1.1.9__All_regions_except_North_America_.zip
- SHA-256: `ff26a7007a315bcbe6d8d286deb696d372a059d3d154a6616f7ac49a0d92477f`
- Size: 1593594 bytes
- Version: 1.1_1.1.9__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ff26a7007a315bcb exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
