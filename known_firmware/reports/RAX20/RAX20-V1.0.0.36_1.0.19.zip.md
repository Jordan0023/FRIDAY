# Firmware Audit: RAX20 / RAX20-V1.0.0.36_1.0.19.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.0.36_1.0.19.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.0.36_1.0.19.zip
- SHA-256: `d8152813c2965518e738f735f13f1c6d60efc10c9ac32b45d2c92615a5afb92d`
- Size: 52058811 bytes
- Version: 1.0.0.36_1.0.19
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, boA`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d8152813c2965518 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
