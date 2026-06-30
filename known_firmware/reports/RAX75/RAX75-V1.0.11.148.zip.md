# Firmware Audit: RAX75 / RAX75-V1.0.11.148.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.11.148.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.11.148.zip
- SHA-256: `a08be3539f34352f0cd880543b87ea7ce871d39a26c2a9e64fec9d0a4ec2abd7`
- Size: 73661283 bytes
- Version: 1.0.11.148
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a08be3539f34352f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
