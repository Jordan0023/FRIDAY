# Firmware Audit: RAX78 / RAX78-V1.0.20.174.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.20.174.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.20.174.zip
- SHA-256: `09cd2acd7b5de824406a63f91f1d0d3afcb0bdbe7a4e584ed66aee9b51a6350a`
- Size: 67722334 bytes
- Version: 1.0.20.174
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa, boa`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/09cd2acd7b5de824 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
