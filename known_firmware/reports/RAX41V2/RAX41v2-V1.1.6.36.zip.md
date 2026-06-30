# Firmware Audit: RAX41V2 / RAX41v2-V1.1.6.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41v2-V1.1.6.36.zip
- Local path: known_firmware/firmware/RAX41V2/RAX41v2-V1.1.6.36.zip
- SHA-256: `c9107da562eadff520737d548afb24ceab14c4ffc67b92a75f358075f3c11c02`
- Size: 81385786 bytes
- Version: 1.1.6.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9107da562eadff5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
