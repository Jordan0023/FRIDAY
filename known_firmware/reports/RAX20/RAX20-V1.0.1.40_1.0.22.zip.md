# Firmware Audit: RAX20 / RAX20-V1.0.1.40_1.0.22.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.1.40_1.0.22.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.1.40_1.0.22.zip
- SHA-256: `9898053f7f93db6f0edcf873115e1ac3261df131eb9f5d7ef8049a614e77f049`
- Size: 52105725 bytes
- Version: 1.0.1.40_1.0.22
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9898053f7f93db6f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
