# Firmware Audit: RAX10 / RAX10-V1.0.20.174.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.20.174.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.20.174.zip
- SHA-256: `1bbb83c825e1101a9127a955c044f992b6ca2ec1f9e1cd0da5cce5cb7c605c6b`
- Size: 54070379 bytes
- Version: 1.0.20.174
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1bbb83c825e1101a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
