# Firmware Audit: WNR2000V1 / WNR2000_Firmware_Version_1.2.0.8__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v1/WNR2000%20Firmware%20Version%201.2.0.8%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNR2000V1/WNR2000_Firmware_Version_1.2.0.8__All_regions_except_North_America_.zip
- SHA-256: `a8e0f008fa2ed3a36e3711903ec066ce3383835f5165ca7021f32bbc74c25491`
- Size: 2742505 bytes
- Version: 2.0.8__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a8e0f008fa2ed3a3 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
