# Firmware Audit: WNR3500V2 / WNR3500v2_Firmware_Version_1.2.2.28__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500V2/WNR3500v2%20Firmware%20Version%201.2.2.28%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR3500V2/WNR3500v2_Firmware_Version_1.2.2.28__All_regions_except_North_America_.zip
- SHA-256: `6f097faf7a8a2e252ea7afdc5224a61bfe967958183c0721b1cb9cc7ca9d7e45`
- Size: 3443761 bytes
- Version: 2.2.28__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6f097faf7a8a2e25 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
