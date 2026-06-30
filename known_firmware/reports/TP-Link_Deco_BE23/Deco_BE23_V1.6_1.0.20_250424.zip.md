# Firmware Audit: TP-Link Deco BE23 / Deco_BE23_V1.6_1.0.20_250424.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250527/Deco BE23_V1.6_1.0.20_250424.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE23/Deco_BE23_V1.6_1.0.20_250424.zip
- SHA-256: `5786b58581112a7fca59b91e54a4f44ca0a3c074b0ad0ceae4f3fa41c6d2ab3e`
- Size: 38214558 bytes
- Version: V1.6_1.0.20 Build 20250424
- Release date: 2025-05-28

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5786b58581112a7f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
