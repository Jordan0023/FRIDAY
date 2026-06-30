# Firmware Audit: RAX75 / RAX75-V1.0.1.62_1.0.26.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.1.62_1.0.26.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.1.62_1.0.26.zip
- SHA-256: `586a0570bf5a4dc7fac7f4b192945c3fcedd0bdddd54aa3ec49cd1cdaecf03c2`
- Size: 49543190 bytes
- Version: 1.0.1.62_1.0.26
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA, Boa, bOA, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `evaL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/586a0570bf5a4dc7 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
