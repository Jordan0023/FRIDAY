# Firmware Audit: TP-Link Deco X55 Pro / Deco_X55_Pro_V1_1.4.7_241115_US_CA.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202501/20250109/Deco X55 Pro_V1_1.4.7_241115_US_CA.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X55_Pro/Deco_X55_Pro_V1_1.4.7_241115_US_CA.zip
- SHA-256: `ec92d7d1be41dc7909adaf38d5a333a9fb7fc2f2a1cea25f2c86b7196ac45c94`
- Size: 27918456 bytes
- Version: V1.6_1.4.7 Build 20241115
- Release date: 2025-01-09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ec92d7d1be41dc79 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
