# Firmware Audit: WNDR3700V1 / WNDR3700_Firmware_Version_1.0.4.49__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V1/WNDR3700%20Firmware%20Version%201.0.4.49%20(North%20America).zip
- Local path: known_firmware/firmware/WNDR3700V1/WNDR3700_Firmware_Version_1.0.4.49__North_America_.zip
- SHA-256: `08087f39b145224fb5e5ae3b750af2b0af9a2ea74eba76a2f925832d5854c333`
- Size: 5946404 bytes
- Version: 0.4.49__North_America_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/08087f39b145224f exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
