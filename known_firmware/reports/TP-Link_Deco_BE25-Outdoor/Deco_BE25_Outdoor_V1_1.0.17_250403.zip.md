# Firmware Audit: TP-Link Deco BE25-Outdoor / Deco_BE25_Outdoor_V1_1.0.17_250403.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250519/Deco BE25 Outdoor_V1_1.0.17_250403.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE25-Outdoor/Deco_BE25_Outdoor_V1_1.0.17_250403.zip
- SHA-256: `4538b4a70d1f344650268df50384ec5b9956e021b2060f998ee7b2d56a50ca51`
- Size: 38210142 bytes
- Version: V1.6_1.0.17 Build 20250403
- Release date: 2025-05-19

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4538b4a70d1f3446 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
