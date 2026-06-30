# Firmware Audit: TP-Link Deco X5400 Pro / Deco_X5400Pro_1.2.3_20231227.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202401/20240130/Deco_X5400Pro_1.2.3_20231227.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X5400_Pro/Deco_X5400Pro_1.2.3_20231227.zip
- SHA-256: `10ef849208ca7b07746e7122d924d00cb719a70703b3ebc9d1e5a6e99010b4c1`
- Size: 25595103 bytes
- Version: V1.6_1.2.3 Build 20231227
- Release date: 2024-01-30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/10ef849208ca7b07 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
