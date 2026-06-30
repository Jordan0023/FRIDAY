# Firmware Audit: TP-Link Deco WB7200 / Deco_WB7200_V1.6_1.0.5_250513.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202506/20250620/Deco WB7200_V1.6_1.0.5_250513.zip
- Local path: known_firmware/firmware/TP-Link_Deco_WB7200/Deco_WB7200_V1.6_1.0.5_250513.zip
- SHA-256: `e47d8822cc0475b5aa2c333f726993301dc2960d43840b678c426b8f79f8db6a`
- Size: 38325574 bytes
- Version: V1.6_1.0.5 Build 20250513
- Release date: 2025-06-20

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e47d8822cc0475b5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
