# Firmware Audit: TP-Link Deco M9 Plus / M9Plus_2.0_2.20_1.9.1_Build_20250612_Rel._45690.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202507/20250729/M9Plus_2.0_2.20_1.9.1 Build 20250612 Rel. 45690.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M9_Plus/M9Plus_2.0_2.20_1.9.1_Build_20250612_Rel._45690.zip
- SHA-256: `1cc9062d4670123c9e56a1daebf07cb136ccb6fbf0719d678a9245895a0f5046`
- Size: 23902178 bytes
- Version: V2_1.9.1 Build 20250612
- Release date: 2025-07-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, evaL`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1cc9062d4670123c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
