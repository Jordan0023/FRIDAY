# Firmware Audit: RAX80 / RAX80-V1.0.11.148.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.11.148.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.11.148.zip
- SHA-256: `417726b11ada0a23b953f7e1d246e0cc7649118d7bdf39e5e684dac9f59495c7`
- Size: 73661279 bytes
- Version: 1.0.11.148
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eval`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/417726b11ada0a23 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
