# Firmware Audit: TP-Link Deco BE85 / Deco_BE85_V2_1.2.1_250731.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202511/20251118/Deco BE85_V2_1.2.1_250731.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE85/Deco_BE85_V2_1.2.1_250731.zip
- SHA-256: `36d4c17759c8be8d64e344d7b02161d3353b786b91157271f1475a030d5cd371`
- Size: 36841078 bytes
- Version: V2.6_1.2.1 Build 20250731
- Release date: 2025-11-18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/36d4c17759c8be8d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
