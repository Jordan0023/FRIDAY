# Firmware Audit: RAX50V2 / RAX50v2-V1.1.6.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50v2-V1.1.6.36.zip
- Local path: known_firmware/firmware/RAX50V2/RAX50v2-V1.1.6.36.zip
- SHA-256: `7f141e2554d0adfe44bb7d9e9507f6fa9b90a94ad23e1c5ebcf1788a6737e5f1`
- Size: 81385772 bytes
- Version: 1.1.6.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7f141e2554d0adfe exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
