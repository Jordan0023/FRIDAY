# Firmware Audit: RAX43V2 / RAX43v2-V1.1.6.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43v2-V1.1.6.36.zip
- Local path: known_firmware/firmware/RAX43V2/RAX43v2-V1.1.6.36.zip
- SHA-256: `029a957943a137a85b87f01ae9b2806bf26d6504eb760c0f40d77436b26c7832`
- Size: 81385779 bytes
- Version: 1.1.6.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/029a957943a137a8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
