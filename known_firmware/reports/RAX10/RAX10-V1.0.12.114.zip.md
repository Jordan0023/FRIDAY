# Firmware Audit: RAX10 / RAX10-V1.0.12.114.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.12.114.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.12.114.zip
- SHA-256: `d7a39ef3afc48fc3c70011d8cb7df0e2a81f59bd02b7f21616c567682c52a2b0`
- Size: 52193954 bytes
- Version: 1.0.12.114
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eVaL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d7a39ef3afc48fc3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
