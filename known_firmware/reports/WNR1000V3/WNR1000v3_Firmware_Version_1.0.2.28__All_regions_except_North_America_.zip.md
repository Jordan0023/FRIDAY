# Firmware Audit: WNR1000V3 / WNR1000v3_Firmware_Version_1.0.2.28__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR1000v3/WNR1000v3%20Firmware%20Version%201.0.2.28%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR1000V3/WNR1000v3_Firmware_Version_1.0.2.28__All_regions_except_North_America_.zip
- SHA-256: `99c7e981a94b1b082606c0113752e99e702baadae258b811f40d873f0a73929b`
- Size: 2586774 bytes
- Version: 0.2.28__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/99c7e981a94b1b08 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
