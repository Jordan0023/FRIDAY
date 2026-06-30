# Firmware Audit: TP-Link Deco X55 Pro / Deco_X55_Pro_V1_1.4.9_250110_US_CA.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202503/20250311/Deco X55 Pro_V1_1.4.9_250110_US_CA.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X55_Pro/Deco_X55_Pro_V1_1.4.9_250110_US_CA.zip
- SHA-256: `765fbb3d4ff8dc2415e409b3f8e4864bf565a3bde6bf83a705025cd5cbb1143c`
- Size: 27919105 bytes
- Version: V1.6_1.4.9 Build 20250110
- Release date: 2025-03-11

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EvaL, System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/765fbb3d4ff8dc24 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
