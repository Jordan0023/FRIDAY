# Firmware Audit: TP-Link Deco BE65 Pro / Deco_BE65_Pro_V1.6_1.3.1_26042912.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202605/20260527/Deco BE65 Pro_V1.6_1.3.1_26042912.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE65_Pro/Deco_BE65_Pro_V1.6_1.3.1_26042912.zip
- SHA-256: `c9841163830bbb7ecad49185ffbb5a6799d1c0c6e6d25126c74392195ef4bbbf`
- Size: 48087508 bytes
- Version: V1.6_1.3.1 Build 26042912
- Release date: 2026-05-27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9841163830bbb7e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
