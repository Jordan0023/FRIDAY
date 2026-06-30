# Firmware Audit: WNDR3400V1 / WNDR3400_Firmware_Version_1.0.0.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3400V1/WNDR3400%20Firmware%20Version%201.0.0.34.zip
- Local path: known_firmware/firmware/WNDR3400V1/WNDR3400_Firmware_Version_1.0.0.34.zip
- SHA-256: `757cfad92b204a67a0aad91a7ddf90d59ee02e0976f8603de9170b5500b5c91b`
- Size: 4507783 bytes
- Version: 0.0.34
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/757cfad92b204a67 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
