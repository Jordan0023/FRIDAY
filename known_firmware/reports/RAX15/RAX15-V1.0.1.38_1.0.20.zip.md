# Firmware Audit: RAX15 / RAX15-V1.0.1.38_1.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.1.38_1.0.20.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.1.38_1.0.20.zip
- SHA-256: `4ba810e194f475154ea22374640b4c2aefa5b703e05cdb9d2bf7518ae9f73eda`
- Size: 52081977 bytes
- Version: 1.0.1.38_1.0.20
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ba810e194f47515 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
