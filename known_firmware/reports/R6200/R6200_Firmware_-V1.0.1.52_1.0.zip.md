# Firmware Audit: R6200 / R6200_Firmware_-V1.0.1.52_1.0.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/R6200/R6200_Firmware_-V1.0.1.52_1.0.zip
- Local path: known_firmware/firmware/R6200/R6200_Firmware_-V1.0.1.52_1.0.zip
- SHA-256: `066e21a8bdc8ccc7242b7cd2d53299038d6d58bdb8610cfcc9d97dd87229384e`
- Size: 9440553 bytes
- Version: 1.0.1.52_1.0
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/066e21a8bdc8ccc7 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
