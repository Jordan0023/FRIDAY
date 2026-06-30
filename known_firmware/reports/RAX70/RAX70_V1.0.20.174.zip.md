# Firmware Audit: RAX70 / RAX70_V1.0.20.174.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70_V1.0.20.174.zip
- Local path: known_firmware/firmware/RAX70/RAX70_V1.0.20.174.zip
- SHA-256: `a02b437714df430b946bcfe4dca21e40814c96c8bf17f7d651b1024ecb1ff2bc`
- Size: 67722357 bytes
- Version: 0.20.174
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a02b437714df430b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
