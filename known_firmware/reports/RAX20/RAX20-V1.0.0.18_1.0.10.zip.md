# Firmware Audit: RAX20 / RAX20-V1.0.0.18_1.0.10.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.0.18_1.0.10.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.0.18_1.0.10.zip
- SHA-256: `9ab5998fd577dd2dc10aa9d9f6b4c79c4d253abc3b72ec1f433ffe0ba4c17ac8`
- Size: 50922054 bytes
- Version: 1.0.0.18_1.0.10
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, boA`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9ab5998fd577dd2d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
