# Firmware Audit: TP-Link Deco M9 Plus / M9Plus_2.0_en_1.8.1_Build_20250219.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250515/M9Plus_2.0_en_1.8.1_Build_20250219.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M9_Plus/M9Plus_2.0_en_1.8.1_Build_20250219.zip
- SHA-256: `0df2f89b15d3f43dfbd811f39239e5d2e6181076984a368465e3ddc93d2f04f2`
- Size: 23749637 bytes
- Version: V2_1.8.1 Build 20250219
- Release date: 2025-05-15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0df2f89b15d3f43d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
