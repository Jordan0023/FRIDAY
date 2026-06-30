# Firmware Audit: WNDR3700V1 / WNDR3700_Initial_Release_Firmware_-_Version_1.0.4.31__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V1/WNDR3700%20Initial%20Release%20Firmware%20-%20Version%201.0.4.31%20(North%20America).zip
- Local path: known_firmware/firmware/WNDR3700V1/WNDR3700_Initial_Release_Firmware_-_Version_1.0.4.31__North_America_.zip
- SHA-256: `d4d772a3775289f5e899166db23c45096df0d3292d0e2933e2c4408a7931be76`
- Size: 5156543 bytes
- Version: 0.4.31__North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d4d772a3775289f5 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
