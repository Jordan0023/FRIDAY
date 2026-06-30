# Firmware Audit: RAX10 / RAX10-V1.0.5.108.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.5.108.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.5.108.zip
- SHA-256: `99e205ffe1bbf89f6987bc0dbf7c79c630e76484d39f720f45691a6b74651e71`
- Size: 51889249 bytes
- Version: 1.0.5.108
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVaL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/99e205ffe1bbf89f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
