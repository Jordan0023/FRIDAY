# Firmware Audit: TP-Link Deco WB10800 / Deco_WB10800_V2.6_1.0.3_250415.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202506/20250620/Deco WB10800_V2.6_1.0.3_250415.zip
- Local path: known_firmware/firmware/TP-Link_Deco_WB10800/Deco_WB10800_V2.6_1.0.3_250415.zip
- SHA-256: `2a5aaa2e0874065c23e95e9dbb4385ffe99b4528ad92e3c33b44edfb2c51aad6`
- Size: 38319292 bytes
- Version: V2.6_1.0.3 Build 20250415
- Release date: 2025-06-20

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2a5aaa2e0874065c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
