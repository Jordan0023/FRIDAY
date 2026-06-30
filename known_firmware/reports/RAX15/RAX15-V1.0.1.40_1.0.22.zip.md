# Firmware Audit: RAX15 / RAX15-V1.0.1.40_1.0.22.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.1.40_1.0.22.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.1.40_1.0.22.zip
- SHA-256: `c26f4437afb7c5c5add838c443a0317f8524fa5504affdba4e2fa770c8d39441`
- Size: 52105726 bytes
- Version: 1.0.1.40_1.0.22
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c26f4437afb7c5c5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
