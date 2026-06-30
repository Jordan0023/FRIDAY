# Firmware Audit: WNR2000V1 / WNR2000_Firmware_Version_1.1.2.6__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v1/WNR2000%20Firmware%20Version%201.1.2.6%20(North%20America).zip
- Local path: known_firmware/firmware/WNR2000V1/WNR2000_Firmware_Version_1.1.2.6__North_America_.zip
- SHA-256: `60180b1c513e129ba5b46ac4d77f1d9d8c537f9ebb20a46500eb99432acb7196`
- Size: 2547096 bytes
- Version: 1.2.6__North_America_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/60180b1c513e129b exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
