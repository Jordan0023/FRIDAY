# Firmware Audit: RAX75 / RAX75-V1.0.1.58_1.0.24.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.1.58_1.0.24.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.1.58_1.0.24.zip
- SHA-256: `3ef9c0cb6de36d77a67b82b888c08e06e2951c9e92d66ebf6aad705a02626cca`
- Size: 48622858 bytes
- Version: 1.0.1.58_1.0.24
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `pwd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3ef9c0cb6de36d77 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
