# Firmware Audit: TP-Link Deco X5400 Pro / Deco_X5400_Pro_1.0_en_1.2.4_Build_20240123_Rel._64692_US_up.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202407/20240718/Deco X5400 Pro_1.0_en_1.2.4_Build_20240123_Rel._64692_US_up.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X5400_Pro/Deco_X5400_Pro_1.0_en_1.2.4_Build_20240123_Rel._64692_US_up.zip
- SHA-256: `3a8610391906e8f9dffb2507a4907be7353aa1810f10427cb8884c83d40fb895`
- Size: 25653730 bytes
- Version: V1.6_1.2.4 Build 20240123
- Release date: 2024-07-18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a8610391906e8f9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
